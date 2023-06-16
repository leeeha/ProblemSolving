#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <queue> 
#define INF 1e9
#define MAX 300001 
using namespace std;

int N, M, K, X;
vector<int> graph[MAX]; 
int d[MAX]; 

void input() {
	cin >> N >> M >> K >> X; 

	for(int i = 0; i < M; i++){
		int a, b; 
		cin >> a >> b; 
		graph[a].push_back(b); 
	}

	fill_n(d, N + 1, INF);
}

void dijkstra(int start) {
	// 출발 노드 초기화 
	priority_queue<pair<int, int>> pq; 
	pq.push({0, start}); // 거리, 노드 번호 
	d[start] = 0; // 최단 거리 테이블 갱신 

	// 방문하지 않은 노드 중에서 
	// 최단 거리 테이블에 저장된 값이 가장 작은 노드부터 꺼내기 
	while(!pq.empty()){ 
		// 거리의 절댓값이 가장 작은 노드가 큐의 top에 위치 
		int dist = -pq.top().first; 
		int now = pq.top().second; 
		pq.pop(); 

		// 현재 노드가 방문 처리된 적 있다면 무시 
		if(dist > d[now]) continue; 

		// 현재 노드와 인접한 노드들에 대한 방문 처리 
		for(auto nodeNum: graph[now]){ 
			int cost = dist + 1; 
			if(d[nodeNum] > cost){ 
				d[nodeNum] = cost; 
				pq.push({-cost, nodeNum}); 
			}
		}
	}
}

void printResult() {
	bool notFound = true; 
	for(int i = 1; i <= N; i++){
		if(d[i] == K) { 
			notFound = false; 
			cout << i << "\n";
		}
	}
	if(notFound) cout << "-1\n"; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	input();  

	dijkstra(X);

	printResult(); 
	
	return 0; 
}
