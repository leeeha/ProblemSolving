#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
#include <queue> 
#include <cstring> 
using namespace std;

const int MAX = 1001; 
vector<int> graph[MAX]; // 0으로 초기화
bool visited[MAX]; // false로 초기화 

void dfs(int x){
	// 방문 처리 
	visited[x] = true; 
	cout << x << " "; 

	// 인접한 노드 중에 방문하지 않은 노드가 있으면 재귀 호출 
	for(int i = 0; i < graph[x].size(); i++){
		int y = graph[x][i]; 
		if(!visited[y]) dfs(y); 
	}
}

void bfs(int start){
	queue<int> q;  
	q.push(start); 
	visited[start] = true;

	while(!q.empty()){ 
		int x = q.front(); 
		q.pop(); 
		cout << x << " "; 

		// 인접한 노드 중에 방문하지 않은 노드 모두 큐에 삽입 
		for(int i = 0; i < graph[x].size(); i++){
			int y = graph[x][i]; 
			if(!visited[y]){ 
				q.push(y); 
				visited[y] = true; 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v; 

	for(int i = 0; i < m; i++){
		int x, y; 
		cin >> x >> y; 
		graph[x].push_back(y); 
		graph[y].push_back(x); 
	}

	// 각 정점에 연결된 정점 번호들을 오름차순 정렬한다. 
	for(int i = 1; i <= n; i++){ 
		sort(graph[i].begin(), graph[i].end()); 
	}

	dfs(v); 

	cout << endl; 
	memset(visited, 0, n + 1); // 1부터 시작하므로 n+1개 초기화 

	bfs(v); 

	return 0;
}