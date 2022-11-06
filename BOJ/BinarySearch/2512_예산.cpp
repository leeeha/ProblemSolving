#include <iostream>
#include <algorithm>
using namespace std; 

int n, m; 
int arr[10001];
int answer = 0; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
	cin >> m;

	sort(arr, arr + n);
	int start = 0; 
	int end = arr[n - 1];

	while(start <= end){
		int sum = 0;
		int mid = (start + end) / 2;
		
		for(int i = 0; i < n; i++){
			sum += min(arr[i], mid);
		}

		// ������ ������ m�� ���� ������ 
		if(sum <= m){
			answer = mid; // ���� ���� 
            
            // ���Ѿ��� �ִ��� ���ϱ� ���� �������� �̵� 
			start = mid + 1; 
		}else{
        	// ���Ѿ���  ���̱� ���� �������� �̵� 
			end = mid - 1; 
		}
	}

	cout << answer; 
	
	return 0;
}