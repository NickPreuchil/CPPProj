#pragma once
#include <iostream>
#include <string>
constexpr double eps = 1e-5;
constexpr int MaxEqCount = 100;

using std::pair;
using std::exception;
using std::string;
using std::to_string;

enum RootCount
{
	ZERO = 0, 
	ONE, 
	TWO, 
	INF
};

struct Result
{
	string Equation = "";
	double* Roots = nullptr;
	RootCount RC;
	string Log = "";
};

class Solution {
public:
	virtual void Evaluate() 
	{
		throw exception("Solution::Evaluate\nSomething goes wrong\n");
	}
	virtual Result* PrintResult() const 
	{
		throw exception("Solution::PrintResult\nSomething goes wrong\n");
	};
	virtual ~Solution() = default;
};