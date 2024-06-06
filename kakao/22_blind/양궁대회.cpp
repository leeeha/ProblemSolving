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
        if(ryan[i] != ans[i]) 
            return ryan[i] > ans[i];
    }
    return false;
}

void updateResult(int chance, int idx){
    int scoreGap = calcScoreGap();
    
    // 라이언이 이길 수 있는 경우 
    if(scoreGap != -1){
        // 남은 모든 화살을 0점에 맞힌다. 
        if(chance > 0) ryan[idx - 1] = chance; 
        
        // 최대 점수 차이를 만들 수 있으면서 
        // 가장 낮은 점수에 더 많이 맞힌 경우 
        if(scoreGap == maxScoreGap && checkLowerCase()){
            ans = ryan; // 방법 갱신 
        }else if(scoreGap > maxScoreGap){
            maxScoreGap = scoreGap; // 최대 점수 차이 갱신 
            ans = ryan; // 방법 갱신 
        }
        
        // 0점 과녁에 맞힌 화살 개수 초기화 
        ryan[idx - 1] = 0;
    }
}

void dfs(int chance, int idx){
    // 10~0점까지 화살 개수 분배를 마쳤거나 
	// n개의 화살을 전부 사용했으면 
    if(idx == MAX || chance == 0){
    	// 결과 갱신 
        updateResult(chance, idx);
        return; 
    }
    
    if(chance > apeach[idx]){
        // i) 어피치보다 한발 더 맞히는 경우 
        ryan[idx] = apeach[idx] + 1;  
        
        // 재귀 호출 
        dfs(chance - ryan[idx], idx + 1);
        
        // 다음 경우의 수를 위한 상태 복구 
        ryan[idx] = 0;
    }
    
    // ii) 화살을 쏘지 않고 다음으로 넘어가는 경우 
    dfs(chance, idx + 1);
}

vector<int> solution(int n, vector<int> info) {
    ryan.resize(MAX, 0);
    apeach = info;
    
    dfs(n, 0);
    
    if(maxScoreGap == -1) return {-1};
    return ans;
}