#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isCorrect(string p) {
    stack<char> st;
    
    for(auto e: p){
        if(e == '('){
            st.push(e);
        }else{
            if(!st.empty()) st.pop(); 
        }
    }
    
    return st.empty();
}

string transform(string u){
    // 처음과 끝 문자 제거 
    u.erase(u.begin());
    u.erase(u.end() - 1);
    
    // 모든 괄호 방향 뒤집기 
    for(int i = 0; i < u.size(); i++){
        if(u[i] == '(') u[i] = ')';
        else u[i] = '(';
    }
    
    return u;
}

string divide(string p){
    if(p == "") return p; 
    
    // 균형 잡힌 괄호 u, v로 분리
    // 열린 괄호, 닫힌 괄호 개수가 동일해지면 바로 분리 
    int open = 0, close = 0; 
    int idx = 0; 
    for(int i = 0; i < p.size(); i++){
        if(p[i] == '(') open++; 
        else close++; 
        
        if(open == close){
            idx = i + 1;
            break; 
        }
    }
    
    string u = p.substr(0, idx);
    string v = p.substr(idx);
    
    string result = "";
    if(isCorrect(u)){ 
        // u가 올바른 괄호인 경우
       result = u + divide(v);
    }else{ 
        // u가 올바른 괄호가 아닌 경우
       result = "(" + divide(v) + ")" + transform(u);
    }
    
    return result; 
}

string solution(string p) {
    return divide(p); 
}