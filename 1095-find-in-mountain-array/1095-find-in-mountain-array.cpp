/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int i=1,j=n-1;
        int peak = -1;
        while(i<=j)
        {
            int mid = (i+j)>>1;
            int curr = mountainArr.get(mid);
            int prev = mountainArr.get(mid - 1);            
            int next = mountainArr.get(mid + 1);
            ////
            if(prev < curr && curr > next)
            {
                peak = mid;
                break;
            }
            else if(prev < curr && curr < next)
            {
                i = mid + 1;
            }
            else{
                j = mid - 1;
            }
        }
        
        int pos = -1;
        int l = 0 , r = peak;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(mountainArr.get(mid) == target)
            {
                pos = mid;
                break;
            }
            else if(mountainArr.get(mid) < target) {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(pos != -1)
        {
            return pos;
        }
        l = peak + 1 ; r = n-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(mountainArr.get(mid) == target)
            {
                pos = mid;
                break;
            }
            else if(mountainArr.get(mid) > target) {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return pos;
    }
};