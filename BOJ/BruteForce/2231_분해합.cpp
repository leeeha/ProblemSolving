#include <iostream>
using namespace std;

int calcDigitSum(int num){
	int sum = num; 
	while(num != 0){
		sum += num % 10; 
		num /= 10; 
	}
	return sum; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; 

	for(int i = 1; i < n; i++){
		if(calcDigitSum(i) == n){
			cout << i << endl;
			return 0;
		}
	}

	cout << "0\n"; 
	
	return 0;
}