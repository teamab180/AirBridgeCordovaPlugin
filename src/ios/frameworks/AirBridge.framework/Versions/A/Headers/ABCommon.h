//
//  ABCommon.h
//  DLActivateTester
//
//  Created by TehranSlippers on 7/16/15.
//  Copyright © 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AB_VERSION @"M_I_v0.2.2"

typedef NS_ENUM(NSUInteger, ABAppindexingScheme) {
    ABAPPIDXING_RESTAURANT,
    ABAPPIDXING_MUSIC
};


@interface ABCommon : NSObject
+ (BOOL)debugMode;
+ (BOOL)isShowDebugConsole;
+ (BOOL)showDebugConsole:(BOOL)set;
+ (BOOL)isDefalutNetworkingToSync;
+ (BOOL)defalutNetworkingToSync:(BOOL)set;

+ (void)wrtieObjectToUserDefaultWith:(NSObject*)object key:(NSString*)key;
+ (void)setSession:(NSString*)token ;
+ (void)setTransactionId:(NSString*)transactionId ;
+ (void)setUserToken:(NSString*)token ;
+ (void)setAppid:(NSString*)token ;

/*
 * 15.12.23 Donutt: IDFA not used in ver 0.2.1 under , 
 * this will be used in after ~~ version.
 */
+ (void)setAirBridgeIDFA:(NSString*)IDFA ;
+ (NSString*)getAirBridgeIDFA;
+ (NSString *)getIDFA:(BOOL *)isReal ;
+ (NSString *)getIFV:(BOOL *)isReal;

+ (void)setAirBridgeCanonicalUserId:(NSString*)cUserId;
+ (NSString*)getAirBridgeCanonicalUserId;

+ (void)setAirBridgeUUID:(NSString*)UUID ;
+ (NSString*)getAirBridgeUUID;

+ (NSString*)getTransactionId;
+ (NSString*)getSession;
+ (NSString*)getFingerprint;
+ (NSDictionary*)getFingerprintToDictionary;
+ (NSString*)getAppid;
+ (NSString*)getUserToken;
+ (NSString *)getUniqueHardwareId:(BOOL *)isReal andIsDebug:(BOOL)debug;

+ (void)setSimpleLinkTokenWith:(NSString*)token ;
+ (NSString *)getSimpleLinkToken;

// storing control
+ (void)saveObject:(id)object toFile:(NSString *)filename;
+ (id)objectFromFile:(NSString *)filename;
+ (NSString *)pathWithFilename:(NSString *)filename;
@end

#ifdef DEBUG
#define ABLog(fmt, ...) NSLog((@"[AB] %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define ABLog(...)
#endif

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
