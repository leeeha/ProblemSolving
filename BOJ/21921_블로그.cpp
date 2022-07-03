#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, x;
	cin >> n >> x; // �ִ� 25�� (x�� ������ ũ��) 

	vector<int> v(n+1); 
	for(int i = 1; i <= n; i++){ 
		cin >> v[i]; // �ִ� 8õ 
	}

	// 1. x�� ���� �ִ� �湮�� �� (0���̸� SAD ���)
	// 2. 1���� 0���� �ƴϸ�, �� �ִ� �湮�� ���� �޼��� �Ⱓ�� �� ������! 
	ll sum = 0;
	vector<ll> psum; 
	for(int i = 1; i <= n; i++){
		if(i > x){ // �ε����� x�� �Ѿ�� 
			sum -= v[i - x]; // ũ�Ⱑ x�� �������� ������ �ڸ��� 
		}
		sum += v[i]; // �����ʿ� ���ο� ���� ���̱� 
		psum.push_back(sum);
	}

	ll max = *max_element(psum.begin(), psum.end());
	if(max != 0){
		cout << max << "\n";

		int cnt = 0;
		for(int i = 0; i < psum.size(); i++){ // �ִ� 25�� 
			if(psum[i] == max) cnt++; 
		}
		cout << cnt << "\n"; // max�� ���� Ƚ�� 
	}else{
		cout << "SAD\n";
	}
	
	return 0;
}

