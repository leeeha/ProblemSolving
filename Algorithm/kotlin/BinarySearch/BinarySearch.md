```kotlin
fun binarySearch(nums: List<Int>, key: Int): Int {
    var left = 0
    var right = nums.size - 1
    
    while(left <= right){
        var mid = (left + right) / 2
        
        if(key == nums[mid]) return mid
        else if(key < nums[mid]) right = mid - 1
        else left = mid + 1
    }
    
    return -1 // not found
}

fun main(){
    val nums = mutableListOf(0, 4, 9, 2, 1, 8, 6, 7, 5, 3)
    nums.sort() // 0 1 2 3 4 5 6 7 8 9 
    println(binarySearch(nums, 3)) // 3 
}
```