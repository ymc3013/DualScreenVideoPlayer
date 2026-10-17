
DEVKITPRO ?= /opt/devkitpro
DEVKITARM ?= $(DEVKITPRO)/devkitARM

TARGET := DualScreenVideoPlayer
CC := $(DEVKITARM)/bin/arm-none-eabi-gcc

CFLAGS := -g -Wall -O2 -march=armv6k -mtune=mpcore \
          -mfloat-abi=hard -mtp=soft -D__3DS__ \
          -I$(DEVKITPRO)/libctru/include

LDFLAGS := -specs=3dsx.specs -L$(DEVKITPRO)/libctru/lib
LIBS := -lctru -lm

all: $(TARGET).3dsx

$(TARGET).elf: source/main.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBS)

$(TARGET).smdh:
	smdhtool --create "Dual Screen Video Player" \
	  "Dual-screen test application" "ymc3013" \
	  $(DEVKITPRO)/libctru/default_icon.png $@

$(TARGET).3dsx: $(TARGET).elf $(TARGET).smdh
	3dsxtool $(TARGET).elf $@ --smdh=$(TARGET).smdh

clean:
	rm -f $(TARGET).elf $(TARGET).smdh $(TARGET).3dsx

.PHONY: all clean
