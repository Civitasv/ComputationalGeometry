#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>

using namespace std;
// 矩形结构体
typedef struct{
	int xmin,xmax,ymin,ymax;
}MyRectangle;

// 计算a、b的最大公约数
int gcd(int a,int b);

// 插入排序
void si_sort(int arr[], int len);

// 选择排序
void select_sort(int arr[], int len);

// 冒泡排序
void bubble_sort(int arr[], int len);

// 快速排序
void fast_sort(int arr[], int start, int end);

// 交换
void swap(int *a, int *b);

// 绘制DDA直线
void drawDDA(int x1,int y1,int x2,int y2);

// Bresenham画线算法
void bresenHamLine(int x1,int y1,int x2,int y2);

// 中点画线法
void midPointLine(int x1,int y1,int x2,int y2);

// 八对称性
void draw_circle_8(int xc, int yc, int x, int y);

// Bresenham画圆算法
void bresenHamCircle(int xc, int yc, int r,int fill);

// 中点画圆算法
void midPointCircle(int xc, int yc, int r);

// 正负法绘制圆
void posnegCircle(int xc,int yc,int r);

// 快速画圆法
void fastCircle(int xc,int yc,int r);

// 矩形填充算法
void fiilRectangle(MyRectangle *rect);

// 射线法判断点是否在多边形内
bool isPointInPolygon(POINT pts[],POINT pt,int size);

// 判断点是否在线上
bool isDotInLineSegment(POINT point,POINT p1,POINT p2);

// 判断多边形走向
bool isClockWise(POINT poly[],int size);