class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int cand) {
       priority_queue<int,vector<int> , greater<int>> left, right;
        int i=0,j=0;
        int n = cost.size();
        for(i=0;i<cand;i++)
        {
            left.push(cost[i]);
        }
        for(j=n-1;j>=max(i,n-cand);j--)
        {
            right.push(cost[j]);
        }
        // i--;
        // j++;
        long long int ans = 0;
        while(i<=j)
        {
            if(k==0) break;
            if(left.top() <= right.top())
            {
                ans += left.top();
                left.pop();
                left.push(cost[i]);
                i++;
            }
            else{
                ans += right.top();
                right.pop();
                right.push(cost[j]);
                j--;
            }
            k--;
        }
        ///
        // if(k == 0) return ans;
        while(!right.empty())
        {
            left.push(right.top());
            right.pop();
        }
        cout<<k<<"->";
        while(k-- && !left.empty())
        {
            ans += left.top();
            left.pop();
            
        }
        return ans;
        // return ans;    
    }
};