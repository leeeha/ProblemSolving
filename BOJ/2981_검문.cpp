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

	// 연속된 값의 차를 최소화 하기 위해 정렬 
	sort(v.begin(), v.end());

	int gcd = v[1] - v[0];
	for(int i = 2; i < n; i++) {
		// 인접한 두 수의 차이의 최대공약수 먼저 구하기 
		gcd = GCD(gcd, v[i] - v[i - 1]);  
	}

	// 위에서 구한 최대공약수의 약수 구하기 
	vector<int> divisor; 
	for(int i = 1; i <= gcd; i++){  
		if(gcd % i == 0){
			// 약수의 성질에 의해 중간까지만 확인하면 됨.  
			if(i > gcd / i) break;
			
			divisor.push_back(i); 

			if(i == gcd / i) break; // 제곱근이면 하나만 뽑고 멈추기 

			// 약수는 곱셈에 대해 대칭이니까 
			divisor.push_back(gcd / i); 
		}
	}

	// 오름차순 정렬 
	sort(divisor.begin(), divisor.end());

	// 첫번째 원소인 1은 제외하고 출력 
	for(int i = 1; i < divisor.size(); i++){
		cout << divisor[i] << " ";
	}

	return 0;
}