t = int(input())
answers = []
for i in range(t):
  n = int(input())
  k = int(input())
  high = k % n;
  low = n - (k % n)
  if(k >= n):
    if(high > low):
      answers.append(2 * low)
    elif high < low:
      answers.append(2 * high)
    else:
      answers.append((2*(low - 1)) + 1)
  else:
    if(k > n - k):
      answers.append(2 * (n - k))
    elif(k < n - k):
      answers.append(2 * k)
    else:
      answers.append((2*(k-1)) + 1)
for answer in answers:
  print(answer)
