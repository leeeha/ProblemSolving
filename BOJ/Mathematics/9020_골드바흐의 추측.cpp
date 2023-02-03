 #include <iostream>
using namespace std; 

bool isPrime(int x){
	if(x < 2) return false; 

	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) return false; 
	}

	return true; 
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; 
	cin >> t; 
	
	while(t--){
		int n; 
		cin >> n;

		for(int i = n / 2; i >= 2; i--){
			if(isPrime(i) && isPrime(n - i)){
				cout << i << " " << n - i << "\n"; 
				break; 
			}
		}
	}

    return 0;
}