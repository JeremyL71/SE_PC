# −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
# Juin 2019
# Cours hippique
# Version très basique, sans mutex sur l’écran, sans arbitre, sans annoncer le gagant, ... ...
# Quelques codes d’échappement (tous ne sont pas utilisés)
CLEARSCR = "\x1B[2J\x1B[;H"  # Clear SCReen
CLEAREOS = "\x1B[J"  # Clear End Of Screen
CLEARELN = "\x1B[2K"  # Clear Entire LiNe
CLEARCUP = "\x1B[1J"  # Clear Curseur UP
GOTOYX = "\x1B[%.2d;%.2dH"  # (’H’ ou ’f’) : Goto at (y,x), voir le code
DELAFCURSOR = "\x1B[K"  # effacer après la position du curseur
CRLF = "\r\n"  # Retour à la ligne

# VT100 : Actions sur le curseur
CURSON = "\x1B[?25h"  # Curseur visible
CURSOFF = "\x1B[?25l"  # Curseur invisible

# VT100 : Actions sur les caractères affichables
NORMAL = "\x1B[0m"  # Normal
BOLD = "\x1B[1m"  # Gras
UNDERLINE = "\x1B[4m"  # Souligné

# VT100 : Couleurs : "22" pour normal intensity
CL_BLACK = "\033[22;30m"  # Noir. NE PAS UTILISER. On verra rien !!
CL_RED = "\033[22;31m"  # Rouge
CL_GREEN = "\033[22;32m"  # Vert
CL_BROWN = "\033[22;33m"  # Brun
CL_BLUE = "\033[22;34m"  # Bleu
CL_MAGENTA = "\033[22;35m"  # Magenta
CL_CYAN = "\033[22;36m"  # Cyan
CL_GRAY = "\033[22;37m"  # Gris

# "01" pour quoi ? (bold ?)
CL_DARKGRAY = "\033[01;30m"  # Gris foncé
CL_LIGHTRED = "\033[01;31m"  # Rouge clair
CL_LIGHTGREEN = "\033[01;32m"  # Vert clair
CL_YELLOW = "\033[01;33m"  # Jaune
CL_LIGHTBLU = "\033[01;34m"  # Bleu clair
CL_LIGHTMAGENTA = "\033[01;35m"  # Magenta clair
CL_LIGHTCYAN = "\033[01;36m"  # Cyan clair
CL_WHITE = "\033[01;37m"  # Blanc

# −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
from multiprocessing import Process
import multiprocessing as mp
import os, time, math, random, sys, ctypes

LONGEUR_COURSE = (
    100  # Tout le monde aura la même copie (donc no need to have a ’value’)
)
keep_running = mp.Value(ctypes.c_bool, True)

lock_affichage= mp.Semaphore(1)

# Une liste de couleurs à affecter aléatoirement aux chevaux
lyst_colors = [
    CL_WHITE,
    CL_RED,
    CL_GREEN,
    CL_BROWN,
    CL_BLUE,
    CL_MAGENTA,
    CL_CYAN,
    CL_GRAY,
    CL_DARKGRAY,
    CL_LIGHTRED,
    CL_LIGHTGREEN,
    CL_LIGHTBLU,
    CL_YELLOW,
    CL_LIGHTMAGENTA,
    CL_LIGHTCYAN,
]


def effacer_ecran():
    print(CLEARSCR, end="")


def erase_line_from_beg_to_curs():
    print("\033[1K", end="")


def curseur_invisible():
    print(CURSOFF, end="")


def curseur_visible():
    print(CURSON, end="")


def move_to(lig, col):
    print("\033[" + str(lig) + ";" + str(col) + "f", end="")


def en_couleur(Coul):
    print(Coul, end="")


def en_rouge():
    print(CL_RED, end="")  # Un exemple !


# La tache d’un cheval
def un_cheval(ma_ligne: int, positions: list):  # ma_ligne commence à 0
    col = 1
    while col < LONGEUR_COURSE and keep_running.value:
        move_to(ma_ligne + 1, col)  # pour effacer toute ma ligne
        erase_line_from_beg_to_curs()
        en_couleur(lyst_colors[ma_ligne % len(lyst_colors)])
        lock_affichage.acquire()
        print("(" + chr(ord("A") + ma_ligne) + ">")
        lock_affichage.release()
        col += 1
        time.sleep(0.1 * random.randint(1, 5))
        positions[ma_ligne] = col


def arbitre(positions: list, predictions: list):
    while True:
        ind_max = [0]
        for i in range(len(positions)):
            move_to(25, 1)
            if positions[i] > positions[ind_max[0]]:
                ind_max = [i]
                lock_affichage.acquire()
                print(f"Le cheval {chr(ord('A')+ind_max[0])} est en tete                                              ")
                lock_affichage.release()
            elif positions[i] == positions[ind_max[0]] and i not in ind_max:
                ind_max.append(i)
                txt = ""
                for ind in ind_max:
                    txt = txt + chr(ord("A") + ind) + ","
                lock_affichage.acquire()
                print(f"Les chevaux {txt[:-1]} sont en tete                                              ")
                lock_affichage.release()
        if positions[ind_max[0]] == LONGEUR_COURSE:
            move_to(25, 1)
            if len(positions) == 1:
                lock_affichage.acquire()
                print(f"Le cheval {chr(ord('A') + ind_max[0])} à gagné la course")
                lock_affichage.release()
            else:
                for ind in ind_max:
                    txt = txt + chr(ord("A") + ind) + ","
                lock_affichage.acquire()
                print(f"Les chevaux {txt[:-1]} ont gagné la course")
                lock_affichage.release()
            move_to(26, 1)
            if predictions[0] in ind_max:
                print("Vous avez gagné votre prediction")
            else:
                print("Vous avez perdu votre prediction")
            break

# −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
# La partie principale :
def course_hippique():
    Nb_process = 20
    mes_process = [0 for i in range(Nb_process)]
    positions = mp.Array("i", Nb_process)
    predictions = mp.Array("i", 1)
    for i in range(len(positions)):
        positions[i] = 0
    # positions[:]=mes_process

    effacer_ecran()
    curseur_invisible()

    for i in range(Nb_process):  # Lancer Nb_process processus
        mes_process[i] = Process(
            target=un_cheval,
            args=(
                i,
                positions,
            ),
        )
        mes_process[i].start()

    move_to(Nb_process + 10, 1)
    print("tous lancés")

    arbitre_process = Process(target=arbitre, args=(positions,predictions,))
    arbitre_process.start()

    move_to(30, 1)
    input_prediction = input("Entrez une prediction (exemple 'A') : ").upper()
    input_int_prediction = ord(input_prediction) - ord("A")
    predictions[0] = input_int_prediction
    move_to(31, 1)
    lock_affichage.acquire()
    print(f"Vous avez pariez sur {input_prediction}")
    lock_affichage.release()


    for i in range(Nb_process):
        mes_process[i].join()
    arbitre_process.join()
    move_to(Nb_process + 15, 1)
    curseur_visible()
    print("Fini")


# La partie principale :
if __name__ == "__main__":
    course_hippique()
