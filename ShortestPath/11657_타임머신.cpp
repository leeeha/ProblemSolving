#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9 
#define MAX 501  
using namespace std; 

int n, m; 
vector<pair<int, pair<int, int>>> edges; 
long long d[MAX]; // 오버 플로우 및 언더 플로우 방지

bool bellmanFord(int start){
	d[start] = 0; // 시작 노드에 대한 초기화 

	// n-1번의 라운드 반복 
	for(int i = 0; i < n; i++){
		// 매 반복마다 모든 간선을 확인하며 
		for(int j = 0; j < m; j++){
			int from = edges[j].first; 
			int to = edges[j].second.first; 
			int cost = edges[j].second.second;

			// 기존의 값보다 현재 간선을 거쳐 가는 게 더 짧으면 
			if(d[from] != INF && d[to] > d[from] + cost){
				d[to] = d[from] + cost; // 최단 거리 테이블 갱신 
				
				// n번째 라운드에서도 값이 갱신된다면 
				// 음수 사이클이 존재 
				if(i == n - 1) return true; 
			}
		}
	}

	return false; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c; 
		edges.push_back({a, {b, c}}); 
	}
	
	fill_n(d, MAX, INF); 

	bool negativeCycle = bellmanFord(1);

	if(negativeCycle){
		cout << "-1\n";
		return 0; 
	}

	// 1번을 제외한 다른 모든 노드로 가기 위한 최단 거리 출력 
	for(int i = 2; i <= n; i++){
		if(d[i] == INF){
			cout << "-1\n";
		}else{
			cout << d[i] << "\n"; 
		}
	}
	
	return 0; 
}