#include<iostream>
#include<cmath>
using namespace std;

bool isPrimeNumber(int x) {
    if (x < 2) // 소수의 정의에서 벗어난 수들은 예외 처리
        return false;
        
    // 2부터 x의 제곱근까지 모든 수를 확인하며
    for (int i = 2; i * i <= x; i++) {
        // x가 해당 수로 나누어 떨어진다면 
        if (x % i == 0) {
            // i와 그에 대칭인 수는 모두 x의 약수이고, x는 소수가 아님.
            return false; 
        }
    }
    
    return true;
}

int main(){
    cout << isPrimeNumber(15) << '\n'; // 0

    return 0;
}