//
//  ZCBleOption.h
//  ZCBLESDK
//
//  Created by 张冲 on 2019/2/21.
//  Copyright © 2019 张冲. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
//此类会有默认配置，如果有其他的配置，可以自己重复赋值

@interface ZCBleOption : NSObject

@property (nonatomic, strong) NSDictionary *bleManagerOptions;
@property (nonatomic, strong) NSDictionary *bleConnectOptions;
@property (nonatomic, strong) NSDictionary *bleScanOptions;

//扫描时的过滤
@property (nonatomic, strong) NSArray *bleScanFilterUUIDS;

//系统连接蓝牙的过滤
@property (nonatomic, strong) NSArray *bleRetrieveConnectedFilterUUIDS;

@property (nonatomic, strong) CBUUID *baseService;
@property (nonatomic, strong) CBUUID *baseWriteCharacter;
@property (nonatomic, strong) CBUUID *baseNotifyCharacter;

@property (nonatomic, strong) CBUUID *adcService;
@property (nonatomic, strong) CBUUID *adcWriteCharacter;
@property (nonatomic, strong) CBUUID *adcNotifyCharacter;

//创建实例
+ (instancetype)sharedOption;

//血氧仪器的配置，这个是默认配置，如果在项目中没有使用其他配置，这个可以不用调用，默认就是这个
- (void)configForOxygenDevice;

//心率带的配置
- (void)configForHeartBand;

@end

