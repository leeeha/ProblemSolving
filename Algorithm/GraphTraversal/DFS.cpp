/**
방문하지 않은 노드를 발견할 때마다 재귀 호출하여 (스택에 원소를 넣어)
그래프에서 깊은 부분을 우선적으로 탐색하는 DFS 알고리즘 

특징
- 임의 노드에서 다음 가지로 넘어가기 전에 해당 브랜치를 모두 탐색하므로, 모든 노드를 방문해야 하는 경우에 적합 
- 스택 자료구조 (주로 재귀함수) 이용 

시간복잡도
- 인접 리스트로 구현: O(V + E)
- 인접 행렬로 구현: O(V^2)
*/
#include <iostream>
#include <vector>
using namespace std;

bool visited[9]; // 전역으로 선언하면 모두 false로 초기화 됨. 
vector<int> graph[9]; // 벡터 자체가 9개 

void dfs(int x) {
	// 현재 노드 방문 처리
	visited[x] = true;
	cout << x << ' ';

	// 그와 연결된 방문하지 않은 노드를 발견할 때마다 재귀호출 
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i]; 
		if (!visited[y]) dfs(y);
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

	dfs(1);
}