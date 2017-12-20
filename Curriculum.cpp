#include "stdafx.h"
#include "Curriculum.h"


Curriculum::Curriculum()
{
	ordinalNum = 0, academicHour = 0, term = 0;
	preClass[1] = 0, preClass[0] = 0;
	compiled = false;
	for (int i = 0; i < 50; i++)
	{
		className[i] = '\0';
	}
}


Curriculum::~Curriculum()
{
}

void Curriculum::setAll(int o, char * c, int a, int t, int p[2])
{
	ordinalNum = o,  academicHour = a, term = t;
	preClass[1] = p[1], preClass[0] = p[0];
	if (t != 0)
	{
		this->setCompile();
	}
	for (int i = 0; i < 50; i++)
	{
		if (c[i] == 0)
			break;
		className[i] = c[i];
	}
}

void Curriculum::setTerm(int n)
{
	term = n;
}

char * Curriculum::getClassName()
{
	return className;
}

int Curriculum::getTerm()
{
	return term;
}

bool Curriculum::isCompiled()
{
	return compiled;
}

void Curriculum::setCompile()
{
	compiled = true;
}

void setAllTerm(Curriculum * c, int num)
{
	int i = 1;
	while (i <= num)
	{
		if (c[i].preClass[0] == 0)
		{
			if (c[i].term == 0)
				c[i].setTerm(1);
		}
		else
		{
			if(c[c[i].preClass[0]].term > c[c[i].preClass[1]].term)
				c[i].setTerm(c[c[i].preClass[0]].term + 1);
			else
				c[i].setTerm(c[c[i].preClass[1]].term + 1);
		}
		i++;
	}
}

void outputClassName(Curriculum c)
{
	if (c.className == 0)
		cout << "class not exist" << endl;
	else
	{
		cout << c.className;
		cout << "   ";
	}
}

void swap(Curriculum &a, Curriculum &b)
{
	int o, a1, t, p1, p2;
	char c[50] = { 0 };
	bool c1 = a.compiled;
	o = a.ordinalNum, a1 = a.academicHour, t = a.term, p1 = a.preClass[0], p2 = a.preClass[1];
	a.compiled = b.compiled, b.compiled = c1;
	for (int i = 0; i < 50; i++)
	{
		if (a.className[i] == 0)
			break;
		c[i] = a.className[i];
	}
	a.ordinalNum = b.ordinalNum, b.ordinalNum=o;
	a.academicHour = b.academicHour, b.academicHour=a1;
	a.term = b.term, b.term=t;
	a.preClass[0] = b.preClass[0], b.preClass[0]=p1;
	a.preClass[1] = b.preClass[1], b.preClass[1]=p2;
	for (int i = 0; i < 50; i++)
	{	
		a.className[i]= b.className[i];
		b.className[i] = c[i];
	}
}
