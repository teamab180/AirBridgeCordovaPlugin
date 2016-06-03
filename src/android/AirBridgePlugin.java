package io.airbridge.cordova;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import io.airbridge.routing.DeepLinkHandler;
import io.airbridge.AirBridge;
import android.os.Bundle;
import android.util.Log;
import android.content.Context;

import java.util.Set;

/**
 * This class echoes a string called from JavaScript.
 */
public class AirBridgePlugin extends CordovaPlugin {

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (action.equals("initInstance")) {
            this.initInstance(args.getString(0),args.getString(1), callbackContext);
            return true;
        }
        if (action.equals("goal")) {
            this.goal(args, callbackContext);
            return true;
        }
        return false;
    }

    private void initInstance(String userToken, String appToken, CallbackContext callbackContext) {
        try{
            AirBridge.init(webView.getContext(), 
                appToken, 
                userToken
            );
            
            final CallbackContext savedCallbackContext = callbackContext;
            AirBridge.addSimpleLinkHandler(new DeepLinkHandler() {
                @Override
                public void onLink(String url, Bundle _data, Context context) {
                    _data.putString("routing",url);
                    
                    JSONObject json = new JSONObject();
                    Set<String> keys = _data.keySet();
                    for (String key : keys) {
                        try {
                            // json.put(key, bundle.get(key)); see edit below
                            json.put(key, JSONObject.wrap(_data.get(key)));
                        } catch(JSONException e) {
                            //Handle exception here
                        }
                    }
                    PluginResult dataResult = new PluginResult(PluginResult.Status.OK, json);
                    dataResult.setKeepCallback(true);
                    savedCallbackContext.sendPluginResult(dataResult);
                }
            });
        } catch(Exception e) {
            callbackContext.error("SDK error occurs:");
            e.printStackTrace();
        }
    }
    
    private void goal(JSONArray args, CallbackContext callbackContext) throws JSONException {
        String goalDescription = "";
        String goalCategory = "";

        if (args.length() > 0) {
            goalDescription = args.getString(0);
        }
        if (args.length() >1) {
            goalCategory = args.getString(1);
        }
        
        AirBridge.goal(goalDescription,goalCategory);
        
        callbackContext.success();
    }
}
