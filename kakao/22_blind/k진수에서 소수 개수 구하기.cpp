#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool isPrime(ll x) { // ll 타입 주의 
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; i++) { // ll 타입 주의 
        if (x % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    // 진법 변환
    deque<int> dq; 
    if(n < k) dq.push_front(n);
    else {
        int q = n;
        while(q / k >= k){
            dq.push_front(q % k);
            q /= k;
        }
        dq.push_front(q % k);
        dq.push_front(q / k);
    }
   
    // 소수 개수 구하기 
    int cnt = 0;
    string temp = "";
    
    for(auto num: dq){
        if(num == 0){
            if(temp != "" && isPrime(stoll(temp))){
                cnt++;
            }
            temp = "";
        }else{
            temp += to_string(num);
        }
    }
    
    if(temp != "" && isPrime(stoll(temp))){
        cnt++;
    }
    
    return cnt;
}