n, m = map(int, input().split(' '))
a = [n]
b = [0] * n
c = [0] * 200000
z = ''

for i in range(n):
	a[i] = input().split(' ')

for i in range(m):
	x = a[i] - 1
	b[x] += 1
	c[b[x]] += 1
	if c[b[x]] == n:
		z += '1'
	else:
		z += '0'
		
print(z)
