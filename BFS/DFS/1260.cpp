#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ���� ���� �ִ� 1000��
bool visited[1001]; 
vector<int> graph[1001];

void dfs(int x){
	visited[x] = true;
	cout << x << ' ';

	for(int i = 0; i < graph[x].size(); i++){
		int y = graph[x].at(i);
		if(!visited[y]) 
			dfs(y); // �湮 ó���� ���� ���� ��尡 ���� ������ ��� ȣ��
	}
}

void bfs(int start) {
	for(int i = 1; i <= 1000; i++){
		visited[i] = false; // dfs���� �湮 ó���ߴ� �� �ʱ�ȭ!
	}
	
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()){ // ť�� �� ������ �ݺ� 
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for(int i = 0; i < graph[x].size(); i++){
			int y = graph[x].at(i);
			if(!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	// ������ ���� N(1 �� N �� 1,000)
	// ������ ���� M(1 �� M �� 10,000)
	// Ž���� ������ ������ ��ȣ V 
	int n, m, v;
	cin >> n >> m >> v;

	// ���� ������ŭ ��峢�� ����� ���� 
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		
		graph[x].push_back(y);
		graph[y].push_back(x); // ����� ����
	}

	// �� ��忡 ����� ���� ���� ���� �߿��� ���� ��ȣ���� �湮�ϵ��� �������� ����!
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	
	bfs(v);
	cout << "\n";
	
	return 0;
}