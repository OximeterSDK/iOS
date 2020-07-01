//
//  ZCOPersonalModel.h
//  ZCBLESDK
//
//  Created by zhangchong on 2020/4/28.
//  Copyright © 2020 张冲. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCOPersonalModel : NSObject

//0是女，1是男
@property(nonatomic, assign) int sex;

//这个值是当前年减去2000的值
@property(nonatomic, assign) int age;

//身高cm
@property(nonatomic, assign) int status;

//体重四舍五入取整
@property(nonatomic, assign) int weight;

//帐号crc，根据帐号计算得到CRC，具体算法后期安卓和iOS统一即可
@property(nonatomic, assign) uint16_t crc;

@end

NS_ASSUME_NONNULL_END
