import os, time, random, sys

i = 0
while i < 4:
    # Si c'est le père
    if os.fork() != 0:
        break
    i = i + 1

print(f"i: {i}")
# init seed
random.seed()
# definition delai
delai = random.randint(0, 4)
# delai
time.sleep(delai)

#  QUESTION 3
try:
    os.wait()
except:
    # cas où il y a rien à attendre
    print(
        "Mon nom est " + chr(ord("A") + i) + " j ai dormi " + str(delai) + " secondes"
    )
    os._exit(0)

# Affichage
print("Mon nom est " + chr(ord("A") + i) + " j ai dormi " + str(delai) + " secondes")
# Fin du processus
os._exit(0)
