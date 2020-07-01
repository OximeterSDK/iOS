//
//  ZCOTestValueModel.h
//  ZCBLESDK
//
//  Created by zhangchong on 2020/4/28.
//  Copyright © 2020 张冲. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZCOTestState) {
    ZCOTestStateNone  =  0x00, //没有测试
    ZCOTestStateTest  =  0x01, //测试中
};

NS_ASSUME_NONNULL_BEGIN

@interface ZCOTestValueModel : NSObject

@property(nonatomic, strong) NSString *time;

@property(nonatomic, assign) ZCOTestState testState;

@property(nonatomic, assign) int oxygen;

@property(nonatomic, assign) int heart;

@property(nonatomic, assign) int hrv;

@property(nonatomic, assign) float pi;

- (instancetype)initWithTbyte:(const uint8_t *)tbyte;

//把模型转为字典，这个可以用MJExtension，这个防止项目中没有使用这个库，所以自己手动转了
- (NSDictionary *)convertDict;
//把字典转为模型
+ (instancetype)convertModelWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
