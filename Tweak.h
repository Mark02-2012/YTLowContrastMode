#import <UIKit/UIKit.h>
#import <rootless.h>

#define LowContrastModeEnabledKey @"lowContrastMode_enabled"

static inline BOOL IS_ENABLED(NSString *key) {
    return [[NSUserDefaults standardUserDefaults] boolForKey:key];
}

@interface YTSettingsCell : YTCollectionViewCell
@end

@interface YTSettingsSectionItem : NSObject
@property BOOL hasSwitch;
@property BOOL switchVisible;
@property BOOL on;
@property BOOL (^switchBlock)(YTSettingsCell *, BOOL);
@property int settingItemId;

- (instancetype)initWithTitle:(NSString *)title
             titleDescription:(NSString *)titleDescription;

+ (instancetype)itemWithTitle:(NSString *)title
             titleDescription:(NSString *)titleDescription
      accessibilityIdentifier:(NSString *)identifier
              detailTextBlock:(NSString *(^)(void))detailTextBlock
                  selectBlock:(BOOL(^)(YTSettingsCell *, NSUInteger))selectBlock;

+ (instancetype)switchItemWithTitle:(NSString *)title
                   titleDescription:(NSString *)titleDescription
            accessibilityIdentifier:(NSString *)identifier
                           switchOn:(BOOL)switchOn
                        switchBlock:(BOOL(^)(YTSettingsCell *, BOOL))switchBlock
                      settingItemId:(NSInteger)itemId;
@end

@interface YTSettingsSectionItemManager : NSObject
@end

@interface YTSettingsViewController : UIViewController
- (void)setSectionItems:(NSArray *)items
            forCategory:(NSUInteger)category
                  title:(NSString *)title
       titleDescription:(NSString *)description
           headerHidden:(BOOL)hidden;
@end

@interface YTSettingsGroupData : NSObject
@property(nonatomic, assign) NSInteger type;
@end

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
