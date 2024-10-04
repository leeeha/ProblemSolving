#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b){
    return a + b > b + a; 
}

string solution(vector<int> nums) {
    string answer = ""; 
    
    vector<string> v; 
    for(int e: nums){
        v.push_back(to_string(e)); 
    }
    
    sort(v.begin(), v.end(), compare); 
    
    // 내림차순 정렬했는데 가장 큰 수가 0이면, 0000...0이 아니라 0을 리턴하도록 
    if(v[0] == "0") return "0"; 
    
    for(string e: v){
        answer += e; 
    }
    
    return answer; 
}