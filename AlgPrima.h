#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

////вспомогательная структура - ребро
//struct Edge 
//{
//	int vA;//начало ребра
//	int vB;//конец
//	int weight;//вес
//
//	Edge()
//	{
//		vA = 0;
//		vB = 0;
//		weight = 0;
//	}
//
//	Edge(int a, int b, int w)
//	{
//		vA=a;
//		vB=b;
//		weight=w;
//	}
//
//	bool operator==(Edge b)
//	{
//		if (vA==b.vA && vB==b.vB) 
//			return true;
//		if (vA==b.vB && vB==b.vA) 
//			return true;
//		return false;
//	}
//
//	bool operator<(Edge b)
//	{
//		if (weight<b.weight) 
//			return true;
//		return false;
//	}
//
//	bool operator<=(Edge b)
//	{
//		if (weight<=b.weight) 
//			return true;
//		return false;
//	}
//};

//есть ли уже такое ребро в графе
int EdgeInGraph(int A, int B, int end, int *vA, int *vB)
	{
		
		for (int i=0; i<end; i++)
			if(vA[i]==A && vB[i]==B || vA[i]==B && vB[i]==A)
				return i;
		return -1;
	}
//генерация ребер в графе (самого графа)
void GenerateGraph(int n, int m, int *vA, int *vB, int *Weight)
	{
		int weight, v1, v2, fl;
		bool flag;
		//делаем граф связным
		for(int i=0; i<n-1; i++)
		{
			weight=rand()%50+1;
			vA[i]=i;
			vB[i]=i+1;
			Weight[i]=weight;
		}
		for(int i=n-1; i<m; i++)
		{
			int sl=0;
			v1=rand()%n;
			flag=false;
			while(flag==false)
			{
				v2=v1;
				while(v2==v1)
					v2=rand()%n;
				weight=rand()%50+1;
				fl=EdgeInGraph(v1, v2, i, vA, vB);
				if(fl==-1) flag=true;
				else sl++;
				if(sl>5)
				{
					sl=0;
					v1=rand()%n+1;
				}
			}
			vA[i]=v1;
			vB[i]=v2;
			Weight[i]=weight;
		}
}

bool Metka(int *m, int n)
{
	for(int i=0; i<n; i++)
		if(m[i]==0) return true;
	return false;
}

