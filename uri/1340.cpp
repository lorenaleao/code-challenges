#include <bits/stdc++.h>

using namespace std ;

int main(){
	int n;
	
	while(cin >> n){
		
		list<int> l;
		
		int op, number, max, queue_counter, stack_counter, pqueue_counter, removals;
		bool impossible = true;
		priority_queue<int> pqueue;
		
		max = -1;
		queue_counter = 0; stack_counter = 0; pqueue_counter = 0;
		removals = 0;
		
		for(int i = 0; i < n; i++){
			
			cin >> op >> number;

			impossible = true;
			
			switch(op){
				case 1:
					l.push_back(number);
					pqueue.push(number);
					break;
				
				case 2:
					removals++;
					cout << number <<endl;
					cout << pqueue.top() <<endl;
					cout << l.front() <<endl;
					cout << l.back() <<endl;
					if(pqueue.top() == number){
						pqueue_counter++;
						pqueue.pop();
						impossible = false;
					}
					if(l.front() == number){
						queue_counter++;
						l.pop_front();
						impossible = false;
					}
					if(l.back() == number){ //problema aqui nessa lista compartilhada pra fazer pop no if de cima e nesse
						stack_counter++;
						l.pop_back();
						impossible = false;
					}
			}
			
			if(impossible and op == 2){
				cout << "impossible\n";
				break;
			}
		}
		cout << removals << endl;
		cout << pqueue_counter << endl;
		cout << queue_counter << endl;
		cout << stack_counter << endl;
		if(pqueue_counter == removals){
			if((queue_counter == removals) != (stack_counter == removals))
				cout << "not sure\n";
			else if(queue_counter != removals and stack_counter != removals)
				cout << "priority queue\n";
			else
				cout << "impossible\n";
		} else if(queue_counter == removals)
			cout << "queue\n";
		else
			cout << "stack\n";

	}

	return 0;
}