#include <iostream>
#include <string> 
#include <algorithm> 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b; 
	cin >> a >> b; 

	int lenA = a.length(); 
	int lenB = b.length(); 

	// A�� �ڸ����� ũ���� 
	if(lenB > lenA){
		swap(a, b);
		swap(lenA, lenB);
	}

	// B�� �ڸ����� �� ������ 0���� ���߱� 
	string temp = "";
	if(lenA != lenB){
		for(int i = 0; i < lenA - lenB; i++){
			temp += "0";
		}
	}
	b = temp + b; 

	// ���ڸ����� �ϳ��� ���ϱ� 
	string ans = "";
	int carry = 0;
	for(int i = lenA - 1; i >= 0; i--){
		int sum = (a[i] - '0') + (b[i] - '0') + carry; 
		if(sum < 0) sum += '0';
		if(sum > 9) carry = 1; 
		else carry = 0; 
		ans += sum % 10 + '0'; 
	}

	if(carry == 1) ans += "1";

	for(int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i]; 
	}
	
	return 0;
}