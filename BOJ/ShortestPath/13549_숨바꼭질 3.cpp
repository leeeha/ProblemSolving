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

	int n, k; // 수빈이와 동생의 위치 
	cin >> n >> k;

	int minTime[MAX]; // 각 좌표에 도달하는 최소 시간 저장 
	for(int i = 0; i < MAX; i++){ 
		minTime[i] = 1e9; 
	}

	queue<pair<int, int>> q; // {수빈의 위치, 해당 지점까지 걸린 시간}
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

	// n에서 k까지 도달하는 데 걸린 최소 시간 출력 
	cout << minTime[k]; 
	
	return 0; 
} 