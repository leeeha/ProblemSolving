#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool visited[1001]; 
vector<int> graph[1001]; 

void dfs(int x){
	visited[x] = true;
	for(int i = 0; i < graph[x].size(); i++){
		int y = graph[x][i];
		if(!visited[y]){
			dfs(y); 
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// 모든 노드가 연결되어 있으면, cnt가 1이고 dfs는 다시 호출되지 않음. 
	// 끊어진 그래프여서 방문 처리가 되지 않은 노드가 있으면, 
	// cnt가 1보다 커지고 dfs 다시 호출됨. 
	int cnt = 0; 
	for(int i = 1; i <= n; i++){
		if(!visited[i]){ 
			cnt++;  
			dfs(i); 
		}
	}

	cout << cnt; 
	
	return 0;
}
