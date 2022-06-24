// �ִ����� (Greatest Common Divisor, GCD) 
// �ּҰ���� (Least Common Multiple, LCM) 
#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(a % b == 0){
		return b;
	}else{
		return gcd(b, a % b); // ��� ȣ�� 
	}
}

int main() {
	int a, b; // 10,000������ �ڿ���
	cin >> a >> b;

	// GCD (��Ŭ���� ȣ����)
	int G = gcd(a, b);
	
	// LCM <- AB / GCD 
	int L = (a * b) / G;

	cout << G << "\n" << L;
	
	return 0;
}