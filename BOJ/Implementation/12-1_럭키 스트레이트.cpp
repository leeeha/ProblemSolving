#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin >> str;

	int mid = str.size() / 2;

	int left = 0, right = 0;
	for(int i = 0; i < mid; i++){
		left += str[i] - '0'; // char에서 int로 변환하는 거 잊지 말기
	}
	for(int i = mid; i < str.size(); i++){
		right += str[i] - '0';
	}

	if(left == right)
		cout << "LUCKY\n";
	else
		cout << "READY\n";

    return 0;
}