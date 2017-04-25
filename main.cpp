#include "AlgPrima.h"

int main(int argc, char* argv[]){

	//	srand(time(NULL));
	//int n=10000; //число вершин графа
	int n;
	cin << n
	int m = 2 * n;
	double tlin1, tlin2, dtlin;


	int *ResLin_vA = new int[n - 1];
	int *ResLin_vB = new int[n - 1];
	int *ResLin_Weight = new int[n - 1];

	int *vA = new int[m];
	int *vB = new int[m];
	int *Weight = new int[m];




	GenerateGraph(n, m, vA, vB, Weight);
	for (int i = 0; i<m; i++)
	{
		int va, vb, w;
		va = vA[i];
		vb = vB[i];
		w = Weight[i];
	}


	//-------------------------------------------------------------------Линейный Алгоритм Прима
	int a, b, k = 0;
	int* mlin = new int[n];
	for (int i = 1; i<n; i++)
		mlin[i] = 0;
	mlin[0] = 1;//начинаем с 0 вершины
	int index = 0;
	while (Metka(mlin, n))
	{
		int minweight = INT_MAX;
		for (int i = 0; i<m; i++)
		{
			a = vA[i];
			b = vB[i];
			if ((mlin[a] == 1 && mlin[b] == 0) || (mlin[a] == 0 && mlin[b] == 1))
				if (Weight[i]<minweight)
				{
					index = i;
					minweight = Weight[i];
				}

		}
		mlin[vA[index]] = 1;
		mlin[vB[index]] = 1;
		ResLin_vA[k] = vA[index];
		ResLin_vB[k] = vB[index];
		ResLin_Weight[k] = Weight[index];

		k++;
	}



	



	//Free memory
	delete ResLin_vA;
	delete ResLin_vB;
	delete ResLin_Weight;

	delete vA;
	delete vB;
	delete Weight;


	return 0;
}