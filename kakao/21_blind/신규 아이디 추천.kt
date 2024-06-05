class Solution {
    fun solution(newId: String) = newId
        .toStepOne()
        .toStepTwo()
        .toStepThree()
        .toStepFour()
        .toStepFive()
        .toStepSix()
        .toStepSeven()
}

fun String.toStepOne() = this.lowercase()

fun String.toStepTwo() = this.filter {
    it.isLowerCase() || it.isDigit() || it == '-' || it == '_' || it == '.'
}

fun String.toStepThree() = this.replace("[.]*[.]".toRegex(), ".")

fun String.toStepFour() = this.removePrefix(".").removeSuffix(".")

fun String.toStepFive() = this.let { if (it.isEmpty()) "a" else it }

fun String.toStepSix() = this.let {
    if (it.length > 15) it.substring(0, 15) else it 
}.removeSuffix(".")

fun String.toStepSeven() = this.let {
    if (it.length <= 2) {
        StringBuilder(it).run {
            while (length < 3) append(it.last())
            toString()
        }
    }
    else it 
}