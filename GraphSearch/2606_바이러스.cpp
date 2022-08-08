#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool visited[101];
vector<int> graph[101]; 
vector<int> temp; 

void dfs(int x){
	visited[x] = true; 
	temp.push_back(x); // 1���� ����� ���� ����ϱ� 

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

	int n, m; // ������ ������ ���� 
	cin >> n >> m; 

	// ���� ���� ���� 
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;

        // ����� ����!!! 
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1); 

	// 1���� ����� ������ ���� ��� (�ڽ��� ����)
	cout << temp.size() - 1; 
	
	return 0;
}
