#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 500
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
  int t = 0; // num of test case
  int index = 1;
  cin >> t;
  while(t > 0){
    int n = 0; // num of building in the HQ 
    int r = 0; // num of roads connect to building
    int s = 0; // start
    int d = 0; // destination
    cin >> n; // số đỉnh
    cin >> r; // số cạnh
    vector<int> distS; 
    vector<int> distD;
    // create a graph
    for(int i = 0; i < r; i++){
      int u = 0; // building u
      int v = 0; // building v
      cin >> u;
      cin >> v;
      graph[u].push_back(make_pair(v,1));
      graph[v].push_back(make_pair(u,1));
    }
    
    cin >> s >> d;
    dijkstra(s);
    distS = dist;

    // re-initialize vector
    dist = vector<int>(MAX, INF);
    
    dijkstra(d);
    distD = dist;
    int largest = 0; 
    for(int i = 0; i < n; i++){
      if(distS[i] != INF && distD[i] != INF){
        if((distS[i]+distD[i]) > largest){
          largest = distS[i]+distD[i];
        }        
      }
    }
    
    cout << "Case " << index << ": " << largest << endl; 
    t--;
    index++;
    
    // re-initialize vector
    dist = vector<int>(MAX, INF);
    //re-initialize graph
    for(int i = 0; i < MAX; i++){
      graph[i].clear();
    }  
  }
  
}
