#pragma once
class Curriculum
{
private:
	int ordinalNum;
	char className[50];
	int academicHour;
	int term;
	int preClass[2];
	bool compiled;
public:
	Curriculum();
	~Curriculum();
	void setAll(int o,char* c,int a,int t,int p[2]);
	void setTerm(int n);
	char* getClassName();
	int getTerm();
	bool isCompiled();
	void setCompile();
	friend void setAllTerm(Curriculum* c,int num);
	friend void outputClassName(Curriculum c);
	friend void swap(Curriculum& a, Curriculum& b);
};

