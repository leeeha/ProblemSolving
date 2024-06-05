#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int calcDist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string solution(vector<int> numbers, string hand) {
    string ans = "";
    
    // 각 키패드의 위치 저장 (4x3)
    vector<pii> pos;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            pos.push_back({i, j});
        }
    }
    
    // 시작 위치 초기화 
    pii left = {3, 0};
    pii right = {3, 2};
    
    // 입력에 따라 손가락 위치 이동 
    for(auto num: numbers){
        pii next; 
        if(num == 0){
            next = pos[10];
        }else{
            next = pos[num - 1];
        }
        
        if(num % 3 == 1){
            ans += "L";
            left = next;
        }else if(num % 3 == 0 && num != 0){
            ans += "R";
            right = next;
        }else{
            int ld = calcDist(next, left);
            int rd = calcDist(next, right);
            
            if(ld < rd){
                ans += "L"; 
                left = next;
            }else if(ld > rd) {
                ans += "R";
                right = next;
            }else{
                if(hand == "left"){
                    ans += "L"; 
                    left = next;
                }else{
                    ans += "R";
                    right = next;
                }
            }
        }
    }
    
    return ans;
}