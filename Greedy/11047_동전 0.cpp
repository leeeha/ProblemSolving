#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v; 
	for (int i = 0; i < n; i++) {
    	int coin;
		cin >> coin;
		v.push_back(coin); // ������������ �Է� 
	}

	int cnt = 0; // �ʿ��� �ּ� ������ ���� 
    
    // ū ȭ�� �������� �׸����ϰ� (Ž��������) �����Ѵ�. 
	for (int i = n - 1; i >= 0; i--) {  
		cnt += k / v[i];
		k %= v[i];
	}

	cout << cnt << "\n";

	return 0;
}