class FrequencyTracker {
public:
    // vector<int> cnt;
    map<int,int> mp,cnt;
    FrequencyTracker() {
        // cnt = vector<int>(1e5+1,0);
        // freq = vector<int>(1e5+1,0);
    }
    
    void add(int number) {
        mp[cnt[number]]--;
            cnt[number]++;
        mp[cnt[number]]++;
        // return;
        
    }
    
    void deleteOne(int number) {
        if(cnt[number] == 0) return;
        mp[cnt[number]]--;
        cnt[number]--;
        mp[cnt[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        
        // return freq[frequency]>0;
        return mp[frequency];
        //
        
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */