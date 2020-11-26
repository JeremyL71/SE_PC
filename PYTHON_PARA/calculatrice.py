import os, time, random
import multiprocessing as mp


def fils_calculette(cmd: str,ret: list):
    print(f"Bonjour du Fils: {os.getpid()}")
    print("Le fils a recu ", cmd)
    res = eval(cmd)
    print("Dans fils, le résultat =", res)
    ret[0] = res
    print("Le fils a envoyé", res)


if __name__ == "__main__":
    res = mp.Array("d", 1)
    while True:
        # Le pere envoie au fils un calcul aléatoire à faire et récupère le résultat
        opd1 = random.randint(1, 10)
        opd2 = random.randint(1, 10)
        operateur = random.choice(["+", "-", "*", "/"])
        str_commande = str(opd1) + operateur + str(opd2)
        fils = mp.Process(target=fils_calculette, args=(str_commande.encode(),res,))
        fils.start()
        print("Le père va demander à faire : ", str_commande)
        fils.join()
        print("Le Pere a recu ", res[0])
        print("-" * 60)
        time.sleep(1)
