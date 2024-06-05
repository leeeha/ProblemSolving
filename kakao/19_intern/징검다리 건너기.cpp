#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 징검다리를 '건너려고 하는' 사람이 x명일 때,
// 한번에 건너뛸 수 있는 최대 칸수가 k 이하인가?
// -> 연속으로 0이 된 디딤돌의 개수가 k보다 작은가? 
bool decision(vector<int> stones, int x, int k) {
    int cnt = 0; 
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] < x) cnt++;
        else cnt = 0;
        
        if(cnt >= k) return false; 
    }
    
    return true; 
}

int solution(vector<int> stones, int k) {
    int left = 0; 
    int right = *max_element(stones.begin(), stones.end()); 
    int ans = -1;
    
    while(left <= right){
        int mid = (left + right) / 2; 
        
        if(decision(stones, mid, k)){ 
            ans = max(ans, mid); 
            left = mid + 1;
        }else{
            right = mid - 1; 
        }
    }
    
    return ans; 
}