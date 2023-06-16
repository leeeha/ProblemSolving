#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#define INF 1e9
#define MAX 10001
using namespace std;

int N, D; 
vector<pair<int, int>> graph[MAX]; // 지름길 정보 저장 
int dist[MAX]; // 특정 지점까지의 최소 운전 거리를 저장하는 테이블 

void input() {
	cin >> N >> D;

	// i 위치까지 가는 최소 운전 거리 초기화 
	for(int i = 0; i <= D; i++){
		dist[i] = i; 
	}

	// 지름길 정보 저장 
	for(int i = 0; i < N; i++){
		int start, end, length; 
		cin >> start >> end >> length;

		if(end - start <= length) continue; 
		if(end > D) continue; 
		
		graph[start].push_back({end, length}); 
	}
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	input(); 

	int before = -1;
	for(int i = 0; i <= D; i++){ 
		if(i != 0) before = dist[i - 1]; 

		// 지름길을 따라가는 경우: dist[i]
		// 일반 고속도로를 따라가는 경우: dist[i - 1] + 1 
		// -> i 위치까지 가는 최소 운전 거리 갱신 
		dist[i] = min(dist[i], before + 1); 

		// i 위치에 지름길이 있는 경우 
		for(auto edge: graph[i]){ 
			int end = edge.first; 
			int length = edge.second; 

			// 지름길을 이용하는 게 더 짧으면 테이블 갱신 
			if(dist[end] > dist[i] + length){ 
				dist[end] = dist[i] + length; 
			}
		}
	}

	cout << dist[D]; 
	
	return 0; 
}
