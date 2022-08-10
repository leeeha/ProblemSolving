#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <cstring> 
#define INF 1e9 
#define MAX 101 
using namespace std; 

int n, m;
int graph[MAX][MAX]; // a���� b�� ���� ��ΰ� ������ 1, ������ 0 
int pathLength[MAX]; // i���� �ڱ� �ڽ��� ������ ��� �������� ��� ���̸� �����ϴ� �迭 
int result[MAX]; // pathLength�� ��� ���ؼ�, �� ����� ���� �ɺ� ������ ���� �����ϴ� �迭 
bool visited[MAX]; 

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()){
		int i = q.front(); 
		q.pop();

		for(int j = 1; j <= n; j++){
			// i���� j�� ���� ��ΰ� �ִµ� ���� �湮���� ���� ��� 
			if(graph[i][j] == 1 && visited[j] == false){
				// �湮 ó�� 
				visited[j] = true;
				q.push(j);
				
				// i���� j������ ��� ���� ���� 
				pathLength[j] = pathLength[i] + 1; 
			}
		}
	}
}

int getMinPerson(){
	int bacon = result[1]; // �ɺ� �������� ��  
	int person = 1; // �ּ� �ɺ� �������� ���� ���� ��� ��ȣ 
	
	for(int i = 2; i <= n; i++){ 
		if(bacon > result[i]){ 
			bacon = result[i]; 
			person = i; 
		}
	}

	return person;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1; 
	}

	for(int i = 1; i <= n; i++){
		bfs(i);

		// i���� �ڱ� �ڽ��� ������ ��� ��� j������ ��� ���̸� �� ���ؼ� 
		// �� ����� ���� �ɺ� �������� �� ���ϱ� 
		for(int j = 1; j <= n; j++){ 
			if(i == j) continue;
			result[i] += pathLength[j]; 
		}

		// �� ����� ���� ������ �ʱ�ȭ 
		memset(visited, false, sizeof(visited));
		memset(pathLength, 0, sizeof(pathLength));
	}

	// �ּ� �ɺ� �������� ���� ���� ��� ��ȣ ��� 
	cout << getMinPerson(); 
	
	return 0;
} 