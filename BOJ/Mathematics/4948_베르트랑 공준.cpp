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
				// i �ڽ��� ������ i�� ��� ��� ����� 
				for(int j = 2 * i; j <= 2 * n; j += i){ 
					prime[j] = false;
				}
			}
		}

		// n���� ũ�� 2n���� �۰ų� ���� ���� �߿� �Ҽ��� ���� 
		int cnt = 0; 
		for(int i = n + 1; i <= 2 * n; i++){ 
			if(prime[i]) cnt++;  
		}

		cout << cnt << "\n"; 
	}

    return 0;
}