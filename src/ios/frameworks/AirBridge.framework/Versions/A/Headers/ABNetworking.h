//
//  ABNetworking.h
//  DLActivateTester
//
//  Created by TehranSlippers on 7/16/15.
//  Copyright © 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "ABCookieMatcher.h"

#define ABNETWORKING_ETYPE_LAUNCH 101
#define ABNETWORKING_ETYPE_GOAL 102
#define ABNETWORKING_ETYPE_BACKGROUND 103
#define ABNETWORKING_ETYPE_INSTALL 104
#define ABNETWORKING_ETYPE_TRACEVIEW 105
#define ABNETWORKING_ETYPE_TRACEACTION 106
#define ABNETWORKING_ETYPE_FOREGROUND 107
#define ABNETWORKING_ETYPE_SIMPLE_LAUNCH 108
#define ABNETWORKING_ETYPE_SIMPLE_GOAL 109

typedef void (^ABNetworkingSuccessBlock)(id json);
typedef void (^ABNetworkingFailBlock)(NSError *error, id json);
typedef void (^ABNetworkingRetryBlock)(NSInteger retryCount);

typedef NS_ENUM(NSUInteger, ABNetworkingType) {
    ABNETWORKING_TYPE_GET,
    ABNETWORKING_TYPE_POST,
    ABNETWORKING_TYPE_GET_SYNC,
    ABNETWORKING_TYPE_POST_SYNC
};

@interface ABNetworking : NSObject
+ (void)networkWithType:(ABNetworkingType)type
                   path:(NSString*)path
             parameters:(NSDictionary *)parameters
           successBlock:(ABNetworkingSuccessBlock)successBlock
              failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)getToPath:(NSString *)path
       parameters:(NSDictionary *)parameters
     successBlock:(ABNetworkingSuccessBlock)successBlock
        failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)postToPath:(NSString *)path
        parameters:(NSDictionary *)parameters
      successBlock:(ABNetworkingSuccessBlock)successBlock
         failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)getSyncToPath:(NSString *)path
           parameters:(NSDictionary *)parameters
         successBlock:(ABNetworkingSuccessBlock)successBlock
            failBlock:(ABNetworkingFailBlock)failBlock;

+ (void)postSyncToPath:(NSString *)path
            parameters:(NSDictionary *)parameters
          successBlock:(ABNetworkingSuccessBlock)successBlock
             failBlock:(ABNetworkingFailBlock)failBlock;


+ (void)installWithPath:(NSString *)path
             parameters:(NSDictionary *)parameters
           successBlock:(ABNetworkingSuccessBlock)successBlock
             retryBlock:(ABNetworkingRetryBlock)retryBlock
              failBlock:(ABNetworkingFailBlock)failBlock;

+ (NSString*)makeServerAddressWith:(NSString*)uuid;
+ (NSString*)makeInstallApiAddress;
+ (NSString*)makeRoutingServerAddressWith:(NSString*)uuid;
+ (NSString*)makeCookieMatchApiAddressWith:(NSString*)uuid deviceToken:(NSString*)deviceToken appToken:(NSString*)appToken ;

@end
