/*
 Joanne Kwon
 March 20, 2017
 Description: implement matrix addition (word matrix).
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//file numbers for matrix
void fill_from_file(int M[10][10], int row_size, int col_size, ifstream &fin)
{
    int matrixSize = row_size * col_size;
    int counter = 0;
    
    vector <int> numbers;
    int value = 0;
    fin >> value;
    while (fin >> value && counter < matrixSize)
    {
        counter++;
        numbers.push_back(value);
    }
    
    int vectorCounter = 0;
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            if (vectorCounter < numbers.size())
            {
                M[i][j] = numbers[vectorCounter];
                vectorCounter++;
            }
            else
                return;
        }
    }
}

//random numbers for matrix
void fill_random(int M[10][10], int row_size, int col_size)
{
    //fill all entries with random values -10 -> 10
    for (int i = 0; i < row_size; i++)
        for (int j = 0; j < col_size; j++)
        {
            M[i][j] = rand() % 21 + (-10);
        }
}

//adding matrix A and B for sum
void add_matrix(int A[10][10], int B[10][10], int sum[10][10], int row_size, int col_size)
{
    for (int i = 0; i < row_size; i++)
        for (int j = 0; j < col_size; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
}

//outputting matrix to console
void print_matrix(int M[10][10], int row_size, int col_size)
{
    const int space = 5;
    cout << fixed << setprecision(0);
    
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << setw(space) << M[i][j] << " ";
        }
        cout << endl;
    }
}

//outputing matrix to file
void print_matrix(int M[10][10], int row_size, int col_size, ofstream &fout)
{
    const int space = 5;
    fout << fixed << setprecision(0);
    
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            fout << setw(space) << M[i][j];
        }
        fout << endl;
    }
}


int main()
{
    srand((int)time(0)); //for random values
    
    int A[10][10];
    int B[10][10];
    int sum[10][10];
    
    int n_rows, n_cols;
    ifstream fin;
    ofstream fout;
    string file_name, file_name_two;
    string response;
    string answer;
    
    //ask the user for n_rows
    cout << "Enter the number of rows: ";
    cin >> n_rows;
    
    //re-enter values for n_rows
    while (n_rows > 10 || n_rows < 1)
    {
        cout << "Please output a value between 1 and 10. ";
        cin >> n_rows;
    }
    
    //ask the user for n_cols
    cout << "Enter the number of columns: ";
    cin >> n_cols;
    
    //re-enter values for n_cols
    while (n_cols > 10 || n_cols < 1)
    {
        cout << "Please output a value between 1 and 10. ";
        cin >> n_cols;
    }
    
    //ask the user if random numbers or file
    cout << "Would you like to fill the matrices with a file or random values [F/R]? ";
    cin >> answer;
    
    //re-enter option (random numbers or file)
    while (!(answer == "F" || answer == "f" || answer == "R" || answer == "r"))
    {
        cout << "Please select F to fill the matrices with a file and R to fill the matrices with random values. ";
        cin >> answer;
    }
    
    //fill matrix from file
    if (answer == "F" || answer == "f")
    {
        cout << "Enter the file name: ";
        cin >> file_name;
        
        fin.open(file_name.c_str()); //open file "file_name"
        
        fill_from_file(A, n_rows, n_cols, fin);
        fill_from_file(B, n_rows, n_cols, fin);
        fin.close();
    }
    
    //fill matrix using random numbers
    else if (answer == "R" || answer == "r")
    {
        fill_random(A, n_rows, n_cols);
        fill_random(B, n_rows, n_cols);
    }
    
    //ask for output option
    cout << "Should the output go to a file or a console [F/C]? ";
    cin >> response;
    
    //re-enter output option
    while (!(response == "F" || response == "f" || response == "c" || response == "C"))
    {
        cout << "Please select F to output the matrices to a file and C to output the matrices to the console. ";
        cin >> response;
    }
    
    //output matrix to file
    if (response == "F" || response == "f")
    {
        cout << "Enter the file name: ";
        cin >> file_name_two;
        
        //open file "file_name_two"
        fout.open(file_name_two.c_str());
        
        add_matrix(A, B, sum, n_rows, n_cols);
        print_matrix(A, n_rows, n_cols, fout);
        fout << endl;
        print_matrix(B, n_rows, n_cols, fout);
        fout << endl;
        print_matrix(sum, n_rows, n_cols, fout);
        fout << endl;
    }
    
    //output matrix to console
    else if (response == "C" || response == "c")
    {
        add_matrix(A, B, sum, n_rows, n_cols);
        print_matrix(A, n_rows, n_cols);
        cout << endl;
        print_matrix(B, n_rows, n_cols);
        cout << endl;
        print_matrix(sum, n_rows, n_cols);
        cout << endl;
    }
    system("pause");
    return 0;
}

