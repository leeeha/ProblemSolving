#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
#define MAX 101
using namespace std;
typedef pair<int, int> pii; 

int map[MAX]; 
bool visited[MAX];

void bfs(int x){
	queue<pii> q; 
	q.push({x, 0}); // ĭ�� ��ȣ, �ֻ����� ���� Ƚ�� 
	visited[x] = true; 

	while(!q.empty()){ 
		int pos = q.front().first; 
		int cnt = q.front().second; 
		q.pop(); 

		if(pos == 100){
			cout << cnt << endl; 
			break; 
		}

		// �ֻ��� �� 1~6���� ��� ����� ���� ������. 
		for(int i = 1; i <= 6; i++){
			// ���ο� ��ġ�� ���� 
			int npos = pos + i; 

			// ���� üũ 
			if(npos > 100) continue;

			// �� �Ǵ� ��ٸ��� ��ġ�� ��ġ���� Ȯ��  
			if(map[npos] != 0){ 
				npos = map[npos]; 
			}
				
			// �湮���� �ʾҴ� ĭ�� ��� �湮 ó�� 
			if(!visited[npos]){ 
				q.push({npos, cnt + 1}); 
				visited[npos] = true;  
			} 
		}
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int n, m; 
	cin >> n >> m; 

	int x, y; 
	for(int i = 0; i < n; i++){
		cin >> x >> y; 
		map[x] = y; 
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		map[x] = y; 
	}

	bfs(1); 
	
    return 0;
}

