#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main() {

    ll n; cin >> n;

    //find dividers 
    set<ll> dividers;
    ll sqrt_n = floor(sqrt(n));
    
    dividers.insert(n);
    for(ll i = 2; i <= sqrt_n; i++){
        if(n % i == 0) {
            dividers.insert(i);
            dividers.insert(n/i);
        }
            
    }
/*
    for(ll i = 0; i < dividers.size(); i++){
        cout << dividers[i] << ' ';
    }
    cout << endl;*/

    vector<ll> despojados;
    bool is_despojado;
    bool prime;

    for(auto d : dividers) {
        ll sqrt_d = floor(sqrt(d));
        //cout << "divider: " << d << endl;
        //cout << "sqrt: " << sqrt_d << endl;
        ll result = d;
        prime = true;
        for(ll i = 2; i <= sqrt_d; i++){ 
            if(result % i == 0) {
                prime = false;
                is_despojado = true;
                //cout << "i " << i << endl;
                //cout << "result " << result << endl;
                result = result/i;
                //cout << "after " << result << endl;
                if(result % i == 0){
                    is_despojado = false;
                    break;
                } 
            }       
        }

        if(is_despojado and !prime)
            despojados.push_back(d);
    }

    /*cout << "despojados: ";
    for(ll i = 0; i < despojados.size(); i++){
        cout << despojados[i] << ' ';
    }
    cout << endl;*/

    cout << despojados.size() << endl;
    return 0;
}