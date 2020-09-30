#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, D, count;
    
    cin >> N >> D;
    vector<int> notes(N);
    
    for(int i = 0; i < N; i++) {
        cin >> notes[i];
    }

    count = 0;
    for(int i = 0; i < N-1; i++) {
        if(abs(notes[i]-notes[i+1]) > D)
            count++;
    }

    cout << count;
    return 0;
}   