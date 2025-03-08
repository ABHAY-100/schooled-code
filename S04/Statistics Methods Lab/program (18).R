data <- c(rep(137.5, 4), rep(142.5, 12), rep(147.5, 16), rep(152.5, 8)) 
breaks <- c(135, 140, 145, 150, 155)

hist(data, breaks = breaks, main = "Height of Students", xlab = "Height (m)", ylab = "No. of Students")
