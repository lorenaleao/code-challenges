#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define DEBUG 0

const int INF = 0x3f3f3f3f;

int dano[1010];
int mana[1010];
int memo[1010][2010];

int M(int i, int j) {
    if(j <= 0)
        return 0;
    if(i == -1)
        return INF;
    
    if(memo[i][j] != -1)
        return memo[i][j];

    memo[i][j] = min(M(i-1, j-dano[i]) + mana[i], M(i-1, j)); 
    return memo[i][j];
}

int main() {
    
    int n, p;

    while(cin >> n >> p) {
        for(int i = 0; i < n; i++){
            int d, m; 
            cin >> d >> m;
            dano[i] = d;
            mana[i] = m; 
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= p; j++){
                memo[i][j] = -1;
            }
        }  

        int ans = M(n-1, p);
        if(ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}