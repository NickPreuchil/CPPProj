#pragma once

#include "Linear.h"
#include "Series.h"
#include "Square.h"

class interactor
{
public:
	interactor()
	{
		while (flag)
		{
			switch (ChooseAct())
			{
			case(1):
			{
				Solution* Sol = nullptr;
				switch (ChooseEq())
				{
				case(1):
				{
					double a, b;
					cout << "Введите коэффициенты линейного уравнения:" << endl;
					cin >> a >> b;
					Sol = new Linear(a, b);
					break;
				}
				case(2):
				{
					double a, b, c;
					cout << "Введите коэффициенты квадратного уравнения:" << endl;
					cin >> a >> b >> c;
					Sol = new Square(a, b, c);
					break;
				}
				}
				if (Sol)
				{
					source.AddEq(Sol);
					delete Sol;
				}

				break;
			}
			case(2):
			{
				source.PrintSeries();
				break;
			}
			case(3):
			{
				flag = false;
				break;
			}
			}
		}
	}
	~interactor() = default;
private:
	int ChooseEq()
	{
		int Selected;
		cout << "\t\tВыберите тип уравнения:" << endl;
		cout << "1 - Линейное | 2 - Квадратное" << endl;
		cin >> Selected;
		if (Selected < 1 and Selected > 2)
		{
			while (true)
			{
				cout << "Неверный номер, попробуйте ещё:" << endl;
				cin >> Selected;
				if (Selected == 1 or Selected == 2)
					break;
			}
		}
		return Selected;
	}
	int ChooseAct()
	{
		int Selected;
		cout << "\t\tВыберите действие:" << endl;
		cout << "1 - Добавить уравнение | 2 - Вывести массив уравнений | 3 - Выйти" << endl;
		cin >> Selected;
		return Selected;
	}
	Series source;
	bool flag = true;
};
