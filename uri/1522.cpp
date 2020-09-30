#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define DEBUG 0

const int MAX = 110;

int s[3][MAX];
int memo[MAX][MAX][MAX];

int calls = 0;
int nao_lembrei = 0;

bool M(int n, int a, int b, int c) {
    if(DEBUG){
        cout << "(a, b, c, n) : " << '(' << a << ", " << b << ", " << c << ", " << n << ')' << endl;
    }

    if(a == n and b == n and c == n)
        return true;

    if(memo[a][b][c] != -1)
        return memo[a][b][c];
    
    if(DEBUG){
        cout << "não lembrei" << endl;
    }
    vector<bool> ans(8);
    int top[] = {s[2][c], s[1][b], s[0][a]};
    int idx[] = {c, b, a};
    bool invalid = false;

    for(int i = 1; i <= 7; i++){
        invalid = false;
        if(DEBUG)
            cout << "i: " << i << endl;
        
        int sum = 0;
        vector<int> bits(3);
        for(int j = 0; j < 3; j++){
            bool bit = (i >> j) & 1;
            if(bit && idx[j] > n-1){
                invalid = true;
                break;
            }
            if(DEBUG)
                cout << "bit: " << bit << endl;
            
            bits[j] = bit;
            if(bit){
                sum += top[j];
                if(DEBUG)
                    cout << "sum: " << sum << endl;
         
            }
        }

        if(DEBUG)
            cout << "--final sum: " << sum << endl << endl;
        
        if(invalid)
            continue;

         if(DEBUG)
            cout << "not invalid -- " << invalid << endl << endl;

        if(sum % 3 == 0){
            ans[i] = M(n, a + bits[2], b + bits[1], c + bits[0]);
        } else
            ans[i] = false;
        
    }  
    
    memo[a][b][c] = ans[1] or ans[2] or ans[3] or ans[4] or ans[5] or ans[6] or ans[7]; 
    return memo[a][b][c];
}

int main() {
    int n;
    cin >> n;
    while(n != 0){
        calls = 0;
        nao_lembrei = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++) {
                int v; cin >> v;
                s[j][i] = v;   
            }
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= n; k++) {
                    memo[i][j][k] = -1;
                }
            }
        }
        
        bool ans = M(n, 0, 0, 0);
        cout << ans << endl;

        cin >> n;
    }

    return 0;
}