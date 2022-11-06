#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define MAX 100001  
using namespace std; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; // �����̿� ������ ��ġ 
	cin >> n >> k;

	int minTime[MAX]; // �� ��ǥ�� �����ϴ� �ּ� �ð� ���� 
	for(int i = 0; i < MAX; i++){ 
		minTime[i] = 1e9; 
	}

	queue<pair<int, int>> q; // {������ ��ġ, �ش� �������� �ɸ� �ð�}
	q.push({ n, 0 }); 
	minTime[n] = 0; 

	while(!q.empty()){
		int x = q.front().first; 
		int time = q.front().second; 
		q.pop(); 

		vector<int> nextX = { x + 1, x - 1, x * 2 };
		for(int i = 0; i < 3; i++){
			if(0 <= nextX[i] && nextX[i] < MAX) {
				int tempTime = time; 
				if(i != 2) tempTime++; 
				
				if(minTime[nextX[i]] > tempTime){
					minTime[nextX[i]] = tempTime;
					q.push({ nextX[i], tempTime });  
				}
			}
		}
	}

	// n���� k���� �����ϴ� �� �ɸ� �ּ� �ð� ��� 
	cout << minTime[k]; 
	
	return 0; 
} 