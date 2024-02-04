//
// Created by wangchuan on 2024/2/4.
//

#ifndef TOUCH_TOUCH_TOOLS_H
#define TOUCH_TOUCH_TOOLS_H

#include "touch.h"

void touch_tap(__s32 x, __s32 y);
void touch_slide(__s32 begin_x, __s32 begin_y, __s32 finish_x, __s32 finish_y);
void delay_touch_slide(__s32 begin_x, __s32 begin_y, __s32 finish_x, __s32 finish_y, unsigned int delay);
void close_tools();
#endif //TOUCH_TOUCH_TOOLS_H