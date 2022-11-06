#include <string>
using namespace std;

int solution(string s){
    int answer = s.size(); // 주어진 문자열의 길이

    // 1개 단위(step)부터 압축 단위를 늘려가며 확인
    for (int step = 1; step <= s.size() / 2; step++){
        string compressed = "";
        string prev = s.substr(0, step); // 앞에서부터 step만큼의 문자열 추출
        int cnt = 1; // 특정 부분 문자열이 반복된 횟수 측정

        // 단위(step) 크기만큼 증가시키며 이전 문자열과 비교
        for (int j = step; j < s.size(); j += step){
            // 이전 문자열과 동일하다면 cnt 증가
            if(prev == s.substr(j, step)) 
                cnt++;
            // 다른 문자열이 나왔다면 (더 이상 압축 불가)
            else{
                compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;

                // 다시 상태 초기화 
                prev = s.substr(j, step); // step이 문자열의 길이를 넘어서도 문자열 끝까지만 추출
                cnt = 1;
            }
        }

        // 남아있는 문자열에 대해서 처리
       compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;

       // 만들어진 압축 문자열 중에서 가장 짧은 것이 정답
       answer = min(answer, (int)compressed.size());
    }

    return answer;
}