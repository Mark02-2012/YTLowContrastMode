#import "Tweak.h"

#define TweakName @"Low Contrast Mode"
static const NSInteger TweakSection = 'lcmd';

@interface YTSettingsSectionItemManager (LowContrastMode)
- (void)updateLowContrastModeSectionWithEntry:(id)entry;
@end

%hook YTSettingsGroupData

- (NSArray *)orderedCategories {
    NSArray *categories = %orig;

    if (self.type != 1)
        return categories;

    NSMutableArray *array = categories.mutableCopy;
    [array insertObject:@(TweakSection) atIndex:0];
    return array.copy;
}

%end

%hook YTSettingsSectionItemManager

%new
- (void)updateLowContrastModeSectionWithEntry:(id)entry {

    NSMutableArray *sectionItems = [NSMutableArray array];

    Class Item = %c(YTSettingsSectionItem);

    YTSettingsSectionItem *version =
    [Item itemWithTitle:@"Low Contrast Mode v1.8.0"
       titleDescription:nil
accessibilityIdentifier:nil
        detailTextBlock:nil
            selectBlock:^BOOL(YTSettingsCell *cell, NSUInteger arg){

        return NO;
    }];

    [sectionItems addObject:version];

    YTSettingsSectionItem *enable =
    [Item switchItemWithTitle:@"Enable Low Contrast Mode"
             titleDescription:@"Requires app restart"
      accessibilityIdentifier:nil
                     switchOn:IS_ENABLED(LowContrastModeEnabledKey)
                  switchBlock:^BOOL(YTSettingsCell *cell, BOOL enabled){

        [[NSUserDefaults standardUserDefaults]
            setBool:enabled
             forKey:LowContrastModeEnabledKey];

        [[NSUserDefaults standardUserDefaults] synchronize];

        return YES;

    }
                settingItemId:0];

    [sectionItems addObject:enable];

    YTSettingsViewController *settings =
        [self valueForKey:@"_settingsViewControllerDelegate"];

    [settings setSectionItems:sectionItems
                  forCategory:TweakSection
                        title:TweakName
             titleDescription:nil
                 headerHidden:NO];
}

- (void)updateSectionForCategory:(NSUInteger)category withEntry:(id)entry {

    if (category == TweakSection) {
        [self updateLowContrastModeSectionWithEntry:entry];
        return;
    }

    %orig;
}

%end
