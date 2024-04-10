// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *delete_first(char *s, char *pattern)
{
	char *ch;
	int len = strlen(pattern), i;
	char *aux;
	ch = strstr(s, pattern);
	if (ch != NULL)
	{
		aux = ch + len;
		i = ch - s;
		s[i] = '\0';
		strcat(s, aux);
	}
	return s;
}

int main(void)
{
	char s[] = "Ana are mere";
	char *pattern = "re";

	(void) s;
	(void) pattern;

	printf("%s\n", delete_first(s, pattern));

	return 0;
}
