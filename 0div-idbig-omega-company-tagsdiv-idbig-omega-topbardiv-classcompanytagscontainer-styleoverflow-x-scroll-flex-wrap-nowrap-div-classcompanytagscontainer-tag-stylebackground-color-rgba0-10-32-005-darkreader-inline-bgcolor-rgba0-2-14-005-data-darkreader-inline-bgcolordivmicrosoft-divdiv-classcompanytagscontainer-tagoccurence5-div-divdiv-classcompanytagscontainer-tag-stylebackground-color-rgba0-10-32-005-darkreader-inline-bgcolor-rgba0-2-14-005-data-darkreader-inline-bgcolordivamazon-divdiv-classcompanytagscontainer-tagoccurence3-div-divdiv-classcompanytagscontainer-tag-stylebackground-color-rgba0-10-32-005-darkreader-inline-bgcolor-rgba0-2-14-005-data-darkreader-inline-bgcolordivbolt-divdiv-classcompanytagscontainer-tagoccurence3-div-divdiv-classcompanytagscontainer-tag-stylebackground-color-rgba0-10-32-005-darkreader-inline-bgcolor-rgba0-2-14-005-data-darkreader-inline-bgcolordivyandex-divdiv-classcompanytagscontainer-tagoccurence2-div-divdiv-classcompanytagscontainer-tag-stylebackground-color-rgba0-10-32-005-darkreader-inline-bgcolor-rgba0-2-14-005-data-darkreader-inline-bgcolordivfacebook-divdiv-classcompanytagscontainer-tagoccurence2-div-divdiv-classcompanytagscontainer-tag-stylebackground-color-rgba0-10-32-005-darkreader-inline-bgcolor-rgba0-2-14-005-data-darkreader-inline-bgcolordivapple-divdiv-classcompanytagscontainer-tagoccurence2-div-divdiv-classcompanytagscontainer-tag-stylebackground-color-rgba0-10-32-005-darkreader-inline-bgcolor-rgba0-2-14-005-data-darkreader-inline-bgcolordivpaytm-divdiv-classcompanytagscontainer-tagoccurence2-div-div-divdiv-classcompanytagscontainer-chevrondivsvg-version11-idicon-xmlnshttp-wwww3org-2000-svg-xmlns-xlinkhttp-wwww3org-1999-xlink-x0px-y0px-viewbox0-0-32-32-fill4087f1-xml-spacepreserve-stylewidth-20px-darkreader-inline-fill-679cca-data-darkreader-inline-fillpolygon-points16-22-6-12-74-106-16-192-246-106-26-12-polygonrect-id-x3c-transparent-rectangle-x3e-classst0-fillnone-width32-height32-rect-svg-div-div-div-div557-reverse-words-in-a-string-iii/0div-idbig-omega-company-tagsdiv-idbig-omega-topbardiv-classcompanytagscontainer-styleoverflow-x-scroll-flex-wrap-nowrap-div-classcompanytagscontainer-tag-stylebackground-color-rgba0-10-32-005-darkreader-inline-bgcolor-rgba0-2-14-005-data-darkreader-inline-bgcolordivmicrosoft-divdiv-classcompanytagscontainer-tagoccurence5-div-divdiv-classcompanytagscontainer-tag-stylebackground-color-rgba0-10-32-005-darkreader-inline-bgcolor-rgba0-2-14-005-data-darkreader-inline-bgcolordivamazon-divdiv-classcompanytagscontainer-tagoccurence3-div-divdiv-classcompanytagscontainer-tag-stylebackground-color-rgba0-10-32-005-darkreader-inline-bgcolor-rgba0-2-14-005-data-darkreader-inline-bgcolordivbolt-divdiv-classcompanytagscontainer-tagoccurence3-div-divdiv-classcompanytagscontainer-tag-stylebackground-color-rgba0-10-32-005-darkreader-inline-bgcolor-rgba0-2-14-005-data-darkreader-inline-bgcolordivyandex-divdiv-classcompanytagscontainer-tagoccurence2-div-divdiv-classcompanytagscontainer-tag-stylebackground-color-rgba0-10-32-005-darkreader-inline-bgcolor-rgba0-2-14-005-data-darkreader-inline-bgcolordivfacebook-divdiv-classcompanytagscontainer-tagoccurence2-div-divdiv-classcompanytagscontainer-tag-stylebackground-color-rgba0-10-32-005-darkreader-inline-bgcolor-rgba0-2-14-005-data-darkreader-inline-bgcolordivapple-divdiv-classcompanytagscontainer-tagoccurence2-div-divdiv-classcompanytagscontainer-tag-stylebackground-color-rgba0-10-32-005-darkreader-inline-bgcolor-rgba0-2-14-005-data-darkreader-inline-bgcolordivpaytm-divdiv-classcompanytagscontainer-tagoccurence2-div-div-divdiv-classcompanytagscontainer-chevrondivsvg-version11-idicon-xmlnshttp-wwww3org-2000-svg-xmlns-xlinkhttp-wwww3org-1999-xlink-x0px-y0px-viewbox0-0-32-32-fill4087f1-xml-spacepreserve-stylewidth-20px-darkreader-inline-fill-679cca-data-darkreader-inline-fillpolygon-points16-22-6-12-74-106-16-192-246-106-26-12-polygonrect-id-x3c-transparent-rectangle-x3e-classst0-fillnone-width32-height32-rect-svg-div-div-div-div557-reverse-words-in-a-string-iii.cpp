class Solution {
public:
    string reverseWords(string s) {
        string t , word;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                reverse(word.begin() , word.end());
                t += word;
                t += " ";
                word = "";
            }
            else
            word += s[i];
        }
        reverse(word.begin() , word.end());
        t += word;
        return t;
    }
};