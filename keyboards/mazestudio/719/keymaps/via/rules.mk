RAW_ENABLE = yes
WPM_ENABLE = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi

SRC += graphics/agirl.qgf.c \
	   graphics.c \
	   fonts/techfont.qff.c \
	   fonts/typodraft.qff.c
	   