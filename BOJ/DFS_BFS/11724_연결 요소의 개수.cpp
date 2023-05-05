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

	// ��� ��尡 ����Ǿ� ������, cnt�� 1�̰� dfs�� �ٽ� ȣ����� ����. 
	// ������ �׷������� �湮 ó���� ���� ���� ��尡 ������, 
	// cnt�� 1���� Ŀ���� dfs �ٽ� ȣ���. 
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
