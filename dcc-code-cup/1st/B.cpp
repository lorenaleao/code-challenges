#include <iostream>
#include <vector>

using namespace std;

#define MAX 10e9

int main(){
    long int n;
    cin >> n;

    if(n % 2 == 0) {
        cout << "Sim\n";
        vector<long int> odd;
        vector<long int> even;
        odd.push_back(1);
        
        for(long int i = 1; i < n; i++) {
            odd.push_back(odd[i-1]+4);
        }
        
        for(long int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                even.push_back(odd[i]+1);
            } else {
                even.push_back(odd[i]-1);
            }    
        }

        for(long int i = 0; i < n; i++) {
            cout << even[i] << ' ';
        }

        cout << '\n';

        for(long int i = 0; i < n; i++) {
            cout << odd[i] << ' ';
        }

    } else 
        cout << "Nao\n";
}