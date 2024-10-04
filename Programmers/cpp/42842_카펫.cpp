#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // w * h == yellow && (w + h) * 2 + 4 == brown 
    for(int i = 1; i * i <= yellow; i++){
        if(yellow % i == 0){
            int w = yellow / i;
            int h = i; 
            if((w + h) * 2 + 4 == brown){
                answer.push_back(w + 2);
                answer.push_back(h + 2);
                break; 
            }
        }
    }
    
    return answer;
}