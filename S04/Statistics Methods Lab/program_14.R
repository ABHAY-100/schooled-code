subjects<-c(1,2,3,4,5)
student1_marks<-c(70,80,85,90,95)
student2_marks<-c(70,71,72,73,74)

plot(subjects,student1_marks,type="o",col="blue",xlab="subjects",ylab="marks",ylim=c(0,100),main="marks of two students")
lines(subjects,student2_marks,type="o",col="red")
