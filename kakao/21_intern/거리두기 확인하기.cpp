#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
const int n = 5;

struct Point {
    int x;
    int y;
    int dist;
};

int calcDist(int x1, int x2, int y1, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

bool bfs(vector<string> arr, int startX, int startY){
    bool visited[n][n] = { false, };
    
    queue<Point> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    
    while(!q.empty()){
        Point now = q.front();
        q.pop();
        
        // 더 이상 탐색할 필요 없이 다음 위치로 넘어감. 
        if(now.dist > 2) continue; 
        
        // 탐색 시작점이 아닌 곳에서 또 다른 P를 만난 경우 
        if(now.dist != 0 && arr[now.x][now.y] == 'P') return false;
        
        for(int i = 0; i < 4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny] == 'X') continue;
            
            // 맨해튼 거리 갱신 
            q.push({nx, ny, now.dist + 1});
            visited[nx][ny] = true;
        }
    }
    
    // 맨해튼 거리가 2보다 큰 위치에 P가 없는 경우 
    return true; 
}

bool isPossible(vector<string> place) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char ch = place[i][j];
            if(ch == 'P'){
                if(bfs(place, i, j) == false) return false;
            }
        }
    }

    return true; 
}

vector<int> solution(vector<vector<string>> places) {
    int n = places.size(); 
    vector<int> answer;
    
    for(auto place: places){
        if(isPossible(place)){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }
    }
    
    return answer;
}