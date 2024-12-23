class Solution {
    fun solution(records: Array<String>): Array<String> {
        val answer = mutableListOf<String>()
        val map = hashMapOf<String, String>()
        
        var action = ""
        var uid = ""
        var nickname = ""

        for(record in records) {
            val s = record.split(" ")
            action = s[0]
            uid = s[1]
            if (s.size == 3){
                nickname = s[2]
            }
            
            // Enter 또는 Change 동작에 대해 
            // uid 기준으로 닉네임 수정 
            if(action != "Leave") {
                map.put(uid, nickname)
            }
        }
        
        for(record in records) {
            val s = record.split(" ")
            action = s[0]
            uid = s[1]
            if (s.size == 3){
                nickname = s[2]
            }
            
            when(action){
                "Enter" -> answer.add(getEnterMessage(map.getOrDefault(uid, "")))
                "Leave" -> answer.add(getLeaveMessage(map.getOrDefault(uid, "")))
            }
        }
        
        return answer.toTypedArray()
    }
    
    fun getEnterMessage(nickname: String) = "${nickname}님이 들어왔습니다."
    fun getLeaveMessage(nickname: String) = "${nickname}님이 나갔습니다."
}
