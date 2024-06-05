#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii; 
typedef long long ll;

int N;
vector<vector<int>> arr;
vector<int> diceA, diceB; // 선택한 주사위의 인덱스 
vector<int> sumA, sumB; // 주사위 눈의 합 

void initArray() {
    diceA.clear(); 
    diceB.clear(); 
    sumA.clear(); 
    sumB.clear(); 
}

// N/2개의 주사위로 나올 수 있는 합 -> 중복 순열 6^(N/2)
void calcSum(int idx, int total, bool isA, vector<int>& selected) {
    if (idx == N / 2){
        isA ? sumA.push_back(total) : sumB.push_back(total);
        return;
    }
    
    for(int i = 0; i < 6; i++){
        int diceIdx = selected[idx];
        calcSum(idx + 1, total + arr[diceIdx][i], isA, selected);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    // 전역변수 초기화
    N = dice.size();
    arr = dice;
    
    // N개 중에 N/2개 선택
    vector<int> temp(N, 1);
    for(int i = 0; i < N / 2; i++){
        temp[i] = 0;
    }
    
    // A가 이긴 횟수를 최대로 만드는
    // 주사위 번호를 오름차순으로 저장 
    vector<int> answer(N / 2);
    
    // A가 이긴 횟수의 최댓값
    int awinMaxCnt = 0;
    
    do{
        initArray();
        
        // diceA, diceB 세팅
        for(int i = 0; i < N; i++){
            if(temp[i] == 0){
                diceA.push_back(i);
            }else{
                diceB.push_back(i);
            }
        }
        
        // 가능한 주사위 눈의 합 저장
        calcSum(0, 0, true, diceA);
        calcSum(0, 0, false, diceB);

        // 이분탐색 세팅 
        sort(sumB.begin(), sumB.end());
        map<int, int> cache;
        int awinCnt = 0;
        
        for(int asum: sumA){
            // 현재 합에 대해 이미 계산된 승률이 있으면 그대로 사용 
            if(cache.count(asum)){
                awinCnt += cache[asum];
                continue;
            }

            // sumB 배열을 이분 탐색하여
            // sumA 원소보다 '작은' sumB 원소 개수를 구한다.
            int low = 0;
            int high = sumB.size();
            
            while(low + 1 < high){
                int mid = (low + high) / 2;
                
                if(asum > sumB[mid]){
                    low = mid;
                }else{
                    high = mid;
                }
            }

            cache[asum] = low;  // 현재 합으로 이긴 횟수 저장 
            awinCnt += low; // 이긴 횟수의 누적 합 
        }

        // 현재까지의 최댓값, 정답 갱신 
        if(awinCnt > awinMaxCnt){
            awinMaxCnt = awinCnt;
            
            for(int i = 0; i < diceA.size(); i++){
                answer[i] = diceA[i] + 1; 
            }
        }
    }while(next_permutation(temp.begin(), temp.end())); 
    
    return answer;
}
