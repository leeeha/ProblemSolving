#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1001;
int N, M;

int graph[MAX][MAX]; // 0: 벽, 1: 빈칸, 2: 목표 지점
int dist[MAX][MAX]; // 2부터 다른 지점까지의 거리 
queue<pii> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input(){
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			dist[i][j] = -1;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> graph[i][j];

			// 목표 지점 위치 저장 
			if(graph[i][j] == 2){
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}
}

void bfs(int x, int y){
	// 2부터 다른 모든 지점까지의 최단 거리 계산 
	// 도달할 수 없는 경우 -1 그대로 출력 
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		int row = now.first;
		int col = now.second;
		
		for(int i = 0; i < 4; i++){
			int nx = row + dx[i];
			int ny = col + dy[i];
			
			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if(dist[nx][ny] != -1) continue;
			if(graph[nx][ny] == 0) continue;

			q.push({nx, ny});
			dist[nx][ny] = dist[row][col] + 1;
		}
	}
}

void solution(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(graph[i][j] == 0){
				cout << "0 ";
				continue;
			}

			bfs(i, j);
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	return 0;
}
