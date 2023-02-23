#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 101 
using namespace std;

int n; 
int graph[MAX][MAX]; 
bool visited[MAX][MAX]; 
vector<int> result; 

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y, int h){
	// �湮 ó�� 
	visited[x][y] = true; 

	// ������ �����¿� Ž�� 
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		// ���� üũ 
		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 

		// ���̰� h���� ũ�鼭 �湮���� ���� ��� 
		if(graph[nx][ny] > h && !visited[nx][ny]){ 
			dfs(nx, ny, h); 
		} 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

	// �� ������ ���� �Է� �ޱ� (1 �̻� 100 ����)
	int maxHeight = -1; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j]; 
			maxHeight = max(maxHeight, graph[i][j]);
		} 
	} 
	
	for(int h = 1; h < maxHeight; h++){ 
		// DFS/BFS Ž������ ���� ������ ���� ���ϱ� 
		int cnt = 0; 
		for(int i = 0; i < n; i++){ 
			for(int j = 0; j < n; j++){ 
				// ���̰� h���� ũ�鼭 �湮���� ���� ��� 
				if(graph[i][j] > h && !visited[i][j]){ 
					cnt++; 
					dfs(i, j, h); 
				}
			}
		}
		result.push_back(cnt); 

		// ������ �ʱ�ȭ 
		memset(visited, 0, sizeof(visited)); 
	}

	int maxCount = *max_element(result.begin(), result.end()); 
	cout << maxCount; 
	
    return 0;
}
