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

		// 예산의 총합이 m을 넘지 않으면 
		if(sum <= m){
			answer = mid; // 정답 갱신 
            
            // 상한액의 최댓값을 구하기 위해 뒤쪽으로 이동 
			start = mid + 1; 
		}else{
        	// 상한액을  줄이기 위해 앞쪽으로 이동 
			end = mid - 1; 
		}
	}

	cout << answer; 
	
	return 0;
}