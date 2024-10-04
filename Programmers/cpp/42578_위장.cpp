#include <string>
#include <vector>
#include <map> 
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> map; 
    
    for(auto e: clothes){
        map[e[1]]++; // 옷의 종류(key)와 개수(value)
    }
    
    for(auto e: map){ 
        // 옷을 선택하지 않는 경우의 수를 포함하여 +1 
        answer *= (e.second + 1); 
    }
    
    return answer - 1; // 모든 옷을 선택하지 않는 경우의 수는 제외하므로 -1 
}