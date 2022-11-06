#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9 
#define MAX 501  
using namespace std; 

int n, m; 
vector<pair<int, pair<int, int>>> edges; 
long long d[MAX]; // ���� �÷ο� �� ��� �÷ο� ����

bool bellmanFord(int start){
	d[start] = 0; // ���� ��忡 ���� �ʱ�ȭ 

	// n-1���� ���� �ݺ� 
	for(int i = 0; i < n; i++){
		// �� �ݺ����� ��� ������ Ȯ���ϸ� 
		for(int j = 0; j < m; j++){
			int from = edges[j].first; 
			int to = edges[j].second.first; 
			int cost = edges[j].second.second;

			// ������ ������ ���� ������ ���� ���� �� �� ª���� 
			if(d[from] != INF && d[to] > d[from] + cost){
				d[to] = d[from] + cost; // �ִ� �Ÿ� ���̺� ���� 
				
				// n��° ���忡���� ���� ���ŵȴٸ� 
				// ���� ����Ŭ�� ���� 
				if(i == n - 1) return true; 
			}
		}
	}

	return false; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c; 
		edges.push_back({a, {b, c}}); 
	}
	
	fill_n(d, MAX, INF); 

	bool negativeCycle = bellmanFord(1);

	if(negativeCycle){
		cout << "-1\n";
		return 0; 
	}

	// 1���� ������ �ٸ� ��� ���� ���� ���� �ִ� �Ÿ� ��� 
	for(int i = 2; i <= n; i++){
		if(d[i] == INF){
			cout << "-1\n";
		}else{
			cout << d[i] << "\n"; 
		}
	}
	
	return 0; 
}