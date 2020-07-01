//
//  ZCOBatteryModel.h
//  ZCBLESDK
//
//  Created by zhangchong on 2020/4/28.
//  Copyright © 2020 张冲. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZCOBatteryState) {
    ZCOBatteryStateNone    =  0x00, //未知状态
    ZCOBatteryStateNormal  =  0x01, //没有此功能
    ZCOBatteryStateCharge  =  0x02, //成功
    ZCOBatteryStateLow     =  0x03, //失败
    ZCOBatteryStateFull    =  0x04, //设备未连接
};

NS_ASSUME_NONNULL_BEGIN

@interface ZCOBatteryModel : NSObject

//电池状态
@property(nonatomic, assign) ZCOBatteryState batteryState;

//电池等级0到4格
@property(nonatomic, assign) int batteryLevel;

- (instancetype)initWithTbyte:(const uint8_t *)tbyte;

@end

NS_ASSUME_NONNULL_END
