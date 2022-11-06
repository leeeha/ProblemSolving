#include <iostream>
#include <vector>
#include <algorithm> 
#define INF 1e9 
#define MAX 101 
using namespace std; 

int n, m;
int graph[MAX][MAX]; // a���� b�� ���� ��ΰ� ������ 1, ������ 0 

void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue; 
					
				// i���� k��, k���� j�� ���� ��ΰ� �ִµ� 
				else if(graph[i][k] != 0 && graph[k][j] != 0){
					// i���� j�� ���� ���� ��ΰ� ������ 
					if(graph[i][j] == 0){
						// k�� ���İ���. 
						graph[i][j] = graph[i][k] + graph[k][j];
					}else{ 
						// ���� ���� ��ΰ� ������ 
						// ���� ���� ��ο� ���̸� ���Ͽ� �ּڰ����� ���� 
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

	int result = INF; // �ּ� ������ �� 
	int person; // �ּ� �ɺ� ������ ���� ���� ��� ��ȣ  

	for(int i = 1; i <= n; i++){
		// i���� j�� ���� �ּ� ��� ���̸� ���Ѵ�.
		int sum = 0;
		for(int j = 1; j <= n; j++){
			sum += graph[i][j];
		}

		// �ּ� ������ ���� �� ���� ���� ��� ��ȣ ���� 
		if(result > sum){ 
			result = sum; 
			person = i; 
		}
	}

	cout << person;
	
	return 0;
} 