# -*- coding: utf-8 -*-
import sys

'''
    题目描述
    对于一个有序数组，我们通常采用二分查找的方式来定位某一元素，请编写二分查找的算法，在数组
    中查找指定元素。

    给定一个整数数组A及它的大小n，同时给定要查找的元素val，请返回它在数组中的位置(从0开始)，
    若不存在该元素，返回-1。若该元素出现多次，请返回第一次出现的位置。
'''

def get_pos(A, n, val):
    # 二分查找
    left = 0
    right = n - 1
    while left <= right:
        # 获取截取数组中间值下标
        mid = (left + right) / 2
        # 中间值即为需要的值，停止循环
        if A[mid] == val:
            break
        # 因为传入的数组为从小到大顺序，因此可以根据mid处的值判断是截取前半部分还是后半部分
        elif A[mid] > val:
            # 中间值比查找值大，截取前半部分
            right = mid - 1
        else:
            # 中间值比查找值小，截取后半部分
            left = mid + 1

    # 未找到值返回-1
    if left > right:
        return -1
    # 相同的值会连续出现，因此可以向前寻找第一个出现该值的位置
    while A[mid - 1] == val:
        mid -= 1
    return mid

def main():
    try:
        while True:
            # 数组大小n，查找的元素val
            n, val = map(int, sys.stdin.readline().split())
            # 从小到大顺序的整数数组
            A = map(int, sys.stdin.readline().split())
            loc = get_pos(A, n, val)
            print(loc)
    except:
        pass

if __name__ == "__main__":
    main()