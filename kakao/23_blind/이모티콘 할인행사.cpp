#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii; 

const int MAX = 7;
int N, M;

vector<pii> g_users; // 비율, 비용 
vector<pii> g_emoticons; // 가격, 할인율

int discounts[4] = {10, 20, 30, 40};
vector<int> candidates;
int selected[MAX];

vector<pii> profits; // 가입자 수, 매출액 (우선순위 주의)

void updateEmoticonDiscounts() {
    for(int i = 0; i < M; i++){
        int discountRate = selected[i];
        g_emoticons[i].second = discountRate;
    }
}

void calcProfits() {
    int registerNum = 0;
    int totalCost = 0; 
    
    for(auto user: g_users){
        int rateForPerchase = user.first; // 구매 기준이 되는 할인율
        int costForRegister = user.second; // 가입 기준이 되는 구매 비용
        
        int cost = 0;
        for(auto emoticon: g_emoticons){
            int price = emoticon.first; 
            int discountRate = emoticon.second; 
            
            if(discountRate >= rateForPerchase){
                cost += price * (1 - ((float)discountRate / 100));
            }
        }
        
        // 기준 금액 이상으로 이모티콘을 구매한 경우, 플러스 가입 
        if(cost >= costForRegister){
            registerNum++;
        }else{ 
            // 그렇지 않으면, 이모티콘 구매만 진행 
            totalCost += cost;
        }
    }
    
    profits.push_back({registerNum, totalCost});
}

// 1. 이모티콘 m개의 할인율 결정 (중복 순열)
// 2. 그에 따른 가입자 수, 매출액 계산 
// 3. '가입자 수 > 매출액' 기준으로 내림차순 정렬 
// 4. 모든 경우의 수 중에 최대 이익 반환 (가입자 수, 매출액 묶어서) 
void dfs(int cnt){
    if(cnt == M){
        updateEmoticonDiscounts();
        calcProfits();
        return;
    }
    
    for(int rate: candidates){ 
        // cnt번째로 선택된 값 저장 
        selected[cnt] = rate; 
        dfs(cnt + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    N = users.size(); 
    M = emoticons.size(); 
    
    for(auto price: emoticons){
        g_emoticons.push_back({price, 0});
    }
    
    int minRate = 1e9; 
    for(auto user: users){
        // 전역 변수 초기화
        g_users.push_back({user[0], user[1]});
        
        // 할인율의 최솟값 구하기
        minRate = min(user[0], minRate);
    }
    
    // 유저의 구매 기준인 할인율 중에서 
    // 최솟값(minRate)은 넘도록 할인 행사를 해야 
    // 회사 입장에서 이득을 볼 수 있다. (판매든 가입이든)
    for(int i = 0; i < 4; i++){
        if(discounts[i] >= minRate){
            candidates.push_back(discounts[i]);
        }
    }
    
    dfs(0);
    
    // 가입자 수, 판매액 기준 내림차순 정렬 
    sort(profits.begin(), profits.end(), greater<>());
    
    answer.push_back(profits[0].first);
    answer.push_back(profits[0].second);
    
    return answer;
}