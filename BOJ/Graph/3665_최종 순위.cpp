#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 501; 
int T, N, M;
int rk[MAX]; // 작년 팀의 순위 
int in[MAX]; // 각 팀의 진입차수 
int graph[MAX][MAX]; // 인접 행렬 
vector<int> ans; // 올해 팀의 순위 
bool flag = false; 

// 자신보다 높은 순위의 노드와 연결 
void makeGraph(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j < i; j++){
			graph[rk[i]][rk[j]] = 1; 
			in[rk[j]]++; 
		}
	}
}

void swapRank(int a, int b){
	// a -> b (a보다 b의 순위가 높은 경우)
	if(graph[a][b] == 1){
		// 간선 방향 뒤집기 b -> a
		graph[a][b] = 0; 
		graph[b][a] = 1; 

		// 진입차수 갱신 
		in[b]--; 
		in[a]++; 
	}
	// b -> a (b보다 a의 순위가 높은 경우)
	else if(graph[b][a] == 1){
		// a -> b 
		graph[b][a] = 0;
		graph[a][b] = 1;
		in[a]--; 
		in[b]++; 
	}
}

void printAnswer(){
	for(int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

void initData(){
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			graph[i][j] = 0; 
		}
	}

	for(int i = 0; i <= N; i++){
		rk[i] = 0;
		in[i] = 0;
	}

	flag = false;
	ans.clear();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T; 

	while(T--){
		cin >> N;

		// 작년 팀의 순위 입력
		for(int i = 1; i <= N; i++){
			cin >> rk[i];
		}

		makeGraph();

		cin >> M;
		for(int i = 0; i < M; i++){
			int a, b; 
			cin >> a >> b;
			swapRank(a, b);
		}

		queue<int> q;
		for(int i = 1; i <= N; i++){
			if(in[i] == 0){
				q.push(i);
			}
		}

		while(!q.empty()){
        	// 진입차수가 0인 노드가 여러 개인지 검사 
			if(q.size() > 1) flag = true;
			
			int now = q.front(); 
			q.pop();
			ans.push_back(now);

			for(int i = 1; i <= N; i++){
				if(graph[now][i] == 1){
					in[i]--; 
					if(in[i] == 0){
						q.push(i);
					}
				}
			}
		}

		// 모든 노드를 처리하지 않았는데 큐가 비었다면 사이클 존재 
		if(ans.size() < N) cout << "IMPOSSIBLE\n";
		else if(flag) cout << "?\n";
		else{
			printAnswer();
		}

		initData();
	}
	
	return 0;
}