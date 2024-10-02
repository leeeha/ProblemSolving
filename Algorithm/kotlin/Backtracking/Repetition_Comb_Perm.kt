class RepetitionCombPerm {
    val MAX = 10
    val selected = MutableList(MAX){0} // 선택된 원소 저장 
    var N = 0
    var M = 0

    // 중복 조합 
    fun combination(idx: Int, cnt: Int){
        if(cnt == M){
            printSelectedM()
            return
        }
        
        for(i in idx..N){
            selected[cnt] = i
            
            // 같은 원소 중복 선택이 가능하므로 
            // (i+1)이 아닌 i로 전달해야 함. 
            combination(i, cnt + 1) 
        }
    }

    // 중복 순열 
    fun permutation(cnt: Int){
        if(cnt == M){
            printSelectedM()
            return 
        }
        
        for(i in 1..N){
            selected[cnt] = i
            permutation(cnt + 1)
        }
    }

    fun printSelectedM(){
        for(i in 0 until M){
            print("${selected[i]} ")
        }
        println()
    }

    fun main(){
        N = (1..3).toList().size 
        M = 2
        
        combination(1, 0) // 6가지
        println()
        permutation(0) // 9가지 
    }
}