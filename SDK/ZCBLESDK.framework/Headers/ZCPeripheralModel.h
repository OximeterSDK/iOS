//
//  ZCPeripheralModel.h
//  ZCBLESDK
//
//  Created by 张冲 on 2019/2/20.
//  Copyright © 2019 张冲. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZCPeripheralModel : NSObject

@property (nonatomic, strong, readonly) CBPeripheral *peripheral;

@property (nonatomic, strong, readonly) NSString *name;

@property (nonatomic, strong) NSString *mac;

@property (nonatomic, strong, readonly) NSString *uuidString;

@property (nonatomic, strong, readonly) NSDictionary *advertisementData;

@property (nonatomic, strong) NSNumber *RSSI;

//信号等级0到4，代表信号4个格数
@property (nonatomic, assign) int rssiLevel;

@property(nonatomic, assign) BOOL isDfu;

//通过广播包初始化模型，sdk内部使用
- (instancetype)initWithPeripheral:(CBPeripheral*)peripheral advertisementData:(NSDictionary*)advertisementData RSSI:(NSNumber *)RSSI;

//通过获取已连接的设备初始化模型，sdk内部使用
- (instancetype)initWithPeripheral:(CBPeripheral*)peripheral;

//判断是否是上次连接的设备
- (BOOL)isLastConnectModel;

//保存本次连接的信息, 供下次自动重连使用
- (void)saveConnectMessage;

//主动断开设备的时候,删除连接信息, 下次进入不再自动重连
+ (void)deleteConnectMessage;

//是否有上次保存连接的设备
+ (BOOL)haveLastConnectMessage;

@end

NS_ASSUME_NONNULL_END
