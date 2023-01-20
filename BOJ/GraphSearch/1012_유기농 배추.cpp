#include <iostream>
#include <cstring> 
#define MAX 51	
using namespace std;

int n, m, k; 
int graph[MAX][MAX]; // 0���� �ʱ�ȭ 
bool visited[MAX][MAX]; // false�� �ʱ�ȭ 

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y){
	visited[x][y] = true;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if(graph[nx][ny] == 1 && !visited[nx][ny]){
			dfs(nx, ny); 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; 
	cin >> t; 

	while(t--){
		cin >> n >> m >> k; 

		while(k--){ 
			int x, y; 
			cin >> x >> y; 
			graph[x][y] = 1; 
		}

		int count = 0; // �ʿ��� �������� �ּ� ���� 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				// �湮���� ���� ĭ�� �߰��ϸ�  
				if(graph[i][j] == 1 && !visited[i][j]){
					count++; 
					dfs(i, j); 
				}
			}
		}

		// ���� ���� ���� ����! 
		cout << count << endl; 

		// �� �׽�Ʈ ���̽����� �迭 �ʱ�ȭ ������� �Ѵ�! 
		memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
	}
	
	return 0; 
}