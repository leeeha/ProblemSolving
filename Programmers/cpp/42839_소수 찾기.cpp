#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#define MAX 7
using namespace std;

char arr[MAX];  
bool selected[MAX];  
vector<int> v; 

void handleOneCase(int r){
    string str = "";
    for(int i = 0; i < r; i++){
        str += arr[i];
    }
    v.push_back(stoi(str));
}

void dfs(int cnt, int r, string nums){
    if(cnt == r){ 
        handleOneCase(r); 
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        if(!selected[i]){ 
            selected[i] = true; 
            arr[cnt] = nums[i]; 
            dfs(cnt + 1, r, nums); 
            selected[i] = false; 
        }
    }
}

bool isPrime(int x){
    if(x < 2) return false; 
    
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false; 
    }
    
    return true;
}

int solution(string nums) {
    int answer = 0;
    
    int n = nums.size();
    
    for(int i = 1; i <= n; i++){
        dfs(0, i, nums); 
        memset(selected, 0, sizeof(selected));
    }
    
    set<int> s(v.begin(), v.end());
    for(auto e: s){
        if(isPrime(e)) answer++; 
    }
    
    return answer;
}