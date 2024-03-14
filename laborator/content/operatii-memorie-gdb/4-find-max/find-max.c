// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *find_max(void *arr, int n, int element_size,
				int (*compare)(const void *, const void *))
{
	void *max_elem = arr, *p;
	int i;
	max_elem = (char *)max_elem;
	for (i = 1; i < n; i++)
	{
		p = (char *)arr + element_size * i;
		if (compare(max_elem, p) == 0)
			*(char *)max_elem = *(char *)p;
	}
	return max_elem;
}

int compare(const void *a, const void *b)
{
	int *pa, *pb;
	pa = (int *)a;
	pb = (int *)b;
	if (*pa > *pb)
		return 1;
	return 0;
}

int main(void)
{
	int n;

	scanf("%d", &n);

	int *arr = malloc(n * sizeof(*arr));

	for (int i = 0 ; i < n; ++i)
		scanf("%d", &arr[i]);
	int *max_elem = (int *)find_max(arr, n, sizeof(int), compare);
	printf("Elementul maxim este: %d\n", *max_elem);
	free(arr);
	return 0;
}
