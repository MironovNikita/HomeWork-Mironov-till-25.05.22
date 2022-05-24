#pragma once

class Fraction
{
private:
	int wh;	//целая часть
	int num;//числитель
	int den;//знаменатель
public:
	Fraction(int wh, int num, int den)
	{
		this->wh = wh;
		this->num = num;
		this->den = den;
	}

	void setWh(int wh)
	{
		this->wh = wh;
	}
	int getWh()
	{
		return wh;
	}

	void setNum(int num)
	{
		this->num = num;
	}
	int getNum()
	{
		return num;
	}

	void setDen(int den)
	{
		this->den = den;
	}
	int getDen()
	{
		return den;
	}

	/*void plus(Fraction f2)
	{
		int z = 0 , x, y;
		//z = wh + f2.getWh();
		if (wh > 0)
		{
			num += wh * den;
		}
		if (f2.getWh() > 0)
		{
			f2.setNum(f2.getNum() + f2.getWh() * f2.getDen());
		}
		
		if (den != f2.getDen())
		{
			y = den * f2.getDen();
			x = num * f2.getDen() + f2.getNum() * den;
		}
		else
		{
			y = den;
			x = num + f2.getNum();
		}


		for (int i = 2; i < 10; i++)
		{
			if (x % i == 0 && y % i == 0)
			{
				x /= i;
				y /= i;
				break;
			}
		}
					
		if (x > y)
		{
			z += x / y;
			x -= z * y;
		}
		else if (x == y)
		{
			z++;
			x = 0;
			y = 0;
		}
		if (x == 0) y = 0;
		
		cout << "Результат сложения дробей: " << z << " целых " << x << " / " << y << endl;
	}*/

	void plus(Fraction f2)
	{
		int z1, x1, y1;
		int x2, y2;
		if (wh > 0)
		{
			x1 = den * wh + num;
		}
		else if (wh == 0) x1 = num;
		else
		{
			x1 = (den * (-1 * wh) + num) * -1;
		}

		if (f2.getWh() > 0)
		{
			x2 = f2.getDen() * f2.getWh() + f2.getNum();
		}
		else if (f2.getWh() == 0) x2 = f2.getNum();
		else
		{
			x2 = (f2.getDen() * (-1 * f2.getWh()) + f2.getNum()) * -1;
		}

		y1 = den;
		y2 = f2.getDen();

		if (y1 != y2)
		{
			x1 *= y2;
			x2 *= y1;
			x1 += x2; //приведение к общему знаменателю
			y1 *= y2;
		}
		else
		{
			//y1 не меняется
			x1 += x2;
		}

		for (int i = 2; i <= 10; i++)
		{
			if (x1 % i == 0 && y1 % i == 0)
			{
				x1 /= i;
				y1 /= i;
				break;
			}
		}

		if (x1 > y1)
		{
			z1 = x1 / y1;
			x1 -= z1 * y1;
		}
		else if (x1 < 0 && ((-1 * x1) / y1 > 0))
		{
			z1 = (-1*x1) / y1;
			x1 *= -1;
			x1 -= z1 * y1;
			z1 *= -1;
		}
		else z1 = 0;

		if (x1 == 0)
		{
			y1 = 0;
		}
		else if (x1 == y1)
		{
			z1++;
			x1 = 0;
			y1 = 0;
		}
		else if (y1 == 1)
		{
			z1 += x1;
			x1 = 0;
			y1 = 0;
		}
		cout << "Результат сложения дробей: " << z1 << " целых " << x1 << " / " << y1 << endl;
	}

