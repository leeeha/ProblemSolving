#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int n;
int arr[1001]; 
int lDP[1001];
int rDP[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		lDP[i] = 1;
		rDP[i] = 1; 
	}
	
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		
		// i보다 앞쪽에 있으면서  
		for (int j = 0; j < i; j++) {
			// i번째 값보다 작은 원소들 중에 
			if (arr[j] < arr[i]) {
				// dp 값이 가장 큰 값을 저장 
				tmp = max(tmp, lDP[j]);
			}
		}

		// 거기에 1을 더해서 i번째 dp값 갱신
		lDP[i] = tmp + 1; 
	}

	for(int i = n - 1; i >= 0; i--){
		int tmp = 0;

		// i보다 뒤쪽에 있으면서 
		for(int j = n - 1; j >= i; j--){ 
			// i번째 값보다 작은 원소들 중에 
			if(arr[j] < arr[i]){ 
				// dp 값이 가장 큰 값을 저장 
				tmp = max(tmp, rDP[j]);
			}
		}
		
		// 거기에 1을 더해서 i번째 dp값 갱신
		rDP[i] = tmp + 1; 
	}

	int ans = 0; 
	for(int i = 0; i < n; i++){
		ans = max(ans, lDP[i] + rDP[i] - 1);
	}

	cout << ans; 

	return 0;
}