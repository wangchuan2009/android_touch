#include <stdio.h>
#include "touch_tools.h"

int main()
{
    touch_tap(100, 100);
    touch_slide(1000, 1000, 1200, 1000);
    delay_touch_slide(1000, 1000, 1200, 1000, 100);
    printf("滑动成功");
    close_tools();
    return 0;
}