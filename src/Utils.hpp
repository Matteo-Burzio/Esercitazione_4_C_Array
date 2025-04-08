#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// Function declarations

// This function reads the file provided
bool read_input_file(const string& file_name,
                     size_t& n,
                     double& S,
                     double*& r,
                     double*& w);

// This function prints r and w correctly
string fancy_print(const size_t& n,
                  const double* const& v);

// This function writes the output file in the requested format
bool write_output_file(const string& file_name,
                       const size_t& n,
                       const double& S,
                       const double& V,
                       const double& r_tot,
                       const double* const& r,
                       const double* const& w);