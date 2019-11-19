#(4)
from math import pi#,cos
theta=2*pi
def fn(x):#x=x%(4*pi)#c=cos(x)
	t=-((x*x)/2)#x%=37
	n=1
	S=1+t
	while abs(t)>=0.005 and n<50:#x\in[-37,37],abs(S-c)>=0.005:
		n+=1
		t=t*(-(x*x))/(((2*n)-1)*(2*n))
		S+=t
	return n
fn(theta)
#(5)
def bn(l):
	if not l:
		return 0.0
	a='0.'
	xj=l
	j=0
	while xj!=0 and j<50:
		b,c=(lambda x: (x[0],x[1:]))(str(2*xj))
		a+=b
		j+=1
		xj=float(c)
	print(a)
