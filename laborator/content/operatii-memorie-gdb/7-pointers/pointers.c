// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define SIGN(X) (((X) > 0) - ((X) < 0))

int my_strcmp(const char *s1, const char *s2)
{
	char *p1, *p2;
	int len1, len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	p1 = (char *)malloc((len1 + 1) * sizeof(char));
	p2 = (char *)malloc((len2 + 1) * sizeof(char));
	strcpy(p1, s1);
	strcpy(p2, s2);
	while (*p1 != '\0' && *p2 != '\0')
	{
		if (*p1 != *p2)
		{
			return SIGN((int)(*p1 - *p2));
		}
		p1++;
		p2++;
	}
	int sgn = SIGN((int)(strlen(s1) - strlen(s2)));
	return sgn;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *psrc = (char *)src, *pdest = (char *)dest;
	size_t i;
	for (i = 0; i < n; i++)
	{
		*pdest = *(psrc + i);
		pdest++;
	}
	return pdest;
}

char *my_strcpy(char *dest, const char *src)
{
	char *p = strdup(src);
	int i = 0;
	do
	{
		*(dest + i) = *p;
		p++;
		i++;
	}while (*p != '\0');
	return dest;
}

int main(void)
{
	char s1[] = "Abracadabra";
	char s2[] = "Abracababra";
	char src[] = "Learn IOCLA, you must!";

	char *dest_str = malloc(sizeof(src));
	char *dest_mem = malloc(sizeof(src));

	if (!dest_str || !dest_mem) {
		perror("malloc() failed");
		return 1;
	}

	assert(SIGN(my_strcmp(s1, s2)) == SIGN(strcmp(s1, s2)));
	assert(my_strcpy(dest_str, src) && !strcmp(dest_str, src));
	assert(my_memcpy(dest_mem, src, sizeof(src)) && !memcmp(dest_mem, src, sizeof(src)));

	free(dest_str);
	free(dest_mem);
	return 0;
}
