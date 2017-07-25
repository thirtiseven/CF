a, b= map(int, input().split())  
flag = 0
while a >= 0 and b >= 0:
	flag = flag + 1
	if flag % 2 == 0:
		b = b - flag
	else:
		a = a - flag
if flag % 2 == 0:
	print("Valera")
else:
	print("Vladik")