#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int GCD(int a, int b){
	if(a % b == 0){
		return b;
	}else{
		return GCD(b, a % b);
	}
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	// ���ӵ� ���� ���� �ּ�ȭ �ϱ� ���� ���� 
	sort(v.begin(), v.end());

	int gcd = v[1] - v[0];
	for(int i = 2; i < n; i++) {
		// ������ �� ���� ������ �ִ����� ���� ���ϱ� 
		gcd = GCD(gcd, v[i] - v[i - 1]);  
	}

	// ������ ���� �ִ������� ��� ���ϱ� 
	vector<int> divisor; 
	for(int i = 1; i <= gcd; i++){  
		if(gcd % i == 0){
			// ����� ������ ���� �߰������� Ȯ���ϸ� ��.  
			if(i > gcd / i) break;
			
			divisor.push_back(i); 

			if(i == gcd / i) break; // �������̸� �ϳ��� �̰� ���߱� 

			// ����� ������ ���� ��Ī�̴ϱ� 
			divisor.push_back(gcd / i); 
		}
	}

	// �������� ���� 
	sort(divisor.begin(), divisor.end());

	// ù��° ������ 1�� �����ϰ� ��� 
	for(int i = 1; i < divisor.size(); i++){
		cout << divisor[i] << " ";
	}

	return 0;
}