class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int sz = n/4;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>sz)
            {
                return arr[i];
            }
        }
        return -1;
    }
};