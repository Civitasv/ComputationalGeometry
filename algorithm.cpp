#include "algorithm.h"


// 计算a, b 最大的公约数
int gcd(int a, int b){
	if(a < b){
		int temp = a;
		a = b;
		b = temp;
	}
	while(a % b){
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}

// 直接插入排序
void si_sort(int arr[], int len){
	for (int i = 1; i < len; i++)// 循环从第二个数组元素开始
	{
		int temp = arr[i];//temp标记为未排序的第一个元素
		while (i >= 0 && arr[i - 1] > temp) //将temp与已排序元素从大到小比较，寻找temp应插入的元素
		{
			arr[i] = arr[i - 1];
			i--;
		}
		arr[i] = temp;
	}
}

// 选择排序：相邻两个元素进行比较，把大的元素的下标记录下来，一轮完整的比较之后，若最大值的下标不是len-i，则两个元素交换位置
void select_sort(int arr[],int len)
{
	for(int i=0; i<len; i++) // 总共要找len-1次最大值,每次找最大值的区间 [0,len-i]
	{
		int index_nmax = 0;
		for(int j=1; j<len-i; j++) // 因为假设了0下标就是最大值，所以循环可以从1开始
		{
			if(arr[j] > arr[index_nmax])
			{
				index_nmax = j;
			}
		}        
		if(index_nmax != len-i-1) // 避免无意义的位置交换
		{
			int tmp = arr[index_nmax];
			arr[index_nmax] = arr[len-i-1];
			arr[len-i-1] = tmp;
		}
	}    
}

// 冒泡排序
void bubble_sort(int arr[], int len){
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int max = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = max;
			}
		}
	}
}

// 交换
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 快速排序
void fast_sort(int arr[], int start, int end){
	int arrBase, arrMiddle;

	int tempStart = start,
		tempEnd = end;

	//对于这种递归的函数，内部必须要有一个函数返回的条件
	if(tempStart >= tempEnd)
		return;

	//拷贝一个基准值作为后面比较的参数
	arrBase = arr[start];
	while(start < end)
	{
		while(start < end && arr[end] > arrBase)
			end--;
		if(start < end)
		{
			swap(&arr[start], &arr[end]);
			start++;
		}

		while(start < end && arr[start] < arrBase)
			start++;
		if(start < end)
		{
			swap(&arr[start], &arr[end]);
			end--;
		}
	}
	arr[start] = arrBase;
	arrMiddle = start;

	//分治方法进行递归
	fast_sort(arr,tempStart,arrMiddle-1);
	fast_sort(arr,arrMiddle+1,tempEnd);

}

// 使用数值微分法绘制直线
void drawDDA(int x1, int y1, int x2, int y2)
{
	// 初始化绘图窗口
	initgraph(640,480);
	float increx,increy,x,y;
	int steps,i;
	if(abs(x2-x1)>abs(y2-y1))
		steps = abs(x2-x1);
	else
		steps = abs(y2-y1);
	increx = (float)(x2-x1)/steps;
	increy = (float)(y2-y1)/steps;
	// 初始值
	x = x1;
	y = y1;
	for(i = 1;i<=steps;i++){
		putpixel(x,y,WHITE);
		x+=increx;
		y+=increy;
	}
} 

// 使用bresenham算法绘制直线
void bresenHamLine(int x1,int y1, int x2, int y2){
	// 初始化绘图窗口
	initgraph(640,480);

	int dx = abs(x2 - x1),
		dy = abs(y2 - y1),
		yy = 0;

	if (dx < dy) {
		yy = 1;
		swap(&x1, &y1);
		swap(&x2, &y2);
		swap(&dx, &dy);
	}

	int ix = (x2 - x1) > 0 ? 1 : -1,
		iy = (y2 - y1) > 0 ? 1 : -1,
		cx = x1,
		cy = y1,
		n2dy = dy * 2,
		n2dydx = (dy - dx) * 2,
		d = dy * 2 - dx;

	if (yy) { // 如果直线与 x 轴的夹角大于 45 度
		while (cx != x2) {
			if (d < 0) {
				d += n2dy;
			} else {
				cy += iy;
				d += n2dydx;
			}
			putpixel(cy, cx, WHITE);
			cx += ix;
		}
	} else { // 如果直线与 x 轴的夹角小于 45 度
		while (cx != x2) {
			if (d < 0) {
				d += n2dy;
			} else {
				cy += iy;
				d += n2dydx;
			}
			putpixel(cx, cy, WHITE);
			cx += ix;
		}
	}
}

// 使用中点画线法绘制直线
void midPointLine(int x1, int y1,int x2,int y2){
	// 初始化绘图窗口
	initgraph(640,480);
	int x = x1, y = y1;
	int a = y1 - y2;
	int b = x2 - x1;
	int cx = (b >= 0 ? 1 : (b = -b, -1));
	int cy = (a <= 0 ? 1 : (a = -a, -1));

	int d, d1, d2;
	if (-a <= b) // 斜率绝对值 <= 1
	{
		d = a + a + b;
		d1 = a + a;
		d2 = a + a + b + b;
		while (x != x2)
		{
			if (d < 0)
			{
				y += cy;
				d += d2;
			}
			else
			{
				d += d1;
			}
			x += cx;
			putpixel(x, y,WHITE);
		}
	}
	else // 斜率绝对值 > 1
	{
		d = a + b + b;
		d1 = b + b;
		d2 = a + a + b + b;
		while (x != x2){
			if (d < 0)
			{
				d += d1;
			}
			else
			{
				x += cx;
				d += d2;
			}
			y += cy;
			putpixel(x, y,WHITE);
		}
	}
}

// 八对称性
void draw_circle_8(int xc, int yc, int x, int y){
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc - x, yc + y, WHITE);
	putpixel(xc + x, yc - y, WHITE);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc + y, yc + x, WHITE);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc - y, yc - x, WHITE);
}

// 使用bresenham算法绘制圆
void bresenHamCircle(int xc, int yc, int r,int fill){
	// 初始化绘图窗口
	initgraph(640,480);
	if (xc + r < 0 || xc - r >= 640 ||
		yc + r < 0 || yc - r >= 480) return;

	int x = 0, y = r, yi, d;
	d = 3 - 2 * r;

	if (fill) {
		// 如果填充（画实心圆）
		while (x <= y) {
			for (yi = x; yi <= y; yi ++)
				draw_circle_8(xc, yc, x, yi);

			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y --;
			}
			x++;
		}
	} else {
		// 如果不填充（画空心圆）
		while (x <= y) {
			draw_circle_8( xc, yc, x, y);

			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y --;
			}
			x ++;
		}
	}
}

// 使用中点画圆法绘制圆
void midPointCircle(int xc,int yc,int r){
	// 初始化绘图窗口
	initgraph(640,480);
	if (xc + r < 0 || xc - r >= 640 ||
		yc + r < 0 || yc - r >= 480) return;
	int x, y;
	double d;
	x = 0;
	y = r;
	d = 1.25 - r;
	draw_circle_8(xc , yc , x , y);
	while(x < y)
	{
		if(d < 0)
		{
			d = d + 2 * x + 3;
		}
		else
		{
			d = d + 2 * ( x - y ) + 5;
			y--;
		}
		x++;
		draw_circle_8(xc , yc , x , y);
	}
}

// 使用正负法绘制圆
void posnegCircle(int xc,int yc,int r){
	// 初始化绘图窗口
	initgraph(640,480);
	int x, y, f;
	x = 0;
	y = r;
	f = 0;
	while(x <= y)
	{
		draw_circle_8(xc, yc, x, y);
		if(f <= 0)
		{
			f = f + 2 * x + 1;
			x++;
		}
		else
		{
			f = f - 2 * y + 1;
			y--;
		}
	}
}

// 快速画圆法
void fastCircle(int xc,int yc,int r){
	// 初始化绘图窗口
	initgraph(640,480);
	int x, y, d;
	x = 0;
	y = r;
	d = -r / 2;
	draw_circle_8(xc , yc , x , y);
	if(r % 2 == 0)
	{
		while(x < y)
		{
			x++;
			if(d < 0)
				d += x;
			else
			{
				y--;
				d += x - y;
			}
			draw_circle_8(xc , yc , x , y);
		}
	}
	else
	{
		while(x < y)
		{
			x++;
			if(d < 0)
				d += x + 1;
			else
			{
				y--;
				d += x - y + 1;
			}
			draw_circle_8(xc , yc , x , y);
		}
	}
}

// 矩形填充算法
void fiilRectangle(MyRectangle *rect){
	// 初始化绘图窗口
	initgraph(640,480);
	int x,y;
	for(y = rect->ymin;y<=rect->ymax;y++){
		for(x = rect->xmin;x<=rect->xmax;x++){
			putpixel(x,y,WHITE);
		}
	}


}

// 射线法
bool isPointInPolygon(POINT pts[],POINT point,int size){
	bool flag = false;
	POINT p1,p2;
	for(int i = 0, j = size; i < size; j = i++) {
		p1 = pts[i];
		p2 = pts[j];
		// 这里判断是否刚好被测点在多边形的边上
		if(isDotInLineSegment(point, p1, p2)) return true;
		if((p1.y > point.y != p2.y > point.y) && (point.x < (point.y - p1.y) * (p1.x - p2.x) / (p1.y - p2.y) + p1.x)) {
			flag = !flag;
		}
	}
	return flag;
}

