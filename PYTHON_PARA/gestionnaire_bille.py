import os, time, random
import multiprocessing as mp

n_max_marble = 10
n_process = 4;

lock_marble = mp.Semaphore(1)
n_marble_remaining = mp.Array("i",1)

def worker(k_marble, m_iteration, n_marble_remaining):
    for i in range(1,m_iteration+1):
        print(f"[Worker {os.getpid()}] Worker with {k_marble} marble, iteration {i} of {m_iteration}")
        get(k_marble,n_marble_remaining)
        print(f"[Worker {os.getpid()}] Get {k_marble} marble")
        time.sleep(random.randint(3, 8))
        giveback(k_marble,n_marble_remaining)
        print(f"[Worker {os.getpid()}] Giveback {k_marble} marble")
    print(f"[Worker {os.getpid()}] End.")

def get(k_marble,n_marble_remaining):
    lock_marble.acquire()
    if k_marble <= n_marble_remaining[0]:
        n_marble_remaining[0] = n_marble_remaining[0] - k_marble
    lock_marble.release()

def giveback(k_marble,n_marble_remaining):
    lock_marble.acquire()
    n_marble_remaining[0] = n_marble_remaining[0] + k_marble
    lock_marble.release()

def controller(n_marble_remaining):
    while True:
        if 0 <= n_marble_remaining[0] <= n_max_marble:
            print(f"[Controler] There is {n_marble_remaining[0]} marble available")
        else:
            print(f"[Controler] Error : There is {n_marble_remaining[0]} marble available")
        time.sleep(1)

if __name__ == "__main__":
    print(f"[main] Start of Program")
    process = [0 for i in range(n_process)]
    n_marble_remaining[0] = n_max_marble

    for i in range(n_process):
        process[i] = mp.Process(target=worker,
                                 args=(
                                     random.randint(3, 8),
                                     random.randint(1, 3),
                                     n_marble_remaining,
                                 )
                                 )
        process[i].start()

    controller_process = mp.Process(target=controller,args=(n_marble_remaining,))
    controller_process.start()

    for i in range(n_process):
        process[i].join()

    controller_process.terminate()
    print(f"[main] End of Program")