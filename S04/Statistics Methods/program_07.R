sum_num<-function(number){
  sum<-0
  repeat{
    digit<-number%%10
    sum<-sum+digit
    number<-number%/%10
    if(number==0){
      break
    }
  }
  return(sum)
}

number<-12345
result<-sum_num(number)
print(paste("sum is:",result))
