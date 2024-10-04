#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int answer = n - lost.size();
    int borrower = 0;
    
    for(int i = 0; i < lost.size(); i++){
        auto it = find(reserve.begin(), reserve.end(), lost[i]);
        if(it != reserve.end()){
            lost.erase(lost.begin() + i);
            i--; // 삭제된 바로 그 위치부터 다시 탐색하도록
            reserve.erase(it);
            
            borrower++;
        }
    }
    
    for(int i = 0; i < lost.size(); i++){
        int a = lost[i];
    
        auto it1 = find(reserve.begin(), reserve.end(), a - 1);
        if(it1 != reserve.end()){ 
            reserve.erase(it1); 
            borrower++;
            continue;
        }
        
        auto it2 = find(reserve.begin(), reserve.end(), a + 1);
        if(it2 != reserve.end()){
            reserve.erase(it2); 
            borrower++;
            continue;
        }
    }
    
    answer += borrower;
    
    return answer;
}