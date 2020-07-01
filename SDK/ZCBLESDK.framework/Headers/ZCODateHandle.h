//
//  ZCODateHandle.h
//  VPH-3Production
//
//  Created by zhangchong on 2020/4/30.
//  Copyright © 2020 veepoo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCODateHandle : NSObject

/// 把日期转化成想要的字符串
/// @param date 日期
/// @param format 字符串格式
+ (NSString *)stringWithDate:(NSDate *)date format:(NSString *)format;

@end

NS_ASSUME_NONNULL_END
