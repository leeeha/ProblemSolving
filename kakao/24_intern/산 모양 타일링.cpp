#include <string>
#include <vector>
using namespace std;

const int MOD = 10007; 

int solution(int n, vector<int> tops) {
    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);
    dp1[0] = 1;
    dp2[0] = 2 + tops[0]; // 2 또는 3 
    
    for (int i = 1; i < n; i++) {
        dp1[i] = (dp1[i - 1] + dp2[i - 1]) % MOD;
        dp2[i] = ((dp1[i - 1] * (1 + tops[i])) + (dp2[i - 1] * (2 + tops[i]))) % MOD;
    }
    
    return (dp1.back() + dp2.back()) % MOD;
}