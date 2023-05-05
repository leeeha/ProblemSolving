#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 20001 
#define RED 1
#define BLUE 2
using namespace std;

int v, e; 
vector<int> graph[MAX]; 
int colored[MAX]; 

void bfs(int start){
	queue<int> q; 
	q.push(start); 
	colored[start] = RED; 

	while(!q.empty()){ 
		int x = q.front(); 
		q.pop(); 

		// 큐에서 꺼낸 노드는 red와 blue 중에 하나 
		int color = 0; 
		if(colored[x] == RED){ 
			color = BLUE; 
		}else{
			color = RED; 
		}

		// 인접한 정점인데 아직 색상이 없는 경우, 반대되는 색상으로 칠하기 
		for(int i = 0; i < graph[x].size(); i++){
			int y = graph[x][i]; 
			if(!colored[y]){
				q.push(y); 
				colored[y] = color; 
			}
		}
	}
}

void dfs(int x){
	if(!colored[x]){ 
		colored[x] = RED; 
	}

	int color = 0; 
	if(colored[x] == RED){ 
		color = BLUE;
	}else {
		color = RED; 
	}

	for(int i = 0; i < graph[x].size(); i++){ 
		int y = graph[x][i]; 
		if(!colored[y]){ 
			colored[y] = color;
			dfs(y); 
		}
	}
}

bool isBipartite(){
	// 그래프를 순회하면서 
	// 인접한 정점이 다른 색상으로 칠해져있는지 검사 
	for(int i = 1; i <= v; i++){
		for(int j = 0; j < graph[i].size(); j++){
			int next = graph[i][j];

			// i번째 정점에 연결된 모든 정점이 서로 다른 색상이면 이분 그래프 
			// 하나라도 같은 색상이 있으면 이분 그래프 x 
			if(colored[i] == colored[next]){
				return false; 
			}
		}
	}
	return true; 
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int k;
	cin >> k; 

	while(k--){
		cin >> v >> e; 

		for(int i = 0; i < e; i++){
			int x, y; 
			cin >> x >> y; 
			graph[x].push_back(y); 
			graph[y].push_back(x); 
		}

		// 1~v번까지 인접한 정점은 서로 다른 색상으로 구분한다. 
		// 한번 색칠이 된 건 스킵한다. 
		for(int i = 1; i <= v; i++){
			if(!colored[i]){
				dfs(i); 
			}
		}

		if(isBipartite()) cout << "YES\n";
		else cout << "NO\n";

		memset(graph, 0, sizeof(graph));
		memset(colored, 0, sizeof(colored));
	}

    return 0;
}

