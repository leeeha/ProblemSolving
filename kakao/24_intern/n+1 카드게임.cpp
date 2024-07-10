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

int N;

bool possibleNextRound(set<int>& mine, set<int>& other){
    for(int first: mine){
        int second = (N + 1) - first;
        
        if(other.find(second) != other.end()){
            mine.erase(first);
            other.erase(second);
            return true;
        }
    }
    
    return false;
}

int solution(int coin, vector<int> cards) {
    int round = 1;
    N = cards.size();
    set<int> myCard, picked;
    
    for(int i = 0; i < N / 3; i++){
        myCard.insert(cards[i]);
    }
    
    int idx = N / 3;
    while(idx < N){
        for(int i = 0; i < 2; i++){
            picked.insert(cards[idx++]);
        }
        
        if(myCard.size() >= 2 && possibleNextRound(myCard, myCard)){
            round++;
        }
        else if(myCard.size() >= 1 && coin >= 1 && 
                possibleNextRound(myCard, picked)){
            round++;
            coin--;
        }
        else if(coin >= 2 && possibleNextRound(picked, picked)){
            round++;
            coin -= 2;
        }else{
            break;
        }
    }
    
    return round;
}