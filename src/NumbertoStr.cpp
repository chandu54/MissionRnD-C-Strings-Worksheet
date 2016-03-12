/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include<math.h>
#include <stdio.h>
void int_to_str(int beforeNumber, int afterNumber, char *str,int sign);
void float_to_int(float number, int digits,char *str);
void number_to_str(float number, char *str, int afterdecimal)
{
	float_to_int(number, afterdecimal,str);
}

void float_to_int(float number, int digits,char *str)
{
	float temp1, temp2;
	long int beforeNumber, afterNumber;
	int sign=0, powerindex = 1;
	if (number<0)

	{
		sign = -1;
		number = number*sign;
	}
	temp2 = number;
	beforeNumber = (int)number;
	temp1 = temp2 - beforeNumber;
	while (powerindex <= digits)
	{
		temp1 = temp1 * 10;
		powerindex++;
	}
	afterNumber = (int)temp1;
	int_to_str(beforeNumber, afterNumber, str, sign);
}
void int_to_str(int beforeNumber, int afterNumber, char *str, int sign)
{
	int index = 0, lindex, len, tempindex, negindex = 1, tempNumber;
	tempNumber = beforeNumber;
	while (tempNumber != 0)
	{
		tempNumber = tempNumber / 10;
		index++;
	}
	len = index;
	if (sign == -1){
		str[0] = '-';
		index++;
		len++;
	}
	while (beforeNumber != 0)
	{
		str[index - 1] = (beforeNumber % 10) + '0';
		beforeNumber = beforeNumber / 10;
		index--;
	}
	if (afterNumber == 0)
		str[len] = '\0';
	else
		str[len] = '.';
	tempindex = len + 1;
	index = tempindex;
	tempNumber = afterNumber;
	while (tempNumber != 0)
	{
		tempNumber = tempNumber / 10;
		index++;
	}
	tempindex = index;
	while (afterNumber != 0)
	{
		str[index - 1] = (afterNumber % 10) + '0';
		afterNumber = afterNumber / 10;
		index--;
	}
	str[tempindex] = '\0';
}