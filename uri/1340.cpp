#include <bits/stdc++.h>

using namespace std ;

int main(){
	int n;
	
	while(cin >> n){
		
		vector<int> v;
		
		int op, number, max;
		bool queue, stack, pqueue;
		
		max = -1;
		queue = false; stack = false; pqueue = false;
		
		for(int i = 0; i < n; i++){
			
			cin >> op >> number;
			
			switch(op){
				case 1:
					if(number > max)
						max = number;
					v.push_back(number);
					break;
				
				case 2:
					if(v[0] == number)
						queue = true;
					if(v[v.size()-1] == number)
						stack = true;
					if(number == max)
					//problema: n vou saber o segundo maior dese jeito, 
						//saber o max a cada intervalo? 
						//fazer vetor de booleanos e setar quando for adicionado?



			}
			

		}
	}

	return 0;
}