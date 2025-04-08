x=c(15,56,23,87)
y=c(43,76,34,67)

result = cor(x,y,method="spearman")

cat("spearman corelation coefficient is:",result)
