n, m = map(int, raw_input().split())
val = map(int, raw_input().split())
for i in xrange(m):
	l, r, x = map(int, raw_input().split())
	count = 0
	for j in xrange(l-1, r):
		if j < (x-1) and val[j] > val[x-1]:
			count += 1
		elif j > (x-1) and val[j] < val[x-1]:
			count -= 1
	if count == 0:
		print 'Yes'
	else:
		print 'No'