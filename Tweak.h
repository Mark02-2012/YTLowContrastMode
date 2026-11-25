#import <UIKit/UIKit.h>
#import <rootless.h>

#define LowContrastModeEnabledKey @"lowContrastMode_enabled"
#define LowContrastModeIntensityKey @"lowContrastMode_intensity"

static inline BOOL IS_ENABLED(NSString *key) {

    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

    if ([defaults objectForKey:key] == nil) {
        [defaults setBool:NO forKey:key];
        return NO;
    }

    return [defaults boolForKey:key];
}

static inline CGFloat LCMIntensity(void) {

    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

    if ([defaults objectForKey:LowContrastModeIntensityKey] == nil) {
        [defaults setInteger:0 forKey:LowContrastModeIntensityKey];
        return 0.68f;
    }

    switch ([defaults integerForKey:LowContrastModeIntensityKey]) {

        case 0: // Default (previously Light)
            return 0.68f;

        case 1: // Slightly Darker
            return 0.62f;

        case 2: // Darker
            return 0.56f;

        case 3: // Softer
            return 0.74f;

        case 4: // Almost White
            return 0.80f;

        default:
            return 0.68f;
    }
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
