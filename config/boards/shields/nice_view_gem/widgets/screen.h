#pragma once
#include <lvgl.h>
#include <zephyr/kernel.h>
#include "util.h"

struct zmk_widget_screen {
    sys_snode_t node;
    lv_obj_t *obj;
    uint8_t cbuf[LV_CANVAS_BUF_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT, 1, LV_COLOR_FORMAT_I1)];
    uint8_t cbuf2[LV_CANVAS_BUF_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT, 1, LV_COLOR_FORMAT_I1)];
    uint8_t cbuf3[LV_CANVAS_BUF_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT, 1, LV_COLOR_FORMAT_I1)];
    struct status_state state;
};

int zmk_widget_screen_init(struct zmk_widget_screen *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_screen_obj(struct zmk_widget_screen *widget);
