students = {
    "maths": int(input("Maths: ")),
    "english": int(input("English: ")),
    "science": int(input("Science: ")),
}

print(f"Avg = {sum(students.values()) / len(students)}")