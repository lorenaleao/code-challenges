#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define MAX 10e9+10

int main(){

    int n; cin >> n;

    ll sum = 0;
    int count = 0;
    bool prime;

    while(n != 1){
        sum += n;
        ll sqrt_n = floor(sqrt(n));
        // cout << n << ' ' << sqrt_n << endl;
        prime = true;
        for(ll i = 2; i <= sqrt_n; i++){
            if(n % i == 0) {
                prime = false;
                n /= i;
                break;
            }
        }

        if(prime)
            break;
    }
   
    cout << sum+1 << endl;
    return 0;
}