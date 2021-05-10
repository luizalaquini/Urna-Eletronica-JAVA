/*
 * NumberUtils.cpp
 *
 * Utility functions for number manipulation.
 *
 *  Created on: Jul 10, 2014
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iomanip>
#include <sstream>
#include "NumberUtils.h"

using namespace std;

/* Converts decimal numbers from textual format to double, following a locale configuration. */
double parseDouble(const string& str, const locale& loc) {
	double num;

	// Creates a stream with the given string and applies the specified locale to it.
	stringstream stream(str);
	stream.imbue(loc);

	// Uses the >> operator to read the the double value from the stream and returns.
	stream >> num;
	return num;
}

/* Converts decimal numbers from double format to text, following a locale configuration. */
string formatDouble(const double num, const locale& loc) {
	// Creates an empty string stream and applies the specified locale to it.
	stringstream stream;
	stream.imbue(loc);

	// Uses the << operator to "print" the double value in the stream and returns its contents.
	stream << fixed << num;
	return stream.str();
}

/* Converts decimal numbers from double format to currency, following a locale configuration. */
string formatDoubleCurrency(const double num, const locale& loc) {
	// Creates an empty string stream and applies the specified locale to it.
	stringstream stream;
	stream.imbue(loc);

	// Uses the << operator to "print" the double value in the stream and returns its contents.
	stream << fixed << setprecision(2) << num;
	return stream.str();
}
