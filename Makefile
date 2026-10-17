
TARGET := DualScreenVideoPlayer
BUILD := build
SOURCES := source
INCLUDES := include

ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS := -g -Wall -O2 -mword-relocations \
          -ffunction-sections -fdata-sections \
          $(ARCH) $(INCLUDE) -D__3DS__

LDFLAGS := -specs=3dsx.specs -g $(ARCH) \
           -Wl,-Map,$(notdir $*.map) \
           -Wl,--gc-sections

LIBS := -lctru

include $(DEVKITPRO)/libctru/default_makefiles/3ds_rules
