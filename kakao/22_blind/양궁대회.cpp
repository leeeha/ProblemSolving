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

const int MAX = 11;
vector<int> ans, apeach, ryan; 
int maxScoreGap = -1;

int calcScoreGap(){
    int a = 0, r = 0;
    
    for(int i = 0; i < MAX; i++){
        if(apeach[i] == 0 && ryan[i] == 0) continue;
        if(apeach[i] >= ryan[i]) a += (10 - i);
        else r += (10 - i);
    }
    
    if(r > a) return r - a; 
    else return -1; 
}

bool checkLowerCase() {
    for(int i = MAX - 1; i >= 0; i--){
        if(ryan[i] > ans[i]) return true; 
        else if(ryan[i] < ans[i]) return false;
    }
    return false; 
}

void updateResult(int chance, int idx){
    int scoreGap = calcScoreGap();
    
    if(scoreGap != -1){
        // 기회가 남았는데 idx == MAX 인 경우
        // 0번 과녁에 남은 화살을 모두 쏜다. 
        if(chance > 0) ryan[idx - 1] = chance; 
        
        // 최대 점수 차이 && 가장 낮은 점수를 더 많이 맞힌 경우 
        if(scoreGap == maxScoreGap && checkLowerCase()){
            ans = ryan;
        }else if(scoreGap > maxScoreGap){
        	// 최대 점수 차이 갱신 
            maxScoreGap = scoreGap;
            ans = ryan;
        }
        
        ryan[idx - 1] = 0;
    }
}

void dfs(int chance, int idx){
    if(idx == MAX || chance == 0){
        updateResult(chance, idx);
        return; 
    }
    
    if(chance > apeach[idx]){
        // 어피치보다 한발 더 맞히기
        ryan[idx] = apeach[idx] + 1;  
        dfs(chance - ryan[idx], idx + 1);
        ryan[idx] = 0;
    }
    
    // 화살을 쏘지 않고 다음으로 패스
    dfs(chance, idx + 1);
}

vector<int> solution(int n, vector<int> info) {
    ryan.resize(MAX, 0);
    apeach = info;
    
    dfs(n, 0);
    
    if(maxScoreGap == -1) return {-1};
    return ans;
}
