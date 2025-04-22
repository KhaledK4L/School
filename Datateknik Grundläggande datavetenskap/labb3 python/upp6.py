år = int(input("Ange år: "))
if år % 4 == 0:
    if år % 100 == 0:
        if år % 400 == 0:
            print("Skottår")
        else:
            print("Inte skottår")
    else:
        print("Skottår")
else:
    print("Inte skottår")        