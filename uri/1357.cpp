#include <bits/stdc++.h>

using namespace std;

int main(){
	map<int, vector<string>> number2braille;
	map<vector<string>, int> braille2number;

	vector<vector<string>> braille(10, vector<string>(3));
	braille[0] = {".*", "**", ".."};
	braille[1] = {"*.", "..", ".."};
	braille[2] = {"*.", "*.", ".."};
	braille[3] = {"**", "..", ".."};
	braille[4] = {"**", ".*", ".."};
	braille[5] = {"*.", ".*", ".."};
	braille[6] = {"**", "*.", ".."};
	braille[7] = {"**", "**", ".."};
	braille[8] = {"*.", "**", ".."};
	braille[9] = {".*", "*.", ".."};
	
	number2braille.insert(pair<int, vector<string>>(0, braille[0]));
	number2braille.insert(pair<int, vector<string>>(1, braille[1])); 
    number2braille.insert(pair<int, vector<string>>(2, braille[2])); 
    number2braille.insert(pair<int, vector<string>>(3, braille[3])); 
    number2braille.insert(pair<int, vector<string>>(4, braille[4])); 
    number2braille.insert(pair<int, vector<string>>(5, braille[5])); 
    number2braille.insert(pair<int, vector<string>>(6, braille[6])); 
    number2braille.insert(pair<int, vector<string>>(7, braille[7]));
    number2braille.insert(pair<int, vector<string>>(8, braille[8])); 
    number2braille.insert(pair<int, vector<string>>(9, braille[9])); 

    braille2number.insert(pair<vector<string>, int>(braille[0], 0));
	braille2number.insert(pair<vector<string>, int>(braille[1], 1)); 
    braille2number.insert(pair<vector<string>, int>(braille[2], 2)); 
    braille2number.insert(pair<vector<string>, int>(braille[3], 3)); 
    braille2number.insert(pair<vector<string>, int>(braille[4], 4)); 
    braille2number.insert(pair<vector<string>, int>(braille[5], 5)); 
    braille2number.insert(pair<vector<string>, int>(braille[6], 6)); 
    braille2number.insert(pair<vector<string>, int>(braille[7], 7));
    braille2number.insert(pair<vector<string>, int>(braille[8], 8)); 
    braille2number.insert(pair<vector<string>, int>(braille[9], 9)); 
 
	int digits_number;
	cin >> digits_number;

	while(digits_number != 0){
		char type;
		cin >> type;

		if(type == 'S'){
			string digits;
			cin >> digits;

			vector<vector<string>> digs_to_print;

			for(char c: digits){
				digs_to_print.push_back(number2braille[int(c - '0')]);
			}

			for(int j = 0; j < 3; j++){
				int i;
				for(i = 0; i < digs_to_print.size()-1; i++){
					cout << digs_to_print[i][j] << ' ';

				}
				cout << digs_to_print[i][j];
				cout << '\n';
			}

		} else {
			vector<vector<string>> digs(digits_number, vector<string>(3));

			for(int j = 0; j < 3; j++){
				for(int i = 0; i < digs.size(); i++){
					cin >> digs[i][j];
				}
			}

			for(vector<string> dig: digs){
				cout << braille2number[dig];
			}
			cout << '\n';

		}

		cin >> digits_number;
	}
	return 0;
}