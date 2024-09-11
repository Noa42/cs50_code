from cs50 import SQL
import csv
db = SQL("sqlite:///roster.db")
house_list =[]
with open ("students.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        db.execute("INSERT INTO students (id, student_name) VALUES (?, ?)", row["id"], row["student_name"])
        if row["house"] not in house_list:
            house_list.append(row["house"])
            db.execute("INSERT INTO houses (house_name, head) VALUES (?, ?)", row["house"], row["head"])
        db.execute("INSERT INTO assignments (student_id, house_id) VALUES (?, (SELECT id FROM houses WHERE house_name = ?))", row["id"], row["house"])



#db.execute("INSERT INTO houses(id, house_name, head) VALUES(1, 'chupi', 'Noa')")