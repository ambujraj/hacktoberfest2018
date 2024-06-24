c = 0

with open("file.py", "r") as f:
    for line in f:
        c+=1
        if "\n" == line:
            pass
        else:
            if line[-2] == " ":
                print(c)
