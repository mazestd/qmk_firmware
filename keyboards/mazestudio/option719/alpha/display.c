#include <qp.h>
#include "images/xw.qgf.h"
#include "images/anime.qgf.h"

static painter_image_handle_t image;

uint32_t deffered_init(uint32_t trigger_time, void *cb_arg)
{
    image = qp_load_image_mem(gfx_anime);

    setPinOutput(GP2);
    writePinHigh(GP2);

    painter_device_t display = qp_st7789_make_spi_device(240, 320, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 0, 3);
    qp_set_viewport_offsets(display, 0, 20);
    qp_init(display, QP_ROTATION_180);

    //qp_rect(display, 1, 2, 80, 40, 24, 255, 255, true);
    qp_animate(display, (240 - image->width), (280 - image->height), image);
    //qp_drawimage(display, (240 - background->width), (280 - background->height), background);

    return(0);
}

void keyboard_post_init_kb(void)
{
    //debug_enable = true;
    defer_exec(3000, deffered_init, NULL);
}