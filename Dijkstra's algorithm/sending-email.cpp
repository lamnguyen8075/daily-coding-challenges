#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 500000
const int INF = 1e9;

vector<vector<pair<int,int>>> graph(MAX);
vector<int> dist(MAX,INF);
int path[MAX];

void dijkstra(int s){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push(make_pair(0,s));
	
	dist[s] = 0; // putting the initial  đỉnh and distance
	while(!pq.empty()){
		pair<int,int> top = pq.top();
		pq.pop();
		int u = top.second;
		int d = top.first;
		
		for(int i = 0; i < graph[u].size(); i++){
			pair<int,int> neighbor = graph[u][i];
			if(d + neighbor.second < dist[neighbor.first]){
				dist[neighbor.first] = d + neighbor.second;
				pq.push(pair<int,int>(dist[neighbor.first],neighbor.first));
				path[neighbor.first] = u;
			}		
		}
	}
}



int main(){
  int q = 0; // num of test case
  int index = 1;
  cin >> q;
  while(q > 0){
    int n = 0; 
    int m = 0;
    int s = 0; 
    int t = 0; 
    // create a graph
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
      int u = 0; // server u
      int v = 0; // server v
      int w = 0; // length
      cin >> u;
      cin >> v;
      cin >> w;
      graph[u].push_back(make_pair(v,w));
      graph[v].push_back(make_pair(u,w));
    }
    
    dijkstra(s);
    
    if(dist[t] != INF){
      cout << "Case #" << index << ": " << dist[t] << endl;
    }
    else{
      cout << "Case #" << index << ": " << "unreachable" << endl;
    }
    
    
    q--;
    index++;
    
    // re-initialize vector
    dist = vector<int>(MAX, INF);
    //re-initialize graph
    for(int i = 0; i < MAX; i++){
      graph[i].clear();
    }  
  }
  
}
