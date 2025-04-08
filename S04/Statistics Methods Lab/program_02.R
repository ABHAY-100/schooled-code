num1 <- as.numeric(readline("Enter the First"))

num2 <- as.numeric(readline("Enter the Second"))
cat("Addition",num1+num2,"\n")
cat("Sub",num1-num2,"\n")
cat("Mul",num1*num2,"\n")

if(num2!=0){
  cat("Div:",num1/num2,"\n")
}else{
  cat("NA")
}

