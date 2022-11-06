#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9 
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

int n, m, k; 
vector<pii> graph[MAX]; // a에서 b로 가는 비용이 c 
int d[MAX]; // x원 이하의 간선은 0, x원보다 비싸면 1 

// x원보다 비싼 간선을 'k개 이하'로 포함하는지 결정하는 함수 
bool decision(int x){ 
	fill_n(d, MAX, INF); 
	priority_queue<pii> pq; 
	pq.push({ 0, 1 }); // 비용, 노드번호 
	d[1] = 0; 
	
	while(!pq.empty()){
		int cost = -pq.top().first; // -1보다 0을 먼저 꺼낸다. 
		int now = pq.top().second; // 노드 번호 
		pq.pop(); 
		
		// 테이블에 저장된 값이 더 작으면 넘어가기 
		if(d[now] < cost) continue; 

		// 거쳐가는 경로가 더 짧은지 검사 
		for(auto edge : graph[now]){
			int next = edge.first;
			int temp = edge.second > x; // x원 이하는 0, 그렇지 않으면 1 
			int nextCost = cost + temp; 
			
			if(nextCost < d[next]){
				d[next] = nextCost; 
				pq.push({ -nextCost, next }); // 최소 힙 
			}
		}
	}

	return d[n] <= k; 

	// 테이블 d에서 1의 개수가 k개 이하면 true 
	// int cnt = 0; 
	// for(int i = 0; i < n; i++){
	// 	if(d[i] == 1){
	// 		cnt++;
	// 	}
	// }
	// if(cnt <= k) return true;
	// else return false; 
}

int main() 
{
	// 노드, 간선, 공짜 케이블의 개수 
    cin >> n >> m >> k;
	
    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
		
		// 양방향 연결을 잊지 말자!!! 
		graph[s].push_back({e, t});
		graph[e].push_back({s, t});
    }

	int ans = -1; 
	int left = 0, right = 1e6; // 비용의 최댓값
	while(left <= right){
		int mid = (left + right) / 2; 

		// 결정 문제를 만족시키는 x의 최솟값을 구하자. 
		if(decision(mid)){
			ans = mid; 
			right = mid - 1; // 최솟값을 구하기 위해서 
		}else{
			left = mid + 1; // true 구간으로 이동하도록 
		}
	}

	cout << ans; 
	
    return 0;
}
