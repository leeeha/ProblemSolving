#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll solution(int cap, int n, vector<int> d, vector<int> p) {
    ll answer = 0; 
    ll a = 0, b = 0; 
    
    for(int i = n - 1; i >= 0; i--){
        a -= d[i];
        b -= p[i];
        
        int cnt = 0; 
        
        // a, b에 cap를 더했는데 0 이상이 되지 않으면 
        // 현재 i번째 집은 다시 들러야 한다.
        // 현재 집에 대한 트럭의 총 방문 횟수를 cnt로 구한다.
        while(a < 0 || b < 0){
            a += cap;
            b += cap; 
            cnt++; 
        }
        
        answer += (i + 1) * 2 * cnt; 
    }
    
    return answer;
}