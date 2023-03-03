#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> v) { 
    sort(v.begin(), v.end());
    
    // 접두어니까 단순히 find 함수를 사용하는 게 아니라 
    // '0부터 v[i] 크기만큼' 부분 문자열을 추출해서 인접한 원소와 비교해야 한다! 
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] == v[i + 1].substr(0, v[i].size())){
            return false; 
        }
    }
    
    return true; 
}