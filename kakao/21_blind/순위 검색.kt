class Solution {
    val answer = mutableListOf<Int>()
    val hash = HashMap<String, MutableList<Int>>()
    
    fun solution(info: Array<String>, query: Array<String>): MutableList<Int> {
    	// 각 개발자가 속할 수 있는 그룹 만들기
        createGroup(info)
        
        // 점수 배열 오름차순 정렬 
        hash.values.forEach {
            it.sort()
        }
        
        // 조건에 부합하는 개발자 수 카운트 (이진 탐색)
        for(str in query){
            countEligibleDevelopers(str)
        }
        
        return answer
    }
    
    fun createGroup(info: Array<String>){
        // 중복 순열 
        info.forEach {
            dfs(
                key = "", 
                cnt = 0,
                arr = it.split(" ").toTypedArray()
            )
        }
    }
    
    fun dfs(key: String, cnt: Int, arr: Array<String>){
        if(cnt == 4){
            val score = arr[cnt].toInt()
            if(!hash.containsKey(key)){
                hash[key] = mutableListOf(score)
            }else{
                hash[key]!!.add(score)
            }
            return
        }
        
        // arr[cnt]: 개발자의 cnt번째 속성 (언어, 직군, 경력, 소울푸드)
        dfs(key + "-", cnt + 1, arr)
        dfs(key + "${arr[cnt]}", cnt + 1, arr)
    }
    
    fun countEligibleDevelopers(str: String){
        val arr = str.replace(" and ", "").split(" ")
        val key: String = arr[0]
        val score: Int = arr[1].toInt()
        answer.add(binarySearch(key, score))
    }
    
    // 점수가 x 이상인 개발자 수 반환 
    fun binarySearch(key: String, x: Int): Int {
        if(!hash.containsKey(key)) return 0 
        
        val scores = hash[key]!!
        var left = 0
        var right = scores.lastIndex
        
        while(left <= right){
            val mid = (left + right) / 2
            if(scores[mid] < x){
                left = mid + 1 
            }else{
                right = mid - 1
            }
        }
        
        return scores.size - left
    }
}