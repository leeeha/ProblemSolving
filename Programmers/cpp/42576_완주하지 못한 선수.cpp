#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 두 배열의 크기 차이는 1
string solution(vector<string> part, vector<string> com) { 
    sort(part.begin(), part.end());
    sort(com.begin(), com.end());
    
    // 짝지어서 비교 
    for(int i = 0; i < com.size(); i++){ 
        if(part[i] != com[i]){ 
            return part[i]; 
        }
    }
    
    return part[part.size() - 1]; 
}