import sys
def printf(fmt, *varargs):
    sys.stdout.write(fmt % varargs)
t = int(raw_input())
for i in range(1,t+1):
  n=int(raw_input())
  s=raw_input()
  x = s.split(' ')
  sum=0
  ans=1
  for j in range(n):
    sum+=int(x[j])
    if sum<0:
      ans+=-sum
      sum=0
  printf("Scenario #%d: ",i)
  print ans