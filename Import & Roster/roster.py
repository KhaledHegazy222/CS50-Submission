import csv
from sys import exit,argv
import cs50

if len(argv) != 2:
    print("Missing Command-line Arguments!")
    exit(1)


db = cs50.SQL("sqlite:///students.db")
ls = []


if argv[1]== "Gryffindor":
    ls = db.execute("Select first,middle,last,birth from students where house = 'Gryffindor' ORDER BY last,first ")


elif argv[1] == "Hufflepuff":
    ls = db.execute("Select first,middle,last,birth from students where house = 'Hufflepuff' ORDER BY last,first ")


elif argv[1] == "Ravenclaw":
    ls = db.execute("Select first,middle,last,birth from students where house = 'Ravenclaw' ORDER BY last,first ")


elif argc[1]== "Slytherin":
    ls = db.execute("Select first,middle,last,birth from students where house = 'Slytherin' ORDER BY last,first ")


else :
    print("Invalid Input")

for row in ls:
    if(row["middle"] != None):
        print (row["first"],row["middle"],row["last"] , sep = " " ,end ="")
        print(", born" , row["birth"] , sep = " ")
    else:
        print (row["first"],row["last"], end = "" ,sep =" ")
        print(", born" , row["birth"] , sep = " ")
