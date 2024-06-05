#include <string>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll; 

int length = 0; 

int movePointer(int idx){
    return idx + 1 >= (2 * length) ? 0 : idx + 1;
}

int solution(vector<int> q1, vector<int> q2) {
    ll sum1 = accumulate(q1.begin(), q1.end(), 0LL);
    ll sum2 = accumulate(q2.begin(), q2.end(), 0LL);
    
    if((sum1 + sum2) % 2 != 0) return -1; 
    
    length = q1.size();
    int cnt = 0;
    
    vector<int> q;
    for(int e: q1){
        q.push_back(e);
    }
    for(int e: q2){
        q.push_back(e);
    }
    
    int p1_s = 0; 
    int p1_e = length - 1; 
    int p2_s = length;
    int p2_e = 2 * length - 1; 
    
    while(cnt <= length * 3){
        if(sum1 > sum2){
            int q1Front = q[p1_s];
            sum1 -= q1Front;
            sum2 += q1Front;
            
            p1_s = movePointer(p1_s);
            p2_e = movePointer(p2_e);
        }
        else if(sum1 < sum2){
            int q2Front = q[p2_s];
            sum2 -= q2Front; 
            sum1 += q2Front; 
            
            p2_s = movePointer(p2_s);
            p1_e = movePointer(p1_e);
        }
        else return cnt; 
        
        cnt++; 
    }
    
    return -1; 
}