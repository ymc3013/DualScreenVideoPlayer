ifeq ($(strip $(DEVKITARM)),)
$(error DEVKITARM is not set)
endif

TARGET := MinimalPlayer
BUILD := build

SOURCES := source
INCLUDES := .

ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS := -g -Wall -O2 -mword-relocations
CFLAGS += -ffunction-sections -fdata-sections $(ARCH)
CFLAGS += -D__3DS__

CXXFLAGS := $(CFLAGS)

LDFLAGS := -specs=3dsx.specs -g $(ARCH)
LDFLAGS += -Wl,--gc-sections

LIBS := -lctru -lm

.PHONY: all clean

all:
	@echo "Compilation de MinimalPlayer..."

include $(DEVKITARM)/3ds_rules

clean:
	@rm -rf $(BUILD)