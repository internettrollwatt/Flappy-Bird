#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h> 
#include <zh-cn.h>
ʹ�� �����ռ� std;
// ����һ���ṹ�壬��ʾһ������ɫ�͸�ʽ���ַ�
struct ColorChar 
{
    char ch; // �ַ�
    int fg; // ǰ��ɫ
    int bg; // ����ɫ
    // ���캯������ʼ���ַ�����ɫ
    ColorChar(char c, int f, int b) : ch(c), fg(f), bg(b) {}
    // ��������������������ɫ�͸�ʽ������ַ�
    friend ostream& operator<<(ostream& os, const ColorChar& cc) {
        // ������ɫ�͸�ʽ������ʹ���� SetConsoleTextAttribute ��������Ҳ����ʹ�������ĺ���
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cc.fg | (cc.bg << 4));
        // ����ַ�
        os << cc.ch;
        // �ָ�Ĭ����ɫ�͸�ʽ
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