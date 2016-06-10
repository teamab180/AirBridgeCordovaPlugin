/********* AirBridgePlugin.m Cordova Plugin Implementation *******/

#import <Cordova/CDV.h>
#import <AirBridge/AirBridge.h>

@interface AirBridgePlugin : CDVPlugin {
  // Member variables go here. 
}

- (void)initInstance:(CDVInvokedUrlCommand*)command;
- (void)goal:(CDVInvokedUrlCommand*)command;

@end

@implementation AirBridgePlugin

- (void)initInstance:(CDVInvokedUrlCommand*)command {
    [ABCommon showDebugConsole:YES];
    
    CDVPluginResult* pluginResult = nil;
    NSString *userToken = [command.arguments objectAtIndex:0];
    NSString *appToken = [command.arguments objectAtIndex:1];
        
    ABLog(@"UserToken: %@",userToken);
    ABLog(@"AppToken: %@",appToken);    
    AirBridge *instance = [AirBridge getInstance:userToken appToken:appToken];
    
    if ([ABCommon debugMode]) {
        [instance noticeSDKInstall:@"Cordova 0.0.3"];
    }
    
    [instance registSimpleLinkRoutingCallback:^(NSString *routing, NSDictionary *params, NSError *error) {
        NSMutableDictionary *routingDictionary = [NSMutableDictionary dictionaryWithDictionary:params];
        routingDictionary[@"routing"] = routing;
        
        NSError *__error=nil;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:routingDictionary
                                                           options:0
                                                             error:&__error];
        NSString *__json;
        if (! jsonData) {
            __json = @"[]";
        } else {
            __json = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        }
        
        [self.commandDelegate evalJs:[NSString stringWithFormat:@"airbridgeCustomOnboarding(%@)", __json]];
        
        ABLog(@"simple routings %@, params %@",routing,params);
    }];
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)goal:(CDVInvokedUrlCommand*)command {
    CDVPluginResult* pluginResult = nil;
    
    NSString *goalDescription = @"";
    NSString *category = @"";

    if ([command.arguments count] > 0) {
        goalDescription = [command.arguments objectAtIndex:0];
    }
    if ([command.arguments count] > 1) {
        category = [command.arguments objectAtIndex:1];
    }
    
    BOOL isGoalFinished = [[AirBridge instance]simpleGoalWithDescription:goalDescription category:category];
    if (isGoalFinished)
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    else 
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
        
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
