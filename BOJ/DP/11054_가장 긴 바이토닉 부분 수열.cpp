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
		
		// i���� ���ʿ� �����鼭  
		for (int j = 0; j < i; j++) {
			// i��° ������ ���� ���ҵ� �߿� 
			if (arr[j] < arr[i]) {
				// dp ���� ���� ū ���� ���� 
				tmp = max(tmp, lDP[j]);
			}
		}

		// �ű⿡ 1�� ���ؼ� i��° dp�� ����
		lDP[i] = tmp + 1; 
	}

	for(int i = n - 1; i >= 0; i--){
		int tmp = 0;

		// i���� ���ʿ� �����鼭 
		for(int j = n - 1; j >= i; j--){ 
			// i��° ������ ���� ���ҵ� �߿� 
			if(arr[j] < arr[i]){ 
				// dp ���� ���� ū ���� ���� 
				tmp = max(tmp, rDP[j]);
			}
		}
		
		// �ű⿡ 1�� ���ؼ� i��° dp�� ����
		rDP[i] = tmp + 1; 
	}

	int ans = 0; 
	for(int i = 0; i < n; i++){
		ans = max(ans, lDP[i] + rDP[i] - 1);
	}

	cout << ans; 

	return 0;
}