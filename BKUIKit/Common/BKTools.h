//
//  BKTools.h
//  BKUIKit
//
//  Created by zhaolin on 2019/10/26.
//  Copyright © 2019 BIKE. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BKTools : NSObject

#pragma mark - 当前显示window

/// 当前显示window
+(UIWindow*)keyWindow;

#pragma mark - 检测是否为空

/**
 检测是否为空
 
 @param object 检测对象
 @return 是否为空
 */
+(BOOL)isEmptyObject:(nonnull id)object;

#pragma mark - 打电话

/// 打电话
/// @param phoneStr 电话号
+(void)callPhone:(nonnull NSString*)phoneStr;

#pragma mark - alert弹框

/**
 alert弹框

 @param title 标题
 @param message 信息
 @param actionTitleArr 按钮
 @param actionMethod 按钮事件回调
 @return alert弹框
 */
+(UIAlertController*)presentAlert:(NSString*)title message:(NSString*)message actionTitleArr:(NSArray*)actionTitleArr actionMethod:(void (^)(NSInteger index))actionMethod;

/**
 alert弹框(富文本)
 
 @param attrTitle 标题
 @param attrMessage 信息
 @param actionTitleArr 按钮
 @param actionMethod 按钮事件回调
 @return alert弹框
 */
+(UIAlertController*)presentAttrAlert:(NSAttributedString*)attrTitle attrMessage:(NSAttributedString*)attrMessage actionTitleArr:(NSArray<NSString*>*)actionTitleArr actionMethod:(void (^)(NSInteger index))actionMethod;

/**
 alert弹框(富文本)
 
 @param attrTitle 标题
 @param attrMessage 信息
 @param actionTitleArr 按钮
 @param actionTitleColorArr 按钮颜色数组
 @param actionMethod 按钮事件回调
 @return alert弹框
 */
+(UIAlertController*)presentAttrAlert:(NSAttributedString*)attrTitle attrMessage:(NSAttributedString*)attrMessage actionTitleArr:(NSArray<NSString*>*)actionTitleArr actionTitleColorArr:(nullable NSArray<UIColor*>*)actionTitleColorArr actionMethod:(void (^)(NSInteger index))actionMethod;

+(UIAlertController*)presentActionSheet:(NSString*)title message:(NSString*)message actionTitleArr:(NSArray*)actionTitleArr actionMethod:(void (^)(NSInteger index))actionMethod;

@end

NS_ASSUME_NONNULL_END
