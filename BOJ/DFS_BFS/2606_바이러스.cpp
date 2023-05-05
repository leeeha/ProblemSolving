#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool visited[101];
vector<int> graph[101]; 
vector<int> temp; 

void dfs(int x){
	visited[x] = true; 
	temp.push_back(x); // 1번과 연결된 정점 기록하기 

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

	int n, m; // 정점과 간선의 개수 
	cin >> n >> m; 

	// 정점 간의 연결 
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;

        // 양방향 연결!!! 
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1); 

	// 1번과 연결된 정점의 개수 출력 (자신은 제외)
	cout << temp.size() - 1; 
	
	return 0;
}
