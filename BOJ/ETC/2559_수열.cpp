#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, k;
	cin >> n >> k; // �ִ� 10�� (k�� ������ ũ��) 

	vector<int> v(n); 
	for(int i = 0; i < n; i++){ 
		cin >> v[i]; // -100 �̻� 100 ���� 
	}

	// �������� k�� ������ �µ��� �� �߿��� �ִ� ��� 
	int start = 0, sum = 0;
	int ans = -1e9; // ���ؼ� ������ ���� �����ϱ� �ʱⰪ �����ϱ�!!!! 
	for(int right = 0; right < n; right++){ 
		sum += v[right]; // �����ʿ� �߰� 
		if(right >= k - 1){ 
			ans = max(ans, sum); 
			sum -= v[start++]; // ���� �����̵�  
		} 
	}

	cout << ans;
	
	return 0;
}