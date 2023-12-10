with open("input10.txt", "r", encoding="utf-8") as f:
    input_list = f.read().splitlines()

maze = {}
for i, line in enumerate(input_list):
    for j, char in enumerate(line):
        maze[i, j] = char
        if char == "S":
            start = (i, j)

answer1 = []
for cur_sign in ["-", "|", "J", "7", "F", "L"]:
    for cur_dir in ["L", "R", "U", "D"]:
        cur_pos = start
        visited = set()
        while cur_pos not in visited:
            visited.add(cur_pos)
            match cur_dir:
                case "R":
                    cur_pos = (cur_pos[0], cur_pos[1] + 1)
                    cur_sign = maze[cur_pos]
                    match cur_sign:
                        case "J":
                            cur_dir = "U"
                        case "7":
                            cur_dir = "D"
                        case "-":
                            continue
                        case _:
                            break
                case "L":
                    cur_pos = (cur_pos[0], cur_pos[1] - 1)
                    cur_sign = maze[cur_pos]
                    match cur_sign:
                        case "L":
                            cur_dir = "U"
                        case "F":
                            cur_dir = "D"
                        case "-":
                            continue
                        case _:
                            break
                case "U":
                    cur_pos = (cur_pos[0] - 1, cur_pos[1])
                    cur_sign = maze[cur_pos]
                    match cur_sign:
                        case "7":
                            cur_dir = "L"
                        case "F":
                            cur_dir = "R"
                        case "|":
                            continue
                        case _:
                            break
                case "D":
                    cur_pos = (cur_pos[0] + 1, cur_pos[1])
                    cur_sign = maze[cur_pos]
                    match cur_sign:
                        case "J":
                            cur_dir = "L"
                        case "L":
                            cur_dir = "R"
                        case "|":
                            continue
                        case _:
                            break
        answer1.append(len(visited))
        if len(visited) == max(answer1):
            longest = visited
print("Answer 1:", max(answer1) // 2)

bigger_maze = {}
for i, line in enumerate(input_list):
    for j, char in enumerate(line):
        if (i, j) not in longest:
            bigger_maze[(i * 3) + 0, (j * 3) + 0] = "0"
            bigger_maze[(i * 3) + 1, (j * 3) + 0] = "0"
            bigger_maze[(i * 3) + 2, (j * 3) + 0] = "0"
            bigger_maze[(i * 3) + 0, (j * 3) + 1] = "0"
            bigger_maze[(i * 3) + 1, (j * 3) + 1] = "0"
            bigger_maze[(i * 3) + 2, (j * 3) + 1] = "0"
            bigger_maze[(i * 3) + 0, (j * 3) + 2] = "0"
            bigger_maze[(i * 3) + 1, (j * 3) + 2] = "0"
            bigger_maze[(i * 3) + 2, (j * 3) + 2] = "0"
        else:
            match char:
                case "S":
                    bigger_maze[(i * 3) + 0, (j * 3) + 0] = "+"
                    bigger_maze[(i * 3) + 1, (j * 3) + 0] = "+"
                    bigger_maze[(i * 3) + 2, (j * 3) + 0] = "+"
                    bigger_maze[(i * 3) + 0, (j * 3) + 1] = "+"
                    bigger_maze[(i * 3) + 1, (j * 3) + 1] = "+"
                    bigger_maze[(i * 3) + 2, (j * 3) + 1] = "+"
                    bigger_maze[(i * 3) + 0, (j * 3) + 2] = "+"
                    bigger_maze[(i * 3) + 1, (j * 3) + 2] = "+"
                    bigger_maze[(i * 3) + 2, (j * 3) + 2] = "+"
                case "-":
                    bigger_maze[(i * 3) + 0, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 0] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 1] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 1] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 2] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 2] = "0"
                case "|":
                    bigger_maze[(i * 3) + 0, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 2, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 1, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 0, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 2, (j * 3) + 2] = "0"
                case "J":
                    bigger_maze[(i * 3) + 0, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 0] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 1, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 1] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 2, (j * 3) + 2] = "0"
                case "7":
                    bigger_maze[(i * 3) + 0, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 0] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 1] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 0, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 2, (j * 3) + 2] = "0"
                case "F":
                    bigger_maze[(i * 3) + 0, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 2, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 1] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 0, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 2] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 2] = "0"
                case "L":
                    bigger_maze[(i * 3) + 0, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 2, (j * 3) + 0] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 1, (j * 3) + 1] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 1] = "0"
                    bigger_maze[(i * 3) + 0, (j * 3) + 2] = "0"
                    bigger_maze[(i * 3) + 1, (j * 3) + 2] = "#"
                    bigger_maze[(i * 3) + 2, (j * 3) + 2] = "0"

bigger_maze[0, 0] = "."
queue = [(0, 1), (1, 0), (1, 1)]
while len(queue) != 0:
    i, j = queue.pop()
    if bigger_maze[i, j] == "0":
        for x in [(i - 1, j - 1), (i, j - 1), (i + 1, j - 1), (i - 1, j), (i + 1, j), (i - 1, j + 1),
                  (i, j + 1),
                  (i + 1, j + 1)]:
            if x in bigger_maze and bigger_maze[x] == ".":
                bigger_maze[i, j] = "."
            if x in bigger_maze and bigger_maze[x] == "0":
                queue.append(x)

answer2 = 0
for i, line in enumerate(input_list):
    for j, char in enumerate(line):
        if bigger_maze[(i * 3) + 0, (j * 3) + 0] == "0" and bigger_maze[(i * 3) + 1, (j * 3) + 0] == "0" and \
                bigger_maze[(i * 3) + 2, (j * 3) + 0] == "0" and bigger_maze[(i * 3) + 0, (j * 3) + 1] == "0" and \
                bigger_maze[(i * 3) + 1, (j * 3) + 1] == "0" and bigger_maze[(i * 3) + 2, (j * 3) + 1] == "0" and \
                bigger_maze[(i * 3) + 0, (j * 3) + 2] == "0" and bigger_maze[(i * 3) + 1, (j * 3) + 2] == "0" and \
                bigger_maze[(i * 3) + 2, (j * 3) + 2] == "0":
            answer2 += 1
print("Answer 2:", answer2)