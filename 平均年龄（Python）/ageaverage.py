# -*- coding: utf-8 -*-
import math
import sys

'''
    题目描述
    已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，假设每年离职率为x，x>0&&x<1,每
    年保持所有员工总数不变进行招聘，新员工平均年龄21岁。 从今年3月末开始，请实现一个算法，可以计算出第N年后
    公司员工的平均年龄。(最后结果向上取整)。

    输入描述:
    输入W Y x N

    输出描述:
    输出第N年后的平均年龄
'''

def average(W, Y, x, N):
    N = int(N)
    for i in range(0, N):
        # (新入职员工年龄总和 + 老员工年龄增长一年后总和) / 公司总人数
        Y = ((21 * (W * x)) + (((Y + 1) * W) * (1 - x))) / W
    # 向上取整
    Y = math.ceil(Y)
    print(int(Y))

def main():
    try:
        while True:
            # 输入公司人数W，平均年龄Y，离职率x，统计年数N（通过一行读取）
            W, Y, x, N = map(float, sys.stdin.readline().split())
            average(W, Y, x, N)
    except:
        pass

if __name__ == "__main__":
    main()