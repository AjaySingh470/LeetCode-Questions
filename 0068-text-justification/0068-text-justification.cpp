class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> v;
        int n = words.size();
        for(int i=0;i<n;)
        {
            int p = i;
            int lineSize = 0;
            bool end = false;
            vector<string> temp;
            while(i<n && lineSize <= maxWidth)
            {
                // cout<<words[i]<<" ";
                if(lineSize + words[i].size() > maxWidth - temp.size())
                {
                    
                    break;
                }
                temp.push_back(words[i]);
                lineSize += words[i].size();
                i++;
            }
            if(i == n)
            {
                end = true;
               
            }
            // adbc aderf gerf
            int wordCount = temp.size();
            int mxw = maxWidth;
            int spaces = maxWidth - lineSize;
            int eachSp = spaces;
            int remSp = 0;
            if(wordCount > 1)
            {
                eachSp /= wordCount-1;
                remSp = spaces%(wordCount-1);
            }
            if(end)
            {
                eachSp = 1;
                remSp = 0;
            }
            string addr = "";
            // cout<<eachSp<<" "<<remSp<<endl;
            for(int i=0;i<temp.size()-1;i++)
            {
                // cout<<temp[i];
                string sps = string(eachSp,' ');
                if(remSp > 0)
                {
                    sps += ' ';
                    remSp--;
                }

                addr += temp[i];
                addr += sps;
            }
           
                addr += temp[wordCount-1];
               
                    int sz = addr.size();
                    spaces = maxWidth - sz;
                    string ty(spaces,' ');
                    addr += ty;
                
            
            v.push_back(addr);
        }
        return v;
    }
};