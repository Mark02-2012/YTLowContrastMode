#import <UIKit/UIKit.h>
#import <rootless.h>

#define LowContrastModeEnabledKey @"lowContrastMode_enabled"
#define LowContrastModeIntensityKey @"lowContrastMode_intensity"

static inline BOOL IS_ENABLED(NSString *key) {

    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

    if ([defaults objectForKey:key] == nil) {
        [defaults setBool:YES forKey:key];
        return YES;
    }

    return [defaults boolForKey:key];
}

static inline CGFloat LCMIntensity(void) {

    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

    if ([defaults objectForKey:LowContrastModeIntensityKey] == nil) {
        [defaults setFloat:0.56f forKey:LowContrastModeIntensityKey];
        return 0.56f;
    }

    return [defaults floatForKey:LowContrastModeIntensityKey];
}

@interface YTQTMButton : UIButton
@end

@interface _ASCollectionViewCell : UICollectionViewCell
- (id)node;
@end

@interface _ASDisplayView : UIView
- (UILabel *)findLabelInSubviews:(NSArray *)subviews;
- (void)customizeLabel:(UILabel *)label;
@end

@interface YTColorPalette : NSObject
@property(nonatomic, readonly) long long pageStyle;
@end

@interface YTCommonColorPalette : NSObject
@property(nonatomic, readonly) long long pageStyle;
@end
