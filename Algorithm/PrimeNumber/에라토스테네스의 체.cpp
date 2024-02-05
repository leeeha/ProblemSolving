#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
	int n = 1000; // 2부터 1000까지의 모든 수에 대해서 소수 판별 
	vector<bool> prime(n + 1, true); // 처음엔 모든 수가 소수인 것으로 초기화 (0과 1은 제외)
	prime[0] = false; 
	prime[1] = false;
	
    // 2부터 n의 제곱근까지 모든 수를 확인하며
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) { // 지워지지 않은 숫자들에 대해서 
			// i 자신을 제외한 i의 배수 모두 지우기 
			for(int j = 2 * i; j <= n; j += i){ 
				prime[j] = false; 
			}
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i]) cout << i << " ";
    }

    return 0;
}