#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, string> pis; // 시간, 방향 

int calcTotalFee(vector<int> fees, int totalTime) {
    if(totalTime <= fees[0]){
        return fees[1];
    }
    
    return fees[1] + ceil((totalTime - fees[0]) / (1.0 * fees[2])) * fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    set<int> cars;
    for(int i = 0; i < records.size(); i++){
        stringstream ss(records[i]);
        string time, car, dir;
        ss >> time >> car >> dir;
        
        // 차 번호 저장 
        cars.insert(stoi(car));
    }
   
    vector<vector<pis>> arr(cars.size());
    
    for(auto it = cars.begin(); it != cars.end(); it++){
        int idx = distance(cars.begin(), it);
        int carNum = *it;
        
        // 현재 차에 대한 모든 입출 시간, 방향 저장
        for(int i = 0; i < records.size(); i++){
            stringstream ss(records[i]);
            string time, car, dir;
            ss >> time >> car >> dir;
            
            if(carNum == stoi(car)){
                // HH:MM -> 분 단위 시간
                string h = time.substr(0, 2);
                string m = time.substr(3, 2);
                int totalMinute = stoi(h) * 60 + stoi(m);

                // 차 종류에 따라 -> 입출 시간, 방향 묶어서 저장
                arr[idx].push_back({totalMinute, dir});
            }
        }
    }
    
    // 차 종류에 따른 주차 요금 계산하기
    for(auto v: arr){
        stack<int> s;
        int totalTime = 0;
        
        for(auto e: v){
            int curTime = e.first;
            string dir = e.second;
            
            if(dir == "IN"){
                s.push(curTime);
            }else{
                totalTime += curTime - s.top();
                s.pop();
            }
        }
        
        if(!s.empty()){
            int lastTime = 23 * 60 + 59;
            totalTime += lastTime - s.top();
        }
        
        int fee = calcTotalFee(fees, totalTime);
        answer.push_back(fee);
    }
    
    return answer;
}