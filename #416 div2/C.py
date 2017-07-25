a = [0] * 5010 
fi = [0] * 5010
se = [0] * 5010
dp = [0] * 5010
vis = [0] * 5020
n = input();
a = list(map(int, input().split()))
for i in a:
	if fi[a[i]] == 0:
		fi[a[i]] = i
	se[a[i]] = i
for i in range(1, int(n)+1):
	dp[i] = dp[i-1]
	st = i
	res = 0
	j = i
	while j >= 0:
		te = a[j]
		if vis[te] == 0:
			if se[te] > i:
				break
			if fi[te] < st:
				st = fi[te]
			res = res ^ te
			vis[te] = 1
		if j <= st:
			dp[i] = max(dp[i], dp[j-1] + res);
		j -= 1;
print(dp[n])

