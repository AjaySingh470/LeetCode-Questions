class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
//      int n = nums.size(), j, k, res = nums[0] + nums[1] + nums[2], curr;
//         sort(nums.begin(), nums.end());
        
//         for (int i = 0; i < n; i++) {
//             j = i + 1, k = n - 1;
            
//             while (j < k) {
//                 curr = nums[i] + nums[j] + nums[k];
//                 if (abs(curr - target) < abs(res - target)) 
//                     res = curr;
                
//                 if (curr < target) j++;
//                 else k--;
                    
//             }
//         }
//         return res;
      int n = v.size();
      sort(v.begin() , v.end());
      int mndiff = INT_MAX;
      int ans = 0;
      for(int i=0;i<n;i++)
      {
        int j = i+1 , k = n-1;
        while(j<k)
        {
          int curr = v[i] + v[j] + v[k];
          if(abs(curr - target) < mndiff)
          {
            mndiff = abs(curr - target);
            ans = curr;
          }
          if(curr < target) j++;
          else k--;
        }
      }
      return ans;
    }
};