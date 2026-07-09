#import <UIKit/UIKit.h>
#import <rootless.h>

#define LowContrastModeEnabledKey @"lowContrastMode_enabled"

static inline BOOL IS_ENABLED(NSString *key) {
    return [[NSUserDefaults standardUserDefaults] boolForKey:key];
}

#pragma mark - Missing interfaces

@interface YTCollectionViewCell : UICollectionViewCell
@end

@interface YTQTMButton : UIButton
@end

#pragma mark - Settings

@interface YTSettingsCell : YTCollectionViewCell
@end

@interface YTSettingsSectionItem : NSObject

@property(nonatomic, assign) BOOL hasSwitch;
@property(nonatomic, assign) BOOL switchVisible;
@property(nonatomic, assign) BOOL on;
@property(nonatomic, copy) BOOL (^switchBlock)(YTSettingsCell *, BOOL);
@property(nonatomic, assign) int settingItemId;

- (instancetype)initWithTitle:(NSString *)title
             titleDescription:(NSString *)titleDescription;

+ (instancetype)itemWithTitle:(NSString *)title
             titleDescription:(NSString *)titleDescription
      accessibilityIdentifier:(NSString *)identifier
              detailTextBlock:(NSString *(^)(void))detailTextBlock
                  selectBlock:(BOOL (^)(YTSettingsCell *, NSUInteger))selectBlock;

+ (instancetype)switchItemWithTitle:(NSString *)title
                   titleDescription:(NSString *)titleDescription
            accessibilityIdentifier:(NSString *)identifier
                           switchOn:(BOOL)switchOn
                        switchBlock:(BOOL (^)(YTSettingsCell *, BOOL))switchBlock
                      settingItemId:(NSInteger)itemId;

@end

@interface YTSettingsGroupData : NSObject
@property(nonatomic, assign) NSInteger type;
@end

@interface YTSettingsViewController : UIViewController

- (void)setSectionItems:(NSArray *)items
            forCategory:(NSUInteger)category
                  title:(NSString *)title
       titleDescription:(NSString *)description
           headerHidden:(BOOL)hidden;

@end

@interface YTSettingsSectionItemManager : NSObject
@end

#pragma mark - Existing interfaces

@interface _ASCollectionViewCell : UICollectionViewCell
- (id)node;
@end

@interface _ASDisplayView : UIView
- (UILabel *)findLabelInSubviews:(NSArray *)subviews;
- (void)customizeLabel:(UILabel *)label;
@end

@interface YTColorPalette : NSObject
@property(readonly, nonatomic) long long pageStyle;
@end

@interface YTCommonColorPalette : NSObject
@property(readonly, nonatomic) long long pageStyle;
@end
