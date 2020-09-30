#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    int t, n, k;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> k;
        if(n < k){
            if(n <= k/2){
                cout << n << endl;
            } else 
                cout << k/2 << endl;
        } else if(n == k){
            cout << n << endl;
        } else {
            if(n % k <= k/2){
                cout << n << endl;
            } else 
                cout << (n/k)*k + k/2 << endl;
        }
    }
    return 0;
}