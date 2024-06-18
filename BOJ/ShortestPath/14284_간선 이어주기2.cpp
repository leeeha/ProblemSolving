#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 5001;
const int INF = 1e9; 
vector<pii> graph[MAX];
int dist[MAX]; 
int n, m, s, e;

void input() {
	cin >> n >> m;  

	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c; 

		// 양방향 연결 
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	cin >> s >> e;

	// 최단 거리 테이블 초기화 
	fill_n(dist, n + 1, INF); 
}

void dijkstra() {
	// 시작 노드로부터의 거리를 기준으로 한 최소 힙  
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s}); // 거리, 노드 번호 
	dist[s] = 0;

	while(!pq.empty()){
		int curDist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		// 한번 처리된 노드는 무시 (이미 경로 확정)
		if(dist[now] < curDist) continue;

		// 현재 노드와 인접한 노드 탐색 
		for(auto edge: graph[now]){
			int next = edge.first; 
			int cost = edge.second; 
			int newCost = cost + curDist; 

			if(dist[next] > newCost){
				dist[next] = newCost; 
				pq.push({newCost, next}); 
			}
		}
	}
}

void solution() {
	dijkstra(); 
	cout << dist[e]; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 
	solution();

	return 0;
}