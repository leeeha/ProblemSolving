#include <string>
#include <vector>
#include <queue> 
using namespace std;

int solution(int bridgeLength, int weight, vector<int> arr) {
    int time = 0; 
    int nextTruckIdx = 0; 
    int weightSum = 0; 
    queue<int> q; 
    
    // bridgeLength 만큼 큐를 0으로 채운다. 
    for(int i = 0; i < bridgeLength; i++){
        q.push(0); 
    }
    
    while(!q.empty()){
        time++; // 시간 측정 

        weightSum -= q.front(); // 앞에서 하나 꺼내기 
        q.pop(); 
        
        // 대기 트럭이 있는 경우 
        if(nextTruckIdx < arr.size()){
            // 무게 한도를 넘어가지 않으면 트럭 추가 
            if(weightSum + arr[nextTruckIdx] <= weight){
                weightSum += arr[nextTruckIdx];
                q.push(arr[nextTruckIdx]);
                nextTruckIdx++; 
            }else{
                // 무게 한도를 넘어가면 0을 추가 
                q.push(0); 
            }
        }
        
        // 대기 트럭을 모두 처리한 경우, 큐에 아무것도 추가하지 않는다. 
    }
    
    return time;
}