sum_num<-function(number){
  sum<-0
  while(number>0){
    digit<-number%%10
    sum<-sum+digit
    number<-number%/%10
  }
  return(sum)
}

number<-12345
result<-sum_num(number)
print(paste("sum is:",result))