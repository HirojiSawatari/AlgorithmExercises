# -*- coding: utf-8 -*-
import sys

'''
    题目描述
    C市现在要转移一批罪犯到D市，C市有n名罪犯，按照入狱时间有顺序，另外每个罪犯有一个罪行值，值
    越大罪越重。现在为了方便管理，市长决定转移入狱时间连续的c名犯人，同时要求转移犯人的罪行值
    之和不超过t，问有多少种选择的方式？

    输入描述:
    第一行数据三个整数:n，t，c(1≤n≤2e5,0≤t≤1e9,1≤c≤n)，第二行按入狱时间给出每个犯人的罪
    行值ai(0≤ai≤1e9)

    输出描述:
    一行输出答案。
'''

# 直接求和均会超时，已废弃
def change_old(n, t, c, a):
    count = 0
    # 遍历罪犯，以该罪犯为第一个转移罪犯进行方案获取（控制不溢出）
    for i in range(n - c + 1):
        '''
        注意：使用循环会使程序超时！
        # 初始化此次转移的罪行值和
        totalt = 0
        # 遍历此罪犯之后的c名罪犯，获取罪行值和
        for j in range(i, (i + c)):
            totalt += a[j]
        '''
        # 利用函数获取i罪犯之后c人的罪行值和
        totalt = sum(a[i:(i + c)])
        # 最终罪行值和不大于最大值，方案数加1
        if totalt <= t:
            count += 1
    print(count)

def change(n, t, c, a):
    count = 0
    # 初始化罪行值和为第一个罪犯后c人的和
    totalt = sum(a[0:c])
    if totalt <= t:
        count += 1
    # 遍历不包括第一种罪犯之后的所有罪犯
    for i in range(c, n):
        # 不直接求和，只将上一序列的第一个罪犯去除，当前遍历的罪犯放入序列末尾，即为新的罪行值和
        totalt = totalt - a[i - c] + a[i]
        if totalt <= t:
            count += 1
    print(count)

def main():
    try:
        while True:
            # 获取总罪犯数n，罪行值和最大值t，转移罪犯数c
            n, t, c = map(int, sys.stdin.readline().split())
            # 按入狱时间顺序获取所有罪犯罪行值
            a = map(int, sys.stdin.readline().split())
            change(n, t, c, a)
    except:
        pass

if __name__ == "__main__":
    main()