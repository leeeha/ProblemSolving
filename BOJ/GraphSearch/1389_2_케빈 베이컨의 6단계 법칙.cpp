#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <cstring> 
#define INF 1e9 
#define MAX 101 
using namespace std; 

int n, m;
int graph[MAX][MAX]; // a에서 b로 가는 경로가 있으면 1, 없으면 0 
int pathLength[MAX]; // i에서 자기 자신을 제외한 모든 노드까지의 경로 길이를 저장하는 배열 
int result[MAX]; // pathLength를 모두 더해서, 각 사람에 대한 케빈 베이컨 수를 저장하는 배열 
bool visited[MAX]; 

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()){
		int i = q.front(); 
		q.pop();

		for(int j = 1; j <= n; j++){
			// i에서 j로 가는 경로가 있는데 아직 방문하지 않은 경우 
			if(graph[i][j] == 1 && visited[j] == false){
				// 방문 처리 
				visited[j] = true;
				q.push(j);
				
				// i에서 j까지의 경로 길이 갱신 
				pathLength[j] = pathLength[i] + 1; 
			}
		}
	}
}

int getMinPerson(){
	int bacon = result[1]; // 케빈 베이컨의 수  
	int person = 1; // 최소 케빈 베이컨의 수를 갖는 사람 번호 
	
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

		// i에서 자기 자신을 제외한 모든 노드 j까지의 경로 길이를 다 더해서 
		// 각 사람에 대한 케빈 베이컨의 수 구하기 
		for(int j = 1; j <= n; j++){ 
			if(i == j) continue;
			result[i] += pathLength[j]; 
		}

		// 각 사람에 대한 데이터 초기화 
		memset(visited, false, sizeof(visited));
		memset(pathLength, 0, sizeof(pathLength));
	}

	// 최소 케빈 베이컨의 수를 갖는 사람 번호 출력 
	cout << getMinPerson(); 
	
	return 0;
} 