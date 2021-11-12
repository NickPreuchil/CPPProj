#pragma once
#include "Solution.h"



class Linear : public Solution 
{
public:
	Linear() {};
	Linear(double _a, double _b) : a_L(_a), b_L(_b) {};
	void Evaluate() override {
		if (a_L == 0 and b_L == 0)
		{
			RC = INF;
		}
		else if (a_L == 0)
		{
			RC = ZERO;
			SpecLog = "Koefficient A = 0";
		}
		else
		{
			value = -b_L / a_L;
		}
		return;
	}
	Result* PrintResult() const override
	{
		Result* res = nullptr;
		res = new Result;
		res->RC = RC;
		res->Log = SpecLog;
		res->Roots = new double[2];
		if (RC == ONE)
			res->Roots[0] = value;
		res->Equation ='(' + to_string(a_L) + ")x + (" + to_string(b_L) + ") = 0";
		return res;
	}
	~Linear() = default;
private:
	double a_L = 0, b_L = 0, value = NULL;
	RootCount RC = ONE;
	string SpecLog = "";
};