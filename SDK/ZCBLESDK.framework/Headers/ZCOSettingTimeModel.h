//
//  ZCOSettingTimeModel.h
//  ZCBLESDK
//
//  Created by zhangchong on 2020/4/28.
//  Copyright © 2020 张冲. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//这个model初始化的时候会自动把时间设置好，如果需要改动在人为改动，如果使用默认初始化就是系统时间和时间制式

@interface ZCOSettingTimeModel : NSObject

//0是24小时，1是12小时
@property(nonatomic, assign) int timeFormat;

//这个值是当前年减去2000的值
@property(nonatomic, assign) int year;

@property(nonatomic, assign) int month;

@property(nonatomic, assign) int day;

@property(nonatomic, assign) int hour;

@property(nonatomic, assign) int minute;

@property(nonatomic, assign) int second;

@end

NS_ASSUME_NONNULL_END
