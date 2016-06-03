//
//  ABLogManager.h
//  AirBridge
//
//  Created by Donutt on 2015. 10. 22..
//  Copyright © 2015년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABLogManager : NSObject

void ABDebugLog(NSString* format,const char* _func,int line, ...);

@end
