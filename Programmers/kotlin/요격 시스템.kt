import kotlin.math.min

class Solution {
    fun solution(targets: Array<IntArray>): Int {
        var answer = 0
        
        // 시작점 기준으로 오름차순 정렬 
        targets.sortBy { it[0] }
        
        var curEnd = 0 
        var nextStart = 0
        var nextEnd = 0 
        
        for(t in targets){
            nextStart = t[0]
            nextEnd = t[1]
            
            // 요격 미사일이 더 필요한 경우 
            if(curEnd <= nextStart){
                answer++ 
                
                // 다음 미사일의 범위로 이동 
                curEnd = nextEnd 
            }else{
                // 요격 범위가 겹치는 경우
                // 더 작은 값으로 엔드 포인트 갱신 (필요한 개수 최소화) 
                curEnd = min(curEnd, nextEnd)
            }
        }
        
        return answer
    }
}
