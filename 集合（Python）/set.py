# -*- coding: utf-8 -*-
from __future__ import print_function
import sys

'''
    题目描述
    给你两个集合，要求 {A} + {B}。
    注：同一个集合中不会有两个相同的元素

    输入
    多组（不超过 5 组）数据。
    每组输入数据分为三行，第一行有两个数字 n,m($0＜n,m\leq10000$)，分别表示
    集合 A 和集合 B 的元素个数。后两行分别表示集合 A 和集合 B。每个元素为不
    超出 int 范围的整数，每个元素之间有一个空格隔开。

    输出
    针对每组数据输出一行数据，表示合并后的集合，要求从小到大输出，每个元素之
    间有一个空格隔开。
'''

def bind(A, B):
    # 拼接
    C = A + B
    # 去除重复元素
    C = list(set(C))
    # 正序排列
    C.sort()
    for i in range(0, len(C)):
        print(C[i], end='')
        if i < len(C) - 1:
            print(' ', end='')
    print()

def main():
    try:
        while True:
            n, m = map(int, sys.stdin.readline().split())
            A = map(int, sys.stdin.readline().split())
            B = map(int, sys.stdin.readline().split())
            bind(A, B)
    except:
        pass

if __name__ == "__main__":
    main()