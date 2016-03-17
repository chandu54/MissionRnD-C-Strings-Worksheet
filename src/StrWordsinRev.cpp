/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *str, int i, int j);
void str_words_in_rev(char *input, int len){
	int i = 0, pos = 0;
	reverse(input, 0, len - 1);
	while (i <= len - 1)
	{
		i++;
		if (input[i] == ' ' || input[i] == '\0')
		{
			reverse(input, pos, i - 1);
			while ((input[i] == ' ' )&& (input[i] != '\0'))
				i++;
			pos = i;
		}
	}
}
	void reverse(char *str, int i, int j)
	{
		
		char temp;
		while (i<j)
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i++;
			j--;
		}
	}
