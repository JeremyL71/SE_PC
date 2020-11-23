import multiprocessing as mp
from time import sleep

verrou_CONTRAINTE_A = mp.Semaphore(0) # default value is 1
verrou_CONTRAINTE_B_C = mp.Semaphore(0) 
verrou_CONTRAINTE_E_D = mp.Semaphore(0)

def tache_A():
    print("je suis la tâche A")
    print("Process A en cours ....")
    sleep(2)
    print("Process A fini.")
    verrou_CONTRAINTE_A.release()
    verrou_CONTRAINTE_A.release()
    verrou_CONTRAINTE_A.release()
    
def tache_B():
    print("je suis la tâche B")
    verrou_CONTRAINTE_A.acquire()
    print("Process B en cours ....")
    sleep(2)
    print("Process B fini.")
    verrou_CONTRAINTE_B_C.release()


def tache_C():
    print("je suis la tâche C")
    verrou_CONTRAINTE_A.acquire()
    print("Process C en cours ....")
    sleep(6)
    print("Process C fini.")
    verrou_CONTRAINTE_B_C.release()
    

def tache_D():
    print("je suis la tâche D")
    verrou_CONTRAINTE_A.acquire()
    print("Process D en cours ....")
    sleep(2)
    print("Process D fini.")
    verrou_CONTRAINTE_E_D.release()

def tache_E():
    print("je suis la tâche E")
    verrou_CONTRAINTE_B_C.acquire()
    verrou_CONTRAINTE_B_C.acquire()
    print("Process E en cours ....")
    sleep(4)
    print("Process E fini.")
    verrou_CONTRAINTE_E_D.release()

def tache_F():
    print("je suis la tâche F")
    verrou_CONTRAINTE_E_D.acquire()
    verrou_CONTRAINTE_E_D.acquire()
    print("Process F en cours ....")
    sleep(2)
    print("Process F fini.")


if __name__ == "__main__":
    pid_A = mp.Process(target= tache_A, args=())
    pid_A.start()

    pid_B = mp.Process(target= tache_B, args=())
    pid_B.start()

    pid_C = mp.Process(target= tache_C, args=())
    pid_C.start()

    pid_D = mp.Process(target= tache_D, args=())
    pid_D.start()

    pid_E = mp.Process(target= tache_E, args=())
    pid_E.start()

    pid_F = mp.Process(target= tache_F, args=())
    pid_F.start()

