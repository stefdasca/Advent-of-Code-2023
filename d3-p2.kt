fun main(args: Array<String>){
    var n = 140
    var ans = 0
    var m = Array(142) {Array(142) {0} }
    var gear_product = Array(142) {Array(142) {0} }
    var gear_number = Array(142) {Array(142) {0} }
    val Ox = arrayOf(-1, -1, -1, 0, 0, 1, 1, 1)
    var Oy = arrayOf(-1, 0, 1, -1, 1, -1, 0, 1)
    for(i in 1..n)
    {
        val text = readln()
        for (x in 0..text.length-1){
            if (text[x] >= '0' && text[x] <= '9')
                m[i][x+1] = text[x] - '0'
            else
                if(text[x] == '.')
                    m[i][x+1] = 15
                else
                    if(text[x] == '*')
                        m[i][x+1] = -1
                    else
                        m[i][x+1] = -2
        }
    }

    for (i in 1..n)
    {
        var nr = 0
        var adjL = 0
        var adjC = 0
        for (j in 1..n)
        {
            if (m[i][j] >= 0 && m[i][j] <= 9)
            {
                nr = nr * 10 + m[i][j]
                for (q in 0..7)
                {
                    if (m[i + Ox[q]][j + Oy[q]] == -1)
                    {
                        adjL = i + Ox[q]
                        adjC = j + Oy[q]
                    }
                }
            }
            else
            {
                if (adjL > 0 || adjC > 0)
                {
                    gear_number[adjL][adjC]++;
                    if(gear_number[adjL][adjC] == 1)
                        gear_product[adjL][adjC] = nr
                    else
                        gear_product[adjL][adjC] *= nr
                }
                nr = 0
                adjL = 0
                adjC = 0
            }
        }
        if (adjL > 0 || adjC > 0)
        {
            gear_number[adjL][adjC]++;
            if(gear_number[adjL][adjC] == 1)
                gear_product[adjL][adjC] = nr
            else
                gear_product[adjL][adjC] *= nr
        }
        nr = 0
        adjL = 0
        adjC = 0
    }

    for(i in 1..n)
    {
        for (j in 1..n)
        {
            if (gear_number[i][j] == 2)
                ans += gear_product[i][j]
        }
    }
    println(ans)
}