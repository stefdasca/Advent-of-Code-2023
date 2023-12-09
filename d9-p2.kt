import java.util.Scanner
fun main(args: Array<String>){
    val input = Scanner(System.`in`)

    var n = 200
    var times = IntArray(5000) { 0 }
    var times2 = IntArray(5000) { 0 }
    var ans = 0

    for(i in 1..n)
    {
        val text = readln()
        var cnt = 0
        var number = 0
        var neg = 0
        for (i in 0..text.length-1){
            if (text[i] >= '0' && text[i] <= '9') {
                number = number * 10 + (text[i] - '0')
            }
            else
            {
                if(text[i] == '-')
                    neg = 1
                else {
                    times[cnt] = number
                    if(neg == 1)
                        times[cnt] *= -1
                    cnt += 1
                    number = 0
                    neg = 0
                }
            }
        }
        times[cnt] = number
        if(neg == 1)
            times[cnt] *= -1
        cnt += 1
        var len = 0
        times2[len] = times[0]
        len += 1
        while(cnt > 1)
        {
            cnt -= 1
            for (i in 0..cnt-1) {
                times[i] = times[i + 1] - times[i]
            }

            times2[len] = times[0]
            len += 1
            var allzeroes = 1
            for(i in 0..cnt-1)
                if(times[i] != 0)
                    allzeroes = 0
            if(allzeroes == 1)
                break
        }
        var newval = 0
        val range = 0..len-1
        var parity = 0
        for(i in range.reversed()) {
            if (i > 0)
                times2[i - 1] = times2[i - 1] - times2[i]
            newval = times2[i]
        }
        ans += newval
    }
    println(ans)
}