#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
#include <cstring> 
#include <queue> 
using namespace std;

const int MAX = 1001; 
int m, n; 
int graph[MAX][MAX];
queue<pair<int, int>> q; // 1�� ��ǥ  

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs() {
	while(!q.empty()){
		// 1�� ��ġ�� �ϳ��� ������ 
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); 

		// �����¿쿡 0�� �ִ��� Ž���Ѵ�. 
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

			// 0�� �߰��� ������ �ɸ� �ð��� �ش� ��ġ�� ���� 
			if(graph[nx][ny] == 0){ 
				graph[nx][ny] = graph[x][y] + 1; 

				// 0���� 1�� ���� �丶���� ��ġ�� ť�� ���� 
				q.push({nx, ny}); 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> m >> n; // n x m 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){ 
			cin >> graph[i][j]; 

			// 1�� ��ġ ���� 
			if(graph[i][j] == 1){
				q.push({i, j}); 
			}
		}
	}

	bfs(); 

	int ans = 0; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] == 0){
				cout << "-1\n";
				return 0; 
			}

			if(ans < graph[i][j]){
				ans = graph[i][j]; 
			}
		}
	}

	// �ִ񰪿��� 1�� ���� ���� 
	cout << ans - 1; 
	
	return 0;
}