def lfsr(n,k,k2,k3,st):
	t=0
	p=[int(st[i]) for i in range(n)]
	a=p[:] #Present string output
	lfs=str(p[0])
	if (k2):
		while (True):
			o=(p[k]+p[k2]+p[k3]+p[0])%2
			p=p[1:]+[o]
			t+=1
			if p!=a:
				lfs+=str(p[0])
			else:
				return lfs,t
	else:
		while (True):
			o=(p[k]+p[0])%2
			p=p[1:]+[o]
			t+=1
			if p!=a:
				lfs+=str(p[0])
			else:
				return lfs,t
f=open('key','r')
s=''
for i in range(15):
	s+='{0:03b}'.format((ord(f.read(1))%9)%8)
f.close()
a,l1=lfsr(15,14,0,0,s[:15])		#Output is a string of 0s and 1s
b,l2=lfsr(13,12,10,9,s[15:28])
c,l3=lfsr(17,14,0,0,s[28:])
f=open('lfsr1.txt','w')
g=open('lfsr2.txt','w')
h=open('lfsr3.txt','w')
o=open('prng.txt','w')
for i in range(800):
	if c[i]=='1':
		s=a[i]
	else:
		s=b[i]
	f.write(a[i])
	g.write(b[i])
	h.write(c[i])
	o.write(s)
f.close()
g.close()
h.close()
o.close()
f=open('input','rb')
g=open('output','wb') #h=open("copy",'wb') #x=[] i=-1
ac,bc,cc=0,0,0
for ch in iter(lambda:f.read(1),b''):
	s='' #i+=1
	for j in range(8):
		if c[cc]=='1':
			s+=a[ac]
		else:
			s+=b[bc]
		ac,bc,cc=(ac+1)%l1,(bc+1)%l2,(cc+1)%l3
	x=int(s,2)
	g.write(bytearray([x^ord(ch)])) #g.seek(0)for k in x: h.write(bytes([k^ord(g.read(1))])) #print(i)
f.close()
g.close()
