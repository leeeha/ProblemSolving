import java.util.*
import kotlin.math.*

/*
최대 길이가 1만인 문자열 t에서 
길이가 p.size인 부분 문자열을 추출하고 
그 중에서 크기가 p.toInt() 이하인 수는 몇개인가? 

Int는 최대 10자리 
Long형은 최대 19자리 
t는 최대 10000자리 -> 숫자로 변환하지 말고 문자열 자체로 비교하자! 
*/
class Solution {
    fun solution(t: String, p: String): Int {
        var answer: Int = 0
        val plen = p.length
        
        for(i in 0 until t.length - plen + 1){
            val temp = t.substring(i, i + plen)
            if(temp.compareTo(p) <= 0){
                answer++
            }
        }
        
        return answer
    }
}