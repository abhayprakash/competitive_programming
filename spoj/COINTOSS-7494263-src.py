t = int(raw_input())
for i in range(t):
  s = raw_input()
  x=s.split(' ');
  n = 2 * (2**(int(x[0])) - 2**(int(x[1])))
  print str(n)+".00"