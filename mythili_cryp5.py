fi=open('infl','rb')
b=fi.read(64)
fi.close()
fi=open('keyfl','rb')
k=fi.read(64)
fi.close()
pi=[((3*(i^49))+17)%64 for i in range(64)]
qi=[((11^(i+23))*29)%64 for i in range(64)]
pi1=[0 for i in range(64)]
qi1=[0 for i in range(64)]
for i in range(64):
	pi1[pi[i]]=i
	qi1[qi[i]]=i
def F(m):
	t=[((m[i]+k[i])%256)^17 for i in range(64)]
	return t
def G(m):
	t=[((m[i]+41)%256)^k[63-i] for i in range(64)]
	return t
def P(m):
	t=[m[pi[i]] for i in range(64)]
	return t
def Q(m):
	t=[m[qi[i]] for i in range(64)]
	return t
def R(m):
	return [((m[i]%32)*8)+int(m[(i+1)%64]/32) for i in range(64)]
def E1(a):
	w=R(Q(G(R(P(F(a))))))
	return w
def F1(m):
	t=[((m[i]^17)-k[i])%256 for i in range(64)]
	return t
def G1(m):
	t=[((m[i]^k[63-i])-41)%256 for i in range(64)]
	return t
def P1(m):
	t=[m[pi1[i]] for i in range(64)]
	return t
def Q1(m):
	t=[m[qi1[i]] for i in range(64)]
	return t
def R1(m):
	return [int(m[i]/8)+((m[(i-1)%64]%8)*32) for i in range(64)]
def D1(a):
	w=F1(P1(R1(G1(Q1(R1(a))))))
	return w
def D(x):
	n=x
	for _ in range(12):
		n=D1(n)
	return n
c=b
for _ in range(12):
	c=E1(c)
d=D(b)
u=D(c)
fo=open('outfl','wb')
fo.write(bytes(c))
fo.close()
fo=open('mythili.txt','w')
for i in [b,k,c,d]:
	fo.write('{'+','.join(map(str,i))+'}\n')
fo.write('{'+','.join(map(str,u))+'}')
fo.close()
