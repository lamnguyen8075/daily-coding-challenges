#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std; 

#define MAX 502
const int INF = 1e9; // nếu mà nó vẫn là INF
// ko có đường đi
// dist[i] != INF tồn tại đường đi ngắn nhất.
vector< vector< pair<int, int> > > graph(MAX);
vector<int> dist(MAX, INF);
int path[MAX];

void dijkstra(int s){
  // option = greater< pair<int, int> >
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
  pq.push(make_pair(0, s)); // (lỗi) push vào trong pair nhưng mà giá trị đầu tiên lại là chỉ số của đỉnh :V
  dist[s] = 0;
  while(!pq.empty()){
    pair<int,int> top = pq.top();
    pq.pop();
    int u = top.second; // u sẽ là chỉ số đỉnh khi lấy ra khỏi Heap.
    int w = top.first; // w sẽ là chi phí để đến đỉnh u mà đã lấy ra khỏi Heap.
    
    for(int i = 0; i < graph[u].size(); i++){
      pair<int,int> neighbor = graph[u][i];
      if(w + neighbor.second < dist[neighbor.first]){
        dist[neighbor.first] = w + neighbor.second;
        pq.push(pair<int,int>(dist[neighbor.first], neighbor.first));
        path[neighbor.first] = u;
      }
    }
  }
}

int main (){
  int n = 0; // number of roads
  int a = 0; // a and b location btw
  int b = 0; // which the road was constructed
  int w = 0; // fixed cost for travelling
  int u = 0; // init location
  int q = 0; // num of query
  int v = 0; // destination
  
  cin >> n; 
  
  // Create graph
  for(int i = 0; i < n; i++){

    cin >> a >> b >> w;
 
    graph[a].push_back(make_pair(b,w));
    // temp.first = a;
    // graph[b].push_back(temp);
    graph[b].push_back(make_pair(a,w));
  }
  
  cin >> u; 
  cin >> q; 
  
  dijkstra(u);
  
  for(int i = 0; i < q; i++){
    int j = 0;
    cin >> v;
    
    if(dist[v] != INF){
      cout << dist[v] << endl;
    }
    else{
      cout << "NO PATH" << endl;
    }
  }  
}
