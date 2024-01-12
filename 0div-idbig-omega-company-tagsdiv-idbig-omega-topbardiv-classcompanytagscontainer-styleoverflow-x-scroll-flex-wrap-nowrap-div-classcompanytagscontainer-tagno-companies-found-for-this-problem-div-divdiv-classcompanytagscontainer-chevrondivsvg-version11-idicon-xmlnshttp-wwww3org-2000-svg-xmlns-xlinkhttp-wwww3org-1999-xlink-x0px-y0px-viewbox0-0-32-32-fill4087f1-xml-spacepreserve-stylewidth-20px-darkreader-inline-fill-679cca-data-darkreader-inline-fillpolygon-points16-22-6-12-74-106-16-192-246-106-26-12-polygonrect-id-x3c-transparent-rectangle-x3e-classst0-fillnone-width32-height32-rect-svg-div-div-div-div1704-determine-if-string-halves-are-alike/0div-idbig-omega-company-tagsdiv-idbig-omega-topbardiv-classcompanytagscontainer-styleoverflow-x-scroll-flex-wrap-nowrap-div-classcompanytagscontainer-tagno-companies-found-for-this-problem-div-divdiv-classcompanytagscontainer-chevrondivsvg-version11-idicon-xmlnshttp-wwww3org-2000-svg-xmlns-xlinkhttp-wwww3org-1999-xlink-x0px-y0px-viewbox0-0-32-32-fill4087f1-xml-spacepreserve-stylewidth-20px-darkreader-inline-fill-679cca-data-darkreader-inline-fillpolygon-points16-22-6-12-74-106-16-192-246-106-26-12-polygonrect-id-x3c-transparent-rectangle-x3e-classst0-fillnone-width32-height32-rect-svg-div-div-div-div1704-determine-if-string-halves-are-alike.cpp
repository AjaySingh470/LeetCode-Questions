class Solution {
public:
    bool check(char ch)
    {
        ch = tolower(ch);
        return ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    bool halvesAreAlike(string s) {
       set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();
        string a = s.substr(0,n/2) , b = s.substr(n/2);
        cout<<a<<" "<<b<<endl;
        int at=0,bt=0;
        for(int i=0;i<n/2;i++)
        {
            if(check(a[i]))
                at++;
            if(check(b[i]))
                bt++;
        }
        return at == bt;
        
    }
};