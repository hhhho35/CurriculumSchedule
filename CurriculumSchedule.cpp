// CurriculumSchedule.cpp : �������̨Ӧ�ó������ڵ㡣
//�й�����ģ�����Ҫ��ƣ�����͵��
//������ֻ�����ô��β��ܶ�ʵ����Ӱ��
//���ơ����캯������ֶ�ǧ������һ��
#include "stdafx.h"
#include"Curriculum.h"

int main()
{
	cout << "�������ļ���" << endl;
	char filename[100] = { 0 };
	cin >> filename;
	fstream f;
	f.open(filename, ios::in);
	while (f.fail())
	{
		cout << "���ļ�ʧ��" << endl;
		cout << "��������ȷ���Ѵ��ڵ��ļ���" << endl;
		cin >> filename;
		f.open(filename, ios::in);
	}
	cout << "�ļ��򿪳ɹ�" << endl << endl;

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
	setAllTerm(cu,i-2);//��֪Ϊʲô�����ļ�β������while
	int num[8] = { 6 ,7	, 3 , 6 , 5 , 5 , 5	,1 };//ÿѧ�ڿγ���
	int num3[8] = { { 0 } };//ÿѧ�ڿγ���,�������ƿγ���������
	int index[8][2] = { {0} };//ÿѧ�ڱ��޿��±�
	int tmp = 0, tmp2 = 0;//��������
	int m1[8] = { 0 };//��������
	for (int j = 1; j <= i - 2; j++)//ѡ�����������޿γ������Ƶ���������
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
	for (int j = 1; j <= i - 2; j++)//����index
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
	for (int j = 0; j < 8; j++)//��������������ϸ��ݸ�ѧ�ڿγ������
	{
		cout << "��" << j + 1 << "ѧ�ڿγ��У�" << endl;
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