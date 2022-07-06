#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cmath> 
using namespace std;

typedef long long ll;
ll arr[5001];
ll ans[3];

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}

	sort(arr, arr + n);

	ll min = 3e9; 
	for(int i = 0; i < n - 2; i++){
		int left = i + 1;
		int right = n - 1;
		
		while(left < right){
			ll sum = arr[i] + arr[left] + arr[right];
			if(abs(sum) < min){
				min = abs(sum); // ÃÖ¼Ú°ª °»½Å 
				ans[0] = arr[i];
				ans[1] = arr[left];
				ans[2] = arr[right];
			}

			if(sum < 0) left++;
			else right--;
		}
	}

	for(int i = 0; i < 3; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
