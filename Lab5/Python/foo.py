from datetime import date
from abc import ABC, abstractmethod

class Person(ABC):
    def __init__(self, line: str):
        self.__name__ = line.split()[0] + ' ' + line.split()[1] + ' ' + line.split()[2]
        self.__date_of_birth = line.split()[3]

    def get_name(self):
        return self.__name__

    def get_age(self) -> str:
        today = date.today()
        b_day = int(self.__date_of_birth.split(':')[0])
        b_month = int(self.__date_of_birth.split(':')[1])
        b_year = int(self.__date_of_birth.split(':')[2])
        d_year = today.year - b_year
        if today.month < b_month:
            d_month = today.month + 12 - b_month
        else:
            d_month = today.month - b_month
        if today.day < b_day:
            d_day = today.day + 30 - b_day
        else:
            d_day = today.day - b_day
        if today.month < b_month or today.month == b_month and today.day < b_day:
            d_year -= 1
        age = f'{str(d_year)} year(s) {str(d_month)} month(s) {str(d_day)} day(s)'
        return age

    @abstractmethod
    def monthly_income(self, hours: float) -> float:
        return 150 * hours

class Student(Person):
    def __init__(self, line1, line2):
        super().__init__(line1)
        self.group_id = int(line2.split()[0])
        self.__average_grade = float(line2.split()[1])
        self.__status = 'n'

    def monthly_income(self, grants: float) -> float:
        if self.__average_grade >= 95:
            self.__status = 'h'
            return grants*1.4
        elif self.__average_grade >= 85:
            self.__status = 'd'
            return grants
        else:
            return 0

class Teacher(Person):
    def __init__(self, line1, line2):
        super().__init__(line1)
        self.__subject = line2.split()[0]
        self.hours = float(line2.split()[1])

    def monthly_income(self, salary: float) -> float:
        return salary*self.hours