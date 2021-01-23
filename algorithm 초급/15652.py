n, r = map(int, input().split())
numbers = [1 + i for i in range(n)]
orders = []

def DFS(now, count):
    if count == r:
        print(*orders)
        return

    for i in range(now, n):
        orders.append(numbers[i])
        DFS(i, count+1)
        orders.pop()

DFS(0,0)