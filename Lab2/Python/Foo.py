import pickle 
from datetime import date 


def create_file(file_name: str):
    input_mode = int(input('''Оберіть режим вводу інформації:
    1)Дозапис в існуючий файл
    2)Створити новий файл\n'''))
    lst = list() 
    if input_mode == 1:
        with open(file_name, "rb") as inf:
            lst = pickle.load(inf)
    with open(file_name, "wb") as ouf:
        line = input('''Введіть інформацію у фрматі [прізвище стать ДД:ММ:РРРР к-сть товарів].
Щоб припинити ввід, уведіть порожній рядок.\n''').split()
        while (line):
            client = {
                'name': line[0],
                'sex': line[1],
                'date_of_birth': line[2],
                'amount': int(line[3]),
            }
            lst.append(client) 
            line = input().split()
        pickle.dump(lst, ouf) 


def create_new_file(source_file_name: str, destination_file_name: str):
    base = list()
    with open(source_file_name, "rb") as inf:
        base = pickle.load(inf) 
    lst = list()
    for i in base:
        if spent(i['amount'], get_age(i['date_of_birth'])) > 250: 
            lst.append(i)
    with open(destination_file_name, "wb") as ouf:
        pickle.dump(lst, ouf)


def print_file(file_name: str):
    try:
        with open(file_name, "rb") as file:
            print(f"=====Вміст {file_name}=====")
            text = pickle.load(file)
            for i in text:
                for values in i.values():
                    print(values, end=' ')
                print()
            print()
    except:
        print('Помилка при відкритті файлу!')


def count_profit(file_name: str):
    profit = 0
    with open(file_name, "rb") as inf:
        lst = pickle.load(inf)
        for i in lst:
            profit += spent(int(i['amount']), get_age(i['date_of_birth']))
    return profit


def get_age(date_of_birth: str):
    current_date = date.today().strftime("%d:%m:%Y").split(':')
    if (int(current_date[1]) > int(date_of_birth.split(':')[1])
            or int(current_date[1]) == int(date_of_birth.split(':')[1])
            and int(current_date[0]) >= int(date_of_birth.split(':')[0])):
        return int(current_date[2]) - int(date_of_birth.split(':')[2])
    else:
        return int(current_date[2]) - int(date_of_birth.split(':')[2]) - 1


def spent(amount: int, age: int):
    if age >= 60:
        return amount * (100 - age - 5)
    else:
        return amount * (100 - age)