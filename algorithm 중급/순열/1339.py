N = int(input())    # 단어개수
words = []          # 단어
for i in range(N): words.append(input())

num = {}            # key : 알파벳, value : 계수
for i in range(N):
    for j in range(len(words[i])):
        if words[i][j] not in num:
            num[words[i][j]] = 10 ** (len(words[i])-j-1)
        else:
            num[words[i][j]] += 10 ** (len(words[i])-j-1)

num = sorted(num.items(), key = lambda x : x[1], reverse = True)

res = 0
for i in range(len(num)):
    num[i] = list(num[i])
    num[i][1] *= (9-i)
    res+= num[i][1]
print(res)