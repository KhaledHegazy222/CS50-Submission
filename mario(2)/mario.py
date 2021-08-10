from cs50 import get_int

i = get_int("Height: ")
while not (i>= 1 and i <=8):
    i = get_int("Heigth: ")


for a in range(i):
    for b in range(i-a-1):
        print(" ",end = "")
    for c in range(a+1):
        print("#",end = "")
    print("")