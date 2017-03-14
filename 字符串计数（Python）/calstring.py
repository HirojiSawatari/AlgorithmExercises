# -*- coding: utf-8 -*-
import sys

def cal(s1, s2, len1, len2):
    count = 0
    s1_count = 0
    s2_count = 0
    s1_len = len(s1)
    s2_len = len(s2)
    # 统计s1之后字符串个数
    for i in range(len1, len2 + 1):
        # 统计长度为i的字符串个数
        for j in range(0, s1_len):
            # 依次遍历字符串内i以内所有字母
            if j == i:
                # 防止溢出字符串
                break
            # 统计每个字符之后字符所产生的字符串个数
            s1_count = s1_count + (26 ** (i - j - 1)) * (26 - (ord(s1[j]) - ord('a') + 1))
        if i > s1_len:
            # 溢出（即此下标处无字母），则全部为之后字符串
            s1_count = s1_count + (26 ** (i - s1_len))
    # 统计s2之后字符串个数
    for i in range(len1, len2 + 1):
        # 统计长度为i的字符串个数
        for j in range(0, s2_len):
            # 依次遍历字符串内i以内所有字母
            if j == i:
                # 防止溢出字符串
                break
            # 统计每个字符之后字符所产生的字符串个数
            s2_count = s2_count + (26 ** (i - j - 1)) * (26 - (ord(s2[j]) - ord('a') + 1))
        if i > s2_len:
            # 溢出（即此下标处无字母），则全部为之后字符串
            s2_count = s2_count + (26 ** (i - s2_len))
    # s1之后字符串个数减去s2之后字符串个数再减去s2本身即为总个数
    count = s1_count - s2_count - 1
    print(count)

def main():
    try:
        while True:
            # 首先以字符串读取
            s1, s2, len1, len2 = map(str, sys.stdin.readline().split())
            # 将字符串长度转化为整数
            len1 = int(len1)
            len2 = int(len2)
            cal(s1, s2, len1, len2)
    except:
        pass

if __name__ == "__main__":
    main()