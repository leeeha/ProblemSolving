#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
#include <queue> 
#include <cstring> 
using namespace std;

const int MAX = 21; 
int ocean[MAX][MAX];
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 
int n; 

struct Fish {
	int y, x, dist; 

	bool operator < (const Fish& b) const {
		if(dist == b.dist){
			if(y == b.y) return x > b.x; 
			return y > b.y; 
		}

		return dist > b.dist; 
	}
}; 

queue<Fish> shark;

void input() {
	cin >> n; 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> ocean[i][j];

			if(ocean[i][j] == 9){ 
				shark.push({i, j, 0}); // 위치, 이동 거리 
				ocean[i][j] = 0; // 빈칸으로 만들기 
			}
		}
	}
}

int solution() {
	int time = 0, eaten = 0, sharkSize = 2; 

	while(true){
		// 상어의 위치에 따라 먹을 수 있는 물고기들이 달라진다.
		priority_queue<Fish> feed; 
		// 물고기까지의 최단 거리를 구할 때 사용되는 배열
		vector<vector<bool>> visited(n, vector<bool>(n));

		while(!shark.empty()){ 
			// 상어의 현재 위치 
			Fish curr = shark.front(); 
			shark.pop();

			// 상어의 주변 탐색 
			for(int i = 0; i < 4; i++){
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];
				int nextDist = curr.dist + 1;

				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 

				// 지나갈 수 있고, 이전에 방문하지 않은 경우 
				if(ocean[ny][nx] <= sharkSize && !visited[ny][nx]){
					// 방문 처리 
					visited[ny][nx] = true;
					// 상어의 위치와 이동 거리 갱신 
					shark.push({ny, nx, nextDist}); 
				}

				// 먹을 수 있는 물고기를 발견하면, 그 위치와 이동 거리 저장 
				if(ocean[ny][nx] > 0 && ocean[ny][nx] < sharkSize){ 
					feed.push({ny, nx, nextDist}); 
				}
			}
		}

		// 더 이상 먹을 수 있는 물고기가 없으면 종료! 
		if(feed.empty()) break;

		// 우선순위가 가장 높은 물고기를 먹는다.
		Fish fish = feed.top();
		int y = fish.y;
		int x = fish.x;
		time += fish.dist; // 걸린 시간 합산

		// 먹은 개수에 따라 상어의 크기 갱신
		if(++eaten == sharkSize){
			eaten = 0;
			sharkSize++;
		}

		ocean[y][x] = 0; // 먹고 나서는 빈칸으로  
		shark.push({y, x, 0}); // 상어의 위치 이동, 거리 초기화
	}

	return time; // 걸린 시간 반환 
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	input(); 

	cout << solution() << endl;

	return 0;
}