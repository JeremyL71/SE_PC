import csv

with open("TP-Python-population.csv", newline="") as csvfile:
    total_pop = []
    csvfile = csv.reader(csvfile, delimiter=",")
    line_count = 0
    for row in csvfile:
        if line_count == 0:
            print(f'Column names are {", ".join(row)}')
            line_count += 1
        else:
            current_pop = row[1]
            total_pop.append(int(current_pop))
            if line_count == 1:
                min_pop = current_pop
                save_date_min_pop = row[0]
                max_pop = current_pop
                save_date_max_pop = row[0]
            else:
                if current_pop < min_pop:
                    min_pop = current_pop
                    save_date_min_pop = row[0]
                if current_pop > max_pop:
                    max_pop = current_pop
                    save_date_max_pop = row[0]
            line_count += 1
    print(f"Processed {line_count} lines.")
    average_pop = sum(total_pop) / len(total_pop)

    print(
        f"En l'an {save_date_min_pop} la population était au plus bas avec {min_pop} "
    )
    print(
        f"En l'an {save_date_max_pop} la population était au plus bas avec {max_pop} "
    )
    print(f"En moyenne, la population moyenne est de {average_pop}")
