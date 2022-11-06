#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
#include <utility> 
#define MAX 1001 
using namespace std;
typedef pair<int, int> pii; 

int m, n; 
int graph[MAX][MAX]; // 0���� �ʱ�ȭ 
queue<pii> q; // 1�� ��ġ ���� 

int dy[] = {-1, 1, 0, 0}; // �� 
int dx[] = {0, 0, -1, 1}; // �� 
int result = 0; 

void bfs(){
	while(!q.empty()){
		int y = q.front().first;  // �� 
		int x = q.front().second; // �� 
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny >= 0 && ny < n && nx >= 0 && nx < m){
				if(graph[ny][nx] == 0){
					// �ش� ĭ�� ������ ������ �ɸ� �ð� ���� 
					graph[ny][nx] = graph[y][x] + 1; 
					
					// 0�� 1�� �����̱� (ť�� ����)
					q.push({ny, nx});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n; // m x n 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j]; 

			// 1�� ��ġ�� ť�� ���� 
			if(graph[i][j] == 1){ 
				q.push({i, j}); 
			}
		}
	}

	bfs(); 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] == 0){
				printf("-1\n");
				return 0; 
			}

			if(result < graph[i][j]){
				result = graph[i][j]; // �ִ� ���� 
			}
		}
	}

	// ù°���� �Ͱ� �� 0�� ��ġ�� 
	// 1+1�� ����Ǵϱ� ����� ���� -1�� ����� �Ѵ�. 
	cout << result - 1; 
	
	return 0; 
}