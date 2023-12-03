fun main(args: Array<String>){
    var n = 140
    var ans = 0
    var m = Array(142) {Array(142) {0} }
    for(i in 1..n)
    {
        val text = readln()
        for (x in 0..text.length-1){
            if (text[x] >= '0' && text[x] <= '9') {
                m[i][x+1] = text[x] - '0'
            }
            else
                if(text[x] == '.')
                    m[i][x+1] = 15
                else
                    m[i][x+1] = -1
        }
    }

    for (i in 1..n)
    {
        var nr = 0
        var adj = 0
        for (j in 1..n)
        {
            if (m[i][j] >= 0 && m[i][j] <= 9) {
                nr = nr * 10 + m[i][j]
                if (m[i - 1][j] == -1 || m[i - 1][j - 1] == -1 || m[i - 1][j + 1] == -1 || m[i][j - 1] == -1 || m[i][j + 1] == -1 || m[i + 1][j] == -1 || m[i + 1][j - 1] == -1 || m[i + 1][j + 1] == -1)
                    adj = 1
            }
            else
            {
                ans += nr * adj
                nr = 0
                adj = 0
            }
        }
        ans += nr * adj
        nr = 0
        adj = 0
    }
    println(ans)
}