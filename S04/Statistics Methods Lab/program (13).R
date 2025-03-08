data <- data.frame(
  name = c("amiya", "raj", "asil"),
  lang = c("python", "r", "java"),
  age = c(22, 34, 45)
)

print("original dataframe:")
print(data)


new_row <- data.frame(name = "john", lang = "c++", age = 30)


data <- rbind(data, new_row)

print("\ndataframe after adding a new row:")
print(data)


data <- data[-3,]

print("\ndataframe after removing a row:")
print(data)


summary_data <- summary(data)

print("\nsummary of the dataframe:")
print(summary_data)
