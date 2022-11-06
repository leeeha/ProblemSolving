#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001]; 
int dp[1001]; 
int maxLength = 0; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
	
	for (int i = 0; i < n; i++) {
		int tmp = 0;

		// i���� ���ʿ� �����鼭  
		for (int j = 0; j < i; j++) {
			// i��° ������ ���� ���ҵ� �߿� 
			if (arr[j] < arr[i]) {
				// dp ���� ���� ū ���� ���� 
				tmp = max(tmp, dp[j]);
			}
		}
		
		dp[i] = tmp + 1; // �ű⿡ 1�� ���ؼ� i��° dp�� ���� 
	    maxLength = max(dp[i], maxLength); // dp ���̺��� �ִ��� ��!  
	}

	cout << maxLength; 
	
	return 0;
}