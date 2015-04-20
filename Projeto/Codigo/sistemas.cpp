#include"sistemas.h"

using namespace std;

int eulerSistemas()
{
	double mi = 0; //condicao inicial «
	double mp = 0; //condicao inicial
	double passo = 60;
	
	cout << "Ka: " << Ka_0 << endl;
	cout << setw(5) << "t \t mi\t mp\t" << endl;
	for (unsigned int t = 0; t < tempo_tomada;)
	{
		mp = mp + passo * (Ka_0*mi - Ket * mp);
		mi = mi + passo * (D(t) - Ka_0 *mi);
		cout << setprecision(5) << setw(5) << t << "\t" << mi << "\t" << "\t" << mp << endl;
		t = t + passo;
	}

	cout << endl << endl << endl;
	mi = 0;
	mp = 0;
	cout << "Ka: " << Ka_1 << endl;
	cout << setw(5) << "t \t mi\t mp\t" << endl;
	for (unsigned int t = 0; t < tempo_tomada;)
	{
		mp = mp + passo * (Ka_1*mi - Ket * mp);
		mi = mi + passo * (D(t) - Ka_1 *mi);
		cout << setprecision(5) << setw(5) << t << "\t" << mi << "\t" << "\t" << mp << endl;
		t = t + passo;
	}

	system("pause");
	system("cls");
	return 0;
}

int rungeSistemas()
{

	double mi = 0; //condicao inicial
	double mp = 0; //condicao inicial

	double m1i;
	double m2i;
	double m3i;
	double m4i;
	double m1p;
	double m2p;
	double m3p;
	double m4p;

	double passo = 60;
	
	cout << "Ka: " << Ka_0 << endl;
	cout << "t \t mi\t mp\t" << endl;
	for (unsigned int t = 0; t < tempo_tomada;)
	{
		m1i = passo * (D(t)- Ka_0*mi);
		m2i = passo * (D(t + passo/2) -Ka_0*(m1i/2 + mi));
		m3i = passo * (D(t + passo/2) -Ka_0*(m2i/2 + mi));
		m4i = passo * (D(t + passo) - Ka_0*(m3i/2 + mi));

		m1p = passo * (Ka_0*mi - Ket*mp);
		m2p = passo * (Ka_0*(mi+m1i/2) - Ket*(mp+m1p/2));
		m3p = passo * (Ka_0*(mi+m2i/2) - Ket*(mp+m2p/2));
		m4p = passo * (Ka_0*(mi+m3i) - Ket*(mp+m3p));

		mi = mi + m1i/6 + m2i/3 + m3i/3 + m4i/6;
		mp = mp + m1p/6 + m2p/3 + m3p/3 + m4p/6;
		cout << setprecision(5) << setw(5) << t << "\t" << mi << "\t" << "\t" << mp << endl;
		t = t + passo;
	}
	cout << endl << endl << endl;

	mi = 0;
	mp = 0;
	cout << "Ka: " << Ka_1 << endl;
	cout << "t \t mi\t mp\t" << endl;
	for (unsigned int t = 0; t < tempo_tomada;)
	{
		m1i = passo * (D(t)- Ka_1*mi);
		m2i = passo * (D(t + passo/2) - Ka_1*(m1i/2 + mi));
		m3i = passo * (D(t + passo/2) - Ka_1*(m2i/2 + mi));
		m4i = passo * (D(t + passo) - Ka_1*(m3i/2 + mi));

		m1p = passo * (Ka_1*mi - Ket*mp);
		m2p = passo * (Ka_1*(mi+m1i/2) - Ket*(mp+m1p/2));
		m3p = passo * (Ka_1*(mi+m2i/2) - Ket*(mp+m2p/2));
		m4p = passo * (Ka_1*(mi+m3i) - Ket*(mp+m3p));

		mi = mi + m1i/6 + m2i/3 + m3i/3 + m4i/6;
		mp = mp + m1p/6 + m2p/3 + m3p/3 + m4p/6;
		cout << setprecision(5) << setw(5) << t << "\t" << mi << "\t" << "\t" << mp << endl;
		t = t + passo;
	}
	cout << endl << endl << endl;
	system("pause");
	system("cls");
	return 0;
}