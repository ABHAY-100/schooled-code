data(airquality)

stripchart(airquality$Ozone, method = "jitter", vertical = TRUE,
           main = "Ozone Reading Strip Chart",
           xlab = "Ozone Concentration (ppb)",
           ylab = "Days")