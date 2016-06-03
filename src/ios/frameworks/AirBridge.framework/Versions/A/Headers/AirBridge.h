//
//  AB.h
//  DLActivateTester
//
//  Created by TehranSlippers on 7/16/15.
//  Copyright © 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCommon.h"
#include "ABObserver.h"
#import "ABRouting.h"

@interface AirBridge : NSObject

+ (AirBridge*)instance;

/**
 * init method for airbridge
 *
 * @param userToken app id를 넣어주세요.
 * @param appToken 사용자 토큰을 넣어주세요. (JWT를 제외한 값을 넣어주세요.)
 * @return
 */
+ (AirBridge*)getInstance:(NSString*)userToken appToken:(NSString*)appToken;

- (void)handleURL:(NSURL*)url;
- (BOOL)canHandleURL:(NSURL*)url;

- (BOOL)launch:(NSDictionary *)params;
- (void)launchWithOptions:(NSDictionary*)options;

- (void)registDefaultRoutingCallback:(abDefaultRoutingCallback)callback;
- (void)registSimpleLinkRoutingCallback:(abSimpleLinkRoutingCallback)callback;

- (void)registRouting:(NSString*)routeString callback:(abAutoRoutingCallback)callback;
- (void)registRouting:(NSString*)routeString description:(NSString*)desc callback:(abAutoRoutingCallback)callback;

- (BOOL)goalWithDescription:(NSString *)goalDescription;
- (BOOL)goalWithDescription:(NSString *)goalDescription category:(NSString*)category;
- (BOOL)goalWithDescription:(NSString *)goalDescription key:(NSString*)goalKey;
- (BOOL)goalWithDescription:(NSString *)goalDescription category:(NSString*)category key:(NSString*)goalKey;

- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription;
- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription category:(NSString*)category;
- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription key:(NSString*)goalKey;
- (BOOL)simpleGoalWithDescription:(NSString *)goalDescription category:(NSString*)category key:(NSString*)goalKey;

- (BOOL)setCurrentTracingView:(NSString*)viewName;
- (BOOL)setCurrentTracingView:(NSString*)viewName userInfo:(NSDictionary*)userInfo;
- (BOOL)setCurrentTracingAction:(NSString*)actionName;
- (BOOL)setCurrentTracingAction:(NSString*)actionName userInfo:(NSDictionary*)userInfo;
- (BOOL)setUser:(NSString*)value;

- (void)noticeAppIndexingScheme:(ABAppindexingScheme)scheme;
- (void)noticeAppIndexingSchemes:(NSArray*)schemes;

- (void)createAppIndexingWith:(NSString*)identifier title:(NSString*)title description:(NSString*)description;

- (void)noticeSDKInstall:(NSString*)thirdPartySDKType ;

/**
 {
 @identifier: [NSString] <required>
 @title: [NSString] <required>
 @description: [NSString] <required>
 @userInfo : [NSDictionary]
 @keywords : [NSSet]
 @thumbnail : [UIImage]
 @expireDate : [NSDate]
 }
 **/
- (void)createAppIndexingWith:(NSDictionary*)indexDataDictionary;
- (void)deleteAppIndexing:(NSString*)identifier;
- (void)deleteAppIndexingWithIdentifiers:(NSArray*)identifiers;

- (BOOL)background;
- (BOOL)foreground;

@end
