#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*******************************************************************************
 * decimalToRoman
 * This function takes in the user input decimal number as well as a
 *  referenced string and converts the decimal number to roman numerals
 *  and stores the numerals in the referenced string.
 *  - returns nothing. passes string by reference.
 ******************************************************************************/

void decimalToRoman(int decimalInput,      // IN - inputed integer
                      string &romanFinal);   // IN - string for end result

/*******************************************************************************
 * romanOutput
 * This function outputs a string that is holding theconverted decimal number
 *  in roman numerals.
 *  - returns nothing.
 ******************************************************************************/

void romanOutput(string romanFinal);      // IN - string holding roman numeral

/*******************************************************************************
 * valueOfRomanChar
 * This function takes in a character from the user input string and calculates
 *  the corresponding decimal value.
 *  - returns the corresponding decimal value.
 ******************************************************************************/

int valueOfRomanChar(char romanDigit);     // IN - char roman numeral from input

/*******************************************************************************
 * romanToDecimal
 * This function takes in a string holding the user input roman numeral
 *  and converts each individual characters to its corresponding decimal
 *  value. Each decimal value is then added to a sum.
 *  - returns the sum of decimal valued roman numerals.
 ******************************************************************************/

int romanToDecimal(string romanInput);     // IN - string roman numeral input

/*******************************************************************************
 * decimalOutput
 * This function takes in the converted roman numeral in decimal form and
 *  outputs the value.
 *  - returns nothing.
 ******************************************************************************/

void decimalOutput(int decimalFinal);      // IN - final result integer

#endif // HEADER_H
