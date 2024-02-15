// import java.util.Arrays;

class Solution {
    public long largestPerimeter(int[] nums) {
        long sm = 0;
        for(int i=0;i<nums.length;i++)
        {
            sm += nums[i];
        }
        Arrays.sort(nums);
        for(int i=nums.length-1;i>=0;i--)
        {
            sm -= nums[i];
            if(sm > nums[i])
            {
                sm += nums[i];
                break;
            }
        }
        if(sm == 0) return -1;
        return sm;
    }
}