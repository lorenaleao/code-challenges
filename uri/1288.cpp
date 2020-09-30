// M[i][j] = 0, i = 0 (peguei 0 objetos) ou j = 0 (não cabe mais nada)
//         = max(M[i-1][j], M[i-1][j - p[i]] + v[i]) 

// vector<int> a(n);
// for (int& i: a) cin >> i;

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    int test_cases, chumbo_quant, cap, res;
    cin >> test_cases;
    for(int i = 0; i < test_cases; i++) {
        cin >> chumbo_quant;
        int weight, power;
        vector<int> wt(chumbo_quant+1), pw(chumbo_quant+1);
        for(int j = 1; j <= chumbo_quant; j++) {
            cin >> power >> weight;
            wt[j] = weight;
            pw[j] = power;
        }

        cin >> cap >> res;

        vector<vector<int>> M(chumbo_quant+1, vector<int>(cap+1));

        for(int j = 1; j <= chumbo_quant; j++){
            for(int k = 1; k <= cap; k++) {
                if(k >= wt[j])
                    M[j][k] = max(M[j-1][k], M[j-1][k - wt[j]] + pw[j]);
                else 
                    M[j][k] = M[j-1][k];
            }
        }

        if(M[chumbo_quant][cap] < res)
            cout << "Falha na missao" << endl;
        else
            cout << "Missao completada com sucesso" << endl;

    }
}