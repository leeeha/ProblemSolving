#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 100001
using namespace std;

int n, k;
bool visited[MAX]; 

void bfs(int x){
	queue<pair<int, int>> q; // (x좌표, 도달 시간)
	q.push({x, 0}); 
	visited[x] = true; 

	while(!q.empty()){
		int pos = q.front().first; 
		int time = q.front().second;
		q.pop(); 

		if(pos == k){ 
			cout << time << endl; 
			break; 
		}

		if(pos + 1 >= 0 && pos + 1 < MAX){
			if(!visited[pos + 1]){
				q.push({pos + 1, time + 1}); 
				visited[pos + 1] = true; 
			}
		}

		if(pos - 1 >= 0 && pos - 1 < MAX){
			if(!visited[pos - 1]){
				q.push({pos - 1, time + 1});
				visited[pos - 1] = true; 
			}
		}

		if(2 * pos >= 0 && 2 * pos < MAX){
			if(!visited[2 * pos]){
				q.push({2 * pos, time + 1});
				visited[2 * pos] = true; 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> n >> k; 
	bfs(n); 

    return 0;
}

