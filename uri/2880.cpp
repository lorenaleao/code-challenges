#include <iostream>
#include <string> 

using namespace std;

int main() {
    string message, crib;
    cin >> message >> crib;
    int count, pos;
    pos = 0;

    for(int i = 0; i < message.size()-crib.size()+1; i++){
        int j = i;
        count = 0;
        for(char l2 : crib) {
            //cout << j << " count: " << count << '\n';
            //cout << message[j] << ' ' << l2 << '\n';
            if(message[j] == l2)
                break;
            j++;
            count++;

        }
        //cout << pos << '\n';
        if(count == crib.size())
            pos++;
    }

    cout << pos << '\n';
    return 0;
}