#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 
#include <utility>
#include <cstring> // memset 
#define MAX 50 
using namespace std;

int w, h;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int numberOfLand = 0; 

// �� �� �� �� , ��� ���� �»� ���� 
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 }; 
int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 }; 

void bfs(int y, int x){
	queue<pair<int,int>> q; 
	q.push({y, x}); // ��, �� 
	visited[y][x] = true;

	while(!q.empty()){
		y = q.front().first; 
		x = q.front().second; 
		q.pop();

		// �ش� ��ġ�� 8����� Ȯ�� 
		for(int i = 0; i < 8; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			// ���� ���� ũ�⸦ ����� �ʰ� 
			if(0 <= ny && ny < h && 0 <= nx && nx < w){
				// ���� �湮���� ���� ���̶�� 
				if(graph[ny][nx] == 1 && !visited[ny][nx]){ 
					// �湮 ó�� 
					visited[ny][nx] = true;  
					q.push({ny, nx}); 
				}
			}
		}
	}
}

void dfs(int y, int x){
	visited[y][x] = true;

	for(int i = 0; i < 8; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(0 <= ny && ny < h && 0 <= nx && nx < w){
			if(graph[ny][nx] == 1 && !visited[ny][nx]){
				visited[ny][nx] = true;
				dfs(ny, nx); 
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(true){
		cin >> w >> h; 
		if(w == 0 && h == 0) 
			break; 

		for(int i = 0; i < h; i++){ // ���̰� �� 
			for(int j = 0; j < w; j++){ // �ʺ� ��  
				cin >> graph[i][j]; 
			}
		}

		// �׷��� Ž�� 
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(graph[i][j] == 1 && !visited[i][j]){
					// ���� ����� ���� ī���� 
					numberOfLand++; 

					// �� �Լ��� �ٽ� ȣ��Ǹ� ���� ������ ���� �ִٴ� �� 
					bfs(i, j); 
					//dfs(i, j); 
				}
			}
		}
		
		// ���� ���� ���
		cout << numberOfLand << "\n"; 

		// �� ���� �׽�Ʈ ���̽��� ���� ������ �ʱ�ȭ 
		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));
		numberOfLand = 0;
	}
	
	return 0;
}


