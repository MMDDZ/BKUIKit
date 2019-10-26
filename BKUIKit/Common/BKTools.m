//
//  BKTools.m
//  BKUIKit
//
//  Created by zhaolin on 2019/10/26.
//  Copyright © 2019 BIKE. All rights reserved.
//

#import "BKTools.h"

@implementation BKTools

#pragma mark - 当前显示window

/// 当前显示window
+(UIWindow*)keyWindow
{
    return [[[UIApplication sharedApplication] windows] objectAtIndex:0];
}

#pragma mark - 检测是否为空

/**
 检测是否为空
 */
+(BOOL)isEmptyObject:(id)object
{
    if (object == nil ||
        object == NULL ||
        [object isKindOfClass:[NSNull class]] ||
        [object isEqual:[NSNull null]]) {
        return YES;
    }
    return NO;
}

#pragma mark - 打电话

/// 打电话
+(void)callPhone:(NSString*)phoneStr
{
    NSURL * phoneUrl = [NSURL URLWithString:[NSString stringWithFormat:@"tel://%@", phoneStr]];
    
    if (@available(iOS 10.0, *)) {
        [[UIApplication sharedApplication] openURL:phoneUrl options:@{} completionHandler:nil];
    } else {
        [DSSharedManager presentAlert:phoneStr message:nil actionTitleArr:@[@"取消", @"呼叫"] actionMethod:^(NSInteger index) {
            if (index == 1) {
                [[UIApplication sharedApplication] openURL:phoneUrl];
            }
        }];
    }
}

#pragma mark - alert弹框

/**
alert弹框
 */
+(UIAlertController*)presentAlert:(NSString*)title message:(NSString*)message actionTitleArr:(NSArray*)actionTitleArr actionMethod:(void (^)(NSInteger index))actionMethod
{
    UIAlertController * alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    
    for (NSString * title in actionTitleArr) {
        
        NSInteger style;
        if ([title isEqualToString:@"取消"]) {
            style = UIAlertActionStyleCancel;
        }else{
            style = UIAlertActionStyleDefault;
        }
        
        UIAlertAction * action = [UIAlertAction actionWithTitle:title style:style handler:^(UIAlertAction * _Nonnull action) {
            if (actionMethod) {
                actionMethod([actionTitleArr indexOfObject:title]);
            }
        }];
        [alert addAction:action];
    }
    [self.displayViewController presentViewController:alert animated:YES completion:nil];
    return alert;
}

@end
