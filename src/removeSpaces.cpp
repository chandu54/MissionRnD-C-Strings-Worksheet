/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stddef.h>
char removeSpaces(char *str) {
	if (str == NULL)
		return NULL;
	int count = 0, index;
	for (index = 0; str[index]; index++)
	{
		if (str[index] != ' ')
			str[count++] = str[index];
	}
	str[count] = '\0';
	return *str;
}