#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define RED 1
#define BLUE 2
using namespace std;

int k, v, e; // 테스트 케이스, 정점, 간선 개수 
vector<int> graph[MAX];
int visited[MAX];

void bfs(int start){
	queue<int> q;
	int color = RED;
	visited[start] = color;
	q.push(start);

	// 큐가 빌 때까지 반복 
	while(!q.empty()){
		int x = q.front();
		q.pop();

		// 인접 노드를 반대되는 색상으로 설정 
		if(visited[x] == RED){
			color = BLUE;
		}else if(visited[x] == BLUE){
			color = RED;
		}

		for(int i = 0; i < graph[x].size(); i++){
			int y = graph[x][i];
			if(!visited[y]){
				visited[y] = color;
				q.push(y);
			}
		}
	}
}

void dfs(int x){
	if(!visited[x]){
		visited[x] = RED;
	}

	for(int i = 0; i < graph[x].size(); i++){
		int y = graph[x][i];
		
        // 인접 노드를 반대되는 색상으로 설정 
		if(!visited[y]){
			if(visited[x] == RED){
				visited[y] = BLUE;
			}else if(visited[x] == BLUE){
				visited[y] = RED;
			}

			dfs(y); // 재귀 호출 
		}
	}
}

bool isBipartite(){
	for(int i = 1; i <= v; i++){
		for(int j = 0; j < graph[i].size(); j++){
			int next = graph[i][j];
            
            // 인접 노드가 같은 색상이면 이분 그래프 X
			if(visited[i] == visited[next]){
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> k;
	while(k--){
		cin >> v >> e;

		// 그래프 정보 입력 
		for(int i = 0; i < e; i++){
			int first, second;
			cin >> first >> second;
			graph[first].push_back(second);
			graph[second].push_back(first);
		}

		// bfs 또는 dfs 탐색
		for(int i = 1; i <= v; i++){
			if(!visited[i]){
				bfs(i);
				//dfs(i);
			}
		}

		if(isBipartite()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}

		// 그 다음 테스트 케이스 검사를 위해 초기화 
		for(int i = 0; i <= v; i++){
			graph[i].clear();
			visited[i] = false;
		}
	}
	
	return 0;
}