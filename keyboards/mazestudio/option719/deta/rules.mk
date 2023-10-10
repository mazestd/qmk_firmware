QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

SRC += images/anime.qgf.c \
	   display.c \
	   lvgl_helpers.c

OPT_DEFS = -O2
