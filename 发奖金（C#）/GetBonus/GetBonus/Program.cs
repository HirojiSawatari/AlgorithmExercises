using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*
 * 题目描述
 * 狐进行了一次黑客马拉松大赛，全公司一共分为了N个组，每组一个房间排成一排开始比赛，比赛结束后没有公布成
 * 绩，但是每个组能够看到自己相邻的两个组里比自己成绩低的组的成绩，比赛结束之后要发奖金，以1w为单位，每
 * 个组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组发的奖金，就会不满意，
 * 作为比赛的组织方，根据成绩计算出至少需要发多少奖金才能让所有的组满意。 
 * 
 * 输入描述:
 * 每组数据先输入N，然后N行输入N个正整数，每个数表示每个组的比赛成绩。
 * 
 * 输出描述:
 * 输出至少需要多少w的奖金
 */

namespace GetBonus
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = 0, i, j, pregrade, prebonus, sum;
            //输入组数
            N = Convert.ToInt32(Console.ReadLine());
            while (N != 0)
            {
                int[] grade = new int[N];
                int[] bonus = new int[N];
                //依次输入分数
                for (i = 0; i < N; i++)
                {
                    grade[i] = Convert.ToInt32(Console.ReadLine());
                }
                //初始化第一组为1w
                bonus[0] = 1;
                for (i = 1; i < N; i++)
                {
                    //初始化该组奖金为1w
                    bonus[i] = 1;
                    //得到前一组的分数，并得到前一组的奖金
                    pregrade = grade[(i - 1)];
                    prebonus = bonus[(i - 1)];
                    //之前一组分数比该组高但奖金不如该组此时奖金
                    if ((prebonus <= bonus[i]) && (pregrade > grade[i]))
                    {
                        //前一组奖金比当前组加一
                        bonus[(i - 1)] = bonus[i] + 1;
                        //之后需将前面的组依次增加奖金
                        for (j = i - 1; j > 0; j--)
                        {
                            if ((bonus[j - 1] <= bonus[j]) && (grade[j - 1] > grade[j]))
                            {
                                bonus[(j - 1)] = bonus[j] + 1;
                            }
                        }
                    }
                    //之前组分数比当前组低
                    if (pregrade < grade[i])
                    {
                        //当前组奖金比之前组多1
                        bonus[i] = bonus[(i - 1)] + 1;
                    }
                }
                sum = bonus.Sum();
                Console.WriteLine(sum);
                N = 0;
                //输入下一组数
                N = Convert.ToInt32(Console.ReadLine());
            }
        }
    }
}
