/*******************************************************************************
 * AUTHOR        : Dillon Welsh, Joe Lung
 * LAB #1        : Roman Numerals
 * CLASS         : CS3A
 * SECTION       : 71206
 * DUE DATE      : 8/27/2020
 ******************************************************************************/

#include "header.h"

/*******************************************************************************
 * ROMAN NUMERAL CONVERSION
 *______________________________________________________________________________
 * This program converts positive integers to roman numerals
 * and vice a versa.
 *______________________________________________________________________________
 * INPUT:
 *  int menuChoice   : Allows user to decide whether to convert from decimal
 *                     to roman numeral by entering 1 or roman numeral to
 *                     decimal by entering 2.
 *  int decimalInput : Accepts input decimal number from user to be
 *                     converted to roman numeral.
 *  string romanInput: Accepts input string from user to be converted to
 *                     decimal number.
 *
 * OUTPUT:
 *  int decimalFinal : Outputs converted roman numeral in decimal.
 *  string romanFinal: Outputs converted decimal in roman numeral.
 ******************************************************************************/

int main()
{
    int menuChoice;        // INPUT - menu option
    int decimalFinal;      // CALC & OUT - integer final result
    int decimalInput;      // INPUT - integer input
    string romanInput;     // INPUT - string roman numeral input
    string romanFinal;     // CALC & OUT - roman numeral final result

    // INPUT - gets conversion selection from user
    cout << "Type 1 for standard -> Roman numeral conversion. \n";
    cout << "Type 2 for Roman numeral -> Standard numeral conversion.\n";
    cin >> menuChoice;

    // PROCESSING - 1st selection decimal to roman
    if(menuChoice == 1)
    {
        // INPUT - user enters decimal number
        cout << "Enter standard number to convert: " << endl;
        cin >> decimalInput;

        // PROCESSING - number out of range
        if(decimalInput <= 0 || decimalInput >= 4000)
        {
            // OUTPUT - invalid input from user
            cout << "invalid\n";
        }
        // PROCESSING - number in range
        else
        {
            // decimalToRoman - converts decimal number to roman numeral string
            decimalToRoman(decimalInput, romanFinal);
            // romanOutput - outputs string with roman numeral
            romanOutput(romanFinal);
        }
    }
    // PROCESSING - 2nd selection roman to decimal
    else if(menuChoice == 2)
    {
        // INPUT -- user entered number as string
        cout << "Enter Roman numeral to convert: " << endl;
        cin.ignore();
        getline(cin,romanInput);
        // romanToDecimal - converts string roman numeral to decimal value
        decimalFinal = romanToDecimal(romanInput);
        // decimalOutput - outputs int with decimal number
        decimalOutput(decimalFinal);
    }
    romanFinal = "";

    return 0;
}
