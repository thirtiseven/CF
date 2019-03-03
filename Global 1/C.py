q = int(input())
for t in range(0, q):
	a = int(input())
	if (a + 1) & a:
		print(2 ** (a.bit_length()) - 1)
	else:
		x = 2
		while a % x:
			if x * x > a:
				x = a
				break
			x = x + 1
		print(a // x)
	