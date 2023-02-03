#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
using namespace std; 

const int n = 10; 

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int>> arr(n, vector<int>(n)); 
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){ 
			cin >> arr[i][j]; 
		}
	}

	// max를 0으로 초기화 하면, 배열의 모든 값이 0일 때 max 값이 업데이트 되지 않으므로 
	// 최댓값의 위치가 저장되지 않는다. max를 0으로 초기화 하면 안 된다! 
	int max = -1; 
	pair<int, int> pii; 
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){ 
			if(max < arr[i][j]){ 
				max = arr[i][j]; 
				pii = {i, j}; 
			}
		}
	}

	cout << max << "\n" << pii.first << " " << pii.second; 

    return 0;
}