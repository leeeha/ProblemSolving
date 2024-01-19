/**
한 노드에서 다른 모든 노드까지의 최단 거리를 구하는 다익스트라 알고리즘

방문하지 않는 노드 중에서 
최단 거리 테이블에 저장된 값이 가장 작은 노드를 찾아 
현재 노드를 거쳐가는 게 빠른지 아닌지 검사한다는 점에서 그리디 알고리즘으로 분류 
실제 구현은 BFS + DP (우선순위 큐 + 최단 거리 테이블)

시간복잡도
: 힙 자료구조 기반의 우선순위 큐 사용하면 O(ElogV)
*/

#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#define MAX 20001
using namespace std;

// 노드, 간선, 출발 노드 
int n, m, start;

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열 
vector<pair<int, int>> graph[MAX];

// 최단 거리 테이블 
int d[MAX];

void input() {
	cin >> n >> m >> start;

	// 최단 거리 테이블 초기화
	fill_n(d, n + 1, INF);

	// 모든 간선 정보 입력 받기
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		graph[a].push_back({b, c});
	}
}

void dijkstra() {
	// 기본적으로 최대 힙으로 선언되기 때문에 
	// 거리가 가장 짧은 노드부터 먼저 꺼내는 '최소 힙'으로 구현하려면
	// 원소를 삽입, 삭제할 때 마이너스 부호를 붙여줘야 한다.
	priority_queue<pair<int, int>> pq;

	// 출발 노드에 대한 초기화
	pq.push({ 0, start }); // 거리, 노드 번호 
	d[start] = 0;

	while (!pq.empty()) {
		// 최단 거리가 가장 짧은 노드 꺼내기
		int curDist = -pq.top().first; // 출발 노드에서 현재 노드까지의 거리
		int curNum = pq.top().second; // 현재 노드 번호
		pq.pop();

		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (curDist > d[curNum]) continue;

		// 현재 노드와 연결된 다른 인접 노드들을 확인
		for(auto edge: graph[curNum]) {
			int adjNum = edge.first; 
			int cost = edge.second; 
			int newCost = curDist + cost; 

			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우 
			if(d[adjNum] > newCost){
				d[adjNum] = newCost; // 최단거리 테이블 갱신 
				pq.push({-newCost, adjNum}); // 우선순위 큐 삽입
			}
		}
	}   
}

void printResult() {
	// 출발 노드에서 다른 모든 노드까지의 최단 거리 출력 
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) // 도달할 수 없는 경우
			cout << "INF" << '\n';
		else // 도달할 수 있는 경우 거리 출력
			cout << d[i] << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	dijkstra();

	printResult(); 

	return 0;
}