	void mult(Fraction f2)
	{
		int  x1, y1, z1;
		int x2, y2;

		if (wh > 0)
		{
			x1 = den * wh + num;
		}
		else if (wh == 0) x1 = num;
		else
		{
			x1 = (den * (-1 * wh) + num) * -1;
		}

		if (f2.getWh() > 0)
		{
			x2 = f2.getDen() * f2.getWh() + f2.getNum();
		}
		else if (f2.getWh() == 0) x2 = f2.getNum();
		else
		{
			x2 = (f2.getDen() * (-1 * f2.getWh()) + f2.getNum()) * -1;
		}

		y1 = den;
		y2 = f2.getDen();
		
		x1 *= x2;
		y1 *= y2;

		if (x1 > y1)
		{
			z1 = x1 / y1;
			x1 -= z1 * y1;
		}
		else if (x1 < 0 && ((-1 * x1) / y1 > 0))
		{
			z1 = (-1 * x1) / y1;
			x1 *= -1;
			x1 -= z1 * y1;
			z1 *= -1;
		}
		else z1 = 0;

		for (int i = 2; i <= 10; i++)
		{
			if (x1 % i == 0 && y1 % i == 0)
			{
				x1 /= i;
				y1 /= i;
				break;
			}
		}

		cout << "Результат перемножения дробей: " << z1 << " целых " << x1 << " / " << y1 << endl;
	}

	void minus(Fraction f2)
	{
		int z1, x1, y1;
		int x2, y2;
		if (wh > 0)
		{
			x1 = den * wh + num;
		}
		else if (wh == 0) x1 = num;
		else
		{
			x1 = (den * (-1 * wh) + num) * -1;
		}

		if (f2.getWh() > 0)
		{
			x2 = f2.getDen() * f2.getWh() + f2.getNum();
		}
		else if (f2.getWh() == 0) x2 = f2.getNum();
		else
		{
			x2 = (f2.getDen() * (-1 * f2.getWh()) + f2.getNum()) * -1;
		}

		y1 = den;
		y2 = f2.getDen();

		if (y1 != y2)
		{
			x1 *= y2;
			x2 *= y1;
			x1 -= x2; //приведение к общему знаменателю
			y1 *= y2;
		}
		else
		{
			//y1 не меняется
			x1 -= x2;
		}

		for (int i = 2; i <= 10; i++)
		{
			if (x1 % i == 0 && y1 % i == 0)
			{
				x1 /= i;
				y1 /= i;
				break;
			}
		}

		if (x1 > y1)
		{
			z1 = x1 / y1;
			x1 -= z1 * y1;
		}
		else if (x1 < 0 && ((-1 * x1) / y1 > 0))
		{
			z1 = (-1 * x1) / y1;
			x1 *= -1;
			x1 -= z1 * y1;
			z1 *= -1;
		}
		else z1 = 0;

		if (x1 == 0)
		{
			y1 = 0;
		}
		else if (x1 == y1)
		{
			z1++;
			x1 = 0;
			y1 = 0;
		}
		else if (y1 == 1)
		{
			z1 += x1;
			x1 = 0;
			y1 = 0;
		}
		cout << "Результат вычитания дробей: " << z1 << " целых " << x1 << " / " << y1 << endl;
	
	}

	void div(Fraction f2)
	{
		int  x1, y1, z1;
		int x2, y2;

		if (wh > 0)
		{
			x1 = den * wh + num;
		}
		else if (wh == 0) x1 = num;
		else
		{
			x1 = (den * (-1 * wh) + num) * -1;
		}

		if (f2.getWh() > 0)
		{
			x2 = f2.getDen() * f2.getWh() + f2.getNum();
		}
		else if (f2.getWh() == 0) x2 = f2.getNum();
		else
		{
			x2 = (f2.getDen() * (-1 * f2.getWh()) + f2.getNum()) * -1;
		}

		y1 = den;
		y2 = f2.getDen();

		x1 *= y2;
		y1 *= x2;

		if (y1 < 0)
		{
			y1 *= -1;
			x1 *= -1;
		}

		if (x1 > y1)
		{
			z1 = x1 / y1;
			x1 -= z1 * y1;
		}
		else if (x1 < 0 && ((-1*x1)/y1 > 0))
		{
			z1 = (-1 * x1) / y1;
			x1 *= -1;
			x1 -= z1 * y1;
			z1 *= -1;
		}
		else z1 = 0;

		for (int i = 2; i <= 10; i++)
		{
			if (x1 % i == 0 && y1 % i == 0)
			{
				x1 /= i;
				y1 /= i;
				break;
			}
		}
		cout << "Результат деления дробей: " << z1 << " целых " << x1 << " / " << y1 << endl;
	}
};

