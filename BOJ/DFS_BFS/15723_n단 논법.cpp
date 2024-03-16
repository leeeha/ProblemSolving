#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll; 
typedef pair<int, int> pii;

const int MAX = 60; 
vector<int> graph[MAX]; // 유향 그래프 
bool visited[MAX];
int N, M; // 전제, 결론 개수
bool connected = false; 

pii extractNodeNumber(string str) {
	string start = str.substr(0, 1);
	string end = str.substr(5, 1);
	int s = start[0] - 'a';
	int e = end[0] - 'a';
	return {s, e};
}

void dfs(int start, int end) {
	if(start == end){
		connected = true;
		return;
	}
	
	visited[start] = true;
	for(int i = 0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if(!visited[next]){
			dfs(next, end);
		}
	}
}

void solution() {
	cin >> N;
	cin.ignore(); // 입력 버퍼 비우기

	for(int i = 0; i < N; i++){
		string premise;
		getline(cin, premise);

		pii node = extractNodeNumber(premise);
		graph[node.first].push_back(node.second);
	}

	cin >> M;
	cin.ignore(); // 입력 버퍼 비우기

	for(int i = 0; i < M; i++){
		string conclusion; 
		getline(cin, conclusion);

		pii node = extractNodeNumber(conclusion);

		// start -> end 연결되어 있는지 확인
		dfs(node.first, node.second);
		
		if(connected){
			cout << "T\n";
		}else{
			cout << "F\n";
		}

		// 각 케이스마다 전역 데이터 초기화 필수 
		connected = false;
		memset(visited, 0, sizeof(visited));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solution(); 
	
	return 0;
}
