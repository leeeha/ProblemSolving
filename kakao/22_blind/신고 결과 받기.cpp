#include <iostream>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // key, value 모두 중복 허용 X
    unordered_map<string, unordered_set<string>> reportHash;
    unordered_map<string, unordered_set<string>> resultHash;
    
    for(auto r: report){
        int pos = r.find(' '); // 공백 위치 
        string user = r.substr(0, pos); // 공백 전 
        string badUser = r.substr(pos + 1); // 공백 다음
        
        reportHash[user].insert(badUser);
        resultHash[badUser].insert(user);
    }
    
    vector<int> ans(id_list.size());
    for(int i = 0; i < id_list.size(); i++){
        string user = id_list[i];
        auto it = reportHash.find(user);
        if(it == reportHash.end()) continue;
        
        for(string badUser: it->second){
        	// 신고 당한 횟수가 k 이상이면 
            if(resultHash[badUser].size() >= k) {
            	// 이용 정지된 유저 수 갱신 
                ans[i]++; 
            }
        }
    }
    
    return ans;
}
