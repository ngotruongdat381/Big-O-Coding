#

n = int(input())

buttons = list(map(int, input().split()))

total = 0;

for i in range(0, len(buttons)):
    total = total + buttons[i]

if (n > 1 and total == n - 1) or (n == 1 and total == 1):
    print("YES")
else:
    print("NO")

