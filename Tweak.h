#import <UIKit/UIKit.h>
#import <rootless.h>

#define LowContrastModeEnabledKey @"lowContrastMode_enabled"

static inline BOOL IS_ENABLED(NSString *key) {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

    if ([defaults objectForKey:key] == nil) {
        [defaults setBool:YES forKey:key];
        return YES;
    }

    return [defaults boolForKey:key];
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
