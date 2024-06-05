#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 50001;
vector<pii> graph[MAX];

// 출입구에서 다른 지점까지 갈 때 가능한 최소 intensity
int intensities[MAX]; 
bool isSummit[MAX];
vector<int> answer(2, -1);

void dijkstra(vector<int> gates){
	// 최소 힙 (intensity가 작은 걸 먼저 꺼내도록)
	priority_queue<pii, vector<pii>, greater<vector<pii>>> pq;

	// 모든 출입구를 출발 노드로 설정한다.
	for(auto num: gates){
		pq.push({0, num}); // (intensity, 노드 번호)
		intensities[num] = 0;
	}

	while(!pq.empty()){
		int cost = pq.top().first; 
		int now = pq.top().second; 
		pq.pop(); 

		// 이미 한번 처리된 경우 패스 
		if(intensities[now] < cost) continue;

		// 산봉우리까지 도달한 경우 
		if(isSummit[now]){
			// 산봉우리 번호 & 최소 intensity 갱신 
			if(answer[0] == -1 || answer[1] > cost){
				answer[0] = now; 
				answer[1] = cost; 
			}
			// 최솟값이 동일한 경우, 산봉우리 번호가 더 낮은 것으로 저장 
			else if(answer[1] == cost && answer[0] > now) 
				answer[0] = now; 
			
			continue; 
		}

		// 현재 노드와 연결된 모든 노드 탐색 
		for(auto edge: graph[now]){
			int next = edge.first; 
			int weight = edge.second;
			weight = max(weight, cost); // 더 높은 가중치 계산 

			// 최소 intensity 갱신 (테이블, 우선순위 큐 갱신)
			if(intensities[next] == -1 || 
				intensities[next] > weight){
				intensities[next] = weight;
				pq.push({weight, next}); 
			}
		}
	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	fill(intensities, intensities + MAX, -1);

	for(auto num: summits){
		isSummit[num] = true; 
	}
	
	for(auto path: paths){
		int start = path[0];
		int end = path[1];
		int cost = path[2];

		// 양방향 연결
		graph[start].push_back({end, cost});
		graph[end].push_back({start, cost});
	}

	dijkstra(gates);

	return answer; 
}