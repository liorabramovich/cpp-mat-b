#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


namespace ariel{

string mat(int column, int row, char firstSymbol, char secondSymbol)
{
    if (column % 2 == 0 || row % 2 == 0) {
        throw invalid_argument("Mat size is always odd");
    }
    if (column < 0 || row < 0)
    {
        throw invalid_argument("Mat size is always positive number");
    }
    if (firstSymbol < minimum_case || firstSymbol > maximum_case)
    {
        throw invalid_argument("First symbol is not valid");
    }
    if (secondSymbol < minimum_case || secondSymbol > maximum_case)
    {
        throw invalid_argument("Second symbol is not valid");
    }

    vector<vector<char>> matrix(row, vector<char>(column));
    int column_start = 0;
    int row_start = 0;
    int column_end = column - 1;
    int row_end = row - 1;

    while (row_start <= row_end && column_start <= column_end)
    {
        matrix = fill_into_rows(matrix, row_start, row_end, column_start, column_end, firstSymbol, secondSymbol);
        matrix = fill_into_columns(matrix, row_start++, row_end--, column_start++, column_end--, firstSymbol, secondSymbol);
    }

    return vector_to_string(matrix, column, row);
}


vector<vector<char>> fill_into_rows(vector<vector<char>> matrix, int row_start, int row_end, int column_start, int column_end, char firstSymbol, char secondSymbol)
{
    for (int i = row_start; i <= row_end; i++)
    {
        if (row_start % 2 == 0 && row_end % 2 == 0)
        {
            matrix[i][column_start] = matrix[i][column_end] = firstSymbol;
        }
        else
        {
            matrix[i][column_start] = matrix[i][column_end] = secondSymbol;
        }
    }
    return matrix;
}

vector<vector<char>> fill_into_columns(vector<vector<char>> matrix, int row_start, int row_end, int column_start, int column_end, char firstSymbol, char secondSymbol)
{
    for (int i = column_start; i <= column_end; i++)
    {
        if (column_start % 2 == 0 && column_end % 2 == 0)
        {
            matrix[row_start][i] = matrix[row_end][i] = firstSymbol;
        }
        else
        {
            matrix[row_start][i] = matrix[row_end][i] = secondSymbol;
        }
    }
    return matrix;
}

string vector_to_string(vector<vector<char>> matrix, int column, int row)
{
    string matrix_answer ;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix_answer += matrix[i][j];
        }
        matrix_answer += "\n";
    }
    return matrix_answer;
}
}