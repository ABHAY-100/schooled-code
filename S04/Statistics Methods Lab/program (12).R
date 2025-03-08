matrix1<- matrix(1:9, nrow =3,ncol=3)
matrix2<- matrix(9:1, nrow =3,ncol=3)

cat("matrix 1:\n")
print(matrix1)

cat("matrix 2:\n")
print(matrix2)

cat("\n operations:\n")

cat("addition:\n")
addition<-matrix1+matrix2
print(addition)

cat("subtraction:\n")
subtraction<-matrix1-matrix2
print(subtraction)

cat("multiplication:\n")
multiplication<-matrix1%*%matrix2
print(multiplication)

cat("transpose of 1:\n")
transpose1<-t(matrix1)
print(transpose1)

cat("transpose of 2:\n")
transpose2<-t(matrix2)
print(transpose2)
