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
	cin >> n >> x; // 최대 25만 (x는 윈도우 크기) 

	vector<int> v(n+1); 
	for(int i = 1; i <= n; i++){ 
		cin >> v[i]; // 최대 8천 
	}

	// 1. x일 동안 최대 방문자 수 (0명이면 SAD 출력)
	// 2. 1번이 0명이 아니면, 그 최대 방문자 수를 달성한 기간이 몇 번인지! 
	ll sum = 0;
	vector<ll> psum; 
	for(int i = 1; i <= n; i++){
		if(i > x){ // 인덱스가 x를 넘어가면 
			sum -= v[i - x]; // 크기가 x인 윈도우의 왼쪽을 자르고 
		}
		sum += v[i]; // 오른쪽에 새로운 원소 붙이기 
		psum.push_back(sum);
	}

	ll max = *max_element(psum.begin(), psum.end());
	if(max != 0){
		cout << max << "\n";

		int cnt = 0;
		for(int i = 0; i < psum.size(); i++){ // 최대 25만 
			if(psum[i] == max) cnt++; 
		}
		cout << cnt << "\n"; // max가 나온 횟수 
	}else{
		cout << "SAD\n";
	}
	
	return 0;
}

