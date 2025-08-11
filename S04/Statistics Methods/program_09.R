calc_area<-function(length,width){
  area<-length*width
  return(area)
}

calc_peri<-function(length,width){
  peri<-2*(length+width)
  return(peri)
}

main<-function(){
  length<-as.numeric(readline("enter length:"))
  width<-as.numeric(readline("enter width:"))
          
  area<-calc_area(length,width)
  peri<-calc_peri(length,width)
  
  cat("area is:",area,"\n")
  cat("perimeter is:",peri,"\n")
}

main()

