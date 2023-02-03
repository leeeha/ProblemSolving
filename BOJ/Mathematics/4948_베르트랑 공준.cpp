#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

int main()
{	
	while(true){
		int n; 
		cin >> n; 

		if(n == 0) break; 

		vector<bool> prime(2 * n + 1, true); 
		prime[0] = false; 
		prime[1] = false; 
	
		for(int i = 2; i * i <= 2 * n; i++){ 
			if(prime[i]){ 
				// i 자신을 제외한 i의 배수 모두 지우기 
				for(int j = 2 * i; j <= 2 * n; j += i){ 
					prime[j] = false;
				}
			}
		}

		// n보다 크고 2n보다 작거나 같은 수들 중에 소수의 개수 
		int cnt = 0; 
		for(int i = n + 1; i <= 2 * n; i++){ 
			if(prime[i]) cnt++;  
		}

		cout << cnt << "\n"; 
	}

    return 0;
}