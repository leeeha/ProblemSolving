import kotlin.math.max 

class Solution {
    val MAX_TIME = 24*60 + 10
    val CLEAN_TIME = 10 
    val rooms = IntArray(MAX_TIME) {0}
    
    fun solution(bookTimes: Array<Array<String>>): Int {
        var lastTime = -1
        
        for(time in bookTimes){
            val start = time[0].toMinutes()
            val end = time[1].toMinutes()
            
            rooms[start] += 1
            rooms[end + CLEAN_TIME] -= 1
            
            lastTime = max(lastTime, end)
        }
        
        for(i in 1..lastTime) {
            rooms[i] += rooms[i - 1]
        }
        
        return rooms.maxOrNull() ?: -1
    }
    
    fun String.toMinutes(): Int {
        val times = split(":").map { it.toInt() }
        return times[0] * 60 + times[1]
    }
}