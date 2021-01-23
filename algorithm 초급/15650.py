n, r = map(int, input().split())
numbers = [1 + i for i in range(n)]
visited = [False for i in range(n)]
orders = []

def DFS(x):
    if x == r:
        print(*orders)              # 배열의 요소 전체출력하는 방법!!
    
    for i in range(n):
        if visited[i] == True: continue

        orders.append(numbers[i])
        visited[i] = True

        DFS(x + 1)
        orders.pop()

        for j in range(i+1, n):     # i이하는 탐색에서 제외
            visited[j] = False

DFS(0)