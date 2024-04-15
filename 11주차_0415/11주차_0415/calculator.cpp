#include<iostream>
#include "Calculator.h"
	int Calculator::X(double x)
	{
		return x;
	}
	int Calculator::Y(double y)
	{
		return y;
	}
	int Calculator::Oper(double sum, double x, double y)
	{
		switch (oper)
		{
		case "+":
			sum = x + y;
			break;
		case "C":
			return 0;
		case "Q":
			break;
		}
	}
}