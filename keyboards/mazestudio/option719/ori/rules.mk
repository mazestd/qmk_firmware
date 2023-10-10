# Enable Quantum Painter
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

# Fixing Compiler Error ( Might be removed later )
OPT_DEFS = -O2

# Additional Resource
SRC += display.c \
       lvgl_helpers.c \
       images/lvgl_bg.c