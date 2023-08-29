class Solution {
public:
    int bestClosingTime(string customers) {
        int y = 0 , n = 0;
        int mn = 0 , curr = 0;
        int hr = 0;
        for(int i=0;i<customers.size();i++)
        {
            char ch = customers[i];
            if(ch == 'Y')
            {
                curr--;
            }
            else curr++;
            if(curr < mn)
            {
                mn = curr;
                hr = i+1;
            }
        }
        return hr;
    }
};