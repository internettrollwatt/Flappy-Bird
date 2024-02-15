#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h> 
#include <zh-cn.h>
使用 命名空间 std;
// 定义一个结构体，表示一个带颜色和格式的字符
struct ColorChar 
{
    char ch; // 字符
    int fg; // 前景色
    int bg; // 背景色
    // 构造函数，初始化字符和颜色
    ColorChar(char c, int f, int b) : ch(c), fg(f), bg(b) {}
    // 重载输出运算符，设置颜色和格式并输出字符
    friend ostream& operator<<(ostream& os, const ColorChar& cc) {
        // 设置颜色和格式，这里使用了 SetConsoleTextAttribute 函数，您也可以使用其他的函数
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cc.fg | (cc.bg << 4));
        // 输出字符
        os << cc.ch;
        // 恢复默认颜色和格式
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return os;
    }
};
int test()
{
    ColorChar z('#', 15, 2);
    cout << z << endl;
    return 0;
}