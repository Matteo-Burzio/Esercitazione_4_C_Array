#include "Utils.hpp"

using namespace std;

// Input function
bool read_input_file(const string& in_file_name,
                    size_t& n,
                    double& S,
                    double*& r,
                    double*& w)
{
    ifstream ifstr(in_file_name); // create input file stream
	
    // Check if the file was opened correctly
    if(ifstr.fail())
    {
	    cerr << "File not found." << endl;
	    return false;
    }

    string tmp; // temporary string to read file correctly

    // Read S from first line
    getline(ifstr, tmp, ';'); // skip text
    ifstr >> S; // get value

    // Read n from second line
    getline(ifstr, tmp, ';'); // skip text
    ifstr >> n; // get value
 
    // Skip unnecessary line
    getline(ifstr, tmp, ';'); // first half
    ifstr >> tmp; // get rest of the line

    // Initialize w and r (using arrays as requested)
    r = new double[n];
    w = new double[n];

    char sep; // temporary variable to treat the ";" separator

    // Read values from the file and store them in the arrays
    for(unsigned int i = 0; i < n; i++)
    {
        ifstr >> w[i] >> sep >> r[i];
    }

    // Close input file
    ifstr.close();
	
    return true;
}


// Function to print r and w correctly
string fancy_print(const size_t& n,
                  const double* const& v)
{
    // Initialize variables
    string str;
    ostringstream osstr;

    // Create the string in the desired format
    osstr << "[ ";
    for(unsigned int i = 0; i < n; i++)
    {
        osstr << v[i] << " "; // no endl to write on a single line
    }
    osstr << "]";

    return osstr.str(); // returns the full string
}


// Output function
bool write_output_file(const string& out_file_name,
                      const size_t& n,
                      const double& S,
                      const double& V,
                      const double& r_tot,
                      const double* const& r,
                      const double* const& w)
{
    
	// Create an output file stream
	ofstream ofstr(out_file_name);

	// Check if the file was opened/created correctly
	if(ofstr.fail())
	{
		cerr << "File cannot be created." << endl;
		return false;
	}

	// Print first line on output file
	ofstr << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

	// Print the entries of r and w in the output file
    ofstr << "w = " << fancy_print(n, w) << endl;
    ofstr << "r = " << fancy_print(n, r) << endl;

	// Print rate of return and final value in the output file
    ofstr << "Rate of return of the portfolio: "
          << setprecision(4) << r_tot << endl;
    ofstr << "V: " << fixed << setprecision(2) << V << endl;

	// Close output file
	ofstr.close();

    // Free up memory
    delete[] r;
    delete[] w;

    return true;   
}