/* File: Term.cpp
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the implementation of member functions for the Term class.
 *
 */
#include <iostream>
#include "term.h"

// default constructor
Term::Term()
{
    weight = 0;
    query = "";
}

// initializes a term with the given query string and weight
Term::Term(string query, long weight)
{
    if (weight < 0)
    {    
        cout << "The weight should be a positive number";
        weight = 0;
    }
    else 
    {
        // your code starts here
	this->weight = weight;
	this->query = query;
    }    
}

// compares the two terms in descending order by weight
// if the order of T1 and T2 in descending order by weight, return 1;
// if T1 and T2 are of the same weight, return 0;
// otherwise return -1
int Term::compareByWeight(Term t1, Term t2)
{
    // your code start here
	if (t1.weight > t2.weight)
	return 1;
	else if (t1.weight == t2.weight)
	return 0;
	else
	return -1;
}

// compares the two terms in lexicographic order but using only the first r characters of each query
int Term::compareByPrefix(Term t1, Term t2, int r)
{
    if (r < 0)
    {
        cout << "The length of the prefix should be a positive number!" << endl;
        return 2;
    }    

    // your code starts here
	if (t1.query.substr(0, r) < t2.query.substr(0, r))
	return 1;
	else if (t1.query.substr(0, r) == t2.query.substr(0, r))
	return 0;
	else 
	return -1;
}

// operator overloading for operators "<" and "<<"
// they both are defined as friend functions

// define the operator "<" for Term class
// T1 < T2 if and only if the query of T1 is less than the query of T2 (based on string comparison)
bool operator<(Term t1, Term t2)
{
    // your code starts here
	if (t1.query < t2.query)
	return true;
	else
	return false; 
}

// define the operator "<<" for Term class
// to send the Term object to the cout, in the following format:
// the weight, followed by a tab key, followed by the query
ostream& operator<<(ostream &out, const Term& t)
{
    // your code starts here
out << t.weight << "\t" << t.query;
}

