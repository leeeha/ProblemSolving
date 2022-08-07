#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> arr;
vector<int> dp; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// ó�� 3���� 0���� �ʱ�ȭ 
	for(int i = 0; i < 3; i++){
		arr.push_back(0);
		dp.push_back(0);
	}

	// �� �������� �� ���� 
	for(int i = 0; i < n; i++){
		int val; 
		cin >> val;
		arr.push_back(val); 
	}

	// �ε��� 3���� ���� 
	for(int i = 3; i < arr.size(); i++){ 
		// i��° ���� ������ �� 
		// (i-1)��° ���� ���� ���� �� ���� ��� �߿� �ִ� ���ϱ� 
		int temp = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);

		// i��° ���� ���� ���� �� ���� ��� �߿� �ִ� ���ؼ� �����ϱ�  
		dp.push_back(max(temp, dp[i-1]));
	}

	// ������ ���ұ��� ��� Ž������ ��, ���� �� �ִ� �ִ� �� ��� 
	cout << dp[arr.size() - 1]; 
	
	return 0;
}