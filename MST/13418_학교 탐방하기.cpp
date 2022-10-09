#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
#include <cmath>
#define MAX 1001 
using namespace std;

int n, m; // 정점과 간선 
int parent[MAX]; // 루트 노드를 저장하는 테이블 
vector<pair<int, pair<int, int>>> edges; // 간선 정보 
vector<int> upHill; // 오르막길의 개수 
int ans = 0; // 최소 비용  

// 특정 원소가 속한 집합 찾아내기 
int findParent(int x){
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀 호출 
	if(x == parent[x]) return x; 
	return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기 
void unionParent(int a, int b){
	a = findParent(a);
	b = findParent(b);

	// 더 작은 번호가 부모 노드가 되도록 
	if(a < b) parent[b] = a;
	else parent[a] = b; 
}

int getWorstCase(){ 
	// 간선 비용에 따라 오름차순 정렬 
	// 오르막길 먼저 추가시키니까 최악의 경로 
	sort(edges.begin(), edges.end()); 

	// 부모 테이블 초기화 
	for(int i = 1; i <= n; i++){
		parent[i] = i;  
	}

	int count = 0; // 오르막길의 개수 
	for(int i = 0; i < edges.size(); i++){
		int isDown = edges[i].first; // 1이면 내리막길, 0이면 오르막길 
		int a = edges[i].second.first; 
		int b = edges[i].second.second; 

		// 사이클이 발생하지 않으면  
		if(findParent(a) != findParent(b)){
			unionParent(a, b); // 같은 집합으로 합치기 
			if(isDown != 1) count++; // 오르막길 개수 갱신 
		}
	}

	return pow(count, 2); // k_max ^ 2
}

int getBestCase(){
	// 부모 테이블 초기화 
	for(int i = 1; i <= n; i++){
		parent[i] = i;  
	}

	int count = 0; // 오르막길의 개수 
	for(int i = edges.size() - 1; i >= 0; i--){ // 내리막길 먼저 추가 (최적의 경로)
		int isDown = edges[i].first; // 1이면 내리막길, 0이면 오르막길 
		int a = edges[i].second.first; 
		int b = edges[i].second.second; 

		// 사이클이 발생하지 않으면  
		if(findParent(a) != findParent(b)){
			unionParent(a, b); // 같은 집합으로 합치기 
			if(isDown != 1) count++; // 오르막길 개수 갱신 
		}
	}

	return pow(count, 2); // k_min ^ 2
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	// 정점과 간선의 개수 
	cin >> n >> m; 

	// 입구와 1번 건물 간의 연결관계
	int a, b, c; 
	cin >> a >> b >> c; 
	edges.push_back({c, {a, b}}); // c가 0이면 오르막길, 1이면 내리막길 

	// 모든 간선 정보 입력 
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c; 
		edges.push_back({c, {a, b}});
	}

	int max = getWorstCase(); 
	int min = getBestCase(); 
	cout << max - min;

	return 0; 
}