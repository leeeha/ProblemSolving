#include<vector>
#include<algorithm>
using namespace std;

// 음식 번호를 기준으로 오름차순 정렬
bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k){
    // (음식을 먹는 데 걸리는 시간, 음식 번호)를 묶어서 저장하기
    vector<pair<int, int>> foods;
    int n = food_times.size(); // 처리할 음식의 개수
    for (int i = 0; i < n; i++){
        foods.push_back(make_pair(food_times[i], i + 1));
    }

    // 시간을 기준으로 오름차순 정렬
    sort(foods.begin(), foods.end());

    int prevTime = 0;
    // auto -> vector<pair<int, int>>::iterator
    // 처리해야 할 음식의 개수 n은 하나씩 줄어든다.
    for (auto it = foods.begin(); it != foods.end(); it++, n--){
        int gap = it->first - prevTime; // 시간 간격
        long long spendTime = (long long)gap * n; // int * int -> int 범위 넘을 수도 있기 때문에 ll 타입으로 캐스팅
        if(gap == 0) continue;
        
        if(spendTime <= k){
            k -= spendTime; // 여기서 k를 한번에 확 줄일 수 있다!
            prevTime = it->first; 
        }else{ 
            k %= n;
            sort(it, foods.end(), comp); // 음식 번호를 기준으로 다시 정렬
            return (it + k)->second; // k%n 인덱스에 해당하는 음식 번호 리턴
        }
    }
    
    return -1; // k초 이내에 모든 음식을 다 먹은 경우
}