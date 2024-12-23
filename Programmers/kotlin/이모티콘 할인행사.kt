/*
N명의 유저에게 M개의 할인 이모티콘 판매
=> 1) 플러스 가입자 수 최대화, 2) 판매액 최대화 

할인율(10,20,30,40) >= x인 이모티콘 모두 구매 
=> 판매액 증가 

구매 비용의 합 >= y이면, 기존 구매 모두 취소하고 플러스에 가입 
=> 판매액 감소, 플러스 가입자수 증가 

이모티콘 1~7번 할인율 책정 
=> 4^7 = 16384 (중복 순열)
*/
import kotlin.math.max 

class Solution {
    var N = 0
    var M = 0 
    lateinit var selected: IntArray // 10~40 중에 하나 선택 
    lateinit var userInfo: Array<IntArray>
    lateinit var emoticonPrice: IntArray
    val discountRates = listOf(10, 20, 30, 40)
    var maxRegisterUser = 0
    var maxSalesAmount = 0 
    
    fun solution(users: Array<IntArray>, emoticons: IntArray): IntArray {
        N = users.size 
        M = emoticons.size 
        selected = IntArray(M) { 0 }
        userInfo = users
        emoticonPrice = emoticons
        
        dfs(0)
        
        return intArrayOf(maxRegisterUser, maxSalesAmount)
    }
    
    // cnt: 선택한 숫자의 개수 
    fun dfs(cnt: Int) {
        if(cnt == M) {
            // 책정된 할인율에 대해 
            // 각 유저의 구매 비용 합 계산 
            val (user, amount) = calcResult()
            
            // 최대 가입자 수, 판매액 갱신 
            if(user > maxRegisterUser) {
                maxRegisterUser = user
                maxSalesAmount = amount
            }else if(user == maxRegisterUser) {
                maxSalesAmount = max(maxSalesAmount, amount)
            }
            
            return 
        }
        
        for(i in 0..3) {
            selected[cnt] = discountRates[i]
            dfs(cnt + 1)
        }
    }
    
    fun calcResult(): Array<Int> {
        var registerUser = 0
        var salesAmount = 0 
        
        for(i in 0..N-1){ // 최대 100 
            val x = userInfo[i][0]
            val y = userInfo[i][1]
            var totalPrice = 0.0 
            
            for(i in 0..M-1){ // 최대 7 
                val discountRate = selected[i].toDouble()
                if(discountRate >= x){
                    totalPrice += emoticonPrice[i] * (1 - discountRate / 100)
                }
            }
            
            if(totalPrice.toInt() >= y) {
                registerUser++ 
            }else{
                salesAmount += totalPrice.toInt()
            }
        }
        
        return arrayOf(registerUser, salesAmount)
    }
}