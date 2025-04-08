factorial<-function(n){
  if(n==0||n==1){
    return(1)
  }else{
    return(n*factorial(n-1))
  }
}

nCr<-function(n,r){
  if(r==0||r==n){
    return(1)
  }else{
    return(factorial(n)/factorial(r)*factorial(n-r))
  }
}

main<-function(){
  n<-as.numeric(readline("enter n:"))
  r<-as.numeric(readline("enter r:"))
  
  if(n%%1!=0||r%%1!=0||n<0||r<0){
    print("n and r must be non negative")
    return()
  }
  if(n<r){
    print("n should be greater than or equal to r")
    return()
  }
  
  fact_n<-factorial(n)
  fact_r<-factorial(r)
  
  result<- nCr(n,r)
  
  cat("factorial of",n,":",fact_n,"\n")
  cat("factorial of",r,":",fact_r,"\n")
  cat("the value of",n,"C",r,result,"\n")
}


main()
