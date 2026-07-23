#include<stdio.h>
int main() {
	double h = 150 * 2 / 15;
	double up = 15, down = 25;
	double ans = (up + down) * h / 2;

  scanf("%lf%lf", &up,&down);

	//int      %d   4字节
	//float    %f   4字节
	//double   %lf  8字节


	printf("%-8.2lf", ans);
	//输出%n.m     n表示宽度（整数位数+小数点+小数位数），如果限制宽度>实际宽度：前面补空格、0n.m 左面补0、-n.m 右面补空格
	//                                                        限制宽度<实际宽度：不限制
	//             m表示小数点位数
	return 0;
}
