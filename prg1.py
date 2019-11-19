import sys
sys.setrecursionlimit(5000)
n=4; c=0 #c=9057=no.of edges
s=[] #a='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
f=open("w4","r")
for w in f:
	s.append(w.rstrip())
f.close(); del f
l=len(s) #no.of 4-letter words
d=[]
A=[]
for i in range(l):
	d.append([])
	A.append([False]*l)
x=''
def bs(w):
	b=0
	e=len(x)-1#m=(l-1)//2
	while b<=e:
		m=(b+e)//2
		if x[m]==w:
			return m
		elif x[m]<w:
			b=m+1
		elif x[m]>w:
			e=m-1
	return l+1
for i in range(l-1):
	w=s[i]
	x=s[(i+1):]
	for j in range(n):
		for k in range(ord(w[j])+1,91):
			w1=w[:j]+chr(k)+w[(j+1):]
			try:
				m=i+bs(w1)+1
				y=s[m]
				d[i].append(m)
				d[m].append(i); c+=1 
				A[i][m]=A[m][i]=True#if w1!=y: print ("Error!!")raise SystemExit(0)
			#if i==6 and len(d[6])<15: print("\n:",w1,y,s[m])if m==6 and len(d[6])<20: print("\n!!",w1,y,s[m],s[i])
			except: 
				pass #print (c,l,len(d[0]),s[0],d[0][:15])
#print ('\n',s[6],[s[i] for i in d[6][:15]])   #print(min([len(i) for i in d]))
print (c,l)
print ("\n\nConnection density = ",(2*c)/(l*(l-1))) # Connection density = 0.0034436332707367978


C=[]         #C[i]=list of vertices in comp i
m=[False]*l  #marked vertices
com=-1   #no.of comps-1
cn=[0]*l #comp number
cs=[]    #cs[com]=no.of vertices in comp com=comp size
lc=[1,[0]] #lc=largest comp, lc[0]=size of lc, lc[1]=list of comp no.s with size lc[0]
def dfs(u):#print("-")
	cn[u]=com
	m[u]=True
	cs[com]+=1
	for v in d[u]:
		if not m[v]:#print(d[v],s[v])
			C[com].append(v)
			dfs(v)
for u in range(l):
	if not m[u]:
		com+=1
		cs.append(0)
		C.append([u])
		dfs(u)
		if lc[0]<cs[com]:
			lc[0]=cs[com]
			lc[1]=[com]
		elif lc[0]==cs[com]
			lc[1].append(com)
print("\n\nNo.of components = ",com+1)
deg=[len(i) for i in d]  #2.b) deg[i]=degree of i
#f=open("deg","w")
#for i in d:
#	f.write(str(len(i)))
#	f.write('\n')
#f.close(); del f
#print("\n\n::",[(s[i],i) for i in range(l) if deg[i]==25])     #word with deg=25='mare'

#cc=list(map(len,[list(filter(lambda x:deg[x]-1,i)) for i in d]))    #wrong
#print("\n\n",len(cc),cc[:30],d[:6],s[2],s[1],s[5])
#lcc=[cc[i]/deg[i] for i in range(l)]

cc=[0]*l
for i in range(len(d)):
	for j in range(len(d[i])-1):
		for k in range((j+1),len(d[i])):
			if A[j][k]:
				cc[i]+=1
f=open("cc","w")
for i in cc:
	f.write(str(i))
	f.write('\n')
f.close(); del f

#v=[]
p={}
def bfs(u):
	#v=[False]*lc[0]
	Q=[u]
	while Q!=[]:
		j=Q[0]; del Q[0]
		for k in d[j]:
			if p[k]==0:
				p[k]=1+p[j]
				Q.append(k)
for i in lc[1]:
	for v in C[i]:
		p={}
		for u in C[i]:
			p[u]=0
		for u in C[i]:
			bfs(u)



































