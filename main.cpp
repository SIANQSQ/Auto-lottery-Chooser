#define _CRT_SECURE_NO_WARNINGS
#define reset 1000000000 
#include <iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<string>
using namespace std;

string getTime()
{
    time_t timep;
    time(&timep); 
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    return tmp;
}

 int main()
{
     system("title 屈圣桥的双色球机选");
     int num;
     string   timenow = getTime();
     cout << "      屈圣桥的双色球机选程序   " << endl;
     cout << "机选时间：" << timenow << endl;
     
     cout << "请输入注数：";
     cin >> num;
     cout << endl;

     for(int zhushu=0;zhushu<num;zhushu++)
     { 
         //红球
         cout << "第" << zhushu + 1 << "注：";
         int redball[6];
         srand((unsigned)time(NULL)+(reset*zhushu));
         int a[33];
         for (int i = 1; i <= 33; i++)
         {
             a[i - 1] = i;
         }
         for (int t = 1; t <= 32; t++)
         {
             swap(a[t], a[rand() % t]);
         }
         for (int j = 0; j <= 5; j++)
         {
             redball[j] = a[j];
         }
         for (int i = 0; i < 6; i++)
         {
             int tmp;
             for (int j = i; j < 6; j++)
             {
                 if (redball[j] < redball[i])
                 {
                     tmp = redball[j];
                     redball[j] = redball[i];
                     redball[i] = tmp;
                 }
             }
         }
         //蓝球
       
         int blueball;
         int c = 1;
         int d = 16;
         blueball = (rand() % (d - c + 1)) + c;

         for (int out = 0; out < 6; out++)
         {
             if (redball[out] < 10)
             {
                 cout << "0";
             }
             cout << redball[out] << "  ";
         }
         cout << "- ";
         if (blueball < 10)
         {
             cout << "0";
         }
         cout << blueball << endl;
     }
     cout << endl << "屈圣桥祝你买彩票中大奖,发大财！！！！！" << endl<<endl;
     system("pause");
}
