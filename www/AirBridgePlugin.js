var AirBridgePlugin = function () {
    
};

AirBridgePlugin.prototype.initInstance = function (userToken, appToken) {
    cordova.exec(win,null, "AirBridgePlugin","initInstance",[userToken,appToken]);
    function win(message) {
        //... process message from java here ...
        airbridgeCustomOnboarding(message);
    }
};

AirBridgePlugin.prototype.goal = function(arg0, success, error) {
    cordova.exec(success, error, "AirBridgePlugin", "goal", [arg0]);
};

module.exports = new AirBridgePlugin();