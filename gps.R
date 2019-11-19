set.seed(1)
library(MASS) #for ginv()
library(rgl)  #for 3d graphs

#data matrix B
B <- matrix(c(15470963.50,-1180726.85,21541839.41,-20260438.90,19603002.46,4726671.62,17059949.34,-20264387.99,3017916.51,15760014.60,21367885.75,-23104936.52,180842.82,-15551720.30,21714117.29,-23382913.05,25616941.53,7756572.54,336879.28,-23101783.81),5,4,byrow=T)
f <- function(v) {
v[4] <- 1i*v[4]
return((Re(v %*% v))/2) }
a <- matrix(c(f(B[1,]),f(B[2,]),f(B[3,]),f(B[4,]),f(B[5,])),5,1)
A <- B
A[1,] <- B[1,]-B[2,]
A[2,] <- B[2,]-B[3,]
A[3,] <- B[3,]-B[4,]
A[4,] <- B[4,]-B[5,]
A[5,] <- B[5,]-B[1,]
b <- a
b[1,] <- a[1,]-a[2,]
b[2,] <- a[2,]-a[3,]
b[3,] <- a[3,]-a[4,]
b[4,] <- a[4,]-a[5,]
b[5,] <- a[5,]-a[1,]
(u <- ginv(A)%*%b)   #solution u=(x,y,z,p) of receiver
sqrt(u[1:3] %*% u[1:3])  #distance of u from centre of earth, should be equal to radius of earth

N<-100000  #number of simulations

distance <- function(u)  #inverse of distance cdf
{x <- rep(0,N)
x[u <= 0.3] <- (4*u[u <= 0.3])/3
x[u > 0.3 & u <= 0.55] <- (1.6*u[u > 0.3 & u <= 0.55])-0.08
x[u > 0.55 & u <= 0.75] <- (2*u[u > 0.55 & u <= 0.75])-0.3
x[u > 0.75 & u <= 0.9] <- (8*u[u > 0.75 & u <= 0.9]/3)-0.8
x[u > 0.9] <- (4*u[u > 0.9])-2
return(x)
}
pseudo_dist <- function(u)   #inverse of pseudo distance cdf
{x <- rep(0,N)
x[u <= 0.05] <- (40*u[u <= 0.05])-10
x[u > 0.05 & u <= 0.125] <- ((80*u[u > 0.05 & u <= 0.125])-28)/3
x[u > 0.125 & u <= 0.225] <- (20*u[u > 0.125 & u <= 0.225])-8.5
x[u > 0.225 & u <= 0.35] <- (16*u[u > 0.225 & u <= 0.35])-7.6
x[u > 0.35 & u <= 0.65] <- ((40*u[u > 0.35 & u <= 0.65])-20)/3
x[u > 0.65 & u <= 0.775] <- (16*u[u > 0.65 & u <= 0.775])-8.4
x[u > 0.775 & u <= 0.875] <- (20*u[u > 0.775 & u <= 0.875])-11.5
x[u > 0.875 & u <= 0.95] <- ((80*u[u > 0.875 & u <= 0.95])-52)/3
x[u > 0.95] <- (40*u[u > 0.95])-30
return(x)
}
#x,y,z,P of each of the 5 satellites for N simulations in 5 X N matrix
x <- matrix(0,5,N)
y <- x
z <- x
P <- x
v <- matrix(0,4,N) #matrix of N solutions for receiver (x,y,z,t)

for(i in 1:5) #loop to simulate x,y,z,P for each of the 5 satellites
{U <- runif(N)
D <- distance(U)
z[i,]<-runif(N,-1,1)
t<-runif(N,-pi,pi)
x[i,]<-D*sin(t)*sqrt(1-(z[i,]*z[i,]))
y[i,]<-D*cos(t)*sqrt(1-(z[i,]*z[i,]))
z[i,]<-D*z[i,]
V <- runif(N)
P[i,] <- -pseudo_dist(V)
}

for(i in 1:N)  #loop to solve N equations
{S <- matrix(c(x[,i],y[,i],z[,i],P[,i]),5,4,byrow=F)
S <- S+B       #store coefficients of the equation
a <- matrix(c(f(S[1,]),f(S[2,]),f(S[3,]),f(S[4,]),f(S[5,])),5,1)
A <- S
A[1,] <- S[1,]-S[2,]
A[2,] <- S[2,]-S[3,]
A[3,] <- S[3,]-S[4,]
A[4,] <- S[4,]-S[5,]
A[5,] <- S[5,]-S[1,]
b <- a
b[1,] <- a[1,]-a[2,]
b[2,] <- a[2,]-a[3,]
b[3,] <- a[3,]-a[4,]
b[4,] <- a[4,]-a[5,]
b[5,] <- a[5,]-a[1,]
v[,i] <- (ginv(A)) %*% b    # solution of the equation
}
range(v[1,]); range(v[2,]); range(v[3,]); range(v[4,])   # range of N solutions v=(x,y,z,t)
(e<-rowMeans(v)); u         # e is the expected position of receiver = mean of N solutions
sqrt(e[1:3] %*% e[1:3])     # distance of expected position from centre of earth
w<-v[1:3,]-e[1:3]           # difference between mean solution and the N possible solutions
(q<-quantile(sqrt((w[1,]*w[1,])+(w[2,]*w[2,])+(w[3,]*w[3,])),probs=0.9))   # 90th percentile of the distance from expected position
#3d graph with 90% set coloured blue and the other possible positions coloured black
open3d(); plot3d(v[1,],v[2,],v[3,],"x","y","z",col=ifelse(sqrt((w[1,]*w[1,])+(w[2,]*w[2,])+(w[3,]*w[3,]))<=q,"black","blue"))

