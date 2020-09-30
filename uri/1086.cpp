#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
	int n, m; cin >> n >> m;

	while(n and m){
		n *= 100; m *= 100;
		int width; cin >> width;
		int wooden_planks; cin >> wooden_planks;
		//vector<int> v(wooden_planks);
		
		multiset <int, greater <int> > s;
		int planks1, planks2, insertions;
		insertions = 0;
		bool possible = false;
		planks1 = planks2 = INF;

		for(int i = 0; i < wooden_planks; i++) {
			int length; cin >> length;
			s.insert(length*100);
		}

		auto s_copy = s;

		if((n % width != 0) and (m % width != 0))
			cout << "impossivel" << endl;
		else {	
			if(n % width == 0) {
				int v_planks = n/width;
				planks1 = 0;
				auto ptr = s.lower_bound(m);
			
				for(auto i = ptr; i != s.end(); i++){
					
					if(insertions == v_planks){
						possible = true;
						break;
					}
					if(*i != m) {
						
						auto i_pos = s_copy.find(*i);
						if(i_pos != s_copy.end())
							s_copy.erase(i_pos);
							
						auto comp = s_copy.find(m-*i);

						if(comp != s_copy.end()){
							planks1 += 2;
							s_copy.erase(comp);
							//s_copy.erase(*i);
							insertions++;
						}
					} else {
						insertions++;
						planks1++;
					}
						
				}

				if(insertions != v_planks) {
					planks1 = INF;
				} else {
					possible = true;
				}
			} 
			
			if(m % width == 0) {
				s_copy = s;
				insertions = 0;
				int h_planks = m/width;
				planks2 = 0;
				auto ptr = s.lower_bound(n);

				for(auto i = ptr; i != s.end(); i++){

					if(insertions == h_planks) {
						possible = true;
						break;
					}
					if(*i != n) {
						auto i_pos = s_copy.find(*i);
						if(i_pos != s_copy.end())
							s_copy.erase(i_pos);

						multiset <int, greater <int> > :: iterator comp = s_copy.find(n-(*i));
						if(comp != s_copy.end()){
							planks2 += 2;
							s_copy.erase(comp);
							//s_copy.erase(*i);
							insertions++;
						}
					} else {
						insertions++;
						planks2++;
					}	
				}

				if(insertions != h_planks) {
					planks2 = INF;
				}  else {
					possible = true;
				}
			}

			if(possible)
				cout << min(planks1, planks2) << endl;
			else 
				cout << "impossivel" << endl;
		}
		
		cin >> n >> m;
	}
	
	return 0;
}