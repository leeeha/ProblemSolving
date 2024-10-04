import java.util.*
import kotlin.math.*

class Solution {
    fun solution(s: String): Int {
        var answer = 0
        val counting = arrayOf(0, 0)
        var x = s[0]
        var splitted = false
        
        s.forEachIndexed { idx, ch ->
            if(splitted){
                x = ch // 첫문자 갱신 
                splitted = false // 분리 여부 갱신 
            }
            
            // 첫문자와 같은지 검사 
            if(x == ch){
                counting[0]++
            }else{
                counting[1]++
            }
            
            // 개수 비교 & 마지막 문자 예외 처리 
            if(counting[0] == counting[1] || idx == s.lastIndex){
                answer++
                splitted = true 
            }
        }
        
        return answer 
    }
}