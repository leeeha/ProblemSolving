#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer = 0; 

void dfs(vector<int> nums, int target, int result, int idx){
    if(idx == nums.size()){ 
        if(result == target){ 
            answer++; 
        }
        
        return; // 그 다음 경우의 수로 이동 
    }
    
    dfs(nums, target, result + nums[idx], idx + 1); 
    dfs(nums, target, result - nums[idx], idx + 1); 
}

int solution(vector<int> nums, int target) {
    // result: 현재까지의 연산 결과, idx: +/- 연산을 진행할 인덱스 
    dfs(nums, target, 0, 0); 
    
    return answer; 
}