// 최대공약수 (Greatest Common Divisor, GCD) 
// 최소공배수 (Least Common Multiple, LCM) 
#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(a % b == 0){
		return b;
	}else{
		return gcd(b, a % b); // 재귀 호출 
	}
}

int main() {
	int a, b; // 10,000이하의 자연수
	cin >> a >> b;

	// GCD (유클리드 호제법)
	int G = gcd(a, b);
	
	// LCM <- AB / GCD 
	int L = (a * b) / G;

	cout << G << "\n" << L;
	
	return 0;
}