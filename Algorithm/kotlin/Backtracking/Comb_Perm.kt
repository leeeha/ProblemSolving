class CombPerm {
    val MAX = 10
    val arr = MutableList(MAX){0} // 선택된 원소 저장 
    val selected = MutableList(MAX){false} // 원소 선택 여부 
    var N = 0
    var M = 0

    // N개 중에 M개 선택 
    // 현재 숫자 번호, 뽑은 개수 
    fun combination(idx: Int, cnt: Int){
        if(cnt == M){
            printSelectedM()
            return 
        }
        
        // 인덱스 idx부터 시작 
        // 순서가 달라도 같은 경우로 취급 
        for(i in idx..N){ 
            if(!selected[i]){
                selected[i] = true  
                arr[cnt] = i // 선택된 숫자 저장 
                combination(i + 1, cnt + 1) 
                selected[i] = false
            }
        }
    }

    // N개 중에 M개 선택하여 나열 
    fun permutation(cnt: Int){
        if(cnt == M){
            printSelectedM()
            return 
        }
        
        // 인덱스 항상 1부터 시작
        // 순서가 다르면 다른 경우로 취급
        for(i in 1..N){ 
            if(!selected[i]){
                selected[i] = true
                arr[cnt] = i // 선택된 숫자 저장 
                permutation(cnt + 1) 
                selected[i] = false
            }
        }
    }

    fun printSelectedM(){
        for(i in 0 until M){
            print("${arr[i]} ")
        }
        println()
    }

    fun main(){
        N = (1..3).toList().size 
        M = 2
        
        combination(1, 0) // 3가지 
        println()
        permutation(0) // 6가지 
    }
}