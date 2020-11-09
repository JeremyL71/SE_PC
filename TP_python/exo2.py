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
            user_list.append(
                user())
            i=i+1
        return user_list

    print("Start main")
    user_list = create_N_user(N)

    for user in user_list:
        print(f"user: ", user.name)
    
    print("End main")


if __name__ == '__main__':
    # Local test
    N = 3
    exo(N)
