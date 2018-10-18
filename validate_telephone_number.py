while True:
    try:
        number = int(raw_input("Enter Your Telephone Number: "))
        if len(str(number)) != 10:
            print("Wrong Telephon Number. Try Again!")
        else:
            print("Your Number is Valid :)")
            break
    except ValueError:
        print("Please Use Numeric Numbers!")
