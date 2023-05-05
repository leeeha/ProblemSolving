#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#include <cmath> 
#define MAX 103 
using namespace std;
typedef pair<int, int> pii; 

int n; // 편의점 개수 
vector<pii> coord; // 출발점, 도착점, 편의점의 좌표 
vector<int> graph[MAX]; // 맨해튼 거리가 1000 이내인 좌표들끼리만 연결한 그래프 
bool visited[MAX]; 

void input(){
	cin >> n; 

	for(int i = 0; i < n + 2; i++){
		int x, y; 
		cin >> x >> y; 
		coord.push_back({x, y}); 
	}
}

int dist(pii p1, pii p2){
	int dx = abs(p1.first - p2.first); 
	int dy = abs(p1.second - p2.second); 
	return dx + dy; 
}

void dfs(int x){ 
	visited[x] = true; 

	for(int i = 0; i < graph[x].size(); i++){
		int y = graph[x][i]; 
		if(!visited[y]){ 
			dfs(y); 
		}
	}
}

void reset(){
	coord.clear(); 
	
	for(int i = 0; i < n + 2; i++){ 
		graph[i].clear(); 
	} 
	
	memset(visited, 0, sizeof(visited)); 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; 
	cin >> t; 

	while(t--){
		input();

		for(int i = 0; i < n + 2; i++){ 
			for(int j = i + 1; j < n + 2; j++){ 
				// 거리가 1000이내인 지점들만 연결 
				if(dist(coord[i], coord[j]) <= 50 * 20){
					graph[i].push_back(j); 
					graph[j].push_back(i); 
				}
			}
		}

		dfs(0); 

		if(!visited[n + 1]) cout << "sad\n";
		else cout << "happy\n"; 

		reset();
	}
	
    return 0;
}

