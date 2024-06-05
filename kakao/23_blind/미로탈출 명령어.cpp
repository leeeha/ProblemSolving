#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int N, M, X, Y, R, C, K;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'d', 'l', 'r', 'u'};

string path = "";
string answer = "impossible";
bool found = false;

int calcRemainingDist(int x, int y){
    return abs(x - R) + abs(y - C);
}

void dfs(int cnt, int curx, int cury) {
    if(found) return;
    
    // 현위치에서 탈출 지점까지 남은 거리
    int dist = calcRemainingDist(curx, cury);
    
    // 남은 이동 횟수가 dist 보다 작은 경우 impossible
    if(K - cnt < dist) return; 
    
    // 남은 이동 횟수에서 dist를 뺐을 때, 짝수가 아닌 경우 impossible 
    if((K - cnt - dist) % 2 == 1) return; 
    
    // 탈출 지점까지 K번 이동한 경우, 재귀 호출 종료
    if(cnt == K && curx == R && cury == C) {
        found = true;
        answer = path; 
        return; 
    }
    
    for(int i = 0; i < 4; i++){
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        
        // 1~N까지임에 주의!!!!! (0~N-1 아님)
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue; 
        
        path += dir[i];
        dfs(cnt + 1, nx, ny);
        path.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n, M = m, X = x, Y = y, R = r, C = c, K = k;
    
    dfs(0, x, y);
    
    return answer; 
}