#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define MAX 26	
using namespace std;

int n, numberOfHousePerBlock; 
int graph[MAX][MAX]; // 0으로 초기화 
bool visited[MAX][MAX]; // false로 초기화 

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void markVisitedNode(int x, int y) {
	q.push({x, y});
	visited[x][y] = true; 
	numberOfHousePerBlock++; 
}

void bfs(int x, int y){
	// 비어있는 큐에서 다시 시작 
	markVisitedNode(x, y);

	// 큐가 빌 때까지 반복 
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = a + dx[i];
			int ny = b + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if(graph[nx][ny] == 1 && visited[nx][ny] == false){
				markVisitedNode(nx, ny);
			}
		}
	}
}

void dfs(int x, int y){
	visited[x][y] = true;
	numberOfHousePerBlock++; 

	// 방문하지 않은 집을 상하좌우로 탐색 
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		if(graph[nx][ny] == 1 && visited[nx][ny] == false){
			dfs(nx, ny); 
		}
	}
}

int main() {
	//ios::sync_with_stdio(0); 
    //iostream과 stdio의 연결이 끊어지기 때문에 scanf 사용시 에러가 발생한다. 
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%1d", &graph[i][j]);
		}
	}

	vector<int> result;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// 방문하지 않은 새로운 단지를 발견하면 
			if(graph[i][j] == 1 && visited[i][j] == false){ 
				// 단지내 집의 수 갱신 
				numberOfHousePerBlock = 0; 
				dfs(i, j); 
                //bfs(i, j);
				result.push_back(numberOfHousePerBlock);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	
	for(auto e: result){
		cout << e << "\n";
	}

	return 0; 
}