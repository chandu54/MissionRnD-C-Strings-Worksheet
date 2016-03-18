/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>
#define SIZE 31;
int nextword(char *s, int i)
{
	while (s[i] != 32 && s[i] != '\0') i++;
	if (s[i] == '\0')
		return i;
	else return i + 1;
}

int compare(char *str1, char *str2, int i, int j)
{
	int i2 = nextword(str1, i);
	if (str1[i2] == '\0') i2--;
	if (str1[i2 - 1] == 32) i2 = i2 - 2;

	int k = i2 - i;
	int j2 = nextword(str2, j);
	if (str2[j2] == '\0') j2--;
	if (str2[j2 - 1] == 32) j2 = j2 - 2;

	while (i<i2 && j<j2)
	{
		if (str1[i] != str2[j]) break;
		else { i++; j++; }
	}

	if (i<i2)
		return 0;
	return k + 1;

}

char ** commonWords(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL) return NULL;
	int i = 0, j = 0, j1;
	char **s = (char **)calloc(sizeof(char *), 970);
	for (i = 0; i<970; i++)
		s[i] = (char *)calloc(sizeof(char), 970);;
	int si = 0;
	for (i = 0; str1[i] != '\0'; i = nextword(str1, i))
	{
		for (j = 0; str2[j] != '\0'; j = nextword(str2, j))
		{
			int k = compare(str1, str2, i, j);
			if (k == 0)
				return NULL;
			else
			{
				char *temp = (char *)calloc(sizeof(char), k + 1);
				int t = 0;
				for (j1 = j; k>0; j1++)
				{
					temp[t] = str2[j1];
					k--;
					t++;
				}
				temp[t] = '\0';
				int y;
				for (y = 0; y<si; y++)
					if (compare(s[y], temp, 0, 0)) break;

				if (y >= si)
				{
					int m = 0;
					while (temp[m] != '\0')
					{
						s[si][m] = temp[m];
						m++;
					}
					s[si][m] = '\0';
					si++;
				}

			}
		}
	}
	if (si == 0)
		return NULL;
	return s;
}
