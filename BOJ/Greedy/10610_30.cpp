#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str; 

	// 내림차순 정렬 
	sort(str.begin(), str.end(), greater<>());

	// 일의 자리가 0이 아니면 종료 
	if(str.back() != '0') { 
		cout << "-1\n";
		return 0; 
	}

	// 모든 자리수의 합이 3의 배수인지 확인 
	int sum = 0; 
	for(auto e: str){ // 최대 10만개 
		sum += e - '0'; // char to int 
	}
	
	if(sum % 3 == 0){
		cout << str; 
	}else {
		cout << "-1\n";
	}
	
	return 0; 
}