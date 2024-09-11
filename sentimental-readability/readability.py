from cs50 import get_string
text = get_string("Text: ")
letters = 0
sentences = 0
for i in text:
    if i.isalpha() == True:
        letters +=1
    if i == "." or i == "!" or i == "?":
        sentences +=1
word_list = text.split()
words = len(word_list)
index = round(0.0588*((letters/words)*100) - 0.296*((sentences/words)*100) -15.8)
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
