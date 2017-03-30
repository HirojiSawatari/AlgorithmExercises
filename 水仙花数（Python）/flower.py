# -*- coding: utf-8 -*-
from __future__ import print_function
import sys

'''
    题目描述：
    春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的：
    “水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。
    现在要求输出所有在m和n范围内的水仙花数。

    输入
    输入数据有多组，每组占一行，包括两个整数m和n（100<=m<=n<=999）。

    输出
    对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大
    于等于m,并且小于等于n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格
    隔开;
    如果给定的范围内不存在水仙花数，则输出no;
    每个测试实例的输出占一行。
'''

def main():
    try:
        while True:
            m, n = map(int, sys.stdin.readline().split())
            istrue = False
            # 遍历各数字
            for i in range(m, n + 1):
                # 获取各位数字
                a = i / 100
                ii = i - (100 * a)
                b = ii / 10
                c = ii - (10 * b)
                if a ** 3 + b ** 3 + c ** 3 == i:
                    if istrue == False:
                        istrue = True
                    else:
                        print(" ", end='')
                    print(i, end='')
            if istrue == False:
                print("no", end='')
            print()
    except:
        pass

if __name__ == "__main__":
    main()