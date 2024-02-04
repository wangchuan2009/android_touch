#include "touch_tools.h"

int fd;

void touch_tap(__s32 x, __s32 y)
{
    if(fd < 0) {
        fd = create_virtual_device();
    }
    simulate_touch(fd, x, y);
}

void touch_slide(__s32 begin_x, __s32 begin_y, __s32 finish_x, __s32 finish_y)
{
    if(fd < 0) {
        fd = create_virtual_device();
    }
    simulate_touch(fd, begin_x, begin_y);
    usleep(50); // 等待一段时间以模拟滑动

    // 模拟滑动
    int i;
    for (i = begin_x; i <= finish_x; i++) {
        simulate_touch(fd, i, begin_y + (finish_y - begin_y) * (i - begin_x) / (finish_x - begin_x));
        usleep(50); // 等待一段时间以模拟滑动
    }
}

void delay_touch_slide(__s32 begin_x, __s32 begin_y, __s32 finish_x, __s32 finish_y, unsigned int delay)
{
    if(fd < 0) {
        fd = create_virtual_device();
    }
    simulate_touch(fd, begin_x, begin_y);
    usleep(delay); // 等待一段时间以模拟滑动

    // 模拟滑动
    int i;
    for (i = begin_x; i <= finish_x; i++) {
        simulate_touch(fd, i, begin_y + (finish_y - begin_y) * (i - begin_x) / (finish_x - begin_x));
        usleep(delay); // 等待一段时间以模拟滑动
    }
}

void close_tools()
{
    destroy_virtual_device(fd);
}
