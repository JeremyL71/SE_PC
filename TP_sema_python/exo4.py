import random
import multiprocessing as mp
from multiprocessing import Process
# from multiprocessing import Queue # ne fonctionne pas en python 3
import queue

permission_de_prendre_un_cookie = mp.Semaphore(1)


def put_random_int(q: queue):
    print("Start put_random_int")
    nombre_production = 10
    cpt = 0
    while cpt < nombre_production:
        q.put(random.randint(0, 20))
        cpt = cpt + 1
    print("End put_random_int")


def get_random_int(q: queue):
    print("Start get_random_int")
    permission_de_prendre_un_cookie.acquire()
    cookie = q.get()
    print(f"j'ai pris ce cookie: {cookie}")
    permission_de_prendre_un_cookie.release()
    print("End get_random_int")


if __name__ == "__main__":
    print("Start main")
    q1 = queue.Queue()
    q2 = queue.Queue()
    p1 = Process(target=put_random_int, args=(q1,))
    p2 = Process(target=put_random_int, args=(q2,))
    c1 = Process(target=get_random_int, args=(q1,))
    c2 = Process(target=get_random_int, args=(q2,))
    print("End main")
