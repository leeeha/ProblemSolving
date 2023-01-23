#include <iostream>
using namespace std;

int hansoo(int num){
	if(num < 100) return num; 

	int cnt = 99; 
	for(int i = 100; i <= num; i++){
		int a, b, c; 
		a = i / 100; 
		b = i % 100 / 10; 
		c = i % 10; 
		
		if((a - b) == (b - c)) {
			cnt++; 
		}
	}

	return cnt; 
}

int main() 
{
	int n; 
	cin >> n; 

	int result = hansoo(n);
	cout << result; 
	
	return 0; 
}