from cs50 import get_float
while True:
    money = (get_float("Change owed: ")*100)
    if money > 0:
        break
cont = 0
while money >= 25:
    money = money -25
    cont += 1
while money >= 10:
    money = money -10
    cont += 1
while money >= 5:
    money = money -5
    cont += 1
while money > 0:
    money = money -1
    cont += 1
print(f"{cont}")