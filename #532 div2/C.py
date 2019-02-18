import math
n, r = map(float, input().split(' '))
s = math.sin(math.pi/n)
print(s/(1-s)*r)