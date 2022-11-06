#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9 
#define MAX 100001 
using namespace std; 

int n, m, start; 
vector<pair<int, int>> graph[MAX];
int d[MAX]; // 최단 거리 테이블 

void dijkstra(int start){
	priority_queue<pair<int, int>> pq; // 기본적으로 최대 힙 (first 기준으로)
	pq.push({ 0, start }); // 거리, 노드번호 
	d[start] = 0; 

	while(!pq.empty()){
		int dist = -(pq.top().first); // 최단 거리 
		int now = pq.top().second; // 노드 번호 
		pq.pop(); 

		// 최단 거리 테이블에 저장된 값이 더 작으면 넘어가기 
		if(dist > d[now]) continue; 

		for(int i = 0; i < graph[now].size(); i++){ 
			// 기존의 값보다 거쳐가는 값이 더 작으면 갱신 
			int cost = dist + graph[now][i].second;
			if(cost < d[graph[now][i].first]){
				d[graph[now][i].first] = cost; 
				pq.push({ -cost, graph[now][i].first }); // 거리, 노드번호 
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 노드 개수 최대 2만개 
	cin >> n >> m >> start;

	// a에서 b로 가는 비용이 c 
	for(int i = 0; i < m; i++){
		int a, b, c; 
		cin >> a >> b >> c;
		graph[a].push_back({b, c}); 
	}

	fill_n(d, MAX, INF); 

	dijkstra(start); 

	for(int i = 1; i <= n; i++){
		if(d[i] == INF) 
			cout << "INF\n";
		else 
			cout << d[i] << "\n"; 
	}
	
	return 0;
}