#include <iostream>
#include <queue>
#include <utility> // pair

#define MAX 1000
using namespace std;

int n, m; // n�� m�� 

// �Է����� ������ �� ���� ����  
int graph[MAX][MAX];

// �� �ı� ���ο� ���� �޶����� �ִ� �Ÿ��� ���� ����
int count[MAX][MAX][2]; // 0�� unbroken, 1�� broken 

// �����¿� Ž�� (���� x�� ����, ���� y�� ����)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// ����� ������ ���� Ž���ϴ� BFS 
int bfs(int x, int y){
	// { {x,y}, broken }
	queue<pair<pair<int, int>, bool>> q;
	q.push({{x, y}, false});
	count[x][y][0] = 1; // ���� �μ��� ���� ����(0)�� �ִ� �Ÿ��� 1�� �ʱ�ȭ
	
	// ť�� �� ������ �ݺ�! 
	while(!q.empty()){ 
		auto Q = q.front();
		int x = Q.first.first;
		int y = Q.first.second;
		bool broken = Q.second;
		q.pop();

		// (n, m) �������� �����ϸ�, ���� broken ���¿� ���� �ִ� �Ÿ� ����!
		if(x == n - 1 && y == m - 1){
			return count[x][y][broken];
		}

		// BFS: �����¿�� �̵��� �� �ִ��� Ž�� 
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			// ���� ������ ��� ��� ����
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// ���� �����µ�, ���� ���� �ѹ��� �μ��� ���� ��� 
			if(graph[nx][ny] == 1 && broken == false){
            	// ���� �μ� ����(1)�� �ִ� �Ÿ� ������Ʈ
				count[nx][ny][1] = count[x][y][0] + 1;
                
				// ���� ������ broken ���¸� true�� ����!
				q.push({{nx, ny}, true});
			}
			// ���� ����, �ѹ��� �湮���� ���� ���̶��  
			else if(graph[nx][ny] == 0 && count[nx][ny][broken] == 0){
            	// �ִ� �Ÿ� ������Ʈ 
				count[nx][ny][broken] = count[x][y][broken] + 1;
                
            	// ���� ��ġ�� �̵� (broken ���´� �״��)
				q.push({{nx,ny}, broken}); 
			}
		}
	}
	
	return -1;
}

int main()
{	
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &graph[i][j]);
		}
	}

	/** ���ڿ��� �Է� �޴� ��� 
	for (int i = 0; i < n; i++){
        string s;
        cin >> s;

		// char to int 
        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';
        }
    }
	*/

	cout << bfs(0, 0) << "\n";

	return 0;
}