/**
위상 정렬
사이클이 없는 방향 그래프 (DAG, directed acyclic graph)의 모든 노드를 
방향성에 거스르지 않도록 순서대로 나열하는 것

- 위상 정렬은 DAG (순환하지 않는 방향 그래프)에 대해서만 수행할 수 있다.
- 위상 정렬에는 여러가지 답이 존재할 수 있다. 한 단계에서 큐에 새롭게 들어가는 원소가 2개 이상이면, 넣는 순서에 따라 여러가지 답이 나올 수 있다.
- 모든 원소를 방문하기 전에 큐가 빈다면 사이클 존재한다고 판단 (사이클에 포함된 모든 원소는 진입차수가 1 이상이므로 큐에 넣을 수 없으므로) 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; 

int v, e; // 노드 개수, 간선 개수 
int indegree[100001]; // 노드 개수 최대 10만개 
vector<int> graph[100001]; // 각 노드에 연결된 노드 번호 저장 

void topologySort(){
	vector<int> result; // 정렬 결과를 저장 
	queue<int> q; 

	// 진입차수가 0인 노드를 큐에 삽입 
	for(int i = 1; i <= v; i++){
		if(indegree[i] == 0){
			q.push(i); 
		}
	}

	while(!q.empty()){
		int now = q.front();
		q.pop(); 
		result.push_back(now); 

		// 해당 원소와 연결된 노드들의 진입차수에서 1 빼기 (간선 제거)
		for(int i = 0; i < graph[now].size(); i++){
			indegree[graph[now][i]] -= 1; 

			// 새롭게 진입차수가 0이 되는 노드들을 큐에 삽입
			if(indegree[graph[now][i]] == 0){
				q.push(graph[now][i]);
			}
		}
	}

	// 위상 정렬을 수행한 결과 출력 
	for(auto e: result) 
		cout << e << " "; 
	cout << "\n"; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	// DAG의 모든 간선 정보 입력 받기 
	for(int i = 0; i < e; i++){
		int a, b;
		cin >> a >> b; 
		graph[a].push_back(b); // 정점 a에서 b로 이동 가능
		indegree[b] += 1; // b의 진입차수 증가 
	}

	topologySort(); 
	
	return 0;
} 