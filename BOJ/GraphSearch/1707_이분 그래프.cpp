#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 20001 
#define RED 1
#define BLUE 2
using namespace std;

int v, e; 
vector<int> graph[MAX]; 
int colored[MAX]; 

void bfs(int start){
	queue<int> q; 
	q.push(start); 
	colored[start] = RED; 

	while(!q.empty()){ 
		int x = q.front(); 
		q.pop(); 

		// ť���� ���� ���� red�� blue �߿� �ϳ� 
		int color = 0; 
		if(colored[x] == RED){ 
			color = BLUE; 
		}else{
			color = RED; 
		}

		// ������ �����ε� ���� ������ ���� ���, �ݴ�Ǵ� �������� ĥ�ϱ� 
		for(int i = 0; i < graph[x].size(); i++){
			int y = graph[x][i]; 
			if(!colored[y]){
				q.push(y); 
				colored[y] = color; 
			}
		}
	}
}

void dfs(int x){
	if(!colored[x]){ 
		colored[x] = RED; 
	}

	int color = 0; 
	if(colored[x] == RED){ 
		color = BLUE;
	}else {
		color = RED; 
	}

	for(int i = 0; i < graph[x].size(); i++){ 
		int y = graph[x][i]; 
		if(!colored[y]){ 
			colored[y] = color;
			dfs(y); 
		}
	}
}

bool isBipartite(){
	// �׷����� ��ȸ�ϸ鼭 
	// ������ ������ �ٸ� �������� ĥ�����ִ��� �˻� 
	for(int i = 1; i <= v; i++){
		for(int j = 0; j < graph[i].size(); j++){
			int next = graph[i][j];

			// i��° ������ ����� ��� ������ ���� �ٸ� �����̸� �̺� �׷��� 
			// �ϳ��� ���� ������ ������ �̺� �׷��� x 
			if(colored[i] == colored[next]){
				return false; 
			}
		}
	}
	return true; 
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int k;
	cin >> k; 

	while(k--){
		cin >> v >> e; 

		for(int i = 0; i < e; i++){
			int x, y; 
			cin >> x >> y; 
			graph[x].push_back(y); 
			graph[y].push_back(x); 
		}

		// 1~v������ ������ ������ ���� �ٸ� �������� �����Ѵ�. 
		// �ѹ� ��ĥ�� �� �� ��ŵ�Ѵ�. 
		for(int i = 1; i <= v; i++){
			if(!colored[i]){
				dfs(i); 
			}
		}

		if(isBipartite()) cout << "YES\n";
		else cout << "NO\n";

		memset(graph, 0, sizeof(graph));
		memset(colored, 0, sizeof(colored));
	}

    return 0;
}

