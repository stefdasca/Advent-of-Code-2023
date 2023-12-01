fun main(args: Array<String>){
    var n = 1000
    var ans = 0
    for(i in 1..n)
    {
        val text = readln()
        var firstDigit = -1
        var lastDigit = -1
        for (i in 0..text.length-1){
            if (text[i] >= '0' && text[i] <= '9') {
                if (firstDigit == -1)
                    firstDigit = text[i] - '0'
                lastDigit = text[i] - '0'
            }
        }
        ans = ans + firstDigit * 10 + lastDigit
    }
    println(ans)
}