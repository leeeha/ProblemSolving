#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int maxExplored = 0;
    sort(dungeons.begin(), dungeons.end()); 
    
    do {
        int explored = 0; 
        int currentK = k; 
        
        for(auto dungeon: dungeons){
            int required = dungeon[0];
            int consumed = dungeon[1];
            
            if(currentK >= required){
                currentK -= consumed; 
                explored++; 
            }
        }
        
        if(explored == dungeons.size()) return explored; 
        
        if(maxExplored < explored){
            maxExplored = explored;
        }
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return maxExplored; 
}