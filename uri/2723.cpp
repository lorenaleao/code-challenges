#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
const int MAX = (1e5)+10;
const int MAX_N = (1e4)+10;
vector<int> p(MAX);

//map<tuple<int, int, int>, int> memo; 
vector<vector<int>> memo(MAX_N, vector<int>(6));

int M(int n, int i, int a, int b) {
    if(i == n+1)
        return 1;
    
    int diff = abs(a-b);
    //cout << "(i, a, b, diff) : " << '(' << i << ", " << a << ", " << b << ", " << diff << ')' << endl;
    if(diff > 5)
        return 0;
    
    if(memo[i][diff] != -1)
        return memo[i][diff];

    //cout << "ainda não calculei!" << endl;
    memo[i][diff] =  M(n, i+1, a+p[i], b) or M(n, i+1, a, b+p[i]);

    return memo[i][diff];
    //memo.insert(make_pair(make_tuple(i, a, b), M(n, i+1, a+p[i], b) or M(n, i+1, a, b+p[i])));
    //return memo[make_tuple(i, a, b)];
}

int main() {
    int t, n, pi;
    cin >> t;

    for(int j = 0; j < t; j++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> pi;
            p[i] = pi;
        }
        
        for(int k = 0; k <= n; k++) {
            for(int l = 0; l < 6; l++) {
                    memo[k][l] = -1;
                }
        }

        int ans = M(n, 1, p[0], 0);
        if(ans)
            cout << "Feliz Natal!" << endl;
        else
            cout << "Ho Ho Ho!" << endl;   
    }
    
    return 0;
}