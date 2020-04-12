class Solution {
public:
    int findNextValidPos(string s){
        int n = s.size();
        int bkspce = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '#')
                bkspce++;
            else {
                i -= bkspce;
                bkspce = 0;
                if(i < 0)
                    return -1;
                else if(s[i] != '#')
                    return i;
                i++;
            }
        }
        return -1;
    }
    bool backspaceCompare(string S, string T) {
        
        // my solution so far
        // it doesn't pass in this case:
        
        // S = "bxj##tw"
        // T = "bxo#j##tw"
        
        int s = S.size();
        int t = T.size();
        while(s >= 0 and t >= 0){ 
            S = S.substr(0, s);
            T = T.substr(0, t);
            cout << S << " " << T << endl;
            s = findNextValidPos(S);
            t = findNextValidPos(T);
            cout << s << " " << t << endl;
            if(s >= 0 and t >= 0){
                if(S[s] != T[t])
                    return false;
            }
        }
        
        if(s < 0 and t < 0)
            return true;
        else
            return false;
    }
};