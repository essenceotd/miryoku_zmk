#include <zephyr/kernel.h>
#include "output.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bt_no_signal);
LV_IMG_DECLARE(bt_unbonded);
LV_IMG_DECLARE(bt);
LV_IMG_DECLARE(usb);

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
// static void draw_usb_connected(lv_obj_t *canvas) {
//     lv_draw_label_dsc_t label_dsc;
//     init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
//     lv_canvas_draw_text(canvas, 12, 140, SCREEN_WIDTH-8, &label_dsc, "USB");
// }
// #endif

// static void draw_ble_disconnected(lv_obj_t *canvas) {
//     lv_draw_label_dsc_t label_dsc;
//     init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
//     lv_canvas_draw_text(canvas, 12, 140, SCREEN_WIDTH-8, &label_dsc, "NULL");
// }

// static void draw_ble_connected(lv_obj_t *canvas) {
//     lv_draw_label_dsc_t label_dsc;
//     init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
//     lv_canvas_draw_text(canvas, 12, 140, SCREEN_WIDTH-8, &label_dsc, "BLE");
// }
static void draw_usb_connected(lv_obj_t *canvas) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    lv_layer_t layer;
    lv_canvas_init_layer(canvas, &layer);
    lv_area_t area = {12, 140, SCREEN_WIDTH - 8, 160};
    lv_draw_label(&layer, &label_dsc, &area, "USB");
    lv_canvas_finish_layer(canvas, &layer);
}

static void draw_ble_disconnected(lv_obj_t *canvas) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    lv_layer_t layer;
    lv_canvas_init_layer(canvas, &layer);
    lv_area_t area = {12, 140, SCREEN_WIDTH - 8, 160};
    lv_draw_label(&layer, &label_dsc, &area, "NULL", NULL);
    lv_canvas_finish_layer(canvas, &layer);
}

static void draw_ble_connected(lv_obj_t *canvas) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    lv_layer_t layer;
    lv_canvas_init_layer(canvas, &layer);
    lv_area_t area = {12, 140, SCREEN_WIDTH - 8, 160};
    lv_draw_label(&layer, &label_dsc, &area, "BLE", NULL);
    lv_canvas_finish_layer(canvas, &layer);
}

void draw_output_status(lv_obj_t *canvas, const struct status_state *state) {
    switch (state->selected_endpoint.transport) {
        case ZMK_TRANSPORT_USB:
            draw_usb_connected(canvas);
            break;
        case ZMK_TRANSPORT_BLE:
            draw_ble_connected(canvas);
            break;
        default:
            draw_ble_disconnected(canvas);
            break;
    }

}
