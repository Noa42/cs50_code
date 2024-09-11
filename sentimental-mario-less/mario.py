from cs50 import get_int
while True:
        floors = get_int("Height: ")
        if floors >= 1 and floors <= 8:
            break
for i in range(floors-1, 0,-1):
    blank = " " * i
    hash = "#" * (floors-i)
    print(blank, hash, sep = "")
print("#" * floors)

