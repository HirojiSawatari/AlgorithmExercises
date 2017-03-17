using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*
 * 题目描述
 * 在股市的交易日中，假设最多可进行两次买卖(即买和卖的次数均小于等于2)，规则是必须一笔成交后
 * 进行另一笔(即买-卖-买-卖的顺序进行)。给出一天中的股票变化序列，请写一个程序计算一天可以获
 * 得的最大收益。请采用实践复杂度低的方法实现。
 * 
 * 给定价格序列prices及它的长度n，请返回最大收益。保证长度小于等于500。
 */

namespace Stock
{
    class Program
    {
        //原算法时间复杂度过大已舍弃
        public static int maxProfitOld(int[] prices, int n)
        {
            // write code here
            int i, j, k, l, profit1, profit2, tp, maxtp = 0;
            //递归执行第一次买
            for (i = 0; i < n; i++)
            {
                //进行第一次卖
                for (j = i + 1; j < n; j++)
                {
                    //记录第一次买卖利润
                    profit1 = prices[j] - prices[i];
                    //进行第二次买
                    for (k = j + 1; k < n; k++)
                    {
                        //进行第二次卖
                        for (l = k + 1; l < n; l++)
                        {
                            //记录第二次买卖利润
                            profit2 = prices[l] - prices[k];
                            tp = profit1 + profit2;
                            //记录最大总利润
                            if (maxtp < tp)
                            {
                                maxtp = tp;
                            }
                        }
                    }
                    //可能只进行一次买卖就能达到最大利润
                    if (profit1 > maxtp)
                    {
                        maxtp = profit1;
                    }
                }
            }
            return maxtp;
        }

        //双向动态规划
        public static int maxProfit(int[] prices, int n)
        {
            // write code here
            int i;
            //i点前部分最大收益数组
            int[] pre = new int[n];
            //i点后部分最大收益数组
            int[] post = new int[n];
            pre[0] = 0;
            //获取i之前的最大收益
            int min_buy = prices[0];
            for (i = 1; i < n; i++)
            {
                //此点之前最佳买入价格
                min_buy = Math.Min(min_buy, prices[i]);
                //此点前一次买卖最大收益（与上一点前最大收益比较，假设i点卖出）
                pre[i] = Math.Max(pre[i - 1], (prices[i] - min_buy));
            }
            post[n - 1] = 0;
            //获取i之后的最大收益
            int max_sell = prices[n - 1];
            for (i = n - 2; i > -1; i--)
            {
                //此点之后最佳卖出价格
                max_sell = Math.Max(max_sell, prices[i]);
                //此点后一次买卖最大收益（与后一点最大收益比较，假设i点买入）
                post[i] = Math.Max(post[i + 1], (max_sell - prices[i]));
            }
            int tp, maxtp = 0;
            for (i = 0; i < n; i++)
            {
                //两次收益相加
                tp = pre[i] + post[i];
                //判断得到最大收益
                maxtp = Math.Max(tp, maxtp);
            }
            return maxtp;
        }

        static void Main(string[] args)
        {
            int n = 0, i, maxtp;
            n = Convert.ToInt32(Console.ReadLine());
            while (n != 0)
            {
                int[] prices = new int[n];
                for (i = 0; i < n; i++)
                {
                    prices[i] = Convert.ToInt32(Console.ReadLine());
                }
                maxtp = maxProfit(prices, n);
                Console.WriteLine(maxtp);
                //输入下一组数
                n = Convert.ToInt32(Console.ReadLine());
            }
        }
    }
}
