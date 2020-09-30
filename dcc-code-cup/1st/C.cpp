#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; 
    cin >> N;
    unordered_set <string> names;
    vector<string> new_names; 
    
    for(int i  = 0; i < N; i++) {
        string ilson_name;
        cin >> ilson_name;
        names.insert(ilson_name);
    }

    cin >> M;

    int count = 0;

    for(int i  = 0; i < M; i++) {
        string name;
        cin >> name;

        if(name.size() >= 5) {
            if(names.find(name) == names.end() && name.substr(name.size()-5, 5) == "ilson") {
                count++;
                new_names.push_back(name);
            }
        }
    }    

    cout << count << '\n';
    for(string s : new_names) {
       cout << s << '\n';
    }
    
    return 0;
}
