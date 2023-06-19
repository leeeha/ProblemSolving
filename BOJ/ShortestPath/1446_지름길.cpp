#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001 
using namespace std;

// 지름길의 개수, 고속도로 길이 
int N, D; 

// 지름길의 위치, 거리를 저장하는 배열 
vector<pair<int, int>> path[MAX]; 

// 특정 위치까지 가는 최단 거리를 저장하는 테이블 
int dist[MAX];

void input(){
	cin >> N >> D; 

	// i 위치까지 가는 최단 거리 초기화 
	for(int i = 0; i <= D; i++){
		dist[i] = i; 	
	}

	for(int i = 0; i < N; i++){
		// 지름길의 시작점, 도착점, 길이 
		int start, end, length; 
		cin >> start >> end >> length; 

		if(end > D) continue; 
		if(end - start <= length) continue; 

		path[start].push_back({end, length});
	}
}

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	input(); 

	int before; 
	for(int i = 0; i <= D; i++){
		if(i == 0) before = -1; 
		else before = dist[i - 1]; 

		// 지름길 반영한 최단 거리: dist[i] 
		// 일반 고속도로 이용한 거리: dist[i - 1] + 1 
		dist[i] = min(dist[i], before + 1);

		// i 위치에서 출발하는 지름길이 없다면 무시 
		if(path[i].empty()) continue; 

		// i 위치에서 출발하는 지름길이 있다면 
		for(auto edge: path[i]){ 
			int end = edge.first; 
			int length = edge.second;

			// 최단 거리 테이블 갱신 
			if(dist[end] > dist[i] + length){
				dist[end] = dist[i] + length; 
			}
		}
	}

	// D까지 가는 최단 거리 출력 
	cout << dist[D] << endl; 

    return 0;
}