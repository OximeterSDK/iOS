//
//  ZCODeviceModel.h
//  ZCBLESDK
//
//  Created by zhangchong on 2020/4/28.
//  Copyright © 2020 张冲. All rights reserved.
//

#import "ZCPeripheralModel.h"
#import "ZCOBatteryModel.h"
//#import "VPServerOtaInfo.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZCODeviceModel : ZCPeripheralModel

@property (nonatomic, strong) NSString *deviceVersion;

@property (nonatomic, assign) int deviceID;

@property (nonatomic, assign) int oxygenType;

@property (nonatomic, assign) int heartType;

@property (nonatomic, assign) int hrvType;

@property (nonatomic, assign) int piType;

//读取完后的会在这里保存
@property (nonatomic, strong) ZCOBatteryModel *batteryModel;

//对应设备的语言
@property (nonatomic, assign) int language;

//对应4个方向1到4
@property (nonatomic, assign) int screenOrientation;

//对应4个方向1到4
@property (nonatomic, assign) BOOL notiTest;


//@property (nonatomic, strong) VPServerOtaInfo *serverOtaInfo;

//接收设备返回的基本信息
- (void)receiceDevBaseByte:(const uint8_t *)tbyte;

//接收设备返回的基本信息
- (void)receiceDevA1BaseByte:(const uint8_t *)tbyte;

@end

NS_ASSUME_NONNULL_END
