#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 101
using namespace std;

int n, m; 
int start, finish; 
vector<int> graph[MAX]; 
bool visited[MAX]; 

int bfs(int x){
	queue<pair<int, int>> q; // 정점번호, 이동횟수 
	q.push({x, 0}); 
	visited[x] = true; 

	while(!q.empty()){
		int num = q.front().first; 
		int cnt = q.front().second; 
		q.pop(); 

		if(num == finish){ 
			return cnt; 
		} 

		for(int i = 0; i < graph[num].size(); i++){
			int y = graph[num][i]; 
            
			if(!visited[y]){ 
				q.push({y, cnt + 1}); 
				visited[y] = true; 
			}
		}
	}

	return -1; 
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> n; 

	cin >> start >> finish; 

	cin >> m; 

	for(int i = 0; i < m; i++){
		int a, b; 
		cin >> a >> b; 
		graph[a].push_back(b); 
		graph[b].push_back(a); 
	}

	cout << bfs(start) << endl; 

    return 0;
}