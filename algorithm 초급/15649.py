n, r = map(int, input().split())                    # n, r 입력
numbers = [1 + i for i in range(n)]                 # n 이하 숫자배열
visited = [False for i in range(n)]                 # 방문체크 배열
orders = []                                         # 방문순서 배열

def DFS(x):                                         # DFS 함수 정의
    if x == r: 
        # for i in range(r):
        #     print(orders[i], end = " ")
        print(*orders)                              # 배열의 요소 전체출력하는 방법!!
    
    for i in range(n):
        if visited[i] == True: continue             # 중복될 경우 pass
    
        orders.append(numbers[i])
        visited[i] = True

        DFS(x+1)

        orders.pop()
        visited[i] = False

DFS(0)
