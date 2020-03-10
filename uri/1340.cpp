#include <bits/stdc++.h>

using namespace std;

template <typename T>
void clear(T &x){
	while(x.size()) x.pop();
}

int main(){
	int n; 

	priority_queue<int> pq;
	queue<int> q;
	stack<int> s;

	while(cin >> n){

		bool stack, queue, pqueue, impossible;

		stack = true;
		queue = true;
		pqueue = true;
		impossible = false;

		for(int i = 0; i < n; i++){
			int op, number;
			cin >> op >> number;

			switch(op){
				case 1:
					q.push(number);
					s.push(number);
					pq.push(number);
					break;
				case 2:
					if(stack){
						if(s.size() and s.top() == number){
							s.pop();
						} else
							stack = false;
					}

					if(queue){
						if(q.size() and q.front() == number){
							q.pop();
						} else
							queue = false;
					}

					if(pqueue){
						if(pq.size() and pq.top() == number){
							pq.pop();
						} else
							pqueue = false;
					}
			}
		}

		if(!stack and !queue and !pqueue){
			impossible = true;
		}

		if(impossible)
			cout << "impossible\n";
		else if((stack and pqueue) or (queue and pqueue))
			cout << "not sure\n";
		else if(stack)
			cout << "stack\n";
		else if(queue)
			cout << "queue\n";
		else if(pqueue)
			cout << "priority queue\n";

		clear(q);
		clear(pq);
		clear(s);
	}

	return 0;
}