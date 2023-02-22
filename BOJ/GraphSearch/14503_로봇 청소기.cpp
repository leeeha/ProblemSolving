#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 51 
using namespace std; 

int n, m; 
int graph[MAX][MAX]; // ��ĭ�� 0, ���� 1 
bool cleaned[MAX][MAX]; // û�ҵǸ� true, �ƴϸ� false 
int cnt = 0; 

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// �� 0 �� 1 �� 2 �� 3  
// (d + 2) % 4 -> ���� ���� üũ 

void dfs(int x, int y, int d){ 
	if(!cleaned[x][y]){ 
		cleaned[x][y] = true; 
		cnt++; 
	}
	
	// �ٶ󺸴� ���� d�� �������� �ݽð� �������� Ž�� ���� 
	for(int i = 0; i < 4; i++){ 
		int nd = (d + 3 - i) % 4; 
		int nx = x + dx[nd]; 
		int ny = y + dy[nd]; 

		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

		// û�ҵ��� ���� ��ĭ�� �߰��� ��� 
		if(graph[nx][ny] == 0 && !cleaned[nx][ny]){ 
			// ������ ȸ���Ͽ� ��ĭ �����Ѵ�. 
			dfs(nx, ny, nd); 
		} 
	}

	// �ֺ� 4ĭ �߿� û�ҵ��� ���� ��ĭ�� ���� ���, ���� ���� ���� Ž�� 
	int back = (d + 2) % 4; 
	int bx = x + dx[back]; 
	int by = y + dy[back]; 

	// ������ ����ų� ���� ����ġ�� �۵��� �����. 
	if(bx < 0 || bx >= n || by < 0 || by >= m || graph[bx][by] == 1) {
		cout << cnt; 
		exit(0); 
	}
	
	// ���� ������ ä�� ��ĭ �����ϰ� �ٽ� Ž���� �����Ѵ�. 
	dfs(bx, by, d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 

	int r, c, d; 
	cin >> r >> c >> d;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j]; 
		}
	}

	// �۵��� ������ �ʰ� �ѹ��� û���� �� �ִ� ĭ�� �ִ� ������ ������. 
	dfs(r, c, d);
	
    return 0;
}