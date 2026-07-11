#import <objc/runtime.h>

#import <YouTubeHeader/YTSettingsGroupData.h>
#import <YouTubeHeader/YTSettingsSectionItem.h>
#import <YouTubeHeader/YTSettingsSectionItemManager.h>
#import <YouTubeHeader/YTSettingsViewController.h>
#import <YouTubeHeader/YTSettingsCell.h>
#import <YouTubeHeader/YTIIcon.h>

#import "Tweak.h"

#define TweakName @"YTLowContrastMode"

static const NSInteger TweakSection = 'lcmd';

@interface YTSettingsSectionItemManager (LowContrastMode)
- (void)updateLowContrastModeSectionWithEntry:(id)entry;
@end

%hook YTSettingsGroupData

+ (NSMutableArray<NSNumber *> *)tweaks {

    NSMutableArray<NSNumber *> *tweaks = %orig;

    if (tweaks && ![tweaks containsObject:@(TweakSection)]) {
        [tweaks addObject:@(TweakSection)];
    }

    return tweaks;
}

- (NSArray<NSNumber *> *)orderedCategories {

    if (self.type != 1 ||
        class_getClassMethod(objc_getClass("YTSettingsGroupData"),
                             @selector(tweaks))) {
        return %orig;
    }

    NSArray<NSNumber *> *orig = %orig;
    NSMutableArray<NSNumber *> *categories = [orig mutableCopy];

    if (![categories containsObject:@(TweakSection)]) {
        [categories insertObject:@(TweakSection) atIndex:0];
    }

    return categories.copy;
}

%end

%hook YTSettingsSectionItemManager

%new(v@:@)
- (void)updateLowContrastModeSectionWithEntry:(id)entry {

    NSMutableArray<YTSettingsSectionItem *> *sectionItems =
        [NSMutableArray array];

    Class Item = %c(YTSettingsSectionItem);

    YTSettingsViewController *settingsViewController =
        [self valueForKey:@"_settingsViewControllerDelegate"];

    //
    // Version
    //

    YTSettingsSectionItem *version =
    [Item itemWithTitle:@"YTLowContrastMode v1.8.3 by Mark02-2012"
       titleDescription:nil
accessibilityIdentifier:nil
        detailTextBlock:nil
            selectBlock:^BOOL (YTSettingsCell *cell,
                               NSUInteger arg1) {

        return NO;

    }];

    [sectionItems addObject:version];

    //
    // Restart notice
    //

    YTSettingsSectionItem *restartBar =
    [Item itemWithTitle:@"Restart YouTube after changing this option."
       titleDescription:nil
accessibilityIdentifier:nil
        detailTextBlock:nil
            selectBlock:^BOOL (YTSettingsCell *cell,
                               NSUInteger arg1) {

        return NO;

    }];

    [sectionItems addObject:restartBar];

    //
    // Enable switch
    //

    YTSettingsSectionItem *enable =
    [Item switchItemWithTitle:@"Enable Low Contrast Mode"
             titleDescription:@"Reduces UI contrast for a more comfortable viewing experience. Some UI elements are still unaffected due to legacy code and will be updated in a future release."
      accessibilityIdentifier:nil
                     switchOn:IS_ENABLED(LowContrastModeEnabledKey)
                  switchBlock:^BOOL (YTSettingsCell *cell,
                                     BOOL enabled) {

        [[NSUserDefaults standardUserDefaults]
            setBool:enabled
             forKey:LowContrastModeEnabledKey];

        return YES;

    }
                settingItemId:0];

    [sectionItems addObject:enable];

    //
    // Intensity picker
    //

    YTSettingsSectionItem *intensity =
[Item itemWithTitle:@"Contrast intensity"
   titleDescription:@"Original"
accessibilityIdentifier:nil
    detailTextBlock:nil
        selectBlock:^BOOL(YTSettingsCell *cell, NSUInteger arg){

    // TODO: picker

    return YES;
}];

[sectionItems addObject:intensity];

    //
    // Register section
    //

    if ([settingsViewController respondsToSelector:
        @selector(setSectionItems:forCategory:title:icon:titleDescription:headerHidden:)]) {

        YTIIcon *icon = [%c(YTIIcon) new];
        icon.iconType = YT_BRIGHTNESS;

        [settingsViewController
            setSectionItems:sectionItems
                forCategory:TweakSection
                      title:TweakName
                       icon:icon
           titleDescription:nil
               headerHidden:NO];

    } else {

        [settingsViewController
            setSectionItems:sectionItems
                forCategory:TweakSection
                      title:TweakName
           titleDescription:nil
               headerHidden:NO];
    }
}

- (void)updateSectionForCategory:(NSUInteger)category
                       withEntry:(id)entry {

    if (category == TweakSection) {
        [self updateLowContrastModeSectionWithEntry:entry];
        return;
    }

    %orig;
}

%end

%ctor {
    %init;
}
