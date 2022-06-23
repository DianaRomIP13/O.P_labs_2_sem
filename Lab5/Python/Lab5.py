from foo import *

base_of_students = list()
base_of_teachers = list()
n = int(input('Enter amount of students: '))
for i in range(n):
    line1 = input('[Surname Name Patronymic DD::MM:YYYY]\n')
    line2 = input('[id grades]\n')
    base_of_students.append(Student(line1, line2))
m = int(input('Enter amount of teachers: '))
for i in range(m):
    line1 = input('[Surname Name Patronymic DD::MM:YYYY]\n')
    line2 = input('[subject hours]\n')
    base_of_teachers.append(Teacher(line1, line2))
grants = float(input('Enter the grants amount: '))
print('STUDENTS:')
for i in range(n):
    print(f'student {base_of_students[i].get_name()} {base_of_students[i].monthly_income(grants)} UAH')
if m > 0:
    payment = float(input('Enter the payment per hour: '))
    richest = base_of_teachers[0]
for i in range(m):
    print(f'teacher {base_of_teachers[i].get_name()} {base_of_teachers[i].monthly_income(payment)} UAH')
    if base_of_teachers[i].monthly_income(payment) > richest.monthly_income(payment):
        richest = base_of_teachers[i]
print(f'Richest teacher: {richest.get_name()}')
print(f'His age: {richest.get_age()}')