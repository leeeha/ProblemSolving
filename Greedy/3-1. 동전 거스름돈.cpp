#include<iostream>
using namespace std;

// 1260원을 거슬러 줄 때 필요한 최소한의 동전 개수 구하기
int n = 1260;
int cnt = 0;
int coinTypes[4] = { 500, 100, 50, 10 };
// 큰 단위가 항상 작은 단위의 배수 형태이기 때문에
// 가장 큰 단위의 동전부터 차례로 거슬러 주면 최적해를 구할 수 있다.

int main()
{
    for (int i = 0; i < 4; i++) {
        // 가장 큰 단위의 동전부터 차례로 거슬러주기
        int coin = coinTypes[i];
        cnt += n / coin; // 1260 = 2*500 + 260, 260 = 2*100 + 60, 60 = 1*50 + 10, 10 = 1*10 + 0
        n %= coin; // n = 260, 60, 10, 0
    }
    cout << cnt << '\n'; // 2 + 2 + 1 + 1
}