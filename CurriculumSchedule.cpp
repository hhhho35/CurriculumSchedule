// CurriculumSchedule.cpp : 定义控制台应用程序的入口点。
//有关数组的，还是要深复制，不能偷懒
//别忘了只有引用传参才能对实参有影响
//复制、构造函数类的字段千万不能少一个
#include "stdafx.h"
#include"Curriculum.h"

int main()
{
	cout << "请输入文件名" << endl;
	char filename[100] = { 0 };
	cin >> filename;
	fstream f;
	f.open(filename, ios::in);
	while (f.fail())
	{
		cout << "打开文件失败" << endl;
		cout << "请输入正确的已存在的文件名" << endl;
		cin >> filename;
		f.open(filename, ios::in);
	}
	cout << "文件打开成功" << endl << endl;

	Curriculum* cu = new Curriculum[40];
	int o, i = 1 , a, t, p[2];
	char test, c[100];
	while (!f.eof())
	{
		f >> o >> c >> a >> t >> p[0] >> test;
		if (test == '*')
		{
			p[1] = 0;
			cu[i].setAll(o, c, a, t, p);
			i++;
		}
		else
		{
			f >> p[1] >> test;
			cu[i].setAll(o, c, a, t, p);
			i++;
		}
	}
	setAllTerm(cu,i-2);//不知为什么到了文件尾不结束while
	int num[8] = { 6 ,7	, 3 , 6 , 5 , 5 , 5	,1 };//每学期课程数
	int num3[8] = { { 0 } };//每学期课程数,按不限制课程数来设置
	int index[8][2] = { {0} };//每学期必修课下标
	int tmp = 0, tmp2 = 0;//辅助变量
	int m1[8] = { 0 };//辅助数组
	for (int j = 1; j <= i - 2; j++)//选择排序，生成无课程数限制的拓扑序列
	{
		tmp = cu[j].getTerm();
		tmp2 = j;
		for (int k = j + 1; k <= i - 2; k++)
		{
			if (tmp > cu[k].getTerm())
			{
				tmp = cu[k].getTerm();
				tmp2 = k;
			}
		}
		if (j != tmp2)
			swap(cu[j], cu[tmp2]);
	}
	for (int j = 1; j <= i - 2; j++)//更新index
	{
		tmp = cu[j].getTerm();
		num3[tmp - 1]++;
		if (cu[j].isCompiled() == true)
		{
			index[tmp - 1][m1[tmp - 1]] = j;
			m1[tmp - 1]++;
		}
	}
	int k1 = 1;
	int r = 0;
	for (int j = 0; j < 8; j++)//在拓扑排序基础上根据各学期课程数输出
	{
		cout << "第" << j + 1 << "学期课程有：" << endl;
		outputClassName(cu[index[j][0]]);
		if (index[j][1] == 0)
			{
				for ( r = 0; r < num[j]-1; )
				{
					if (cu[k1 + r].isCompiled())
						k1++;
					else
					{
						outputClassName(cu[k1 + r]);
						r++;
					}
				}
				k1 += r;
			}
		else
		{
			outputClassName(cu[index[j][1]]);
			for ( r = 0; r < num[j] - 2; )
			{
				if (cu[k1 + r].isCompiled())
					k1++;
				else
				{
					outputClassName(cu[k1 + r]);
					r++;
				}
			}
			k1 += r;
		}
		cout << endl << endl;
	}
	f.close();
    return 0;
}