#Coordinates of expected solution (x,y,z) are observed to be normally distributed as shown in graph
par(mfrow=c(3,1)); hist(v[1,],nclass=100,prob=T,xlab="x",main="Histogram of x"); curve(dnorm(x, mean=mean(v[1,]), sd=sd(v[1,])), add=TRUE,col="red")
hist(v[2,],nclass=100,prob=T,xlab="y",main="Histogram of y"); curve(dnorm(x, mean=mean(v[2,]), sd=sd(v[2,])), add=TRUE,col="red")
hist(v[3,],nclass=100,prob=T,xlab="z",main="Histogram of z"); curve(dnorm(x, mean=mean(v[3,]), sd=sd(v[3,])), add=TRUE,col="red")

#The 5th and 95th percentiles of coordinates are almost equal to that of normal distribution
qnorm(c(0.05,0.95),mean(v[1,]),sd(v[1,])); quantile(v[1,],c(0.05,0.95))
qnorm(c(0.05,0.95),mean(v[2,]),sd(v[2,])); quantile(v[2,],c(0.05,0.95))
qnorm(c(0.05,0.95),mean(v[3,]),sd(v[3,])); quantile(v[3,],c(0.05,0.95))

#Matrix d stores values of 5th and 95th percentiles of x,y,z from matrix of possible solutions v
d<-matrix(c(quantile(v[1,],probs=c(.05,.95)),quantile(v[2,],probs=c(.05,.95)),quantile(v[3,],probs=c(.05,.95))),3,2,byrow=T)
g<-v[1:3,(d[1,1]<=v[1,])&(d[1,2]>=v[1,])&(d[2,1]<=v[2,])&(d[2,2]>=v[2,])&(d[3,1]<=v[3,])&(d[3,2]>=v[3,])]; dim(g)
#Plot with 90% set coloured black and rest blue
#open3d(); plot3d(v[1,],v[2,],v[3,],"x","y","z",col=ifelse((d[1,1]<=v[1,])&(d[1,2]>=v[1,])&(d[2,1]<=v[2,])&(d[2,2]>=v[2,])&(d[3,1]<=v[3,])&(d[3,2]>=v[3,]),"black","blue"))
#Plot with unit axes lengths in ratio 1:1:1
#open3d(); plot3d(v[1,],v[2,],v[3,],"x","y","z",col=ifelse((d[1,1]<=v[1,])&(d[1,2]>=v[1,])&(d[2,1]<=v[2,])&(d[2,2]>=v[2,])&(d[3,1]<=v[3,])&(d[3,2]>=v[3,]),"black","blue"),aspect=F); #aspect3d("iso")

s<-matrix(c(var(v[1,]),cov(v[1,],v[2,]),cov(v[1,],v[3,]),cov(v[2,],v[1,]),var(v[2,]),cov(v[2,],v[3,]),cov(v[3,],v[1,]),cov(v[3,],v[2,]),var(v[3,])),3,3)
s<-solve(s)
p<-function(x) {
m<-matrix(x-e[1:3],1,3)
return((m%*%s%*%t(m))[1,1]) }
(q1<-qchisq(0.9,df=3))
q2<-function() {
q3<-rep(F,N)
for(i in 1:N) {
q3[i]<-(p(v[1:3,i])<=q1) }
return(q3) }
q22<-q2()
open3d(); plot3d(v[1,],v[2,],v[3,],"x","y","z",col=ifelse(q22,"Blue","Black"))
sum(q22); rm(q22); s<-solve(s)
open3d(); plot3d(ellipse3d(s[1:3,1:3],level=0.99,center=e[1:3]),col=rgb(1,0,0.3),alpha=0.2,aspect=T)
plot3d(ellipse3d(s[1:3,1:3],level=0.9,center=e[1:3]),add=T)
open3d(); plot3d(ellipse3d(s[1:3,1:3],level=0.99,center=e[1:3]),col=rgb(1,0,0.3),alpha=0.2)
plot3d(ellipse3d(s[1:3,1:3],level=0.9,center=e[1:3]),add=T)
open3d(); plot3d(ellipse3d(s[1:3,1:3],level=0.99,center=e[1:3]),col=rgb(1,0,0.3),alpha=0.2,aspect=T)
plot3d(ellipse3d(s[1:3,1:3],level=0.9,center=e[1:3]),add=T,col="Green",alpha=0.6)
plot3d(v[1,]-e[1],v[2,]-e[2],v[3,]-e[3],col=ifelse(q2(),"Blue","Black"),add=T,alpha=0.3)
(s1<-sqrt(q1)*sqrt(eigen(s)$values))
(4/3)*pi*s1[1]*s1[2]*s1[3]; rm(list=ls())