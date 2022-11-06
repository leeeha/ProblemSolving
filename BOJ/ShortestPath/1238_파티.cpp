#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9 
#define MAX 1001 
using namespace std; 

int n, m, x; 
vector<pair<int, int>> graph[MAX]; // ���� ���� ���� 
int d[MAX]; // �ִ� �Ÿ� ���̺� 
int res[MAX]; // �պ� �Ÿ� ���� 

void dijkstra(int start){
	priority_queue<pair<int, int>> pq; // �⺻������ �ִ� �� (first ��������)
	pq.push({ 0, start }); // �Ÿ�, ����ȣ 
	d[start] = 0; 

	while(!pq.empty()){
		int dist = -(pq.top().first); // �ִ� �Ÿ� 
		int now = pq.top().second; // ��� ��ȣ 
		pq.pop(); 

		// �ִ� �Ÿ� ���̺� ����� ���� �� ������ �Ѿ�� 
		if(dist > d[now]) continue; 

		for(int i = 0; i < graph[now].size(); i++){ 
			// ������ ������ ���İ��� ���� �� ������ ���� 
			int cost = dist + graph[now][i].second;
			if(cost < d[graph[now][i].first]){
				d[graph[now][i].first] = cost; 
				pq.push({ -cost, graph[now][i].first }); // �Ÿ�, ����ȣ 
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// ��� ���� �ִ� 1000�� 
	cin >> n >> m >> x; 
	
	for(int i = 0; i < m; i++){
		int a, b, c; 
		cin >> a >> b >> c; 
		graph[a].push_back({b, c}); 
	}

	for(int i = 1; i <= n; i++){
		fill_n(d, MAX, INF); // ���� ��尡 �ٲ� ������ �ʱ�ȭ 
		dijkstra(i); 
		res[i] = d[x]; // i���� x�� ���� �ִ� �Ÿ� 
	}

	fill_n(d, MAX, INF); // ���� ��尡 �����Ǿ� ������ �ѹ��� �ʱ�ȭ 
	dijkstra(x); 
	for(int i = 1; i <= n; i++){ 
		res[i] += d[i]; // x���� i�� ���ƿ��� �ִ� �Ÿ� 
	}

    // �� �߿��� �ִ� ���ϱ� 
	int ans = *max_element(res + 1, res + n + 1); 
	cout << ans; 
	
	return 0; 
}

