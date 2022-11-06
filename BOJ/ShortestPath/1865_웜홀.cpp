#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 1e9 
#define MAX 501 
using namespace std; 

int n, m, w; // ���, ����, ��Ȧ ���� 
int s, e, t; // ����, ��, ����ġ 
vector<pair<int, pair<int, int>>> edges; 
long long d[MAX]; // �ִ� �Ÿ� ���̺� 

bool bellmanFord(){ 
	d[1] = 0; // ���� ��带 1������ ���� 
	
	// (n-1)���� ���� �ݺ� 
	for(int i = 0; i < n; i++){ 
		// �� �ݺ����� '��� ����'�� �ϳ��� Ȯ���Ѵ�. 
		for(int j = 0; j < edges.size(); j++){ // ���ο� ��Ȧ ��� ���� 
			int from = edges[j].first; 
			int to = edges[j].second.first; 
			int cost = edges[j].second.second;
            
            //if(d[from] == INF) continue; 
			
			// ���� ������ ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ��� 
			if(d[to] > d[from] + cost){ 
				d[to] = d[from] + cost; // �ִ� �Ÿ� ���̺� ���� 
				
				// n��°���� �ִ� �Ÿ��� ���ŵȴٸ� ���� ����Ŭ ����!  
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

	int tc; 
	cin >> tc;
	
	while(tc--){
		// �׽�Ʈ ���̽����� �ʱ� ������ �ʱ�ȭ 
		fill_n(d, MAX, -1); 
		edges.clear(); 
		
		cin >> n >> m >> w; 

		// ���δ� �����, ��� ���� 
		for(int i = 0; i < m; i++){
			cin >> s >> e >> t;
			edges.push_back({s, {e, t}}); 
			edges.push_back({e, {s, t}}); 
		}

		// ��Ȧ�� �ܹ���, ���� ���� 
		for(int i = 0; i < w; i++){ 
			cin >> s >> e >> t; 
			edges.push_back({s, {e, -t}}); 
		}

		// ���� ����Ŭ�� �����ϴ��� Ȯ��
		if(bellmanFord()) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0; 
}
