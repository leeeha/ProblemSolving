#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string nums[10] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int solution(string s) {
    string ans = "";
    
    for(int i = 0; i < s.size();){
    	// 숫자일 때는 i + 1
        if(s[i] >= '0' && s[i] <= '9'){
            ans += s[i++];
        }else{
            for(int j = 0; j < 10; j++){
                if(s.find(nums[j], i) == i){ 
                    // 인덱스를 문자열로 변환하여 더하기 
                    ans += '0' + j;
                    // 영단어일 때는 i + length
                    i += nums[j].length(); 
                    break; 
                }
            }
        }
    }
    
    return stoi(ans);
}
