class TimeMap {
public:
    const int NUL = INT_MIN;
    const int MAXN = 2*1e5;
    struct TS {
        int timestamp;
        string value;
    };

    unordered_map<string, vector<TS>> um;

    TS getTSByTimestamp(vector<TS>& ts, int t) {
        TS res = {NUL, ""};
        int n = ts.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            TS curr = ts[m];
            int currTimeStamp = curr.timestamp;
            if (currTimeStamp == t) {
                res = curr;
                break;
            } else {
                if (currTimeStamp < t) {
                    if (res.timestamp <= currTimeStamp) {
                        res = curr;
                    }

                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return res;
    }

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<TS>& ts = um[key];
        TS res = getTSByTimestamp(ts, timestamp);
        return res.value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */