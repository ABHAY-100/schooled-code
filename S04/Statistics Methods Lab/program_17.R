continents <- c("Africa", "Asia", "Europe", "North America", "Oceania", "South America", "Soviet Union")
areas <- c(11.7, 10.4, 1.9, 9.4, 3.3, 6.9, 7.9)

barplot(
  areas,
  names.arg = continents,
  xlab = "Continents",
  ylab = "Area (millions of square miles)",
  col = "blue",
  main = "Areas of Continents",
  las = 2
)
