#include<iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n;

	if(n == 1) return 0; 

	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			cout << i << "\n"; 
			n /= i; 
		}
		if(n == 1) break; 
	}

	if(n > 1) cout << n << "\n"; 

    return 0;
}