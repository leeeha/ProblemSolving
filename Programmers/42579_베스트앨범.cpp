#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm> 
using namespace std;

bool compare1(pair<string, int> a, pair<string, int> b){
    return a.second > b.second; 
}

bool compare2(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b){
    // 재생 횟수가 같으면 고유 번호가 낮은 순으로 정렬 
    if(a.first.second == b.first.second){
        return a.second < b.second; 
    }
    
    // 기본적으로는 재생 횟수가 높은 순으로 정렬 
    return a.first.second > b.first.second; 
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 각 장르별 재생 횟수에 따라 우선순위를 정한다. 
    map<string, int> m; // 각 장르별 재생횟수 
    vector<pair<pair<string, int>, int>> v; // 장르, 재생횟수, 고유번호 
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i]; 
        v.push_back({{genres[i], plays[i]}, i}); 
    }
    
    vector<pair<string, int>> mtv(m.begin(), m.end()); // map to vector 
    sort(mtv.begin(), mtv.end(), compare1); // 재생횟수가 높은 순으로 정렬 

    // 장르 내에서 재생횟수가 높은 순으로 정렬, 재생횟수가 같으면 고유번호가 낮은 순으로 정렬 
    sort(v.begin(), v.end(), compare2); 
    
    // 장르 내에서 가장 많이 재생된 2곡의 고유번호를 answer에 저장한다. 
    for(int i = 0; i < mtv.size(); i++){
        string genresName = mtv[i].first;
        int cnt = 0; 
        
        for(int j = 0; j < v.size(); j++){ 
            if(genresName == v[j].first.first){ // 장르 비교 
                answer.push_back(v[j].second); // 고유번호 저장 
                cnt++; 
            }
            
            if(cnt >= 2) break; 
        }
    }
    
    return answer;
}