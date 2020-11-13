import os
import random
import sys
import re


def create_random_int(nb_int: int):
    list_note = []
    for i in range(nb_int):
        list_note.append(random.randint(0, 20))
    return list_note


def parcours_list(mylist: list, index: int):
    while (index, len(mylist)):
        try:
            print(f"element: {mylist[index]} et index: {index}")
            index = index + 2
        except Exception:
            break


def create_childs(list_note: list):
    # Create a pipe
    r, w = os.pipe()
    # define index
    index = 0
    # create two sons
    while index < 2:
        newpid = os.fork()
        # road for the child
        if newpid == 0:
            # This is the child process
            # Closes file descriptor w
            os.close(r)
            current_sum = child(list_note, index)
            w = os.fdopen(w, "w")
            w.write(str(current_sum) + ",")
            w.close()
            os._exit(0)
        # road for the dad
        else:
            pids = (os.getpid(), newpid)
            print("parent: %d, child: %d\n" % pids)
            index = index + 1

    # This is the parent process
    # Closes file descriptor r
    os.close(w)
    r = os.fdopen(r)
    answer = r.read()
    list_answer = re.findall(r"\d+", answer)
    print(f"list_answer: {list_answer}")
    list_answer = convert_string_to_int(list_answer)
    total_sum = sum(list_answer)
    print(f"total_sum: {total_sum}")


def child(list_note: list, index: int):
    print(f"\nChild: {os.getpid()}")
    newlist = []
    while (index, len(list_note)):
        try:
            print(
                f"[CHILD {os.getpid()}] current_note: {list_note[index]} & index: {index}"
            )
            newlist.append(list_note[index])
            index = index + 2
        except Exception:
            break
    current_sum = sum(newlist)
    print(f"[CHILD {os.getpid()}] current_sum: {current_sum}\n")
    return current_sum


def convert_string_to_int(mylist: list):
    for i in range(0, len(mylist)):
        mylist[i] = int(mylist[i])
    return mylist


if __name__ == "__main__":
    list_note = create_random_int(int(sys.argv[1]))
    create_childs(list_note)