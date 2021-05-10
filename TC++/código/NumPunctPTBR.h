/*
 * NumPunctBR.h
 *
 * Subclass of numpunct<char> that specifies the character that separates integer and decimal parts in decimal numbers for the pt-BR locale.
 *
 *  Created on: Jul 10, 2014
 *      Author: http://ideone.com/bhZy3U
 */

#ifndef NUMPUNCTBR_H_
#define NUMPUNCTBR_H_

#include <locale>
#include <string>

using namespace std;

class NumPunctPTBR: public numpunct<char> {
protected:
	char do_decimal_point() const;
	string do_grouping() const;
	char do_thousands_sep() const;
};

#endif
