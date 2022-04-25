#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 정점 개수 최대 1000개
bool visited[1001]; 
vector<int> graph[1001];

void dfs(int x){
	visited[x] = true;
	cout << x << ' ';

	for(int i = 0; i < graph[x].size(); i++){
		int y = graph[x].at(i);
		if(!visited[y]) 
			dfs(y); // 방문 처리를 하지 않은 노드가 없을 때까지 재귀 호출
	}
}

void bfs(int start) {
	for(int i = 1; i <= 1000; i++){
		visited[i] = false; // dfs에서 방문 처리했던 거 초기화!
	}
	
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()){ // 큐가 빌 때까지 반복 
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for(int i = 0; i < graph[x].size(); i++){
			int y = graph[x].at(i);
			if(!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	// 정점의 개수 N(1 ≤ N ≤ 1,000)
	// 간선의 개수 M(1 ≤ M ≤ 10,000)
	// 탐색을 시작할 정점의 번호 V 
	int n, m, v;
	cin >> n >> m >> v;

	// 간선 개수만큼 노드끼리 양방향 연결 
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		
		graph[x].push_back(y);
		graph[y].push_back(x); // 양방향 연결
	}

	// 각 노드에 연결된 여러 개의 노드들 중에서 낮은 번호부터 방문하도록 오름차순 정렬!
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	
	bfs(v);
	cout << "\n";
	
	return 0;
}