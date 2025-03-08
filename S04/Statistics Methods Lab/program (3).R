check<-function(num){
  if(num>0){
    cat(num,"is a positive number\n")
  }else if(num<0){
    cat(num,"is a negative number\n")
  }else{
    cat("The number is zero\n")
  }
  }
  


number<-as.numeric(readline(prompt="Enter a number: "))
check(number)
