#ifndef _GAUSS_HPP
#define _GAUSS_HPP

void printMat(double** m, int n);
void printMat(double** m, int n, int o);
double** newMat(int n);
double** newMat(int n, int o);
void delMat(double** m);
void printVec(double* v, int n);
double* newVec(int n);
void delVec(double* v);
double** randomMat(int n);
double* randomVec(int n);
double** copyMat(double** m, int zeilen, int spalten);
bool gauss(double** a, double* b, int n);
double* solve(double **a, double* b, int n);
double* gaussSolve(double **mat, double *vec, int n);
double** mulMat(double** m1, int zeilen1, int spalten1, double** m2, int zeilen2, int spalten2);
double* mulMatVec(double** m, int zeilen, int spalten,double* v, int n);

#endif