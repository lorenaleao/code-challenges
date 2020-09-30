#include <bits/stdc++.h>

using namespace std;

#define dbg 0
#define endl '\n'
#define ll long long
#define print(x) cout << " = " << x << endl;

const ll MAX = 1e10;
const int N = 1e5;

vector<int> popcorn_packages(N);

bool check(ll possible_ans, int t, int n, int c) {
    ll sum = 0;
    ll max_popcorn = t*possible_ans;
    
    for(int i = 0; i < n; i++) {
        if(c == 0)
            break;
        if(dbg) { cout << "i"; print(i); }
        if(dbg) { cout << "c"; print(c); }
        
        if(dbg) {
            cout << "sum + popcorn_packages[i]"; 
            print(sum + popcorn_packages[i]);
        }
        
        if(sum + popcorn_packages[i] <= max_popcorn){
            if(dbg) cout << "if" << endl;
            sum += popcorn_packages[i];
        } else {
            c--;
            sum = 0;
            if(sum + popcorn_packages[i] <= max_popcorn){
                sum += popcorn_packages[i];
            } else 
                return false;
        }
    }
    if(c > 0) 
        return true;
    return false;
}

int main() {
    int n, c, t; cin >> n >> c >> t;
    
    for(int i = 0; i < n; i++) {
        int popcorn_count; cin >> popcorn_count;
        popcorn_packages[i] = popcorn_count;
    }

    //binary search on the number of seconds the group needs to eat all the popcorn
    ll left = 0;
    ll right = MAX;
    
    // cout << check(1, t, n, c) << endl;
    // cout << check(2, t, n, c) << endl;
    // cout << check(3, t, n, c) << endl;
    // cout << check(4, t, n, c) << endl;
    // cout << check(5, t, n, c) << endl;
    // cout << check(6, t, n, c) << endl;
    // cout << check(7, t, n, c) << endl;
    // cout << check(100, t, n, c) << endl;
    
    while(right > left) {
        ll middle = (right+left)/2;
        
        if(check(middle, t, n, c)) {
            right = middle;
        } else {
            left = middle + 1;
        }   
    }

    cout << left << endl;

    return 0;
}
