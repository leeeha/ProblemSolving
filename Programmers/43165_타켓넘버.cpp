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
        
        return; // �� ���� ����� ���� �̵� 
    }
    
    dfs(nums, target, result + nums[idx], idx + 1); 
    dfs(nums, target, result - nums[idx], idx + 1); 
}

int solution(vector<int> nums, int target) {
    // result: ��������� ���� ���, idx: +/- ������ ������ �ε��� 
    dfs(nums, target, 0, 0); 
    
    return answer; 
}