/*
 * NumPunctBR.cpp
 *
 * Subclass of numpunct<char> that specifies the character that separates integer and decimal parts in decimal numbers for the pt-BR locale.
 *
 *  Created on: Jul 10, 2014
 *      Author: http://ideone.com/bhZy3U
 */

#include "NumPunctPTBR.h"

/* In pt-BR, integer and decimal parts of decimal numbers are separated with a ',': e.g., 3,14. */
char NumPunctPTBR::do_decimal_point() const {
	return ',';
}

/* This locale uses grouping (at every 3 digits). */
string NumPunctPTBR::do_grouping() const {
	return "\03";
}

/* In pt-BR, grouping of thousands are separated with a '.': e.g., 1.000 for a thousand. */
char NumPunctPTBR::do_thousands_sep() const {
	return '.';
}

