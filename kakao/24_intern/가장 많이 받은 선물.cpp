#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    vector<int> answer;
    
    int n = friends.size();
    
    // 주고 받은 선물 개수 
    vector<vector<int>> arr(n, vector<int>(n, 0));
    
    // 선물 지수 (give 개수 - take 개수)
    vector<int> score(n, 0);
    
    // 이름에 해당하는 인덱스를 맵에 저장
    unordered_map<string, int> map;
    for(int i = 0; i < n; i++){
        map[friends[i]] = i; 
    }
    
    for(auto gift: gifts){
        stringstream ss(gift);
        string give, take;
        ss >> give >> take;

        // arr 배열 초기화 
        int giveIdx = map[give];
        int takeIdx = map[take];
        arr[giveIdx][takeIdx]++;
        
        // score 배열 초기화
        score[giveIdx]++; 
        score[takeIdx]--; 
    }
    
    // 다음 달에 받을 수 있는 선물 개수 구하기 
    // 1. 나보다 선물을 적게 준 사람한테 하나씩 받을 수 있다. 
    // 2. 선물 주고받은 개수가 동일하면, 선물 지수가 작은 사람에게 하나씩 받을 수 있다.
    for(int i = 0; i < n; i++){
        int sum = 0;
        
        for(int j = 0; j < n; j++){
            int giveNum = arr[i][j];
            int takeNum = arr[j][i];
            
            if (i == j || giveNum < takeNum) continue;
            
            // 선물 개수 비교
            if(giveNum > takeNum) sum++; 
            else{
                // 선물 지수 비교
                if(score[i] > score[j]){
                    sum++;
                }
            }
        }
        
        answer.push_back(sum);
    }
    
    return *max_element(answer.begin(), answer.end());
}