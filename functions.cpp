#include "header.h"

/*******************************************************************************
 * FUNCTION decimalToRoman
 * _____________________________________________________________________________
 * This function takes in the user input decimal number as well as a
 *  referenced string and converts the decimal number to roman numerals
 *  and stores the numerals in the referenced string.
 *  - returns nothing. passes string by reference.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      decimalInput: User input decimal number to convert.
 *      &romanFinal : Referenced string to hold convert roman numeral.
 *
 * POST-CONDITIONS
 *      Passes &romanFinal by reference.
 ******************************************************************************/

void decimalToRoman(int decimalInput,        // IN - inputed integer
                      string &romanFinal)    // IN - string for end result
{
    int i;              // CALC - iterator
    int div;            // CALC - finds the place value
    int number[] =      // CALC - array of corresponding nums for roman numerals
    {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string symbol[] =   // CALC & OUT - array of roman numeral symbols
    {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

    i = 12;

    // PROCESSING - execute while passed number is greater than 0
    while(decimalInput > 0)
    {
        // PROCESSING - find input number place corresponding to value in array
        div = decimalInput/number[i];
        decimalInput %= number[i];
        // PROCESSING - execute div number of times in each number place
        while(div--)
        {
            // PROCESSING - add roman symbol to final string
            romanFinal += symbol[i];
        }
        // PROCESSING - next value in array
        i--;
    }
}

/*******************************************************************************
 * FUNCTION romanOutput
 * _____________________________________________________________________________
 * This function outputs a string that is holding the converted decimal number
 *  in roman numerals.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      romanFinal: string holding roman numeral.
 *
 * POST-CONDITIONS
 *      N/A. Outputs romanFinal.
 ******************************************************************************/

void romanOutput(string romanFinal)    // IN - string holding roman numeral
{
    // OUTPUT - displays final roman numeral
    cout << romanFinal << endl;
}

/*******************************************************************************
 * Function valueOfRomanChar
 * _____________________________________________________________________________
 * This function takes in a character from the user input string and calculates
 *  the corresponding decimal value.
 *  - returns the corresponding decimal value.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      romanDigit: char roman numeral.
 *
 * POST-CONDITIONS
 *      returns int holding corresponding decimal value.
 ******************************************************************************/

int valueOfRomanChar(char romanDigit)   // IN - char roman numeral from input
{
    // PROCESSING - converts char roman numeral to decimal number
    switch(romanDigit)
    {
    default: return 0;
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
}

/*******************************************************************************
 * FUNCTION romanToDecimal
 * _____________________________________________________________________________
 * This function takes in a string holding the user input roman numeral
 *  and converts each individual characters to its corresponding decimal
 *  value. Each decimal value is then added to a sum.
 *  - returns the sum of decimal valued roman numerals.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      romanInput: string holding roman numeral.
 *
 * POST-CONDITIONS
 *      returns converted decimal value.
 ******************************************************************************/

int romanToDecimal(string romanInput)   // IN - string roman numeral input
{
    int n;              // CALC - holds length of string input
    int ans;            // CALC - holds sum of decimal conversion
    int p;              // CALC - keeps track of last numeral
    int run;            // CALC - keeps track of consecutive numerals
    int addorsub;       // CALC - keeps track when next num is > or < than last

    ans = 0;
    p = 0;
    n = romanInput.length() - 1;

    // PROCESSING - execute for lenght of string from high to low
    for(int i = n; i >= 0; i--)
    {
        // PROCESSING - reject + 4 consecutive nums or - 2 consecutive nums
        if((run >= 4 && addorsub == 1) || (run >=2 && addorsub == -1))
        {
            break;
        }
        // PROCESSING - current number greater than last
        // valueOfRomanChar - takes in roman char and returns decimal value
        if(valueOfRomanChar(romanInput[i]) > p)
        {
            // PROCESSING - add char to final string, addition
            // valueOfRomanChar - takes in roman char and returns decimal value
            ans += valueOfRomanChar(romanInput[i]);
            run = 1;
            addorsub = 1;
        }
        // PROCESSING - current number same as last
        // valueOfRomanChar - takes in roman char and returns decimal value
        else if(valueOfRomanChar(romanInput[i]) == p)
        {
            // PROCESSING - add char to final string, add 1 to run
            // valueOfRomanChar - takes in roman char and returns decimal value
            ans += valueOfRomanChar(romanInput[i]);
            run += 1;
        }
        // PROCESSING - current number less than last
        else
        {
            // PROCESSING - subs char from final string, adds 1 to run, subtract
            // valueOfRomanChar - takes in roman char and returns decimal value
            ans -= valueOfRomanChar(romanInput[i]);
            run = 1;
            addorsub = -1;
        }
        // PROCESSING - stores current num for next iterations comparison
        // valueOfRomanChar - takes in roman char and returns decimal value
        p = valueOfRomanChar(romanInput[i]);
    }

    // PROCESSING - returns 0 if invalid consecutive input else final string
    if((run >= 4 && addorsub == 1) || (run >=2 && addorsub == -1))
    {
        return 0;
    }
    else return ans;
}

/*******************************************************************************
 * FUNCTION decimalOutput
 * _____________________________________________________________________________
 * This function takes in the converted roman numeral in decimal form and
 *  outputs the value.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      decimalFinal: final converted decimal number.
 *
 * POST-CONDITIONS
 *      N/A. Outputs decimalFinal.
 ******************************************************************************/

void decimalOutput(int decimalFinal)    // IN - final result integer
{
    // PROCESSING - invalid consecutive input from decimal to roman convert
    if(decimalFinal == 0)
    {
        // OUTPUT - invlaid input
        cout << "invalid\n";
    }
    // OUTPUT - final decimal number
    else cout << decimalFinal << endl;
}
