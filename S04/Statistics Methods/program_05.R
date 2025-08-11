find_factors<-function(num){
  factors<-c()
  
  for (i in 1:num){
    if(num%%i==0){
      factors<-c(factors,i)
    }
  }
  return(factors)
}

number<-24
factors<-find_factors(number)
cat("the factors of",number,"are:",factors,"\n")
