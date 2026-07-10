TARGET := iphone:clang:latest:16.0

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = LowContrastMode

LowContrastMode_FILES = \
	Tweak.xm \
	Settings.xm

LowContrastMode_CFLAGS = -fobjc-arc
LowContrastMode_CFLAGS += -I$(THEOS_PROJECT_DIR)/YouTubeHeader

include $(THEOS_MAKE_PATH)/tweak.mk
