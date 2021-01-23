n, r = map(int, input().split())
numbers = [1 + i for i in range(n)]
#visited = [False for i in range(n)]     # 중복을 허용하므로 visited 배열이 필요 없음
orders = []

def DFS(x):
    if x == r:
        print(*orders)
        return

    for i in range(n):
        orders.append(numbers[i])
        DFS(x+1)
        orders.pop()
    
DFS(0)