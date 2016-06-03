//
//  ABObserver.h
//  UdlSDKSample
//
//  Created by TehranSlippers on 7/30/15.
//  Copyright (c) 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ABCommon.h"

@interface ABObserver : NSObject

//+(NSString *)getSettingLanguage;
+(NSString *)getAppURLScheme;

+(NSString*)getDeviceType;
+(NSString*)getAppVersion;
+(NSString*)getSDKVersion;
+(NSString*)getOSVersionReturnNumber;
+(NSString*)getOSVersion;
+(CGSize)getScreenSize;
+ (NSString *)getIPAddress:(BOOL)preferIPv4;

@end
