//
//  ABRequestOperation.h
//  UdlSDKSample
//
//  Created by TehranSlippers on 8/6/15.
//  Copyright (c) 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABNetworking.h"

@interface ABRequestOperation : NSOperation <NSCoding>

- (instancetype)initWithType:(ABNetworkingType)type
                        path:(NSString*)path
                  parameters:(NSDictionary *)parameters;
- (instancetype)initWithType:(ABNetworkingType)type
                        path:(NSString*)path
                  parameters:(NSDictionary *)parameters
                failureCount:(NSUInteger)failureCount;

- (BOOL)reQueue ;

@property (assign) NSUInteger failureCount;
@property (assign, nonatomic) ABNetworkingType type;
@property (strong, nonatomic) NSString* path;
@property (strong, nonatomic) NSDictionary* parameters;
@property (nonatomic, assign) BOOL isInstall;

@end
