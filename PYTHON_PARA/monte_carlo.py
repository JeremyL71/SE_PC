import random, time, sys
import multiprocessing
from multiprocessing import Pool
import time

# calculer le nbr de hits dans un cercle unitaire (utilisé par les différentes méthodes)
def monte_carlo_pi_part(nb_iteration):
    print(f"nb_iteration: {nb_iteration}")
    count = 0
    for i in range(int(nb_iteration)):
        x = random.random()
        y = random.random()
        # si le point est dans l’unit circle
        if (x * x + y * y) <= 1:
            count += 1
    return count


if __name__ == "__main__":
    print("Debut du temps multiprocess !")

    start_time = time.time()
    np = multiprocessing.cpu_count()
    print("You have {0:1d} CPUs".format(np))
    # Nummber of points to use for the Pi estimation
    n = 10000000
    # iterable with a list of points to generate in each worker
    # each worker process gets n/np number of points to calculate Pi from
    part_count = [n / np] * np
    # Create the worker pool
    # http://docs.python.org/library/multiprocessing.html#module-multiprocessing.pool
    pool = Pool(processes=np)
    # parallel map
    count = pool.map(monte_carlo_pi_part, part_count)
    print("Esitmated value of Pi:: ", sum(count) / (n * 1.0) * 4)
    print("--- %s seconds ---" % (time.time() - start_time))
    temps_multi = time.time() - start_time

    print("Fin du temps multiprocess !")

    print("Debut du temps monoprocess !")

    start_time = time.time()
    nb_total_iteration = 10000000
    nb_hits = monte_carlo_pi_part(nb_total_iteration)
    print(
        "Valeur estimée Pi par la méthode Mono−Processus : ",
        4 * nb_hits / nb_total_iteration,
    )
    print("--- %s seconds ---" % (time.time() - start_time))
    temps_mono = time.time() - start_time

    print("Fin du temps monoprocess !")

    print(f"difference: {abs(temps_multi-temps_mono)}")

    if len(sys.argv) < 2:
        print("penser a ajout le nom de processus en argument en appelant le programme")
    else:
        print(f"Debut du temps multiprocess avec: {int(sys.argv[1])} processus")

        start_time = time.time()
        # Nummber of points to use for the Pi estimation
        n = 10000000
        # iterable with a list of points to generate in each worker
        # each worker process gets n/np number of points to calculate Pi from
        part_count = [n / int(sys.argv[1])] * int(sys.argv[1])
        # Create the worker pool
        # http://docs.python.org/library/multiprocessing.html#module-multiprocessing.pool
        pool = Pool(processes=int(sys.argv[1]))
        # parallel map
        count = pool.map(monte_carlo_pi_part, part_count)
        print("Esitmated value of Pi:: ", sum(count) / (n * 1.0) * 4)
        print("--- %s seconds ---" % (time.time() - start_time))
        temps_multi = time.time() - start_time

        print(f"Fin du temps multiprocess avec: {int(sys.argv[1])} processus")
