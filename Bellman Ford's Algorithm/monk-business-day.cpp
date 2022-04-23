#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

#define MAX 1500

const int INF = 1e9;
vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);
int n, m;
struct Edge{
	int source;
	int target;
  int weight;
	Edge(int source = 0, int target = 0, int weight = 0){
		this -> source = source;
		this -> target = target;
		this -> weight = weight;
	}
};
vector<Edge> graph;

bool BellmanFord(int s){
	int u, v;
  int w;
	dist[s] = 0; 
	for(int i = 1; i <= n -1; i++){
		for( int j = 0; j < m; j++){
			u = graph[j].source;
			v = graph[j].target;
			w = graph[j].weight;
			if( dist[u] != INF && (dist[u] + w < dist[v])){
				dist[v] = dist[u] + w;
				path[v] = u;
			}
		}
	}

	for(int i = 0; i < m; i++){
		u = graph[i].source;
		v = graph[i].target;
		w = graph[i].weight;
		if( dist[u] != INF && (dist[u] + w < dist[v])){
			return false;
		}		
	}
	return true;
}

int main (){
	int testcase = 0;
  cin >> testcase;
	while(testcase > 0){

		int k = 0; 
		int j = 0; 
		int c = 0; 
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> k >> j >> c;
			c *= (-1);
			graph.push_back(Edge(k,j,c));
		}

		bool res = BellmanFord(1);
		if(res == false){
			cout << "Yes" << endl;
		}    
		else{
			cout << "No" << endl;
		}

    vector<int> distReset(MAX, INF);
    vector<int> pathReset(MAX, -1);
    vector<Edge> graphReset;
    dist = distReset;
    path = pathReset;
    graph = graphReset;
    testcase--;
    n = 0; 
    m = 0; 
  }
}
