class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = 0;
        for(int i=0;i<sentence.size();i++)
        {
            string word = "";
            int j = 0;
            while(i < sentence.size() and sentence[i] != ' ')
            {
                word += sentence[i];
                i++;
            }
                ans++;
            int k = 0;
            while(k<word.size() and j<searchWord.size())
            {
                if(word[k] != searchWord[j])
                    break;
                k++;
                j++;
            }
            if(j == searchWord.size())
                return ans;
        }
        return -1;
    }
};