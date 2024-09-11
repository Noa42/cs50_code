from pyfiglet import Figlet
import sys
import random
def main():
    figlet = Figlet()
    if len(sys.argv) != 3 and len(sys.argv) != 1:
        print("Invalid usage")
        exit(1)
    if len(sys.argv) == 1:
        f = random.choice(figlet.getFonts())
        figlet.setFont(font=f)
        s = input("Input: ")
        print("Output:")
        print(figlet.renderText(s))
        exit(0)
    elif sys.argv[1] != "-f" or sys.argv[1] != "--font":
            if sys.argv[2] in figlet.getFonts():
                figlet.setFont(font=sys.argv[2])
                s = input("Input: ")
                print("Output:")
                print(figlet.renderText(s))
                exit(0)
            else:
                print("Invalid usage")


main()
