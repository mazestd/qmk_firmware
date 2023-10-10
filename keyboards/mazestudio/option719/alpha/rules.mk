# Enable Quantum Painter
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi

# Fixing Compiler Error ( Might be removed later )
OPT_DEFS = -O2

# Additional Resource
SRC += display.c \
       images/xw.qgf.c \
       images/anime.qgf.c