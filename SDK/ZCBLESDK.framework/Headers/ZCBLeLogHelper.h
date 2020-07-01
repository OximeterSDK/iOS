//
//  ZCBLeLogHelper.h
//  VPH-3Production
//
//  Created by zhangchong on 2020/5/29.
//  Copyright © 2020 veepoo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCBLeLogHelper : NSObject

//使用key的时候找开发者要，只有内部开发才给收集蓝牙收发日志
+ (void)setLogKey:(NSString *)key;

//开始接收
+ (void)startReceiveBleLog;

//接收结束
+ (void)endReceiveBleLog;

/**
 保存蓝牙数据

 @param receiveData 蓝牙接收和发送的原始数据
 @param write 是发送还是接收
 */
+ (void)receiveBleLogData:(NSData *)receiveData isWrite:(BOOL)write;

/**
 保存蓝牙状态信息
 
 @param bleStateState 蓝牙的状态
 */
+ (void)saveBleLogState:(NSString *)bleStateState;

+ (NSString *)getSaveStringWithData:(NSData *)data;

+ (void)clearData;

+ (NSString *)getContent;

@end

NS_ASSUME_NONNULL_END
