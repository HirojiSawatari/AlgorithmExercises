# -*- coding: utf-8 -*-

'''
    题目描述

    我们规定对一个字符串的shift操作如下：
    shift(“ABCD”, 0) = “ABCD”
    shift(“ABCD”, 1) = “BCDA”
    shift(“ABCD”, 2) = “CDAB”
    换言之, 我们把最左侧的N个字符剪切下来, 按序附加到了右侧。
    给定一个长度为n的字符串，我们规定最多可以进行n次向左的循环shift操作。如
    果shift(string, x) = string (0＜= x ＜n), 我们称其为一次匹配(match)。求
    在shift过程中出现匹配的次数。

    输入
    输入仅包括一个给定的字符串，只包含大小写字符。

    输出
    输出仅包括一行，即所求的匹配次数。
'''

def main():
    try:
        while True:
            # 输入字符串
            str = raw_input()
            # shift(0)的时候必定匹配
            count = 1
            length = len(str)
            # shift从第二个元素开始扫描
            for head in range(1, length):
                i = head
                isbreak = False
                for j in range(0, length):
                    if str[j] != str[i]:
                        isbreak = True
                        break
                    if i == length - 1:
                        i = 0
                    else:
                        i += 1
                # 判断是否中途break
                if isbreak == False:
                    count += 1
            print(count)
    except:
        pass

if __name__ == "__main__":
    main()