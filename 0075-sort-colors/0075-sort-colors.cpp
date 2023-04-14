class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ,mid = 0,b = n-1;
        // 2 0 2 1 1 0
        while(mid <= b)
        {
          if(nums[mid] == 0)
          {
            // nums[l] = nums[mid];
            swap(nums[l] , nums[mid]);
            l++;
            mid++;
          }
          else if(nums[mid] == 1)
            mid++;
          else if(nums[mid] == 2){
            // if(mid > b){ mid++; continue;}
            swap(nums[b] , nums[mid]);
            b--;
          }
            
    
        }
      
        
    }
};