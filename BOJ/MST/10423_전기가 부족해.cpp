#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
#include <cmath>
#define MAX 1001 
using namespace std;

int n, m, k; // 정점, 간선, 발전소의 개수  
int parent[MAX]; // 루트 노드를 저장하는 테이블 
bool elec[MAX]; // 발전소가 설치된 정점 표시 
vector<pair<int, pair<int, int>>> edges; // 간선 정보 
int result = 0; // 최소 비용 

int findParent(int x){
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀 호출 
	if(x == parent[x]) return x; 
	return parent[x] = findParent(parent[x]); 
}

void unionParent(int cost, int a, int b){
	a = findParent(a);
	b = findParent(b);

	// 두 정점 모두 발전소와 연결된 경우 
	if(elec[a] && elec[b])
		return; 
	// 둘 중에 하나만 발전소와 연결된 경우 
	else if(elec[a] && !elec[b]){
		// 발전소가 있는 지점에 연결 
		parent[b] = a;
		result += cost; 
	}else{
		parent[a] = b;
		result += cost; 
	}
}

void solution(){
	// 간선 비용에 따라 오름차순 정렬 
	sort(edges.begin(), edges.end()); 

	// 부모 테이블 초기화 
	for(int i = 1; i <= n; i++){
		parent[i] = i;  
	}

	for(int i = 0; i < edges.size(); i++){
		int cost = edges[i].first; 
		int u = edges[i].second.first; 
		int v = edges[i].second.second; 

		// 사이클을 형성하지 않으면서 
		if(findParent(u) != findParent(v)){
			// 발전소에 연결되어 있지 않은 정점이 있으면 연결! 
			unionParent(cost, u, v);
		}
	}

	cout << result; // 최소 비용 출력 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	// 정점, 간선, 발전소의 개수 
	cin >> n >> m >> k; 

	// 발전소가 설치된 정점 표시하기 
	for(int i = 0; i < k; i++){ 
		int idx;
		cin >> idx; 
		elec[idx] = true; 
	} 

	// 간선 정보 입력 
	for(int i = 0; i < m; i++){
		int u, v, w; 
		cin >> u >> v >> w; 
		edges.push_back({w, {u, v}});
	}

	solution(); 

	return 0; 
}