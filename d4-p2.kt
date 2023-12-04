fun main(args: Array<String>){
    var n = 204
    var total = 0
    var mars = IntArray(205) { 1 }
    for(i in 1..n)
    {
        var text = readln()
        text += 'x'
        var colon = 0
        var line = 0
        var hashMap : HashMap<Int, Int> = HashMap<Int, Int> ()
        var nr = 0
        var ans = 0
        for (i in 0..text.length-1)
        {
            if (text[i] == ':')
                colon = 1
            if (text[i] == '|')
                line = 1
            if (colon == 1)
            {
                if (text[i] >= '0' && text[i] <= '9')
                    nr = nr * 10 + (text[i] - '0')
                else
                    if (nr != 0)
                    {
                        if (line == 1) {
                            if(hashMap.containsKey(nr) == true)
                                ans++
                            nr = 0
                        }
                        else {
                            hashMap.put(nr, 1)
                            nr = 0
                        }
                    }
            }
        }
        total += mars[i]
        for (j in i+1..i+ans)
            if (j <= 204)
                mars[j] += mars[i]
    }
    println(total)

}