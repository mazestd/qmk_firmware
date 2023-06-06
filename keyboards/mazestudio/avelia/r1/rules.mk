#MCU Name
MCU = RP2040

#Bootloader selection
BOOTLOADER = rp2040

#Build Option

MOUSEKEY_ENABLE = yes		# Mouse Keys Function
EXTRAKEY_ENABLE = yes 		# Audio and System Control Function
COMMAND_ENABLE = yes		# Command for Debugging
NKRO_ENABLE = yes			# N-Key Roll-over
BACKLIGHT_ENABLE = no		# Enable Per-Key backlight
RGBLIGHT_ENABLE = no		# Enable Underglow RGB
AUDIO_ENABLE = no

QUANTUM_PAINTER = yes
#QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS = st7735_spi

#Additional Configuration to fix compiler issue
OPT_DEFS = -O2
EXTRALDFLAGS = -Wl,--defsym,FLASH_LEN=8192k

SRC += display.c
SRC += anime.qgf.c