// 点与线得关系
bool isDotInLineSegment(POINT point,POINT p1,POINT p2){
	bool flag = false;
	double x0 = point.x,y0 = point.y,x1 = p1.x,x2 = p2.x,y1 = p1.y,y2=p2.y;
	double xmin = x1<x2?x1:x2;
	double ymin = y1<y2?y1:y2;
	double xmax = x1>x2?x1:x2;
	double ymax = y1>y2?y1:y2;

	if((x1-x0)*(y2-y1)-(x2-x1)*(y1-y0)==0&&(x0>=xmin)&&(x0<=xmax)&&(y0>=ymin)&&(y0<=ymax)){
		flag = true;
	}
	return flag;
}

// 判断多边形走向是否是逆时针，逆时针为true
bool isClockWise(POINT poly[],int size)
{
	double d = 0;
	for (int i = 0; i < size-1; i++)
	{
		d += -0.5 * (poly[i + 1].y + poly[i].y) * (poly[i + 1].x - poly[i].x);
	}
	if (d > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main(){

	/*----------------------- 测试最大公约数的计算------------------------
	int a = 12,b = 18;
	cout<<gcd(a,b);
	*/

	/*----------------------- 测试直接插入排序算法---------------------------
	int arr[] = {99, 2, 3, 1, 22, 88, 7, 77, 54};
	si_sort(arr,9);
	for (int i = 0; i < 9; i++)
	cout << arr[i] << endl;*/

	/*------------------------ 测试选择排序算法------------------------------
	int arr[] = {99, 2, 3, 1, 22, 88, 7, 77, 54};
	select_sort(arr,9);
	for (int i = 0; i < 9; i++)
	cout << arr[i] << endl;
	*/

	/*------------------------ 测试冒泡排序算法-------------------------------
	int arr[] = {99, 2, 3, 1, 22, 88, 7, 77, 54};
	bubble_sort(arr,9);
	for (int i = 0; i < 9; i++)
	cout << arr[i] << endl;
	*/


	/*------------------------ 测试快速排序算法-------------------------------
	int arr[] = {99, 2, 3, 1, 22, 88, 7, 77, 54};
	int arrLength = sizeof(arr)/sizeof(int);
	fast_sort(arr,0,arrLength-1);
	for (int i = 0; i < 9; i++)
	cout << arr[i] << endl;
	*/

	/*------------------------ 测试DDA绘制直线方法-----------------------------
	int x1 = 30,y1 = 30,x2 = 10,y2 = 100;
	drawDDA(x1,y1,x2,y2);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/


	/*------------------------ 测试bresenham绘制直线方法-----------------------------
	int x1 = 30,y1 = 30,x2 = 10,y2 = 100;
	bresenHam(x1,y1,x2,y2);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/


	/*------------------------ 测试中点画线法绘制直线方法-----------------------------
	int x1 = 30,y1 = 30,x2 = 10,y2 = 100;
	midPointLine(x1,y1,x2,y2);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/


	/*------------------------ 测试bresenham法绘制圆方法-----------------------------
	int x1 = 30,y1 = 30,r = 10,fill = 1;
	bresenHamCircle(x1,y1,r,0);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/


	/*------------------------ 测试中点画线法绘制圆方法-----------------------------
	int x1 = 30,y1 = 30,r = 10 ;
	midPointCircle(x1,y1,r);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/


	/*------------------------ 测试正负画线法绘制圆方法-----------------------------
	int x1 = 30,y1 = 30,r = 10 ;
	posnegCircle(x1,y1,r);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/


	/*------------------------ 测试快速画圆方法-----------------------------
	int x1 = 30,y1 = 30,r = 10 ;
	fastCircle(x1,y1,r);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/

	/*------------------------ 测试矩形填充方法-----------------------------
	MyRectangle rect = {10,50,10,50} ;
	fiilRectangle(&rect);
	_getch();
	// 关闭绘图窗口
	closegraph();
	*/

	/*------------------------ 测试点与多边形关系判断方法-----------------------------
	POINT pts[] = { {50, 200}, {200, 200}, {200, 50} ,{50,50}, {50, 200}};
	POINT pt = {200,100};
	bool isIn = isPointInPolygon(pts,pt,5);
	cout<<isIn<<endl;
	*/

	/*------------------------ 测试多边形走向判断方法-----------------------------
	POINT pts[] = { {50, 200}, {50, 50}, {200, 50} ,{200,200}, {50, 200}};
	POINT pts2[] = { {50, 200}, {200, 200}, {200, 50} ,{50,50}, {50, 200}};
	bool isClock = isClockWise(pts2,5);
	cout<<isClock<<endl;
	*/

	system("pause");

}
