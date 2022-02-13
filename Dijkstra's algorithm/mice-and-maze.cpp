#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std; 

#define MAX 105
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
  int n = 0; // # of cells
  int e = 0; // exit
  int t = 0; // start
  int connection = 0; 
  
  int a = 0; 
  int b = 0; 
  int w = 0; // time each cạnh 
  int count = 0; 
  cin >> n >> e >> t >> connection; 
  
  // Create graph
  for(int i = connection - 1; i >= 0; i--){
    cin >> a >> b >> w;
    graph[b].push_back(make_pair(a,w));
  }

  dijkstra(e);
  
  for(int i = 1; i <= n; i++){
    if(dist[i] <= t){
      count++;
    } 
  }
  cout << count;

}
