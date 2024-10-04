#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a {1, 2, 3, 4, 5};
vector<int> b {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> c {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> generateCheatingSheet(int n, vector<int> arr){
    vector<int> v; 
    
    int q = n / arr.size(); 
    int r = n % arr.size(); 
    
    for(int i = 0; i < q; i++){ 
        for(auto e: arr){ 
            v.push_back(e); 
        }
    }
    
    for(int i = 0; i < r; i++){ 
        v.push_back(arr[i]); 
    }
    
    return v; 
}

int getScore(vector<int> answers, vector<int> v){
    int cnt = 0;
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == v[i]) cnt++; 
    }
    return cnt; 
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int n = answers.size();
    vector<int> v1 = generateCheatingSheet(n, a);
    vector<int> v2 = generateCheatingSheet(n, b);
    vector<int> v3 = generateCheatingSheet(n, c);
    
    int s1 = getScore(answers, v1);
    int s2 = getScore(answers, v2);
    int s3 = getScore(answers, v3);
    
    vector<int> score; 
    score.push_back(s1); 
    score.push_back(s2); 
    score.push_back(s3); 
    
    int maxVal = *max_element(score.begin(), score.end()); 
    
    for(int i = 0; i < score.size(); i++){
        if(score[i] == maxVal){ 
            answer.push_back(i + 1); 
        }
    }
    
    return answer; 
}

// 숏코드 참고 

#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> one {1, 2, 3, 4, 5};
vector<int> two {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> thr {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer; 
    
    vector<int> scores(3);
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == one[i % one.size()]) scores[0]++; 
        if(answers[i] == two[i % two.size()]) scores[1]++; 
        if(answers[i] == thr[i % thr.size()]) scores[2]++; 
    }
    
    int maxVal = *max_element(scores.begin(), scores.end());
    for(int i = 0; i < scores.size(); i++){
        if(scores[i] == maxVal){
            answer.push_back(i + 1); 
        }
    }
    
    return answer; 
}