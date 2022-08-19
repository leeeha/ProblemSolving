#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9 
#define MAX 501 
using namespace std; 

int n, m, w; // 노드, 간선, 웜홀 개수 
int s, e, t; // 시작, 끝, 가중치 
vector<pair<int, pair<int, int>>> edges; 
long long d[MAX]; // 최단 거리 테이블 

bool bellmanFord(){ 
	d[1] = 0; // 시작 노드를 1번으로 고정 
	
	// (n-1)번의 라운드 반복 
	for(int i = 0; i < n; i++){ 
		// 매 반복마다 '모든 간선'을 하나씩 확인한다. 
		for(int j = 0; j < edges.size(); j++){ // 도로와 웜홀 모두 포함 
			int from = edges[j].first; 
			int to = edges[j].second.first; 
			int cost = edges[j].second.second;
            
            //if(d[from] == INF) continue; 
			
			// 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우 
			if(d[to] > d[from] + cost){ 
				d[to] = d[from] + cost; // 최단 거리 테이블 갱신 
				
				// n번째에도 최단 거리가 갱신된다면 음수 사이클 존재!  
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

	int tc; 
	cin >> tc;
	
	while(tc--){
		// 테스트 케이스마다 초기 데이터 초기화 
		fill_n(d, MAX, -1); 
		edges.clear(); 
		
		cin >> n >> m >> w; 

		// 도로는 양방향, 양수 간선 
		for(int i = 0; i < m; i++){
			cin >> s >> e >> t;
			edges.push_back({s, {e, t}}); 
			edges.push_back({e, {s, t}}); 
		}

		// 웜홀은 단방향, 음수 간선 
		for(int i = 0; i < w; i++){ 
			cin >> s >> e >> t; 
			edges.push_back({s, {e, -t}}); 
		}

		// 음수 사이클이 존재하는지 확인
		if(bellmanFord()) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0; 
}
