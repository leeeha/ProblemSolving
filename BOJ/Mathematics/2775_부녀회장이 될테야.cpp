#include <iostream>
#include <vector>
#include <cstring> 
#include <algorithm> 
#include <utility>
using namespace std;

const int MAX = 15;  
int arr[MAX][MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t; 

	while(t--){
		int k, n; 
		cin >> k >> n; 

		for(int j = 1; j <= n; j++){ 
			arr[0][j] = j; 
		}

		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				// �Ʒ����� 1ȣ���� jȣ������ ��� �� ���ϱ� 
				for(int l = 1; l <= j; l++){
					arr[i][j] += arr[i-1][l]; 
				}
			}
		}

		cout << arr[k][n] << "\n"; 

		// �迭 �ʱ�ȭ 
		memset(arr, 0, sizeof(arr)); 
	}
	
	return 0;
}