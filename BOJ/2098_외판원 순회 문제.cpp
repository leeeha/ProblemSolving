#include <iostream>
#define INF 1e9 
using namespace std; 

int N, END;
int cost[16][16];
int dp[16][1 << 16]; 

int TSP(int now, int visited){
	// ��� ��带 �湮�ߴµ� 
	if(visited == END){
		// ���� ��忡�� 0������ ���� ��ΰ� ������ 
		if(cost[now][0] > 0){ 
			return cost[now][0]; // �ּ� ��� ��ȯ 
		}

		return INF; // �Ұ����� ��쿡�� INF ��ȯ 
	}

	// ���� ���¸� �̹� ����� ���� dp ���̺� �ִٸ� �״�� ���
	if(dp[now][visited] != 0) return dp[now][visited];

	// ������ ���� ��忡 ���� Ž�� ���� 
	dp[now][visited] = INF; 
    
	for(int i = 0; i < N; i++){
		// ���� ��忡�� i�� ���� ���� ��ΰ� ������ �н�
		if(cost[now][i] == 0) continue;
        
		// �̹� �湮�� ���� �н� 
		if(visited & (1 << i)) continue;

		// i�� ��� �湮 ó�� �� �ּ� ��� ��ȯ 
		int temp = TSP(i, visited | 1 << i); 
		dp[now][visited] = min(dp[now][visited], cost[now][i] + temp); 
	}

	return dp[now][visited]; // �ּ� ��� ��ȯ 
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> N;
	END = (1 << N) - 1;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> cost[i][j]; 
		}
	}
	
	// 0�� ������ �׷��� Ž�� 
	cout << TSP(0, 1) << "\n"; 

	return 0;
}