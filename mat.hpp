#include <string>
#include <vector>
using namespace std;

const short minimum_case = 33; //For Test Num 4
const short maximum_case = 126; //For Test Num 4

namespace ariel
{
	string mat(int column, int row, char firstSymbol, char secondSymbol);
	vector<vector<char>> fill_into_rows(vector<vector<char>> matrix, int row_start, int row_end, int column_start, int column_end, char firstSymbol, char secondSymbol);
	vector<vector<char>> fill_into_columns(vector<vector<char>> matrix, int row_start, int row_end, int column_start, int column_end, char firstSymbol, char secondSymbol);
	string vector_to_string(vector<vector<char>> matrix, int column, int row);
} 


