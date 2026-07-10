TARGET := iphone:clang:latest:15.0

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = LowContrastMode

LowContrastMode_FILES = \
    Tweak.xm \
    Settings.xm

LowContrastMode_CFLAGS = -fobjc-arc
LowContrastMode_CFLAGS += -I$(PWD)/YouTubeHeader

include $(THEOS_MAKE_PATH)/tweak.mk
