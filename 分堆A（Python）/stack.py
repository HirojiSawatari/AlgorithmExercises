# -*- coding: utf-8 -*-
import sys

'''
    题目描述：
    小明得到了n个石头，他想把这些石头分成若干堆，每堆至少有一个石头。他把这些石堆排在一条直
    线上，他希望任意相邻两堆的石头数都不一样。小明最后的得分为石头数大于等于k的石堆数，问他
    最多能得多少分。
    严格地，小明把n个石头分成了m堆，每堆个数依次为a1，a2，.....，am。要求满足：
    1、ai≥1（1≤i≤m）
    2、ai≠ai+1（1≤i＜m）
    3、a1+a2+...+am＝n
    小明想知道a1，a2.....，am中大于等于k的数最多能有多少个？

    输入
    输入两个数n, k。（1≤k≤n≤109）

    输出
    输出最大的得分
'''

def main():
    try:
        while True:
            n, k = map(int, sys.stdin.readline().split())
            count = 0
            # 旧方法依次遍历
            '''
            tempk = k
            while n > 0:
                n -= tempk
                # 相邻两堆不同
                if k == tempk:
                    tempk += 1
                else:
                    tempk = k
                if n >= 0:
                    count += 1
            '''
            if n > 0:
                # 不够凑一组k和k+1，但大于k
                if n < (k * 2 + 1):
                    if n >= k:
                        count = 1
                else:
                    # 将每个k和k+1绑定为一组
                    count = (n / (k * 2 + 1)) * 2
                    tempk = n - (k * 2 + 1) * (count / 2)
                    if tempk >= k:
                        count += 1
            print(count)
    except:
        pass

if __name__ == "__main__":
    main()