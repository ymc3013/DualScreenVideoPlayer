
TARGET := MinimalPlayer
BUILD := build
SOURCES := .
INCLUDES :=

ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS := -g -Wall -O2 -mword-relocations
CFLAGS += -ffunction-sections -fdata-sections $(ARCH)

LDFLAGS := -specs=3dsx.specs -g $(ARCH)
LDFLAGS += -Wl,--gc-sections

LIBS := -lctru

include $(DEVKITARM)/3ds_rules
