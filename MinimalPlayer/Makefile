.SUFFIXES:

ifeq ($(strip $(DEVKITPRO)),)
$(error DEVKITPRO is not set)
endif

include $(DEVKITPRO)/libctru/default_config

TARGET := MinimalPlayer
BUILD := build
SOURCES := source
INCLUDES := include

ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS := -g -Wall -Wextra -O2 -mword-relocations
CFLAGS += -ffunction-sections -fdata-sections $(ARCH)
CFLAGS += -D__3DS__

CXXFLAGS := $(CFLAGS)

ASFLAGS := $(ARCH)

LDFLAGS := -specs=3dsx.specs $(ARCH)
LDFLAGS += -Wl,--gc-sections

LIBS := -lctru -lm

APP_TITLE := MinimalPlayer
APP_DESCRIPTION := Minimal video player test
APP_AUTHOR := ymc3013

include $(DEVKITARM)/3ds_rules