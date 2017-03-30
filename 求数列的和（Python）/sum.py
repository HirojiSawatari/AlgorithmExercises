# -*- coding: utf-8 -*-
import math
import sys

'''
    题目描述：
    数列的定义如下：
    数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。

    输入
    输入数据有多组，每组占一行，由两个整数n（n<10000）和m(m<1000)组成，n和m的
    含义如前所述。

    输出
    对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数
'''

def main():
    try:
        while True:
            n, m = map(int, sys.stdin.readline().split())
            sum = n
            for i in range(m - 1):
                n = math.sqrt(n)
                sum += n
            print('%.2f' % sum)
    except:
        pass

if __name__ == "__main__":
    main()