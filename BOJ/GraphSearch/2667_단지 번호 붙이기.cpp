#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define MAX 26	
using namespace std;

int n, numberOfHousePerBlock; 
int graph[MAX][MAX]; // 0���� �ʱ�ȭ 
bool visited[MAX][MAX]; // false�� �ʱ�ȭ 

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void markVisitedNode(int x, int y) {
	q.push({x, y});
	visited[x][y] = true; 
	numberOfHousePerBlock++; 
}

void bfs(int x, int y){
	// ����ִ� ť���� �ٽ� ���� 
	markVisitedNode(x, y);

	// ť�� �� ������ �ݺ� 
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

	// �湮���� ���� ���� �����¿�� Ž�� 
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
    //iostream�� stdio�� ������ �������� ������ scanf ���� ������ �߻��Ѵ�. 
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
			// �湮���� ���� ���ο� ������ �߰��ϸ� 
			if(graph[i][j] == 1 && visited[i][j] == false){ 
				// ������ ���� �� ���� 
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