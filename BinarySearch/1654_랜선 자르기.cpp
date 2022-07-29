#include <iostream>
#include <algorithm> 
#include <vector>
typedef long long ll; 
using namespace std; 

int k, n; // 최대 1만, 100만 
ll arr[10001]; 
ll answer = 0; 

// x의 길이가 너무 크면, 개수가 n개를 안 넘고 
// x의 길이가 너무 작으면, 개수가 n개를 훌쩍 넘는다. 
bool decision(int x){ 
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += arr[i] / x; 
	}

	if(sum >= n){ 
		return true;
	}else{
		return false; 
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n; 

	for(int i = 0; i < k; i++){ 
		cin >> arr[i];
	}

	ll left = 1; 
	ll right = *max_element(arr, arr + k); 

	// 이진 탐색 진행 
	while(left <= right){
		ll mid = (left + right) / 2;

		// mid 길이로 자른 개수가 n개 이상이면
		if(decision(mid)){
			// x의 최댓값 갱신
			answer = max(answer, mid);

			// x의 길이를 더 늘려서, 개수를 줄인다.
			left = mid + 1; 
		}else{ 
			// 자른 개수가 n개 미만이면 
			// x의 길이를 더 줄여서, 개수를 늘린다. 
			right = mid - 1;
		}
	}

	cout << answer; 

	return 0;
}
