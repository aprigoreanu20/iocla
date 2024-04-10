// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

int main(void)
{
	int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
	int i, n;
	unsigned char *char_ptr;
	n = sizeof(v) / sizeof(unsigned char);
	char_ptr = (unsigned char *)v;
	printf("Afisare octet cu octet: \n");
	for (i = 0; i < n; i++)
	{
		printf("%p -> 0x%hhx\n", char_ptr, *char_ptr);
		char_ptr++;
	}
	printf("Afisare din doi in doi octeti: \n");
	short *short_ptr;
	short_ptr = (short *)v;
	n = sizeof(v) / sizeof(short);
	for (i = 0; i < n; i++)
	{
		printf("%p -> 0x%hx\n", short_ptr, *short_ptr);
                short_ptr++;
	}
	int *int_ptr;
	int_ptr = v;
	n = sizeof(v) / sizeof(int);
	printf("Afisare din patru in patru octeti: \n");
	for (i = 0; i < n; i++)
        {
                printf("%p -> 0x%x\n", int_ptr, *int_ptr);
                int_ptr++;
        }
	return 0;
}
