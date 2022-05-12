from Foo import *

file_name1 = input("Enter the file name: ")
create_file(file_name1)
print_file(file_name1)
print("Total profit: ", count_profit(file_name1))
file_name2 = input("Enter the new file name: ")
create_new_file(file_name1, file_name2)
print_file(file_name2)