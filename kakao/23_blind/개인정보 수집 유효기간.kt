class Solution {
    fun solution(today: String, terms: Array<String>, privacies: Array<String>): IntArray {
        val answer = mutableListOf<Int>()
        
        val calcTotalDays = { ymd: List<Int> -> 
            ymd[0] * MONTH_OF_YEAR * DAY_OF_MONTH + ymd[1] * DAY_OF_MONTH + ymd[2]
        }
        
        val expireDaysByTerm = terms
            .map { it.split(' ') }
            .associate { (k, v) -> k to v.toInt() * DAY_OF_MONTH }
        
        privacies.forEachIndexed { index, privacy -> 
            val ymd = privacy.split(' ').first()
            val term = privacy.split(' ').last()
            
            val todayDate = calcTotalDays(today.toIntList(delimiter = '.'))
            val startDate = calcTotalDays(ymd.toIntList(delimiter = '.'))
            
            if(todayDate >= startDate + expireDaysByTerm.getValue(term)){
                answer.add(index + 1)
            }
        }
        
        return answer.toIntArray()
    }

    fun String.toIntList(delimiter: Char) = this.split('.').map { it.toInt() }
    
    companion object {
        private const val MONTH_OF_YEAR = 12
        private const val DAY_OF_MONTH = 28
    }
}