#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9 
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

int n, m, k; 
vector<pii> graph[MAX]; // a���� b�� ���� ����� c 
int d[MAX]; // x�� ������ ������ 0, x������ ��θ� 1 

// x������ ��� ������ 'k�� ����'�� �����ϴ��� �����ϴ� �Լ� 
bool decision(int x){ 
	fill_n(d, MAX, INF); 
	priority_queue<pii> pq; 
	pq.push({ 0, 1 }); // ���, ����ȣ 
	d[1] = 0; 
	
	while(!pq.empty()){
		int cost = -pq.top().first; // -1���� 0�� ���� ������. 
		int now = pq.top().second; // ��� ��ȣ 
		pq.pop(); 
		
		// ���̺� ����� ���� �� ������ �Ѿ�� 
		if(d[now] < cost) continue; 

		// ���İ��� ��ΰ� �� ª���� �˻� 
		for(auto edge : graph[now]){
			int next = edge.first;
			int temp = edge.second > x; // x�� ���ϴ� 0, �׷��� ������ 1 
			int nextCost = cost + temp; 
			
			if(nextCost < d[next]){
				d[next] = nextCost; 
				pq.push({ -nextCost, next }); // �ּ� �� 
			}
		}
	}

	return d[n] <= k; 

	// ���̺� d���� 1�� ������ k�� ���ϸ� true 
	// int cnt = 0; 
	// for(int i = 0; i < n; i++){
	// 	if(d[i] == 1){
	// 		cnt++;
	// 	}
	// }
	// if(cnt <= k) return true;
	// else return false; 
}

int main() 
{
	// ���, ����, ��¥ ���̺��� ���� 
    cin >> n >> m >> k;
	
    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
		
		// ����� ������ ���� ����!!! 
		graph[s].push_back({e, t});
		graph[e].push_back({s, t});
    }

	int ans = -1; 
	int left = 0, right = 1e6; // ����� �ִ�
	while(left <= right){
		int mid = (left + right) / 2; 

		// ���� ������ ������Ű�� x�� �ּڰ��� ������. 
		if(decision(mid)){
			ans = mid; 
			right = mid - 1; // �ּڰ��� ���ϱ� ���ؼ� 
		}else{
			left = mid + 1; // true �������� �̵��ϵ��� 
		}
	}

	cout << ans; 
	
    return 0;
}
