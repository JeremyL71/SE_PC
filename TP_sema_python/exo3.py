import multiprocessing as mp
from time import sleep

lock = mp.Semaphore(0) # default value is 1

def T0():
    print("\nje suis T0")
    sleep(1)
    print("\nici T0 et j'ai fini")
    lock.acquire()
    T2()

def T1():
    print("\nje suis T1")
    sleep(1)
    print("\nici T1 j'ai fini")
    lock.release()

def T2():
    print("\nje suis T2")
    sleep(1)
    print("\nici T2 et j'ai fini")
    lock.release()


if __name__ == "__main__":
    pid_1 = mp.Process(target= T1, args=())
    pid_1.start()

    pid_2 = mp.Process(target= T0, args=())
    pid_2.start()
