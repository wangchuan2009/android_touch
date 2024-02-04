#include "touch/touch.h"
#define PHONE_ID 0x1234
#define PHONE_PROJECT_ID 0x5678
#define DEV_PATH "/dev/uinput"
void send_event(int fd, __u16 type, __u16 code, __s32 value) {
    struct input_event ev;
    memset(&ev, 0, sizeof(ev));

    ev.type = type;
    ev.code = code;
    ev.value = value;

    write(fd, &ev, sizeof(ev));
}

int create_virtual_device()
{
    int fd = open(DEV_PATH, O_WRONLY | O_NONBLOCK);
    if (fd < 0) {
        printf("无法打开 %s\n", DEV_PATH);
        return -1;
    }

    ioctl(fd, UI_SET_EVBIT, EV_ABS);
    ioctl(fd, UI_SET_ABSBIT, ABS_MT_POSITION_X);
    ioctl(fd, UI_SET_ABSBIT, ABS_MT_POSITION_Y);

    struct uinput_setup usetup;
    memset(&usetup, 0, sizeof(usetup));
    usetup.id.bustype = BUS_USB;
    usetup.id.vendor = PHONE_ID; // 你的设备的供应商ID
    usetup.id.product = PHONE_PROJECT_ID; // 你的设备的产品ID
    strcpy(usetup.name, "Virtual Touch Device");

    ioctl(fd, UI_DEV_SETUP, &usetup);
    ioctl(fd, UI_DEV_CREATE);

    return fd;
}

void simulate_touch(int fd, __s32 x, __s32 y)
{
    send_event(fd, EV_ABS, ABS_MT_POSITION_X, x);
    send_event(fd, EV_ABS, ABS_MT_POSITION_Y, y);
    send_event(fd, EV_SYN, SYN_REPORT, 0);
}

void destroy_virtual_device(int fd)
{
    ioctl(fd, UI_DEV_DESTROY);
    close(fd);
}