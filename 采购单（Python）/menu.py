# -*- coding: utf-8 -*-
import sys

'''
    题目描述
    过年啦！小B高兴的不行了，她收到了很多红包，可以实现好多的愿望呢。小B可是对商店货
    架上心仪的货物红眼好久了，只因囊中羞涩作罢，这次她可是要大大的shopping一番。小B
    想去购物时，总是习惯性的把要买的东西列在一个购买清单上，每个物品单独列一行（即便
    要买多个某种物品），这次也不例外。
    小B早早的来到了商店，由于她太激动，以至于她到达商店的时候，服务员还没有把各个商品
    的价签排好，所有的价签还都在柜台上。因此还需要一段时间，等服务器把价签放到对应的
    商品处，小B才能弄清她的购买清单所需的费用。
    小B都有些迫不及待了，她希望你能够根据购买清单，帮她算算最好和最坏的情况下所需的费
    用，你能帮她吗？

    输入
    输入中有多组测试数据。每组测试数据的第一行为两个整数n和m（1=＜n, m=＜1000），分别
    表示价签的数量以及小B的购买清单中所列的物品数。第二行为空格分隔的n个正整数，表示
    货架上各类物品的价格，每个数的大小不超过100000。随后的m行为购买清单中物品的名称，
    所有物品名称为非空的不超过32个拉丁字母构成的字符串，保证清单中不同的物品种类数不
    超过n，且商店有小B想要购买的所有物品。

    输出
    对每组测试数据，在单独的行中输出两个数a和b，表示购买清单上所有的物品可能需要的最小
    和最大费用。
'''

def minprice(price, num):
    # 从小到大排序
    price.sort()
    minp = 0
    for i in range(len(num)):
        minp += price[i] * num[i]
    return minp

def maxprice(price, num):
    # 从大到小排序
    price.sort(reverse=True)
    maxp = 0
    for i in range(len(num)):
        maxp += price[i] * num[i]
    return maxp

def main():
    try:
        while True:
            # 商品个数，需要商品个数
            n, m = map(int, sys.stdin.readline().split())
            price = map(int, sys.stdin.readline().split())
            name = []
            for i in range(m):
                name.append(map(str, sys.stdin.readline().split()))
            # 商品名中可能有重复元素，统计每个元素出现个数
            newname = []
            # 去重
            for i in name:
                if not i in newname:
                    newname.append(i)
            # 统计原数组中每个元素出现次数
            num = [name.count(i) for i in newname]
            # 个数从大到小排列
            num.sort(reverse=True)
            a = minprice(price, num)
            b = maxprice(price, num)
            print("%d %d" % (a, b))
    except:
        pass

if __name__ == "__main__":
    main()