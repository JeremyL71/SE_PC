import sys


def convert_string_to_int(mylist: list):
    print("start convert_string_to_int")
    for i in range(0, len(mylist)): 
        mylist[i] = int(mylist[i]) 
    print("end convert_string_to_int")
    return mylist

def check_arg(mylist: list):
    print("start check_arg")
    valide = True
    for i in range(0, len(mylist)): 
        if ((mylist[i] < 0) or (mylist[i] >20)):
            valide = False
    print("end check_arg")
    return valide

def show_arg(mylist: list):
    print("start show_arg")
    for i in range(0, len(mylist)):
        print(f"element: {mylist[i]}")
    print("end show_arg")

if __name__ == '__main__':
    # Local test
    list_argument = sys.argv
    
    if len(list_argument) == 1:
        print('\nAucune moyenne à calculer')
    else:
        del list_argument[0]
        list_argument = convert_string_to_int(list_argument)

        if check_arg(list_argument) is True:
            moyenne = "{:.2f}".format(float(sum(list_argument) / len(list_argument)))
            print(f"Moyenne: {moyenne}")
        else:
            print('\nNote non valide')
