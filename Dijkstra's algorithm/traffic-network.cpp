#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 500000
const int INF = 1e9;

//vector<vector<pair<int,i00t>>> graph(MAX);
//vector<vector<pair<int,int>>> graphTwoWay(MAX);

vector<int> dist(MAX,INF);
int path[MAX];

struct graphK{
  int u;
  int v; 
  int q;
} graphTwoWay;

void dijkstra(int s, vector<vector<pair<int, int>>> graph){
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
  int testcase = 0; 
  int n = 0; // 
  int m = 0; 
  int k = 0; 
  int s = 0; 
  int t = 0; 
  int d = 0; //
  int c = 0; //
  int l = 0; //
  int uu = 0; 
  int vv = 0; 
  int qq = 0; 
  cin >> testcase; 
  
  while(testcase > 0){
    vector<vector<pair<int,int>>> graph(MAX);
    vector<vector<pair<int,int>>> graph_rev(MAX);
    vector<int> distS; 
    vector<int> distT;
    
      cin >> n >> m >> k >> s >> t; 
    vector<graphK> gtw(k);
    // Make graph
    for(int i = 0; i < m; i++){
      cin >> c >> d >> l;
      graph[c].push_back(make_pair(d,l));
      graph_rev[d].push_back(make_pair(c,l));
      // có thêm một mảng danh sách kề ở đây, tên là graph_rev chẳng hạn.
    }

    for(int i = 0; i < k; i++){
      cin >> uu >> vv >> qq;
      gtw[i].u = uu; 
      gtw[i].v = vv;
      gtw[i].q = qq;
    }

      dist = vector<int>(MAX, INF);

      int lengthST = 0; 
      dijkstra(s, graph);
      distS = dist;
      lengthST = dist[t];
      // re-initialize vector dist
      dist = vector<int>(MAX, INF);
      
      dijkstra(t, graph_rev); // graph_rev
      distT = dist;
      int lowest = INF; // INF ??

        for(int i = 0; i < k; i++){
          // S -> u + w + v -> T
          if(lowest > distS[gtw[i].u] + distT[gtw[i].v] + gtw[i].q) 
          {
            lowest = distS[gtw[i].u] + distT[gtw[i].v] + gtw[i].q;
          }
          
          if(lowest > distS[gtw[i].v] + distT[gtw[i].u] + gtw[i].q) 
          {
            lowest = distS[gtw[i].v] + distT[gtw[i].u] + gtw[i].q;
          }
          
          // S -> v + w + u -> T
        }    
        if(lowest != INF){
          cout << lowest << endl;
        }
        else{
          cout << -1 << endl;  
        }
        
      testcase--;
  }
 

  
  return 0;
}
