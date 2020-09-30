#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define DEBUG 0

typedef long long ll;
const ll MAX = 110;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> s(MAX);
ll memo[MAX][MAX][MAX];
//vector<vector<vector<ll>>> memo(MAX, vector<vector<ll>>(MAX, vector<ll>(MAX)));

ll M(ll n, ll k, ll j, ll last) {
    if(DEBUG)
        cout << "(n, k, j, last) : " << '(' << n << ", " << k << ", " << j << ", " << last << ')' << endl;
    
    if(k > n+1-j)
        return 0;
    if(DEBUG) 
        cout << "1" << endl;
    if(k == 0)
        return 1;
    if(DEBUG) 
        cout << "2" << endl;
    if(j > n)
        return 0;
    
    if(DEBUG) 
        cout << "3" << endl;
    
    if(memo[k][j][last] != -1)
        return memo[k][j][last];

    if(DEBUG) 
        cout << "ainda não calculei!" << endl;
    
    if(s[last] > s[j]) {
        if(DEBUG) 
            cout << "numero atual <= ao ult da seq!" << endl;
        memo[k][j][last] = M(n, k, j+1, last);
        return memo[k][j][last];
    }
    
    memo[k][j][last] = M(n, k-1, j+1, j) + M(n, k, j+1, last);
    if(DEBUG) 
        cout << "memo[k][j][last] = " << memo[k][j][last] << endl;
    return memo[k][j][last];
}

int main() {
    ll n, k;
    cin >> n >> k;
    while(n != 0){
        s[0] = -LINF;
        for(ll i = 1; i <= n; i++){
            ll num; cin >> num;
            s[i] = num;
        }

        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= n; j++) {
                for(int m = 0; m <= n; m++) {
                     memo[i][j][m] = -1;
                }
            }
        }
        
        ll last = 0;
        ll ans = M(n, k, 1, last);
        cout << ans << endl;
        cin >> n >> k;
    }

    return 0;
}