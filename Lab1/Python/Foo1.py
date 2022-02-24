def inFile(filename):
    with open(filename, "a") as inf:
        while(True):
            str = input()
            if str == "***":
                return
            else:
                inf.write(str+'\n')


def compare(path1, path2, path3):
    rows = 0
    with open(path3, "w") as ouf:
        with open(path1, "r") as inf1:
            text1 = inf1.readlines()
            with open(path2, "r") as inf2:
                text2 = inf2.readlines()
                for i in text1:
                    if i in text2:
                        continue
                    else:
                        ouf.write(i)
                        rows += 1
    return rows


def outFile(path):
    with open(path) as file:
        print(f"{path}:\n\n{''.join(file.readlines())}")