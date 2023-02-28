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
    // ��� Ƚ���� ������ ���� ��ȣ�� ���� ������ ���� 
    if(a.first.second == b.first.second){
        return a.second < b.second; 
    }
    
    // �⺻�����δ� ��� Ƚ���� ���� ������ ���� 
    return a.first.second > b.first.second; 
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // �� �帣�� ��� Ƚ���� ���� �켱������ ���Ѵ�. 
    map<string, int> m; // �� �帣�� ���Ƚ�� 
    vector<pair<pair<string, int>, int>> v; // �帣, ���Ƚ��, ������ȣ 
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i]; 
        v.push_back({{genres[i], plays[i]}, i}); 
    }
    
    vector<pair<string, int>> mtv(m.begin(), m.end()); // map to vector 
    sort(mtv.begin(), mtv.end(), compare1); // ���Ƚ���� ���� ������ ���� 

    // �帣 ������ ���Ƚ���� ���� ������ ����, ���Ƚ���� ������ ������ȣ�� ���� ������ ���� 
    sort(v.begin(), v.end(), compare2); 
    
    // �帣 ������ ���� ���� ����� 2���� ������ȣ�� answer�� �����Ѵ�. 
    for(int i = 0; i < mtv.size(); i++){
        string genresName = mtv[i].first;
        int cnt = 0; 
        
        for(int j = 0; j < v.size(); j++){ 
            if(genresName == v[j].first.first){ // �帣 �� 
                answer.push_back(v[j].second); // ������ȣ ���� 
                cnt++; 
            }
            
            if(cnt >= 2) break; 
        }
    }
    
    return answer;
}