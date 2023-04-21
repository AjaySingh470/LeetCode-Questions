class LUPrefix {
public:
    vector<int> v;
    int mxval = 0;
    LUPrefix(int n) {
        v = vector<int>(n+2,0);
        // v[0] = 1;
    }
    
    void upload(int video) {
        v[video] = 1;
        while(v[mxval+1] == 1)
            mxval++;
    }
    
    int longest() {
        return mxval;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */