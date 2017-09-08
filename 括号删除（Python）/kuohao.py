#-*- coding: utf-8 -*-

def calmove(str1):
    l = len(str1)
    # 遍历字符串
    for i in range(0, l):
        # 找第一个左括号
        if str1[i] == '(':
            break
    head = i
    # 统计之后左括号与右括号数
    islef = 1 # 判断此时是否是左括号
    lef = 1
    rig = 0
    for i in range(head + 1, l):
        # 左括号继续统计
        if str1[i] == '(':
            if islef == 1:
                lef += 1
            else:
                break
        elif str1[i] == ')':
            if islef == 1:
                islef = 0;
            rig += 1
    total = 1
    for i in range(0, lef):
        total *= rig
        rig -= 1
        if rig == 0:
            break
    print(total)


def main():
    try:
        while True:
            str1 = raw_input()
            if str1 == "":
                print(0)
            else:
                calmove(str1)
    except:
        pass

if __name__ == "__main__":
    main()