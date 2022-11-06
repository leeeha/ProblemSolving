#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
#include <cmath>
#define MAX 1001 
using namespace std;

int n; // 별의 개수 
int parent[MAX]; // 루트 노드를 저장하는 테이블 
vector<pair<float, float>> coord; // 별의 좌표 
vector<pair<float, pair<int, int>>> edges; // 정점 a와 b 사이의 거리 c
float result = 0; // 최소 비용 

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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n; // 별의 개수 
	
	for(int i = 0; i < n; i++){
		parent[i] = i; // 부모 테이블 초기화 
	}

	for(int i = 0; i < n; i++){
		float x, y; 
		cin >> x >> y; 
		coord.push_back({x, y}); // 별의 좌표 
	}

	for(int i = 0; i < n; i++){
		float x1 = coord[i].first; 
		float y1 = coord[i].second; 

		for(int j = i + 1; j < n; j++){
			float x2 = coord[j].first; 
			float y2 = coord[j].second; 
            
            // 두 정점 사이의 거리 구하기 
			float dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
			edges.push_back({dist, {i, j}}); 
		}
	}

	// 간선의 비용에 따라 오름차순 정렬 
	sort(edges.begin(), edges.end()); 

	for(int i = 0; i < edges.size(); i++){
		float cost = edges[i].first; 
		int a = edges[i].second.first; 
		int b = edges[i].second.second; 
        
		if(findParent(a) != findParent(b)){
			unionParent(a, b);
			result += cost; 
		}
	}

	cout << result; 

	return 0; 
}