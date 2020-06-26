def maxx(a, b):
	n = a + b - 1
	nn = b-1
	return int(n*(n+1)*(n+2)/6)-(nn*(nn+1)/2)
	
def minn(a, b):
	n = a + b - 1
	nn = a-1
	return int(n*(n*n+5)/6)+(nn*(nn+1)/2)
	
t = int(input())

while t > 0:
	t = t-1
	x1, y1, x2, y2 = map(int,input().split(' '))
	x = x2 - x1 + 1
	y = y2 - y1 + 1
	if x < 1 or y < 1:
		print(0)
	else:
		print(int(maxx(x, y)-minn(x, y)+1))