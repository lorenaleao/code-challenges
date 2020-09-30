#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

const int N = 1e7;
 

void initialize(vector<int>& parent, vector<int>& size) {
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i ;
        size[i] = 1;
    }
}

int root(vector<int>& parent, int i) {
    while(parent[i] != i) {
        parent[i] = parent[parent[i]] ; 
        i = parent[i]; 
    }
    return i;
}

void join(vector<int>& parent, vector<int>& size, int u, int v) {
    int root_u = root(parent, u);
    int root_v = root(parent, v);
    
    if(size[root_u] < size[root_v]) {
        parent[root_u] = parent[root_v];
        size[root_v] += size[root_u];
    } else {
        parent[root_v] = parent[root_u];
        size[root_u] += size[root_v];
    }
}

bool find(vector<int>& parent, int u, int v) {
    if( root(parent, u) == root(parent, v))
        return true;
    else
        return false;
}

using Edge = pair<int, pair<int, int>>;

int mst(vector<pair<int, pair<int, int>>>& edges, function<bool(Edge, Edge)> comparator) {
    int total_cost = 0;
    int count = 0;
    sort(edges.begin(), edges.end(), comparator);
    
    vector<int> parent(edges.size());
    vector<int> size(edges.size());
    initialize(parent, size);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(!find(parent, u, v) and count != edges.size() - 1) {
            total_cost += edges[i].first;
            join(parent, size, u, v);
            count++;
        }    
    }

    return total_cost;
}

vector<pair<int, pair<int, int>>> edges;

int main() {
    int n; cin >> n;
    int entrada, saida, custo; 
    
    while(cin >> entrada >> saida >> custo) {
        edges.push_back({custo, {entrada-1, saida-1}});       
    }
    
    int max_cost = mst(edges, greater<Edge>());
    int min_cost =  mst(edges, less<Edge>());
    cout << max_cost << endl;
    cout << min_cost << endl;

    edges.clear();	
    return 0;
}