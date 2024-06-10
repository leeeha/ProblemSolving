#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> answer;
unordered_map<string, vector<int>> um;

void createGroup(string str) {
    stringstream ss(str);
    string arr[4][2] = {{"-"}, {"-"}, {"-"}, {"-"}};
    
    // 언어, 직군, 경력, 소울푸드
    for(int i = 0; i < 4; i++){
        ss >> arr[i][1];
    }
    
    int score;
    ss >> score;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
             for(int k = 0; k < 2; k++){
                 for(int l = 0; l < 2; l++){
                     string key = arr[0][i] + arr[1][j] + arr[2][k] + arr[3][l];
                     um[key].push_back(score);
                 }
             }
        }
    }
}

void countEligibleDevelopers(string str){
    stringstream ss(str);
    string arr[8];
    string key = "";
    
    for(int i = 0; i < 8; i++){
        ss >> arr[i];
    }
    
    for(int i = 0; i <= 6; i += 2){
        key += arr[i];
    }
    
    int score = stoi(arr[7]);
    vector<int> scores = um[key];
    
    int idx = lower_bound(scores.begin(), scores.end(), score) - scores.begin(); 
    answer.push_back(scores.size() - idx); 
}

vector<int> solution(vector<string> info, vector<string> query) {
    // 각 개발자가 속할 수 있는 그룹 만들기: O(N)
    for(auto str: info){ 
        createGroup(str);
    }
    
    // 해시의 점수 배열 오름차순 정렬: O(KlogK) 
    for(auto it = um.begin(); it != um.end(); it++){
        sort(it->second.begin(), it->second.end());
    }
    
    // 조건에 부합하는 개발자 수 카운트: O(MlogK) 
    for(auto str: query){
        countEligibleDevelopers(str);
    }
    
    return answer;
}