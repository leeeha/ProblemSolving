#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++){
        int duration = 0;
        for(int j = i + 1; j < prices.size(); j++){
            if(prices[i] <= prices[j]){
                duration++;
            }else{
                duration++; // 한번 감소가 되더라도 +1 
                break; 
            }
        }
        answer.push_back(duration);
    }
    
    return answer;
}
