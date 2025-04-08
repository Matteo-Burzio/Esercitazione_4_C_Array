#include "Utils.hpp"

using namespace std;

int main()
{
    // Initialize variables
	string input_file_name = "data.txt";
	string output_file_name = "result.txt";
	size_t n; // size of arrays
	double S; // total investment
	double V = 0; // final value of the portfolio
	double r_tot; // rate of return of the portfolio
	double *w = nullptr; // pointer for first vector
	double *r = nullptr; // pointer for second vector

	// Read the given file
	if(!read_input_file(input_file_name, n, S, r, w))
	{
		return 1;
	}

	// The vector operation needed to solve this exercise is:
	// V = (1+r) . (S*w) 
	// where r and w are vectors, "." is the dot product
	for(unsigned int i = 0; i < n; i++)
	{
		V += (1.0 + r[i]) * S * w[i];
	}
	
	// To get the total rate of return the formula is:
	// r_tot = (V/S) - 1
	// where V is the value computed before
	r_tot = (V/S) - 1.0;

	// Write on output file
	if(!write_output_file(output_file_name, n, S, V, r_tot, r, w))
	{
		return 1;
	}

    return 0;
}

