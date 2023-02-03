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

	// max�� 0���� �ʱ�ȭ �ϸ�, �迭�� ��� ���� 0�� �� max ���� ������Ʈ ���� �����Ƿ� 
	// �ִ��� ��ġ�� ������� �ʴ´�. max�� 0���� �ʱ�ȭ �ϸ� �� �ȴ�! 
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