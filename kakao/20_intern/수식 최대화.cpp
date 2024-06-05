#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll; 

vector<ll> nums; // 수식 내의 숫자들
vector<char> operators; // 수식 내의 연산자들
map<int, char> op; // 인덱스와 연산자
vector<char> priorities; // 연산자 우선순위 
bool selected[3];
ll answer = 0;

void split(string expression){
    op[0] = '+';
    op[1] = '-';
    op[2] = '*';
    
    string num = "";
    for(auto ch: expression){
        if(ch >= '0' && ch <= '9'){
            num += ch;
        }else{
            nums.push_back(stoll(num));
            operators.push_back(ch);
            num = "";
        }
    }
    nums.push_back(stoll(num));
}

ll calcTwoNumber(ll a, ll b, char op) {
    if(op == '+') return a + b; 
    if(op == '-') return a - b; 
    if(op == '*') return a * b; 
}

ll calcExpression() {
	// 복사본 배열 생성 (다음 경우의 수를 위해 원본 유지)
    vector<ll> tmpNums = nums;
    vector<char> tmpOps = operators; 

    for(char oper: priorities){
        // 주어진 수식에서 우선순위가 높은 연산자부터 먼저 찾아서 계산한다. 
        for(int i = 0; i < tmpOps.size(); i++){
            if(tmpOps[i] == oper){
                // i번째 원소 갱신
                tmpNums[i] = calcTwoNumber(tmpNums[i], tmpNums[i + 1], oper);; 
                
                // (i+1)번째 원소 삭제
                tmpNums.erase(tmpNums.begin() + i + 1);
                
                // i번째 연산자 삭제
                tmpOps.erase(tmpOps.begin() + i);
                
                // 값이 갱신된 원소도 다음 연산에 포함되도록  
                i--;
            }
        }
    }
    
    return abs(tmpNums[0]);
}

// 연산자 우선순위 정하기 (순열 3!)
void dfs(int cnt){
    if(cnt == 3){
        ll result = calcExpression();
        answer = max(answer, result);
        return;
    }
    
    for(int i = 0; i < 3; i++){
        if(!selected[i]){
            selected[i] = true;
            priorities.push_back(op[i]);
            dfs(cnt + 1);
            priorities.pop_back();
            selected[i] = false;
        }
    }
}

ll solution(string expression) {
    split(expression);
    dfs(0);
    return answer; 
}