#MCU Name
MCU = atmega32u4

#Bootloader selection
BOOTLOADER = caterina

#Build Option

BOOTMAGIC_ENABLE = yes		# Enable Boot Loader via Key Switch
MOUSEKEY_ENABLE = no		# Mouse Keys Function
EXTRAKEY_ENABLE = yes 		# Audio and System Control Function
CONSOLE_ENABLE = yes		# Debugging
COMMAND_ENABLE = yes		# Command for Debugging
NKRO_ENABLE = yes			# N-Key Roll-over
BACKLIGHT_ENABLE = no		# Enable Per-Key backlight
RGBLIGHT_ENABLE = no		# Enable Underglow RGB
AUDIO_ENABLE = no 			# Audio Output

LAYOUT = split_bs

OLED_ENABLE = yes			# Enable OLED Functionality
OLED_DRIVER = SSD1306		# OLED Driver Type
WPM_ENABLE = yes