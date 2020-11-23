import random
import namegenerator


def exo(N: int):
    class user(object):
        def __init__(self, name=None, age=None, list_note=None):
            if name is None:
                self.name = namegenerator.gen()
            else:
                self.name = name
            if age is None:
                self.age = generate_random_age()
            else:
                self.age = age

            if list_note is None:
                self.list_note = generate_list_random_note()
            else:
                self.list_note = list_note

    def generate_list_random_note():
        list = []
        for i in range(5):
            list.append(random.randint(0, 20))
        return list

    def generate_random_age():
        return random.randint(18, 30)

    def create_N_user(N: int):
        i = 0
        user_list = []
        while i < N:
            user_list.append(user())
            i = i + 1
        return user_list

    def all_notes(user_list: list):
        total_list_note = []
        NB_USER = len(user_list)
        index_user = 0
        while index_user < NB_USER:
            index_note = 0
            NB_note_current_user = len(user_list[index_user].list_note)
            while index_note < NB_note_current_user:
                total_list_note.append(user_list[index_user].list_note[index_note])
                index_note = index_note + 1
            index_user = index_user + 1
        return total_list_note

    def compute_general_average(user_list: list):
        total_list_note = all_notes(user_list)
        print(f"NB_notes: {len(total_list_note)}")
        print(f"sum of notes : {sum(total_list_note)}")
        average = sum(total_list_note) / len(total_list_note)
        return average

    def lower_note(user_list: list):
        total_list_note = all_notes(user_list)
        lower_note = min(total_list_note)
        return lower_note

    def highest_note(user_list: list):
        total_list_note = all_notes(user_list)
        highest_note = max(total_list_note)
        return highest_note

    print("Start main")

    user_list = create_N_user(N)
    print(f"Moyenne de la classe: {compute_general_average(user_list)}")
    print(f"Plus petite note: {lower_note(user_list)}")
    print(f"Plus grande note: {highest_note(user_list)}")

    print("End main")


if __name__ == "__main__":
    # Local test
    N = 10
    exo(N)
