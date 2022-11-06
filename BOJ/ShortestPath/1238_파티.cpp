#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9 
#define MAX 1001 
using namespace std; 

int n, m, x; 
vector<pair<int, int>> graph[MAX]; // 간선 정보 저장 
int d[MAX]; // 최단 거리 테이블 
int res[MAX]; // 왕복 거리 저장 

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

	// 노드 개수 최대 1000개 
	cin >> n >> m >> x; 
	
	for(int i = 0; i < m; i++){
		int a, b, c; 
		cin >> a >> b >> c; 
		graph[a].push_back({b, c}); 
	}

	for(int i = 1; i <= n; i++){
		fill_n(d, MAX, INF); // 시작 노드가 바뀔 때마다 초기화 
		dijkstra(i); 
		res[i] = d[x]; // i에서 x로 가는 최단 거리 
	}

	fill_n(d, MAX, INF); // 시작 노드가 고정되어 있으니 한번만 초기화 
	dijkstra(x); 
	for(int i = 1; i <= n; i++){ 
		res[i] += d[i]; // x에서 i로 돌아오는 최단 거리 
	}

    // 그 중에서 최댓값 구하기 
	int ans = *max_element(res + 1, res + n + 1); 
	cout << ans; 
	
	return 0; 
}

