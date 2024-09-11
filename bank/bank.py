entrada = input("Greeting: ")
entrada = entrada.lower()
if entrada.startswith("hello") == True:
    print("$0")
elif entrada[0].startswith("h") == True:
    print("$20")
else:
    print("$100")