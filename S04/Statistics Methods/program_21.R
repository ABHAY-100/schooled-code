data(airquality)
str(airquality)
boxplot(airquality[,c("ozone","solar.r","wind","temp","month","day:")],
        main="box plot of air quality variables"),
xlab="variables",
ylab="value")
