class TimeMap {
public:
    TimeMap() {
        
    }
    
    int search(int val,vector<pair<int,string>> &v)
    {
        int l = 0 , r = v.size()-1;
        int ans = 0;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(v[mid].first<=val)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
    
    map<string,vector<pair<int,string>>> time;
    
    void set(string key, string value, int timestamp) {
        // key -> value with timestamp;
        time[key].push_back({timestamp,value});
        // val[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
         // vector<pair<int,string>> tm = time[key];
        
        if(time.find(key) == time.end()) return "";
        if(timestamp < time[key][0].first)
            return "";
        //////////////////
        
        int l = 0 , r = time[key].size();
        int val = timestamp;
        int ns = 0;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(time[key][mid].first<=val)
            {
               
                l = mid + 1;
            }
            else
                r = mid;
        }
        /////////////////
        int it = r;
        if(it == 0 ) return "";
        
        string ans = time[key][it-1].second;
        return ans;
    }
};

/* 
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */