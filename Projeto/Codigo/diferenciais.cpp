#include"diferenciais.h"

using namespace std;


int Euler()
{
	int passo = 60;

	double yn = 0;
	double yn1;

	double y60;
	double y120;
	double y240;

	double qc;
	double erro;



	cout << "Medicao de 1 em 1 hora." << endl;
	for (unsigned int t = 0; t < tempo_tomada;)
	{
		yn1 = yn + passo * (D(t) - Ke * yn)/vap;
		cout << setprecision(5) << setw(5) << "Tempo: " << t << " minutos\t" << "Y: " << yn << "\n"; //falta QC e erro
		yn = yn1;
		t = t + passo;
	}

	y60 = yn;
	passo = 2 * passo;
	yn = 0;
	cout << endl << endl << endl;
	cout << "Medicao de 2 em 2 horas." << endl;

	for (unsigned int t = 0; t < (72*60);)
	{
		yn1 = yn + passo * (D(t) - Ke * yn)/vap;
		cout << setprecision(5) << setw(5) << "Tempo: " << t << " minutos\t" << "Y: " << yn << "\n"; //falta QC e erro
		yn = yn1;
		t = t + passo;
	}

	y120 = yn;
	passo = 2 * passo;
	yn = 0;
	cout << endl << endl << endl;
	cout << "Medicao de 4 em 4 horas." << endl;

	for (unsigned int t = 0; t < (72*60);)
	{
		yn1 = yn + passo * (D(t) - Ke * yn)/vap;
		cout << setprecision(5) << setw(5) << "Tempo: " << t << " minutos\t" << "Y: " << yn << "\n"; //falta QC e erro
		yn = yn1;
		t = t + passo;
	}
	y240 = yn;
	cout << endl << endl;
	qc = (y120 - y240) / (y60 - y120);
	erro = abs(y240 - y120);
	cout << "Quoficiente de Convergencia: " << setprecision(5) << qc << endl;
	cout << "Erro: " << setprecision(5) << erro << endl;
	system("pause");
	system("cls");
	return 0;
}

int EulerModificado()
{
	double y[72];
	double y1[36];
	double y2[18];
	double yn1;
	double yn = 0;
	double pn1 = 0;
	double qc;
	double erro;

	int contador = 0;
	int passo = 60;
	
	double y60;
	double y120;
	double y240;

	cout << "Medicao de 1 em 1 hora." << endl;
	for (unsigned int t = 0; t < tempo_tomada;)
	{
		y[t/passo] = yn;
		if (t >= (passo * 2))
		{
			pn1 = y[t/passo -1] + 2 * passo * (D(t) - Ke * yn)/vap;
		}
		if (t >= (passo * 2))
		{
			yn1 = yn + passo/2 *( (D(t) - Ke * yn)/vap + (D(t + passo) - Ke * pn1)/vap);
		}
		else yn1 = yn + passo * (D(t) - Ke * yn)/vap;

		cout << setprecision(5) << setw(5) << "Tempo: " << t << " minutos\t" << "Y: " << yn << "\n";
		yn = yn1;

		t = t + passo;
	}

	y60 = yn;
	passo = 2 * passo;
	yn = 0;
	cout << endl << endl << endl;
	cout << "Medicao de 2 em 2 horas." << endl;

	for (unsigned int t = 0; t < tempo_tomada;)
	{
		y[t/passo] = yn;
		if (t >= (passo * 2))
		{
			pn1 = y[t/passo -1] + 2 * passo * (D(t) - Ke * yn)/vap;
		}
		if (t >= (passo * 2))
		{
			yn1 = yn + passo/2 *( (D(t) - Ke * yn)/vap + (D(t + passo) - Ke * pn1)/vap);
		}
		else yn1 = yn + passo * (D(t) - Ke * yn)/vap;

		cout << setprecision(5) << setw(5) << "Tempo: " << t << " minutos\t" << "Y: " << yn << "\n";
		yn = yn1;

		t = t + passo;
	}

	y120 = yn;
	passo = 2 * passo;
	yn = 0;
	cout << endl << endl << endl;
	cout << "Medicao de 4 em 4 horas." << endl;


	for (unsigned int t = 0; t < tempo_tomada;)
	{
		y2[t/passo] = yn;
		if (t >= (passo * 2))
		{
			pn1 = y2[t/passo -1] + 2 * passo * (D(t) - Ke * yn)/vap;
		}
		if (t >= (passo * 2))
		{
			yn1 = yn + passo/2 *( (D(t) - Ke * yn)/vap + (D(t + passo) - Ke * pn1)/vap);
		}
		else yn1 = yn + passo * (D(t) - Ke * yn)/vap;

		yn = yn1;

		cout << setprecision(5) << setw(5) << "Tempo: " << t << " minutos\t" << "Y: " << yn << "\n";

		t = t + passo;
	}
	

	y240 = yn;
	cout << endl << endl;
	qc = (y120 - y240) / (y60 - y120);
	erro = abs(y240 - y120);
	cout << "Quoficiente de Convergencia: " << setprecision(5) <<qc << endl;
	cout << "Erro: " << setprecision(5) << erro << endl;
	system("pause");
	system("cls");
	return 0;
}

int RungeKutta2()
{
	return 0;
}

int RungeKutta4()
{
	return 0;
}

double D(int t)
{
	if (t == (4 * 60))
		return 1000;
	else return 0;
}