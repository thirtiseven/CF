t = int(input())

while t > 0:
	t = t-1
	n = int(input())
	n = n//2
	n = n*(n+1)*(2*n+1)*8/6
	print(int(n))
	