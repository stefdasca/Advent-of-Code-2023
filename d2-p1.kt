fun main(args: Array<String>){
    var n = 100
    var ans = 0
    for(i in 1..n)
    {
        val text = readln()
        var maxRed = 0
        var maxBlue = 0
        var maxGreen = 0
        var nr = 0
        for (i in 0..text.length-1){
            if (text[i] >= '0' && text[i] <= '9') {
                nr = nr * 10 + (text[i] - '0')
            }
            else
            {
                if(text[i] == ' '){
                    continue
                }
                if (text[i] == 'r') {
                    if (nr >= maxRed)
                        maxRed = nr
                }
                if(text[i] == 'b'){
                    if(nr >= maxBlue)
                        maxBlue = nr
                }
                if(text[i] == 'g') {
                    if (nr >= maxGreen)
                        maxGreen = nr
                }
                nr = 0
            }
        }
        if(maxRed <= 12 && maxBlue <= 14 && maxGreen <= 13)
            ans += i
    }
    println(ans)
}