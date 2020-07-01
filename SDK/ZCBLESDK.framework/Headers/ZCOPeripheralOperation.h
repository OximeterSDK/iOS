//
//  ZCOPeripheralOperation.h
//  ZCBLESDK
//
//  Created by zhangchong on 2020/4/28.
//  Copyright © 2020 张冲. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZCBlePeripheralProtocol.h"
#import "ZCOBatteryModel.h"
#import "ZCOTestValueModel.h"
#import "ZCOSettingTimeModel.h"
#import "ZCOPersonalModel.h"

typedef NS_ENUM(NSInteger, ZCOSystemOpration) {
    ZCOSystemOprationReboot  = 0x01, //重启设备
    ZCOSystemOprationClear   = 0x02, //清除数据
    ZCOSystemOprationReset   = 0x03, //复位
    ZCOSystemOprationShutdown= 0x04, //关机
    ZCOSystemOprationOTA     = 0x05, //进入升级模式
    ZCOSystemOprationLEDON   = 0x06, //使屏幕亮屏
    ZCOSystemOprationLEDOFF  = 0x07, //使屏幕灭屏
    ZCOSystemOprationRedLigth= 0x08, //红灯亮灭测试
};

typedef NS_ENUM(NSInteger, ZCOOprationState) {
    ZCOOprationStateNone     =      0x00, //没有此功能
    ZCOOprationStateSuccess  =      0x01, //成功
    ZCOOprationStateFailure  =      0x02, //失败
    ZCOOprationStateDisconnected  = 0x0A, //设备未连接
};

//监听这个通知获取设备反馈数据
#define ZCO_NOTIDATA_KEY @"receiveDataNoti"
#define ZCO_WRITEDATA_KEY @"writeDataNoti"

typedef void(^ZCOSystemResult)(ZCOOprationState oprationState, NSString *operationMsg);

typedef void(^ZCOReadBaseResult)(ZCOOprationState oprationState);

typedef void(^ZCOReadBatteryResult)(ZCOOprationState oprationState, ZCOBatteryModel *batteryModel);

//设置开始和结束监听状体，start为当前设备是否为上报状态
typedef void(^ZCOSyncTimeResult)(ZCOOprationState oprationState);

//同步个人信息
typedef void(^ZCOSyncPersonalResult)(ZCOOprationState oprationState);

//设置和读取设备语言的block类型
typedef void(^ZCOLanguageResult)(ZCOOprationState oprationState, int language);

//设置和读取屏幕方向的block类型
typedef void(^ZCOScreenOrientationResult)(ZCOOprationState oprationState, int orientation);

//设置和读取屏幕驱动的block类型
typedef void(^ZCOScreenDriverResult)(ZCOOprationState oprationState, int driverType);

//设置开始和结束监听状体，start为当前设备是否为上报状态
typedef void(^ZCONotiTestResult)(ZCOOprationState oprationState, BOOL start);

@interface ZCOPeripheralOperation : NSObject <ZCBlePeripheralDelegate>

//通过这个block监听设备返回值的信息，在使用界面监听这个block，不用的时候置为nil
@property(nonatomic, copy) void(^testValueResult)(ZCOTestValueModel *testModel);

//通过这个block监听设备ADC返回值的信息，在使用界面监听这个block，不用的时候置为nil
@property(nonatomic, copy) void(^testAdcResult)(NSArray <NSNumber *>*points);


+ (instancetype)shareOperation;

//发送自定义的指令
- (void)zc_sendCustomCommandData:(NSData *)commandData;

//设备系统指令操作重启、清除数据、复位、关机、固件升级
- (void)zc_sendSystemOpration:(ZCOSystemOpration)systemsOpration result:(ZCOSystemResult)result;

//读取设备的基本信息MAC、设备版本、设备号,返回结果后信息直接更新到model中
- (void)zc_readDevBaseInfoWithResult:(ZCOReadBaseResult)result;

//读取电池信息
- (void)zc_readBatteryInfoWithResult:(ZCOReadBatteryResult)result;

//同步时间
- (void)zc_syncTimeWithModel:(ZCOSettingTimeModel *)settingTimeModel andResult:(ZCOSyncTimeResult)result;

//同步个人信息
- (void)zc_syncPersonalWithModel:(ZCOPersonalModel *)personalModel andResult:(ZCOSyncPersonalResult)result;

//读取设备语言
- (void)zc_readLanguageWithResult:(ZCOLanguageResult)result;

//设置设备语言
- (void)zc_settingLanguage:(int)language andResult:(ZCOLanguageResult)result;

//读取屏幕方向
- (void)zc_readScreenOrientationWithResult:(ZCOScreenOrientationResult)result;

//设置屏幕方向
- (void)zc_settingScreenOrientation:(int)orientation andResult:(ZCOScreenOrientationResult)result;

//读取屏幕驱动
- (void)zc_readScreenDriverWithResult:(ZCOScreenDriverResult)result;

//设置屏幕驱动
- (void)zc_settingScreenDriver:(int)driverType andResult:(ZCOScreenDriverResult)result;



//设置开始和结束监听
- (void)zc_notiTestDataWithStart:(BOOL)start andResult:(ZCONotiTestResult)result;

@end

