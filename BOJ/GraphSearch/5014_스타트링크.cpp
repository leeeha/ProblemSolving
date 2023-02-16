#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 1000001
using namespace std;

int F, S, G, U, D; 
bool visited[MAX]; 

int bfs(int start){ 
	queue<pair<int, int>> q; // 현재위치, 이동횟수 
	q.push({start, 0}); 
	visited[start] = true; 

	while(!q.empty()){
		int x = q.front().first; 
		int cnt = q.front().second; 
		q.pop(); 

		if(x == G){ 
			return cnt; 
		} 

		if(x + U <= F){
			if(!visited[x + U]){
				q.push({x + U, cnt + 1});
				visited[x + U] = true;
			}
		}

		if(x - D >= 1){
			if(!visited[x - D]){ 
				q.push({x - D, cnt + 1});
				visited[x - D] = true; 
			} 
		}
	}

	return -1; 
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> F >> S >> G >> U >> D; 

	int result = bfs(S); 

	if(result == -1){
		cout << "use the stairs";
	}else{
		cout << result; 
	}

    return 0;
}

