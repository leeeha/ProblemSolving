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

	// �������� ���� 
	sort(str.begin(), str.end(), greater<>());

	// ���� �ڸ��� 0�� �ƴϸ� ���� 
	if(str.back() != '0') { 
		cout << "-1\n";
		return 0; 
	}

	// ��� �ڸ����� ���� 3�� ������� Ȯ�� 
	int sum = 0; 
	for(auto e: str){ // �ִ� 10���� 
		sum += e - '0'; // char to int 
	}
	
	if(sum % 3 == 0){
		cout << str; 
	}else {
		cout << "-1\n";
	}
	
	return 0; 
}