#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int COURSE_NUM = 11;
unordered_map<string, int> um;
int maxComb[COURSE_NUM];

void combination(string order, int r){
    int n = order.size();
    if(n < r) return;
    
    // 0 -> 1 순으로 구성된 오름차순 배열 
    vector<int> select(n, 1);
    for(int i = 0; i < n - r; i++){
        select[i] = 0;
    }
    
    do{
        string comb = "";
        for(int i = 0; i < n; i++){
            if(select[i]) comb += order[i];
        }
        
        um[comb]++;
        maxComb[r] = max(maxComb[r], um[comb]);
    }while(next_permutation(select.begin(), select.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto& order: orders){
        sort(order.begin(), order.end());
    }
    
    for(auto num: course){
        for(auto order: orders){
            combination(order, num);
        }
        
        for(auto ele: um){
            string comb = ele.first;
            int ordersByCustomer = ele.second;
            
            if(ordersByCustomer >= 2 && 
               ordersByCustomer == maxComb[num]){
                answer.push_back(comb);
            }
        }
        
        um.clear();
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}