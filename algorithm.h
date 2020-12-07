#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>

using namespace std;
// ���νṹ��
typedef struct{
	int xmin,xmax,ymin,ymax;
}MyRectangle;

// ����a��b�����Լ��
int gcd(int a,int b);

// ��������
void si_sort(int arr[], int len);

// ѡ������
void select_sort(int arr[], int len);

// ð������
void bubble_sort(int arr[], int len);

// ��������
void fast_sort(int arr[], int start, int end);

// ����
void swap(int *a, int *b);

// ����DDAֱ��
void drawDDA(int x1,int y1,int x2,int y2);

// Bresenham�����㷨
void bresenHamLine(int x1,int y1,int x2,int y2);

// �е㻭�߷�
void midPointLine(int x1,int y1,int x2,int y2);

// �˶Գ���
void draw_circle_8(int xc, int yc, int x, int y);

// Bresenham��Բ�㷨
void bresenHamCircle(int xc, int yc, int r,int fill);

// �е㻭Բ�㷨
void midPointCircle(int xc, int yc, int r);

// ����������Բ
void posnegCircle(int xc,int yc,int r);

// ���ٻ�Բ��
void fastCircle(int xc,int yc,int r);

// ��������㷨
void fiilRectangle(MyRectangle *rect);

// ���߷��жϵ��Ƿ��ڶ������
bool isPointInPolygon(POINT pts[],POINT pt,int size);

// �жϵ��Ƿ�������
bool isDotInLineSegment(POINT point,POINT p1,POINT p2);

// �ж϶��������
bool isClockWise(POINT poly[],int size);