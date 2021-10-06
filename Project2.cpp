/*
 * Course: CS216-00x
 * Project: Lab 10 (as part of Project 2)
 * Purpose: repeatedly ask the user to type prefix to match
 *          then generate at maximum THREE matched terms 
 *          and display the matched terms in descending order by weight.
 ***** PLEASE DO NOT CHANGE THIS FILE *****
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "term.h"
#include "SortingList.h"
#include "Autocomplete.h"
#include "magicString.h"

using namespace std;

int main(int argc, char** argv) {
    const int ARGUMENTS = 3;
    
    // check the command line argument, an input file name is needed
    if (argc != ARGUMENTS)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }    
    
    // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Cannot open the file named " << argv[1] << endl;
        return 2;
    }  
	int num_of_results = atoi(argv[2]);
	if ( num_of_results <= 0){
	cout << "Needs to be positive." << endl;
	return -1;	
}
    
    // read in the terms from the input file
    // line by line and store into Autocomplete object
    Autocomplete Autocomplete;
    long weight;
    string query;
    
    while (!infile.eof())
    {
        infile >> weight >> ws;
        getline(infile, query);
        if (query != "")
        {    
            Term newterm(query, weight);
            Autocomplete.insert(newterm);
        }    
    } 

    // read the time clock 
    // before calling sort() function and after it
    // to measure the time spent for sorting operation
    clock_t tstart, tstop;
    tstart = clock();
    Autocomplete.sort();
    tstop = clock();
    double  elapsed = (double)(tstop-tstart)/CLOCKS_PER_SEC;
    cout << "Time for sorting all terms: "<<  elapsed << " seconds." << endl;
    
    string input;
    string prefix;
    cout << "Please input the search query (type \"exit\" to quit): " << endl;
    getline(cin, input);
    prefix = input;
    while (prefix != "exit")
    {
        // measure the time spent for searching one prefix-matched term
	    clock_t tstart, tstop;
    	tstart = clock();
	magicString edit = prefix;
	string nprefix = edit.wordFormat();
        SortingList<Term> matchedTerms = Autocomplete.allMatches(nprefix);
        tstop = clock();
        double  elapsed = (double)(tstop-tstart)/CLOCKS_PER_SEC;
        cout << "Time for searching the maximum three of matched terms: "<<  elapsed << " seconds." << endl;
//	matchedTerms sub(std::substr(0, nprefix.length()-1);
//	for (size_t j = 0; j < num_of_results; j++)
//       	{if (matchedTerms[j] != nprefix)
//		matchedTerms[j] = "No matched query!";} 
        if (matchedTerms.size() == 0)
        {    
            cout << "No matched query!" << endl;
        }
        else
        {	
            for (size_t i = 0; i < num_of_results && i < matchedTerms.size(); i++){
		cout << matchedTerms[i] << endl;
	}
        }

        cout << "Please input the search query (type \"exit\" to quit): " << endl;
        getline(cin, input);
        prefix = input;
    }    
    return 0;
}

