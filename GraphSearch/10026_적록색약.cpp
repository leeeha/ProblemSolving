#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <cstring> 
using namespace std; 

const int MAX = 100; 
int n, cnt;
char arr[MAX][MAX]; 
bool visited[MAX][MAX]; 

// y�� ��, x�� �� 
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 }; 

void dfs(int y, int x) {
	visited[y][x] = true;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(!visited[ny][nx] && arr[y][x] == arr[ny][nx]){ 
			dfs(ny, nx); 
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}

	// �׷������� ����Ǿ� ������ ���� ���� 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// ���� ����� ���� ���ϱ� 
			if(!visited[i][j]){ 
				dfs(i, j);
				cnt++; 
			}
		}
	}
	cout << cnt << " ";

	// ���ϻ����� ��� 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	memset(visited, false, sizeof(visited));

	cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){ 
				dfs(i, j);
				cnt++; 
			}
		}
	}
	cout << cnt << endl; 
	
	return 0;
} 
