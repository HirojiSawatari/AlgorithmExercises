#-*- coding: utf-8 -*-
import sys

def callen(str1):
    # 记录最长重复位置下标
    head = 0
    l = len(str1)
    for i in range(1, l):
        #是否与第一个字母相同
        if str1[i] == str1[0]:
            j = i + 1
            if j == l: # 避免aa无解
                head = 1
                break
            for j in range(i + 1, l):
                if str1[j] != str1[j - i]:
                    break
            if j == l - 1:
                head = i;
                break
    if head > 0:
        str2 = str1[0:head] + str1
    else:
        str2 = str1 + str1
    print(str2)

def main():
    try:
        while True:
            str1 = raw_input()
            callen(str1)
    except:
        pass

if __name__ == "__main__":
    main()