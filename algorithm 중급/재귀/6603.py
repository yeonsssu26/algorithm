def pick_numbers(start, depth): # DFS
    if (depth == 6): # k는 6이상 13미만이므로
        for i in range(len(res)):
            if(res[i] == 0): break
            else: print(res[i], end=" ")
        print("")
    else:
        for i in range(start, k):
            res.append(s[i])
            pick_numbers(i+1, depth+1)
            res.pop()

while(True):
    s = list(map(int, input().split())) # 집합
    k = s[0] # 원소개수
    res = [] # 조합결과
    if k == 0: break # 종료조건
    else:
        s.remove(k)
        pick_numbers(0,0)
        print("")