#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define DEBUG 0

const int MAX = 1010;

int s[MAX];
int memo[MAX][MAX];

int M(int i, int j) {
    if(i <= j){
        if(DEBUG){
            cout << "(  i,    j ) : " << '(' << i << ", " << j << ')' << endl;
            cout << "(s[i], s[j]) : " << '(' << s[i] << ", " << s[j] << ')' << endl;
        }
        if(memo[i][j] != -1)
            return memo[i][j];

        int even_i = 0, even_j = 0;
        if(s[i] % 2 == 0)
            even_i = 1;

        if(s[j] % 2 == 0)
            even_j = 1;
        
        if(DEBUG){
            cout << "(ev_i, ev_j) : " << '(' << even_i << ", " << even_j << ')' << endl;
        }
        if((j-i) % 2 != 0){
            if(DEBUG){
                cout << "1º jogador" << endl;
            }
            memo[i][j] = max(M(i+1, j) + even_i, M(i, j-1) + even_j);
            if(DEBUG){
                cout << "1º jogador - memo: " << memo[i][j] << endl;
            }
            return memo[i][j];
        } else {
            if(DEBUG){
                cout << "2º jogador" << endl;
            }
            memo[i][j] = min(M(i+1, j), M(i, j-1));
            if(DEBUG){
                cout << "2º jogador - memo: " << memo[i][j] << endl;
            }
            return memo[i][j];
        }
        
    }

    return 0;
}

int main() {
    
    int n; cin >> n;

    while(n != 0) {
        if(DEBUG){
            cout << "----------------------------------------" << endl;
        }
        for(int i = 0; i < 2*n; i++){
            int num; cin >> num;
            s[i] = num; 
        }
        
        for(int i = 0; i < 2*n; i++){
            for(int j = 0; j < 2*n; j++){
                memo[i][j] = -1;
            }
        }  

        int ans = M(0, (2*n) - 1);
        cout << ans << endl;
        cin >> n;
        
        if(DEBUG){
            cout << "----------------------------------------" << endl;
        }
    }

    return 0;
}