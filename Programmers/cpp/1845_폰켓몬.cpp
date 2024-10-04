#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<int> v)
{
//     int n = v.size(); 
    
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//     int size = v.size(); 
    
//     if(size >= n/2){ 
//         return n/2; 
//     }else{
//         return size; 
//     }
    
    unordered_set<int> s(v.begin(), v.end());
    return min(s.size(), v.size() / 2); 
}