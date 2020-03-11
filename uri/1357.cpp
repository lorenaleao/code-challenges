#include <bits/stdc++.cpp>

using namespace std;

int main(){
	map<int, vector<string>> number2braille;
	map<vector<string>, int> braille2number;

	number2braille.insert(pair<int, int>(1, 40)); 
    number2braille.insert(pair<int, int>(2, 30)); 
    number2braille.insert(pair<int, int>(3, 60)); 
    number2braille.insert(pair<int, int>(4, 20)); 
    number2braille.insert(pair<int, int>(5, 50)); 
    number2braille.insert(pair<int, int>(6, 50)); 
    number2braille.insert(pair<int, int>(7, 10));
 
	int digits_number;
	cin >> digits_number;

	while(digits_number != 0){
		char type;
		cin >> type;

		if(type == 'S'){

		} else {

		}

		cin >> digits_number;
	}
	return 0;
}