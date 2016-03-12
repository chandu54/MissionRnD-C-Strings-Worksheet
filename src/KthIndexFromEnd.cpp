/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stddef.h>

char KthIndexFromEnd(char *str, int K) {
	
	if (str ==NULL)
		return NULL; 
	int index = 0, len;
	while (str[index] != '\0')
		index++;
	len = index; 
	if (len == 0 ||K>len)
		return '\0';
	else if (len == 1&&K==0)
		return str[0];
	else if (K>=0&&K<len)
		return str[len - K- 1];
	else
		return '\0';
	
}