
# SE_PC

  

Système d'exploitation et programmation concurrente (CPE)

rappel: gcc -o exo1 -Wall -Werror exo1.c

  

## TP_SIGNAUX:

**exercice2:**  *Modifier le programme précédent pour qu'il ignore le signal SIGINT. Lancez-le en tâche de fond (./exo2 &). Essayez de l'interrompre avec un ^C. Que constatez-vous ? Pour l’arrêter, il faut taper ps –l pour obtenir son numéro de processus (pid) et lancer la commande :*

  

--> impossible d'arrêter le programme car

    signal(SIGINT , SIG_IGN);

ignore l'interruption ^C

**exercice5:** *Recopier le programme précédent et le modifier pour que le père n'envoie plus de signal au fils mais que le fils intercepte tous les SIGINT en affichant un message d'interception. Exécutez alors le programme et interrompez le par un ^C : Que constatez-vous? Expliquez pourquoi. (Pour vous aider, utilisez la commande ps –l).*

**trace**:

    Et moi luke[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268

	Je suis le père[PERE] Je suis le processus: 2268 (mon PID), mon Pere est 1536
	[PERE] Je suis le processus: 2268 (mon PID), mon Pere est 1536
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268
	[PERE] Je suis le processus: 2268 (mon PID), mon Pere est 1536
	^C
	signal 2 reçu par le processus: 2269
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 1
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 1


Le père est tué par le CTRL+C, le fil deviens un zombie  car il ne peut être tué par le SIGUNT

## TP_PROGRAMMATION_CONCURRENTE:

**exercice4:**  *Donnez l’arbre généalogique des processus engendrés par ce programme.*


# SE_PC

  

Système d'exploitation et programmation concurrente (CPE)

rappel: gcc -o exo1 -Wall -Werror exo1.c

  

## TP_SIGNAUX:

**exercice2:**  *Modifier le programme précédent pour qu'il ignore le signal SIGINT. Lancez-le en tâche de fond (./exo2 &). Essayez de l'interrompre avec un ^C. Que constatez-vous ? Pour l’arrêter, il faut taper ps –l pour obtenir son numéro de processus (pid) et lancer la commande :*

  

--> impossible d'arrêter le programme car

    signal(SIGINT , SIG_IGN);

ignore l'interruption ^C

**exercice5:** *Recopier le programme précédent et le modifier pour que le père n'envoie plus de signal au fils mais que le fils intercepte tous les SIGINT en affichant un message d'interception. Exécutez alors le programme et interrompez le par un ^C : Que constatez-vous? Expliquez pourquoi. (Pour vous aider, utilisez la commande ps –l).*

**trace**:

    Et moi luke[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268

	Je suis le père[PERE] Je suis le processus: 2268 (mon PID), mon Pere est 1536
	[PERE] Je suis le processus: 2268 (mon PID), mon Pere est 1536
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268
	[PERE] Je suis le processus: 2268 (mon PID), mon Pere est 1536
	^C
	signal 2 reçu par le processus: 2269
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 2268
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 1
	[FILS] Je suis le processus: 2269 (mon PID), mon Pere est 1


Le père est tué par le CTRL+C, le fil deviens un zombie  car il ne peut être tué par le SIGUNT

## TP_PROGRAMMATION_CONCURRENTE:

**exercice4:**  *Donnez l’arbre généalogique des processus engendrés par ce programme.*

| PA |  |  |  |  |
|----|----|----|----|----|
|  BREAK  |  PB  |    |    |   |
|  |  BREAK| PC   |    |  |
|    |  |   BREAK |  PD|  PDfils |
|  |  |    |  BREAK  |   |   |

Quels sont les affichages possibles à l’écran

    Mon nom est {n'importe quelle lettre} j ai dormi 1 secondes
	Mon nom est {n'importe quelle lettre}j ai dormi 1 secondes
	Mon nom est {n'importe quelle lettre}j ai dormi 2 secondes
	Mon nom est {n'importe quelle lettre} j ai dormi 4 secondes
	Mon nom est D j ai dormi 4 secondes



Quels sont les affichages possibles à l’écran

    Mon nom est {n'importe quelle lettre} j ai dormi 1 secondes
	Mon nom est {n'importe quelle lettre}j ai dormi 1 secondes
	Mon nom est {n'importe quelle lettre}j ai dormi 2 secondes
	Mon nom est {n'importe quelle lettre} j ai dormi 4 secondes
	Mon nom est D j ai dormi 4 secondes

