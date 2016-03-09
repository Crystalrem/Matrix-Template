#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#ifndef _matrix_h
#define _matrix_h
template <class type_name>
class Matrix
{
	int n, m;
	type_name **matrix = NULL;
public:
	Matrix(int n0 = 1, int m0 = 1): n(n0), m(m0)
	{
		matrix = new type_name *[n];
		for (int i = 0; i < n; i++)
			matrix[i] = new type_name [m];
	}
	~Matrix()
	{
		type_name **tmp = matrix; 
		for(int i = 0; i < n; i++)
			delete [] tmp[i];
		delete [] tmp;
		delete tmp;  
	}
	int nRow() {return n; } 
	int nCol() {return m; } 
	friend Matrix operator + (Matrix t1, Matrix t2)
	{
		Matrix re(t1.n, t1.m);
		for (int i = 0; i < t1.n; i++)
		 	for (int j = 0; j < t1.m; j++)
		 	{
		 		re.matrix[i][j] = t1.matrix[i][j] + t2.matrix[i][j];
			}
		return re;
	}
	bool operator == (const Matrix<type_name> &t) const
	{	
		if(n != t.n || m != t.m) return false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if(matrix[i][j] != t.matrix[i][j]) return false;
		}
		return true;
	}
};
//template <class type_name>

//Matrix<type_name> ::friend Matrix<type_name> ::operator + (Matrix<type_name> t1, Matrix<type_name> t2)


#endif
