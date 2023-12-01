fun main(args: Array<String>){
    var n = 1000
    var ans = 0
    for(i in 1..n)
    {
        val text = readln()
        var firstDigit = -1
        var lastDigit = -1
        val v = arrayOf("one", "two", "three", "four", "five", "six", "seven", "eight", "nine");
        for (i in 0..text.length-1){
            if (text[i] >= '0' && text[i] <= '9')
            {
                if(firstDigit == -1)
                    firstDigit = text[i] - '0'
                lastDigit = text[i] - '0'
            }
            else
            {
                for (j in 0..8)
                {
                    if (i + v[j].length <= text.length)
                    {
                        var ok = 1
                        for (x in 0..v[j].length-1)
                            if(text[i + x] != v[j][x])
                                ok = 0
                        if(ok == 1)
                        {
                            if(firstDigit == -1)
                                firstDigit = j+1;
                            lastDigit = j+1;
                        }
                    }
                }
            }
        }
        ans = ans + firstDigit * 10 + lastDigit
    }
    println(ans)
}