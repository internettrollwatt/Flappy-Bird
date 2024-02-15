#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h> 
#include <zh-cn.h>//中文编程头文件（部分函数采用直译的方式进行翻译）
使用 命名空间 std;
// 定义所用数据
常量 整形 屏幕宽度 = 80;
常量 整形 屏幕高度 = 25;
常量 整形 管道宽度 = 4;
常量 整形 小鸟横坐标 = 10;
整形 得分 = 0;
整形 关卡 = 0;
整形 管道间隙 = 7;
整形 难度 = 1;
枚举 字符类型
{
    小鸟字符 = 'O',
    管道字符 = '#',
    空白字符 = ' '
};
整形 小鸟纵坐标 = 屏幕高度 / 2;
整形 管道横坐标 = 屏幕宽度 - 管道宽度;
整形 管道纵坐标 = 随机数() % (屏幕高度 - 管道间隙);
布尔值 游戏结束 = 假;
// 定义函数
无类型 绘制屏幕();
无类型 小鸟位置();
无类型 管道位置();
无类型 碰撞检测();
无类型 光标(整形 乙, 整形 甲);
无类型 屏幕检测();
整形 主函数()
{
    随机数种子(时间(0));
    屏幕检测();
    如果(键盘检测() == 32)
    {
        循环xx直到(!游戏结束)
        {
            绘制屏幕();
            碰撞检测();
            小鸟位置();
            管道位置();
            延时(70);
        }
        执行命令(清理屏幕);
        延时(500);
        输出 << "游戏结束" << 换行;
        输出 << "您的得分是";
        文本属性设置(文本为绿色);
        输出 << 得分 << 换行;
        文本属性设置(清除所有属性);
        返回 0;
    }
}
无类型 绘制屏幕()
{
    光标(0, 0);
    输出 << 字符串类(屏幕宽度, '-') << 换行; // 在第一行和最后一行输出一排“-”，表示上下边框
    循环(整形 甲 = 0; 甲 < 屏幕高度; 甲++)
    {
        循环(整形 乙 = 0; 乙 < 屏幕宽度; 乙++)
        {
            字符 丙 = 空白字符;
            如果(乙 == 小鸟横坐标 && 甲 == 小鸟纵坐标) { // 显示小鸟
                丙 = 小鸟字符;
            }
            如果(乙 >= 管道横坐标 && 乙 < 管道横坐标 + 管道宽度) // 显示管道
            {
                如果(甲 < 管道纵坐标 || 甲 > 管道纵坐标 + 管道间隙)
                {
                    丙 = 管道字符;
                }
            }
            输出 << 丙;
        }
        输出 << 换行;
    }
    输出 << 字符串类(屏幕宽度, '-') << 换行; // 在第一行和最后一行输出一排“-”，表示上下边框
    输出 << "得分";
    引用 控制台 = 获取标准句柄(标准输出句柄);
    文本属性设置(文本为绿色);
    输出 << 得分;
    文本属性设置(清除所有属性);
    输出 << " ; 难度";
    文本属性设置(文本为红色);
    输出 << 难度;
    文本属性设置(清除所有属性);
    输出 << " ; 关卡";
    文本属性设置(文本为黄色);
    输出 << 关卡 << 换行;
    文本属性设置(清除所有属性);
    输出 << "操作指导：按下空格键使小鸟上升，操纵小鸟避开障碍物吧！" << 换行;
}
无类型 小鸟位置()
{

    如果(按键检测())
    {
        如果(键盘检测() == ' ')
        {
            小鸟纵坐标--;
        }
    }
    否则
    {
        小鸟纵坐标++;
    }
}
无类型 管道位置()
{
    管道横坐标--; // 管道向左移动一格
    如果(管道横坐标 == 小鸟横坐标)
    {
        如果(关卡 <= 10)
        {
            得分++;
            关卡++;
        }
        如果(关卡 > 10 && 关卡 <= 15)
        {
            得分 = 得分 + 2;
            关卡++;
        }
        如果(关卡 > 15 && 关卡 <= 20)
        {
            得分 = 得分 + 3;
            关卡++;
        }
        如果(关卡 > 20)
        {
            得分 = 得分 + 4;
            关卡++;
        }
        如果(关卡 == 5)
        {
            管道间隙--;
            难度++;
        }
        如果(关卡 == 10)
        {
            管道间隙--;
            难度++;
        }
        如果(关卡 == 15)
        {
            管道间隙--;
            难度++;
        }
        如果(关卡 == 20)
        {
            管道间隙--;
            难度++;
        }
    }
    如果(管道横坐标 == 0) // 生成新的管道
    {
        管道横坐标 = 屏幕宽度 - 管道宽度;
        管道纵坐标 = 随机数() % (屏幕高度 - 管道间隙);
    }
}
无类型 碰撞检测()
{
    如果(小鸟纵坐标 < 0 || 小鸟纵坐标 >= 屏幕高度) // 检测小鸟是否碰到上下边界
    {
        游戏结束 = 真;
    }
    如果(管道横坐标 == 小鸟横坐标)  // 检测是否碰到管道
    {
        如果(小鸟纵坐标 < 管道纵坐标 || 小鸟纵坐标 > 管道纵坐标 + 管道间隙)
        {
            如果(关卡 <= 10)
            {
                得分--;
            }
            如果(关卡 > 10 && 关卡 <= 15)
            {
                得分 = 得分 - 2;
            }
            如果(关卡 > 15 && 关卡 <= 20)
            {
                得分 = 得分 - 3;
            }
            如果(关卡 > 20)
            {
                得分 = 得分 - 4;
            }
            游戏结束 = 真;
        }
    }
}
无类型 光标(整形 乙, 整形 甲)
{
    定义坐标 坐标结构体 = {乙, 甲};
    引用 丁 = 获取标准句柄(标准输出句柄);
    设置控制台坐标(丁, 坐标结构体);
}
无类型 屏幕检测()
{
    循环(整形 甲 = 0; 甲 < 屏幕宽度; 甲++)
    {
        输出 << "-";
    }
    输出 << 换行;
    循环(整形 己 = 0; 己 < 屏幕高度+1; 己++)
    {
        输出 << "|";
        循环(整形 丙 = 0; 丙 < 屏幕宽度 - 2; 丙++)
        {
            输出 << " ";
        }
        输出 << "|"<<换行;
    }
    循环(整形 甲 = 0; 甲 < 屏幕宽度; 甲++)
    {
        输出 << "-";
    }
    输出 << 换行<<"请确保当前窗口可以完整的显示此方框,随后按下空格键开始游戏";
}