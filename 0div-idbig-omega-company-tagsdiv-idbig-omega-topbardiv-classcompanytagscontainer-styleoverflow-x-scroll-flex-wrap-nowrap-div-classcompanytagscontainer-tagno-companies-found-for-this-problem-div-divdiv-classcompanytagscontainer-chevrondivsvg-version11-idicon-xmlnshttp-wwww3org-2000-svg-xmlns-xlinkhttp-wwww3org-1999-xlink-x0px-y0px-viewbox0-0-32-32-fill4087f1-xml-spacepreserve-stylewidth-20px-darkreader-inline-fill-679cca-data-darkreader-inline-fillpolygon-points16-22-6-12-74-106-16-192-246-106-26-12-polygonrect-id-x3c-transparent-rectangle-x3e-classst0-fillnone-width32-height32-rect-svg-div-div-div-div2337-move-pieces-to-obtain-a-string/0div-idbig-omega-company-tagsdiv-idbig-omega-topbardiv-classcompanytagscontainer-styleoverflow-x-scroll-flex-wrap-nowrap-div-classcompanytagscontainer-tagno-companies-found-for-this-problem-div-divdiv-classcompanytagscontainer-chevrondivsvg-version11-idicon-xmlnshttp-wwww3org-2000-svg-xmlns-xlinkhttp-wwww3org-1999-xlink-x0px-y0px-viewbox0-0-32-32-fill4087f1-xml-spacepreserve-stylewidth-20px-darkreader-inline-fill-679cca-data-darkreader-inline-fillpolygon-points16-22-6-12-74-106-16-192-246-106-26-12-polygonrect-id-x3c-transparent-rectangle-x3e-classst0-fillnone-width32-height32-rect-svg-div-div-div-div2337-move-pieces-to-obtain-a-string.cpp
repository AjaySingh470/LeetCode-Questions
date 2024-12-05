class Solution {
public:
    bool canChange(string start, string target) {
        
        int i=0,j=0;
        int n = start.size();
        while(i<n and j<n)
        {
            while(i<n and start[i] == '_')
                i++;
            while(j<n and target[j] == '_')
                j++;
            if(start[i] != target[j]) return false;
            if(start[i] == target[j])
            {
                if(start[i] == 'L')
                {
                    if(i<j) return false;
                }
                else{
                    if(i>j) return false;
                }
            }
            i++;
            j++;
        }
        
        while(i<n)
        {
            if(start[i] != '_') return false;
            i++;
        }
        while(j<n)
        {
            if(target[j] != '_') return false;
            j++;
        }   
        
        return true;
    }
};