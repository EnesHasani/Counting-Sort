#include <iostream>
#include <math.h>
using namespace std;
int Min(int vargu_i_pa_Sortuar[], int madhesia) {
	int min = vargu_i_pa_Sortuar[0];
	for (int i = 1; i < madhesia; i++)
	{
		if (min > vargu_i_pa_Sortuar[i])                        //Gjejme numrin me te vogel ne vargun e pasortuar
			min = vargu_i_pa_Sortuar[i];
	}
	return min;
}
int Max(int vargu_i_pa_Sortuar[] , int madhesia) {
	int max = vargu_i_pa_Sortuar[0];
	for (int i = 1; i < madhesia; i++)
	{
		if (max < vargu_i_pa_Sortuar[i])                        //Gjejme numrin me te madh ne vargun e pasortuar
			max = vargu_i_pa_Sortuar[i];
	}
	return max;
}
int *Counting_sort(int vargu_i_pa_Sortuar[], int madhesia) {
	int min = Min(vargu_i_pa_Sortuar, madhesia);

	if (min < 0) {
		for (int i = 0; i < madhesia; i++)
		{
			vargu_i_pa_Sortuar[i] += abs(min);
		}
	}

	int max = Max(vargu_i_pa_Sortuar, madhesia);

	int* vargu_numerues = new int[max + 1];                       //  Anetaret e ketij vargu tregojne se sa here paraqitet  indeksi qe i korrespondon vleres se elementit ne vargun e pa sortuar(po ashtu edhe ne te sortuarin). Pra sa here paraqitet nje numer ne varg .

	for (int i = 0; i < max ; i++)
	{
		vargu_numerues[i] = 0;                                    //I inicializojme te gjithe antaret e vargut numrues fillimisht me vleren 0 ; 
	}


	for (int i = 0; i < madhesia ; i++)
	{
		vargu_numerues[vargu_i_pa_Sortuar[i]]++;                                 // Per cdo vlere qe fitojme te anetaret e vargut te pasortuar , indeksin e vargut numerues qe ka po ate vlere e rrisim per nje (1)
	}


	for (int i = 1; i <=max ; i++)
	{
		vargu_numerues[i] = vargu_numerues[i - 1] + vargu_numerues[i];                                 //E bojme update vargun numerues , ky varg na jep informata per pozitat(jo indeksat) e anetareve te vargut te sortuar qe do ta krijojme 
	}

	int* vargu_i_Sortuar = new int[madhesia];

	for (int i=madhesia-1  ;  i >= 0 ; i--)
	{
		vargu_numerues[vargu_i_pa_Sortuar[i]]--;                                                                  // vargu_i_pa_Sortuar[i] na jep vleren qe gjendet ne indeksin i ne vargun e pa sortuar , kjo vlere gjendet ne intervalin 0 <= i <=max , pasi qe vargu_numerues[vargu_i_pa_Sortuar[i]] tregon poziten qe do ta kete ne varg te sortuar, ate e zvoglojme per nje dhe marrim indeksin e anetarit i ne vargun e ri 

		vargu_i_Sortuar[vargu_numerues[vargu_i_pa_Sortuar[i]]]= vargu_i_pa_Sortuar[i];                               //  Tregon se ne cilin indeks te vargut te sortuar do te vendoset anetari i cili ne vargun e pasortuar kishte indeksin i .
	}

	for (int i = 0; i < madhesia ; i++)
	{
		vargu_i_Sortuar[i] -= abs(min);
	}
	return vargu_i_Sortuar;
}
int main() {
	int madhesia_e_vargut;
	cout << "Vendos numrin e anetareve : ";
	cin >> madhesia_e_vargut;
	int* vargu_i_pa_sortuar= new int[madhesia_e_vargut];
	for (int i = 0; i < madhesia_e_vargut; i++)
	{
		cout << "Vendos anetarin " << i + 1 << ": ";
		cin >> vargu_i_pa_sortuar[i];
	}
	int *vargu_i_sortuar = Counting_sort(vargu_i_pa_sortuar, madhesia_e_vargut);
	cout << "Vargu i sortuar : ";
	for (int i = 0; i < madhesia_e_vargut; i++)
	{
		cout << vargu_i_sortuar[i]<<" ";
	}
	cout << endl;
	return 0;
}
