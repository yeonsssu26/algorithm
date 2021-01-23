# 초기화, 입력
k = int(input())                            # 부등호 개수 입력 (부등호 : k개, 숫자 : k+1개)
ineq_str = input()                          # 부등호 str으로 입력받음
ineq = ineq_str.split()                     # 부등호를 배열에 저장

# 최댓값 구하기
max_arr = []
for i in range(k+1):
    max_arr.append(9-i)

for i in range(1,k+1):
    for j in range(0,i): # 양옆만 비교하는 것이 아니라 이전꺼 전부 비교해야 함 # 뒤에서 앞으로 swap
        if(ineq[i-j-1] == '<' and max_arr[i-j-1] > max_arr[i-j]):
            tmp = max_arr[i-j]
            max_arr[i-j] = max_arr[i-j-1]
            max_arr[i-j-1] = tmp

        elif(ineq[i-j-1] == '>' and max_arr[i-j-1] < max_arr[i-j]):
            tmp = max_arr[i-j]
            max_arr[i-j] = max_arr[i-j-1]
            max_arr[i-j-1] = tmp

max_str = ""
for i in range(len(max_arr)):       # array to string
    max_str += str(max_arr[i])

print(max_str)                      # 최댓값 출력


# 최솟값 구하기
min_arr = []
for i in range(k+1):
    min_arr.append(i)

for i in range(1, k+1):
    for j in range(0,i): # 양옆만 비교하는 것이 아니라 이전꺼 전부 비교해야 함 # 앞에서 뒤로 swap
        if(ineq[i-j-1] == '<' and min_arr[i-j-1] > min_arr[i-j]):
            tmp = min_arr[i-j]
            min_arr[i-j] = min_arr[i-j-1]
            min_arr[i-j-1] = tmp

        elif(ineq[i-j-1] == '>' and min_arr[i-j-1] < min_arr[i-j]):
            tmp = min_arr[i-j]
            min_arr[i-j] = min_arr[i-j-1]
            min_arr[i-j-1] = tmp

min_str = ""
for i in range(len(min_arr)):       # array to string
    min_str += str(min_arr[i])

print(min_str)                      # 최솟값 출력