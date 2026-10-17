ifeq ($(strip $(DEVKITARM)),)
$(error DEVKITARM is not set. Install devkitARM and devkitPro)
endif

TARGET := MinimalPlayer
BUILD := build

SOURCES := .
INCLUDES := .

ARCH := -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS := -g -Wall -O2 -mword-relocations
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += $(ARCH)
CFLAGS += -D__3DS__

CXXFLAGS := $(CFLAGS)

LDFLAGS := -specs=3dsx.specs -g
LDFLAGS += $(ARCH)
LDFLAGS += -Wl,--gc-sections

LIBS := -lctru -lm

.PHONY: all clean

all: $(BUILD)/$(TARGET).3dsx

include $(DEVKITARM)/3ds_rules

clean:
	@rm -rf $(BUILD)