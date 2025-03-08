print_month_name <- function(month_num) {
  month_name <- switch(month_num,
                       "January",
                      "February",
                      "March",
                     "April",
                       "May",
                "June",
           "July",
                      "August",
                   "September",
                    "October",
                    "November",
                  "December",
          "invald")
  
  cat("the month corres to",month_num,"is",month_name,"\n")
}

month_number<-as.integer(readline(prompt ="Enter the month number:"))
print_month_name(month_number)
