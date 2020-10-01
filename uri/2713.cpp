#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

const int MAX = 1010;

double m[MAX];
double dm[MAX];
double memo[MAX][110];

double M(int i, int j, double v) {
    if(i == 0)
        return 0;

    if(memo[i][j] != -1)
        return memo[i][j];

    if(j > 0){
        memo[i][j] =  min(M(i-1, j, v) + m[i]/v, M(i-1, j-1, v) + m[i]/(v + dm[i]));
        return memo[i][j];
    }

    memo[i][j] = M(i-1, j, v) + m[i]/v;
    return memo[i][j];
}

int main() {
    int n, k; 
    double v; 

    while(cin >> n >> k >> v) {
        for(int i = 1; i <= n; i++){
            double x, d; 
            cin >> x >> d;
            m[i] = x;
            dm[i] = d; 
        }
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                memo[i][j] = -1;
            }
        }  

        double ans = M(n, k, v);
        cout << fixed << setprecision(4) << ans << endl;
    }

    return 0;
}