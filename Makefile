DEVKITPRO ?= /opt/devkitpro
DEVKITARM ?= $(DEVKITPRO)/devkitARM

TARGET := DualScreenVideoPlayer
CC := $(DEVKITARM)/bin/arm-none-eabi-gcc

SOURCES := main.c video.c audio.c
HEADERS := video.h audio.h

ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS := -g -Wall -Wextra -O2 -mword-relocations
CFLAGS += -ffunction-sections -fdata-sections $(ARCH)
CFLAGS += -D__3DS__ -I$(DEVKITPRO)/libctru/include

LDFLAGS := -specs=3dsx.specs
LDFLAGS += -L$(DEVKITPRO)/libctru/lib
LDFLAGS += -Wl,--gc-sections

LIBS := -lctru -lm

.PHONY: all clean

all: $(TARGET).3dsx

$(TARGET).elf: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@ $(LIBS)

$(TARGET).smdh:
	smdhtool --create "Dual Screen Video Player" \
		"Dual-screen test application" "ymc3013" \
		$(DEVKITPRO)/libctru/default_icon.png $@

$(TARGET).3dsx: $(TARGET).elf $(TARGET).smdh
	3dsxtool $(TARGET).elf $@ --smdh=$(TARGET).smdh

clean:
	rm -f $(TARGET).elf $(TARGET).smdh $(TARGET).3dsx