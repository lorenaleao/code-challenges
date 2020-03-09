#include <bits/stdc++.h>

using namespace std;

int main(){

	int bills[] = {10000, 5000, 2000, 1000, 500, 200};
	int coins[] = {100, 50, 25, 10, 5, 1};

	double m;
	cin >> m;
	
	int m_int = m * 100;

	cout << "NOTAS:\n"; 
	for(int i = 0; i < 6; i++){
		cout << setprecision(0) << m_int/bills[i] << " nota(s) de R$ " << fixed << setprecision(2) << bills[i]/100.0 << '\n'; 
		m_int = m_int % bills[i];
	}

	cout << "MOEDAS:\n"; 
	for(int i = 0; i < 6; i++){
		cout << setprecision(0) << m_int/coins[i] << " moeda(s) de R$ " << fixed << setprecision(2) << coins[i]/100.0 << '\n'; 
		m_int = m_int % coins[i];
	}
	
	return 0;
}