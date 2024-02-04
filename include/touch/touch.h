//
// Created by wangchuan on 2024/2/4.
//

#ifndef TOUCH_TOUCH_H
#define TOUCH_TOUCH_H

#include <linux/uinput.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int create_virtual_device();
void send_event(int fd, __u16 type, __u16 code, __s32 value);
void simulate_touch(int fd, __s32 x, __s32 y);
void destroy_virtual_device(int fd);

#endif //TOUCH_TOUCH_H
