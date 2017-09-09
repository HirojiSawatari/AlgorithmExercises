#-*- coding: utf-8 -*-

'''
    一个由小写字母组成的字符串可以看成一些同一字母的最大碎片
    组成的。例如，"aaabbaaac"是由下面碎片组成的：'aaa'，
    'bb'，'c'。牛牛现在给定一个字符串，你帮助计算这个字符串
    的所有碎片的平均长度是多少。
    
    输入描述：
    输入包括一个字符串s，字符串s的长度length（1 <= length <=50），
    s只含小写字母（'a'-'z'）
    
    输出描述：
    输出一个整数，表示所有碎片的平均长度，四舍五入保留两位小数。
    
    如样例所示：s = "aaabbaaac"
    所有碎片的平均长度 = (3 + 2 + 3 + 1) / 4 = 2.25
'''

def calchip(str1):
    n = 0   # 碎片个数
    ave = 0.0 # 碎片均长
    curlen = 0.0  # 当前碎片长度
    curcode = ''    # 当前字符
    l = len(str1)
    # 遍历字符
    for i in range(0, l):
        # 当前字符不等，碎片结束
        if curcode != str1[i] and curlen != 0:
            ave = ((ave * n) + curlen) / (n + 1)
            n += 1
            curlen = 0
        # 当前碎片第一个字符
        if curlen == 0:
            curcode = str1[i]
        curlen += 1
    # 结束时需统计最后一个碎片
    ave = ((ave * n) + curlen) / (n + 1)
    print('%.2f' % ave)

def main():
    try:
        while True:
            str1 = raw_input()
            calchip(str1)
    except:
        pass

if __name__ == "__main__":
    main()