class Logger {
public:
    unordered_map<string, int> msgTS;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(msgTS.find(message) == msgTS.end()){
            msgTS[message] = timestamp;
            return true;
        } else if(timestamp >= msgTS[message] + 10){
            msgTS[message] = timestamp;
            return true;
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */