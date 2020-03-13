#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi; 

#define INFINITE 1e9

vector<int> dijkstra(std::vector<pi> adj[], int vertices, int src){
	vector<int> dist(vertices, INFINITE); 
	vector<bool> spt_set(vertices, false);
	int set_size;
	
	dist[src] = 0;
	spt_set[src] = true;
	set_size = 1;

	int v = src;

	while(set_size != vertices){
		//updating distances
		for(pair<int, int> p: adj[v]){
			int new_dist = dist[v] + p.first;
			if(new_dist < dist[p.second])
				dist[p.second] = new_dist;
		}
		//minimum distance
		int min = INFINITE;
		int min_index = -1;
		for(int i = 0; i < dist.size(); i++){
			if(!spt_set[i] and dist[i] < min){
				min = dist[i];
				min_index = i;
			}
		}

		v = min_index;
		spt_set[v] = true;
		set_size++;
	}

	return dist;

}

void add_edge(vector<pair<int, int>> adj[], int u, int v, int wt){
	adj[u].push_back(make_pair(wt, v));
	adj[v].push_back(make_pair(wt, u));
}

int main(){
	int islands, cables;
	cin >> islands >> cables;

	vector<pair<int, int>> adj[islands];

	for(int i = 0; i < cables; i++){
		int u, v, ping;
		cin >> u >> v >> ping;
		add_edge(adj, u-1, v-1, ping);
	}

	int server_island;
	cin >> server_island;

	vector<int> islands_pings = dijkstra(adj, islands, server_island-1);

	int min, max;
	min = INFINITE;
	max = -INFINITE;
	
	for (int i = 0; i < islands_pings.size(); ++i){
		if(i != server_island-1){
			if(islands_pings[i] < min)
				min = islands_pings[i];
			if(islands_pings[i] > max)
				max = islands_pings[i];
		}
	}

	cout << max-min << '\n';

	return 0;
}