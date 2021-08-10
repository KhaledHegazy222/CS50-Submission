from sys import argv,exit
import csv
sample = open(argv[2],"r")
s = sample.read()

def main():
    if(len(argv)!=3):
        print("Missing Command-Line Arguments!!")
        exit(1)
    database = open(argv[1],"r")
    C =[]
    ls = csv.reader(database)
    for row in ls:
        for elem in range(1,len(row)):
            C.append(count(row[elem]))
        break;
    reader = csv.DictReader(database)

    for row in ls:
        A=0
        for elem in range(1,len(row)):
            if C[elem-1]== int(row[elem]):
                A+=1
        if(A == len(C)):
            print(row[0])
            exit(0)
    print("No Match")
    exit(1)


























def count(dna):
    Z = 0
    counter = 0
    k = 0
    max = 0
    for i in range(0,len(s)):
        if len(s)-i < len(dna) :
            if max < counter:
                max = counter
            break;

        else :
            for j in range(len(dna)):
                if s[i+j]==dna[j] and k==0:
                    Z += 1
                else:
                    break
            if(Z==len(dna)):
                counter += 1
                k = Z-1
            elif(k!=0):
                k -= 1
                continue
            else:
                if max < counter:
                    max = counter
                counter = 0
            Z = 0
    return max






main()