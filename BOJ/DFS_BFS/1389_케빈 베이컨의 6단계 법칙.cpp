#include <iostream>
#include <vector>
#include <algorithm> 
#define INF 1e9 
#define MAX 101 
using namespace std; 

int n, m;
int graph[MAX][MAX]; // a에서 b로 가는 경로가 있으면 1, 없으면 0 

void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue; 
					
				// i에서 k로, k에서 j로 가는 경로가 있는데 
				else if(graph[i][k] != 0 && graph[k][j] != 0){
					// i에서 j로 직접 가는 경로가 없으면 
					if(graph[i][j] == 0){
						// k를 거쳐간다. 
						graph[i][j] = graph[i][k] + graph[k][j];
					}else{ 
						// 직접 가는 경로가 있으면 
						// 거쳐 가는 경로와 길이를 비교하여 최솟값으로 저장 
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 
					}
				}
			}
		}
	}
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

	floyd(); 

	int result = INF; // 최소 베이컨 수 
	int person; // 최소 케빈 베이컨 수를 갖는 사람 번호  

	for(int i = 1; i <= n; i++){
		// i에서 j로 가는 최소 경로 길이를 더한다.
		int sum = 0;
		for(int j = 1; j <= n; j++){
			sum += graph[i][j];
		}

		// 최소 베이컨 수와 그 수를 갖는 사람 번호 갱신 
		if(result > sum){ 
			result = sum; 
			person = i; 
		}
	}

	cout << person;
	
	return 0;
} 