#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0, h = 0; 
    
    for(auto v: sizes){
        // 너비는 최댓값 중에 최댓값 
        w = max(w, max(v[0], v[1]));
        // 높이는 최솟값 중에 최댓값 
        h = max(h, min(v[0], v[1]));
    }
    
    // 모든 명함을 수납할 수 있는 지갑의 최소 크기 
    return w * h; 
}