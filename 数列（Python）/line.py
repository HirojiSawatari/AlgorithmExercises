# -*- coding: utf-8 -*-
import sys

'''
    题目描述：
    给定两个长度为 n 的整数数列 A 和 B。再给定 q 组查询，每次查询给出两个
    整数 x 和 y，求满足 Ai >= x 且 Bi >= y 这样的 i 的数量。

    输入
    第一行给定两个整数 n 和 q。
    第二行给定数列 A，包含 n 个整数。
    第三行给定数列 B，包含 n 个整数。
    接下来 q 行，每行两个整数 x 和 y，意义如上所述。

    输出
    对于每组查询，输出所求的下标数量。
'''

def main():
    try:
        while True:
            n, q = map(int, sys.stdin.readline().split())
            A = map(int, sys.stdin.readline().split())
            B = map(int, sys.stdin.readline().split())
            x = []
            y = []
            for i in range(q):
                xn, yn = map(int, sys.stdin.readline().split())
                x.append(xn)
                y.append(yn)
            for i in range(q):
                count = 0
                # 遍历数列
                for j in range(n):
                    if A[j] >= x[i] and B[j] >= y[i]:
                        count += 1
                # 每一组xy输出一次
                print(count)
    except:
        pass

if __name__ == "__main__":
    main()