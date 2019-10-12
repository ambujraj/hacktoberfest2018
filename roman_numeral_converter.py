def check_correctness(expr,some_dict):
    for i in expr:
        if i not in some_dict.keys():
            return False

    return True

val_dict={"M":1000,"D":500,"C":100,"L":50,"X":10,"V":5,"I":1}

expr=input("Enter the roman numeral string : ")
expr=expr.upper()

the_num=0
if (check_correctness(expr,val_dict)):
    for i in expr:
        the_num+=val_dict[i]

print(the_num)