#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 101
using namespace std;
typedef pair<int, int> pii; 

int map[MAX]; 
bool visited[MAX];

void bfs(int x){
	queue<pii> q; 
	q.push({x, 0}); // 칸의 번호, 주사위를 던진 횟수 
	visited[x] = true; 

	while(!q.empty()){ 
		int pos = q.front().first; 
		int cnt = q.front().second; 
		q.pop(); 

		if(pos == 100){
			cout << cnt << endl; 
			break; 
		}

		// 주사위 눈 1~6까지 모든 경우의 수를 따진다. 
		for(int i = 1; i <= 6; i++){
			// 새로운 위치로 갱신 
			int npos = pos + i; 

			// 범위 체크 
			if(npos > 100) continue;

			// 뱀 또는 사다리의 위치와 겹치는지 확인  
			if(map[npos] != 0){ 
				npos = map[npos]; 
			}
				
			// 방문하지 않았던 칸인 경우 방문 처리 
			if(!visited[npos]){ 
				q.push({npos, cnt + 1}); 
				visited[npos] = true;  
			} 
		}
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int n, m; 
	cin >> n >> m; 

	int x, y; 
	for(int i = 0; i < n; i++){
		cin >> x >> y; 
		map[x] = y; 
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		map[x] = y; 
	}

	bfs(1); 
	
    return 0;
}

