#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
#include <queue> 
#include <cstring> 
using namespace std;

const int MAX = 100001; 
bool visited[MAX]; // 특정 좌표의 방문 여부 저장 

int n, k; // 두 사람의 좌표 
queue<pair<int, int>> q; // (좌표, 도달 시간) 

void checkVisited(int pos, int time){
	if(pos >= 0 && pos < MAX){ 
		if(!visited[pos]){ 
			// bfs 경로에 따라 누적해서 time 증가 
			q.push({pos, time + 1}); 
			visited[pos] = true; 
		}
	}
}

void bfs(int start){
	q.push({start, 0}); 
	visited[start] = true; 

	while(!q.empty()){ 
		int x = q.front().first; 
		int time = q.front().second; 
		q.pop();

		if(x == k){
			cout << time << endl;
			return;
		}

		checkVisited(x + 1, time); 
		checkVisited(x - 1, time); 
		checkVisited(2 * x, time); 
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> k;

	bfs(n);

	return 0;
}