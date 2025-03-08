grades<-c(a=20,b=30,c=25,d=15,f=10)
colors<-c("red","green","blue","yellow","orange")

pie(grades,labels=paste(names(grades),"(",grades,"%)",sep=""),col=colors,main="percentage of grades in class")