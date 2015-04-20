#include "zeros.h"

using namespace std;

int Bissecao()
{
	double a = 0;
	double b = 0.5; // guess
	double xn;
	double xn1;

	int contador = 0;

	double fa;
	double fb;
	double fxn = 0;

	double erro = 1;
	cout << "a \t b \t xn \t fa \t\t fb \t\t fxn \t erro" << endl;
	while (erro > precisao) //precisao
	{
		fa = a * exp(-a * tmax) - Ket*exp(-Ket * tmax);
		fb = b * exp(-b * tmax) - Ket*exp(-Ket * tmax);
		xn = (a+b)/2;
		fxn = xn * exp(-xn * tmax) - Ket*exp(-Ket * tmax);

		if (fxn < 0)
			a = xn;

		if (fxn > 0)
			b = xn;

		xn1 = (a+b)/2;
		if (contador == 0)
		{
			erro = 1;
		}
		else erro = abs((xn1 - xn)/xn1);
		contador++;
		cout << setprecision(5) << setw(5) << a << "\t" << b << "\t" << xn << "\t" << fa << "\t" << fb << "\t" << fxn << "\t" << erro << endl;

	}
	system("pause");
	system("cls");
	return 0;
}

int Newton()
{
	double xn = 0.5; //guess
	double xn1;
	double fxn;
	double dfxn;
	double erro = 1;

	cout << "Primeiro zero: \n";
	cout << "xn \t f(xn) \t df(xn) \t erro\n";
	while (erro > precisao)
	{
		fxn = xn * exp(-xn * tmax) - Ket*exp(-Ket * tmax);
		dfxn = exp(-5*xn)-5*xn*exp(-5*xn);
		xn1 = xn - fxn/dfxn;
		erro = abs(xn1 - xn);
		cout << setprecision(5) << setw(5) << xn << "\t" << fxn << "\t" << dfxn << "\t" << erro;
		xn = xn1;
		cout << endl;
	}

	erro = 1;
	xn = 0.1;
	cout << endl << endl;
	cout << "Segundo zero: \n";
	cout << "xn \t f(xn) \t df(xn) \t erro\n";
	while (erro > precisao)
	{
		fxn = xn * exp(-xn * tmax) - Ket*exp(-Ket * tmax);
		dfxn = exp(-5*xn)-5*xn*exp(-5*xn);
		xn1 = xn - fxn/dfxn;
		erro = abs(xn1 - xn);
		cout << setprecision(5) << setw(5) << xn << "\t" << fxn << "\t" << dfxn << "\t" << erro;
		xn = xn1;
		cout << endl;
	}

	system("pause");
	system("cls");
	return 0;
}

int Corda()
{
	double a = 0;
	double b = 0.5; //guess
	double xn;
	double xn1;

	int contador = 0;

	double fa;
	double fb;
	double fxn = 0;

	double erro = 1;
	cout << "Primeiro zero: \n";
	cout << "a \t b \t xn \t fa \t\t fb \t\t fxn \t erro" << endl;
	while (erro > precisao)
	{
		fa = a * exp(-a * tmax) - Ket*exp(-Ket * tmax);
		fb = b * exp(-b * tmax) - Ket*exp(-Ket * tmax);
		if (contador == 0)
			xn = 0;
		else xn = (a*fb - b*fa)/(fb-fa);
		fxn = xn * exp(-xn * tmax) - Ket*exp(-Ket * tmax);

		if (fxn < 0)
			a = xn;

		if (fxn > 0)
			b = xn;

		xn1 = (a*fb - b*fa)/(fb-fa);
		if (contador == 0)
		{
			erro = 1;
		}
		else erro = abs((xn1 - xn)/xn1);
		contador++;
		cout << setprecision(5) << setw(5) << a << "\t" << b << "\t" << xn << "\t" << fa << "\t" << fb << "\t" << fxn << "\t" << erro << endl;

	}

	erro = 1;
	a = 0;
	b = 0.2;
	fxn = 0;
	contador = 0;
	cout << endl << endl;
	cout << "Segundo zero: \n";
	cout << "a \t b \t xn \t fa \t\t fb \t\t fxn \t erro" << endl;
	while (erro > precisao)
	{
		fa = a * exp(-a * tmax) - Ket*exp(-Ket * tmax);
		fb = b * exp(-b * tmax) - Ket*exp(-Ket * tmax);
		if (contador == 0)
			xn = 0;
		else xn = (a*fb - b*fa)/(fb-fa);
		fxn = xn * exp(-xn * tmax) - Ket*exp(-Ket * tmax);

		if (fxn < 0)
			a = xn;

		if (fxn > 0)
			b = xn;

		xn1 = (a*fb - b*fa)/(fb-fa);
		if (contador == 0)
		{
			erro = 1;
		}
		else erro = abs((xn1 - xn)/xn1);
		contador++;
		cout << setprecision(5) << setw(5) << a << "\t" << b << "\t" << xn << "\t" << fa << "\t" << fb << "\t" << fxn << "\t" << erro << endl;

	}
	system("pause");
	system("cls");
	return 0;
}
