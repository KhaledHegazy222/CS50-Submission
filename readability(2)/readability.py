from cs50 import get_string
s = get_string("Text: ")
letters = 0.0
words = 1.0
sentences = 0.0
for i in range(len(s)):
    if (s[i] >= "A" and s[i] <= "Z") or (s[i] >= "a" and s[i] <= "z") :
        letters +=1
    elif s[i] == " ":
        words +=1
    elif s[i] == "?" or s[i] == "!" or s[i] == ".":
        sentences +=1

index = 0.0588 * ( (letters / words)*100 ) - 0.296 * (sentences / words ) * 100 - 15.8;
index = round(index)
if index > 16 :
    print("Grade 16+")
elif index < 1 :
    print("Before Grade 1")
else  :
    print(f"Grade {index}")