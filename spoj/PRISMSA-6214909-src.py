import math
ss = math.sin(60 * 2 * math.pi / 360.0)
t = int(input())
for i in range(t):
  v = float(input())
  s = (4.0**(2.0/3.0) * ss + 6.0/(4.0**(1.0/3.0) * ss)) * v**(2.0/3.0)
  print s
