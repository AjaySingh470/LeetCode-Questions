class Solution {
public:
    bool winnerOfGame(string colors) {
        int as = 0 , bs = 0;
        int n = colors.size();
        int at = 0 , bt = 0;
        for(int i=0;i<n;i++)
        {
            if(colors[i] == 'A')
            {
                at++;
            }
            else{
                as += max(at - 2 , 0);
                at = 0;
            }
            //
        }
                        as += max(at - 2 , 0);

        for(int i=0;i<n;i++)
        {
            if(colors[i] == 'B')
            {
                bt++;
            }
            else{
                bs += max(bt - 2 , 0);
                bt = 0;
            }
        }
                        bs += max(bt - 2 , 0);

        cout<<at<<" "<<bt<<endl;
        if(as <= bs)
            return false;
        return true;
    }
};