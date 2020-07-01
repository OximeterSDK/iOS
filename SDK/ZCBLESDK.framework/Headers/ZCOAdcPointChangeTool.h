//
//  ZCOAdcPointChangeTool.h
//  VPH-3Production
//
//  Created by zhangchong on 2020/4/30.
//  Copyright © 2020 veepoo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCOAdcPointChangeTool : NSObject

//血氧波形转换
int32_t Adc_Data_Convert(uint32_t data);

@end

NS_ASSUME_NONNULL_END
