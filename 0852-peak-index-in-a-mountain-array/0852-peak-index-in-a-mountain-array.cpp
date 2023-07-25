class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0 , r = arr.size()-1;
        int ans = 0;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(arr[mid] < arr[mid + 1])
            {
                l = mid + 1;
                ans = mid;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
};