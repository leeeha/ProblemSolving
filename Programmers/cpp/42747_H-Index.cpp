#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> citations) {
    int h = 0; 
    
    while(true){
        int cnt = 0; 
        for(auto e: citations){
            if(e >= h) cnt++; 
        }
        if(h > cnt) break;
        h++; 
    }
    
    return h - 1; 
}