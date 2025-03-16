#include <iostream>
#include <omp.h>
//for random number generation
#include<cstdlib>
#include<ctime>
//for matrix like view setw()
#include <iomanip>
using namespace std;
const int N=2;

int matrix1[N][N];
int matrix2[N][N];
int matrix_add[N][N];
int matrix_mul[N][N];



void create_matrix(int matrix[N][N])
{

    for (int i=0;i<N;i++){
    for(int j=0;j<N;j++){
    matrix[i][j]= rand() % 25 + 1;
    }
    }
}
void print_matrix(int matrix[N][N], string name)
{

    cout<<"printing matrix "<<name<<endl;
    for(int i =0;i<N;i++){
    cout<<"| ";
    for(int j=0;j<N;j++){
    cout<< setw(4)<<matrix[i][j]<<" ";
    }
    cout<<"| ";
    cout<< endl;
    }
  cout<<endl;
}
void matrix_multiplication_coarse_grain(){
double start = omp_get_wtime(); 
#pragma omp parallel for

for(int i=0;i<N;i++){
for(int j=0;j<N;j++){
matrix_mul[i][j] = 0; // Initialize the result matrix with 0
for (int k = 0; k < N; k++) {
matrix_mul[i][j] += matrix1[i][k] * matrix2[k][j]; // Matrix multiplication formula
}
}
}

double end = omp_get_wtime();  // End time
    cout << "Coarse-Grain Execution Time: " << (end - start) << " seconds" << endl;
}
void matrix_multiplication_fine_grain(){
double start = omp_get_wtime(); 
#pragma omp parallel for collapse(2)

for(int i=0;i<N;i++){
for(int j=0;j<N;j++){
matrix_mul[i][j] = 0; // Initialize the result matrix with 0
for (int k = 0; k < N; k++) {
matrix_mul[i][j] += matrix1[i][k] * matrix2[k][j]; // Matrix multiplication formula
}
}
}

double end = omp_get_wtime();  // End time
    cout << "Fine-Grain Execution Time: " << (end - start) << " seconds" << endl;
}

void coarse_grain_addition() {
    double start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
             matrix_add[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    double end = omp_get_wtime();
    cout << "Coarse-Grain Addition Time: " << (end - start) << " seconds" << endl;
}

void fine_grain_addition() {
    double start = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix_add[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    double end = omp_get_wtime();
    cout << "Fine-Grain Addition Time: " << (end - start) << " seconds" << endl;
}

int main()
{

// random number
srand(time(0));
create_matrix(matrix1);
create_matrix(matrix2);


//print matrix
print_matrix(matrix1,"matrix1");
print_matrix(matrix2,"matrix2");

omp_set_num_threads(4);
//multiply matrices
matrix_multiplication_coarse_grain();
matrix_multiplication_fine_grain();
print_matrix(matrix_mul,"Multiply Matrix");
//add matrices
coarse_grain_addition();
fine_grain_addition();
print_matrix(matrix_add,"Addition Matrix");

return 0;
}
