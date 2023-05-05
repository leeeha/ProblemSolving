#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 301
using namespace std; 
typedef pair<int, int> pii; 

int n, m; 
int graph[MAX][MAX]; 
bool visited[MAX][MAX];
vector<pii> iceberg; // ������ ��ġ  
vector<int> zero; // �� ���꿡 ������ 0�� ���� 
int year = 0; // 2�� �̻��� ����� �и��� ������ �ɸ� �ð� 

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void input() {
	cin >> n >> m; 

	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){ 
			cin >> graph[i][j];
			
			if(graph[i][j] != 0){
				// ������ ��ġ ���� 
				iceberg.push_back({i, j}); 
			}
		}
	}
}

bool isEmpty() {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(graph[i][j] != 0) return false; 
		}
	}
	return true; 
}

void countAdjacentZero(){
	for(int i = 0; i < iceberg.size(); i++){
		int cnt = 0; 
		int x = iceberg[i].first; 
		int y = iceberg[i].second; 

		// �� ������ �����¿� Ž��
		for(int i = 0; i < 4; i++){ 
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

			if(graph[nx][ny] == 0){ 
				cnt++; 
			}
		}
		
		zero.push_back(cnt); 
	}
}

void updateIcebergHeight(){
	for(int i = 0; i < iceberg.size(); i++){ 
		int x = iceberg[i].first; 
		int y = iceberg[i].second; 

		// ������ ���� ���� (0���� �پ���� �ʴ´�.)
		if(graph[x][y] < zero[i]){ 
			graph[x][y] = 0; 
		}else{
			graph[x][y] -= zero[i]; 
		}
	}
}

void dfs(int x, int y){
	visited[x][y] = true; 

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

		if(graph[nx][ny] != 0 && !visited[nx][ny]){
			dfs(nx, ny); 
		} 
	}
}

int countIcebergSet(){ 
	int num = 0; 
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){
			if(graph[i][j] != 0 && !visited[i][j]){ 
				num++;
				dfs(i, j);
			}
		}
	}
	return num; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input(); 

	// ������ �� ���� ������ �ݺ��ؾ� �ϴ� ������? 
	// 1. �� ���꿡 ������ 0�� ������ �����Ѵ�. (zero �迭 -> �ʱ�ȭ)
	// 2. ������ ���̿� ��� �ð��� �����Ѵ�. (graph �迭 -> ����) 
	// 3. ���� ����� ����� �˻��Ѵ�. (visited �迭 -> �ʱ�ȭ) 

	while(!isEmpty()){ 
		countAdjacentZero(); 

		updateIcebergHeight(); 

		year++; 

		int num = countIcebergSet(); 
		if(num >= 2) { 
			cout << year; 
			return 0; 
		}
		
		zero.clear(); 
		memset(visited, 0, sizeof(visited)); 
	}

	cout << "0"; 
	
    return 0;
}