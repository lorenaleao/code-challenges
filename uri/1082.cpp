#include <bits/stdc++.h>

using namespace std;

void add_edge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs_util(int u, vector<int> adj[], vector<bool> &visited, set<char> &elems){
	visited[u] = true;
	elems.insert('a' + u); //log(n)

	for(int i = 0; i < adj[u].size(); i++){
		if(!visited[adj[u][i]])
			dfs_util(adj[u][i], adj, visited, elems);
	}
}

vector<set<char>> dfs(vector<int> adj[], int v){
	vector<bool> visited(v, false);
	vector<set<char>> connected_comp;
	
	for(int i = 0; i < v; i++){
		if(!visited[i]){
			set<char> elems;
			dfs_util(i, adj, visited, elems);
			connected_comp.push_back(elems);
		}
	}

	return connected_comp;
}

int main(){
	int n; cin >> n;

	for(int i = 0; i < n; i++){
		
		int v, e;
		cin >> v >> e;
		
		vector<int> adj[v];

		for(int j = 0; j < e; j++){
			char u, v;
			cin >> u >> v;
			add_edge(adj, int(u)-97, int(v)-97);
		}

		vector<set<char>> connected_comp = dfs(adj, v);

		cout << "Case #" << i+1 << ":\n";
		for(int j = 0; j < connected_comp.size(); j++){
			for(auto elem: connected_comp[j])
				cout << elem << ',';
			cout << '\n';
		}

		cout << connected_comp.size() << " connected components\n\n";
	}

	return 0;
}
