def exo(N: int):
    chaine=""
    i=1
    while i<N:
        print(chaine)
        chaine = construction(str(i), chaine)
        i=i+1

def construction(i: int, chaine: str):
    chaine= chaine+i
    return chaine

if __name__ == '__main__':
    # Local test
    N=10
    exo(N)