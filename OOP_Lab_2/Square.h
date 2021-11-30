#pragma once
#include "Solution.h"



class Square : public Solution
{
public:
	Square() {};
	Square(double _a, double _b, double _c) : a_S(_a), b_S(_b), c_S(_c) {};
	void Evaluate() override
	{
		double D = (b_S * b_S) - (4 * a_S * c_S);
		if (abs(D) < eps)
		{
			RC = ONE;
			SpecLog = "Discriminant is equal to 0";
			value_1 = -b_S / (2 * a_S);
		}
		else if (D < 0)
		{
			RC = ZERO;
			SpecLog = "Discriminant is less then 0";
		}
		else
		{
			value_1 = (-b_S - sqrt(D)) / (2 * a_S);
			value_2 = (-b_S + sqrt(D)) / (2 * a_S);
		}
	}
	Result* PrintResult() const override
	{
		Result* res = nullptr;
		res = new Result;
		res->RC = RC;
		res->Log = SpecLog;
		res->Roots = new double[2];
		switch (RC)
		{
		case ONE:
			res->Roots[0] = value_1;
			break;
		case TWO:
			res->Roots[0] = value_1;
			res->Roots[1] = value_2;
			break;
		}
		res->Equation = '(' + to_string(a_S) + ")x^2 + (" + to_string(b_S) + ")x + (" + to_string(c_S) + ") = 0";
		return res;
	}
	~Square() = default;
private:
	double a_S = 0, b_S = 0, c_S = 0, value_1 = NULL, value_2 = NULL;
	RootCount RC = TWO;
	string SpecLog = "";
};