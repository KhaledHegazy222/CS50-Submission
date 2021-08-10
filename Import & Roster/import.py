import csv
import cs50
from sys import argv,exit


if(len(argv) != 2):
    print("Missing Command-line Arguments!")
    exit(1)


open("students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

db.execute("Create Table students(first TEXT,middle TEXT,last TEXT, house TEXT, birth NUMERIC )")


file = open(argv[1],"r")

reader = csv.DictReader(file)

for row in reader:
    ls = []
    j= 0
    name = row["name"]
    ls = name.split()
    # for i in range(len(name)):
    #     if name[i] == " " :
    #         ls.append(name[j:i])
    #         j=i
    # ls.append(name[j:i+1])
    house = row["house"]
    birth = int(row["birth"])


    dictionary = {}

    if len(ls) == 2:
        dictionary["first"] = ls[0]
        dictionary["middle"] = None
        dictionary["last"] = ls[1]

    else:

        dictionary["first"] = ls[0]
        dictionary["middle"] = ls[1]
        dictionary["last"] = ls[2]

    db.execute("INSERT INTO students(first , middle, last , house , birth) VALUES(?,?,?,?,?)",dictionary["first"] , dictionary["middle"] , dictionary["last"],house , birth)









