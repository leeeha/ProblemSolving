/**
방문하지 않은 모든 노드를 큐에 삽입하고 하나씩 꺼내면서 
그래프에서 가까운 노드부터 우선적으로 탐색하는 BFS 알고리즘 

특징
- 모든 노드를 탐색하는 것보다 '최소 비용'이 우선일 때 적합
- 간선의 가중치가 동일한 경우에 주로 사용
- 큐 자료구조 사용 

시간복잡도
- 인접 리스트로 구현: O(V + E)
- 인접 행렬로 구현: O(V^2)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[9];
vector<int> graph[9];

void bfs(int start) {
	queue<int> q;

	// 현재 노드 방문 처리
	q.push(start);
	visited[start] = true;

	while(!q.empty()) {
		// 큐의 앞에서부터 원소를 하나씩 뽑아서 
		int x = q.front();
		q.pop();
		cout << x << ' ';

		// 그와 연결된 아직 방문하지 않은 노드들 모두 큐에 삽입 
		for(int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if(!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main(void) {
	// 노드 1에 연결된 노드 정보 저장 
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	// 노드 2에 연결된 노드 정보 저장 
	graph[2].push_back(1);
	graph[2].push_back(7);

	// 노드 3에 연결된 노드 정보 저장 
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	// 노드 4에 연결된 노드 정보 저장 
	graph[4].push_back(3);
	graph[4].push_back(5);

	// 노드 5에 연결된 노드 정보 저장 
	graph[5].push_back(3);
	graph[5].push_back(4);

	// 노드 6에 연결된 노드 정보 저장 
	graph[6].push_back(7);

	// 노드 7에 연결된 노드 정보 저장 
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	// 노드 8에 연결된 노드 정보 저장 
	graph[8].push_back(1);
	graph[8].push_back(7);

	bfs(1);
}