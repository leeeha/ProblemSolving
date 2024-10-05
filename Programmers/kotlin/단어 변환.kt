import kotlin.math.*

class Solution {
    var answer = 50
    var targetWord = ""
    lateinit var arr: Array<String>
    lateinit var visited: MutableList<Boolean> 
    
    fun solution(begin: String, target: String, words: Array<String>): Int {
        arr = words
        visited = MutableList(words.size) { false }
        targetWord = target
        
        if(!words.contains(target)) return 0
        dfs(begin, 0)
    
        return answer
    }
    
    fun dfs(now: String, depth: Int){
        // 현재까지의 최단 거리보다 크면 패스 
        if(answer <= depth) return 
        
        // 타켓 단어에 도달한 경우, 최단 거리 갱신 
        if(now == targetWord){
            answer = min(answer, depth)
            return 
        }
        
        for(i in 0 until arr.size){
            if(now == arr[i]) continue
            
            // 한 글자 차이나면서 이전에 방문하지 않은 경우 
            if(possible(now, arr[i]) && !visited[i]){
                visited[i] = true 
                dfs(arr[i], depth + 1)
                visited[i] = false 
            }
        }
    }
    
    fun possible(a: String, b: String): Boolean {
        var cnt = 0
        for(i in 0 until a.length){
            if(a[i] != b[i]) cnt++
        }
        return cnt == 1
    }
}