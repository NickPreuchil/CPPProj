#pragma once

#include <iostream>

#include "Linear.h"
#include "Square.h"

using std::cin;
using std::cout;
using std::endl;

class Series {
public:
	Series() 
	{
		ResArray = new Result* [MaxEqCount];
	};
	void AddEq(Solution* Eq)
	{
		Eq->Evaluate();
		Result* temp = Eq->PrintResult();
		ResArray[ResCount++] = temp;
	}
	void PrintSeries()
	{
		if (ResCount == 0)
			cout << "�� ��� �� �������� �� ������ ���������" << endl;
		for (int i = 0; i < ResCount; i++)
		{
			Result* TmpRes = ResArray[i];
			cout << "������� ��������� | " << TmpRes->Equation << " |" << endl;
			switch (TmpRes->RC)
			{
			case(ZERO):
			{
				cout << "��������� �� ����� ������������ ������";
				if (TmpRes->Log != "")
					cout << '(' << TmpRes->Log << ')' << endl;
				else
					cout << endl;
				break;
			}
			case(ONE):
			{
				cout << "��������� ����� ���� ������������ ������";
				if (TmpRes->Log != "")
					cout << '(' << TmpRes->Log << ')' << endl;
				else
					cout << endl;
				cout << "x = " << TmpRes->Roots[0] << endl;
				break;
			}
			case(TWO):
			{
				cout << "��������� ����� ��� ������������ �����";
				if (TmpRes->Log != "")
					cout << '(' << TmpRes->Log << ')' << endl;
				else
					cout << endl;
				cout << "x_1 = " << TmpRes->Roots[0] << endl;
				cout << "x_2 = " << TmpRes->Roots[1] << endl;
				break;
			}
			case(INF):
			{
				cout << "��������� ����� ����������� ����� ������������ ������";
				if (TmpRes->Log != "")
					cout << '(' << TmpRes->Log << ')' << endl;
				else
					cout << endl;
				break;
			}
			}
			cout << "-----------------------------------------------------------------" << endl;
		}
	}
	~Series()
	{
		if(ResArray)
			delete[] ResArray;
	}
private:
	Result** ResArray = nullptr;
	int ResCount = 0;
};