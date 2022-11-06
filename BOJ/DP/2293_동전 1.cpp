#include <iostream>
#include <vector>
using namespace std;

int dp[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}

	dp[0] = 1; 

	// ������ �������� �ִ� k������ ����� ���� ���ŵȴ�.
	for(int i = 1; i <= n; i++){
		// ������ ũ�⸦ ù��° ���� ũ����� k������ 1�� �ø��鼭 
		for(int j = v[i]; j <= k; j++){
			// ��ȭ�Ŀ� ���� ���̺� ���� 
			dp[j] += dp[j - v[i]]; 
		}
	}

	cout << dp[k]; 
	
	return 0;
}