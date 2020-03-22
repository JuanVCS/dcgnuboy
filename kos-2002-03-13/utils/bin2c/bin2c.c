/* Converts a binary file into a C integer array (for inclusion in
   a source file) 

   (c)2000 Dan Potter

   bin2c.c,v 1.1.1.1 2001/09/26 07:05:00 bardtx Exp
*/

#include <stdio.h>

void convert(char *ifn, char *ofn) {
	FILE *i, *o;
	unsigned char buffer[2048];
	int red, left, lc, q;

	i = fopen(ifn, "r");
	o = fopen(ofn, "w");
	if (!i || !o) {
		printf("error: can't open input or output file\n");
		return;
	}

	fseek(i, 0, SEEK_END); left = ftell(i); fseek(i, 0, SEEK_SET);

	lc = 0;
	while(left > 0) {
		red = fread(buffer, 1, 2048, i);
		left -= red;
		for (q=0; q<red; q++) {
			fprintf(o, "%d, ", buffer[q]);
			if ((++lc) >= 30) {
				lc = 0;
				fprintf(o, "\n");
			}
		}
	}

	fclose(i); fclose(o);
}

int main(int argc, char **argv) {
	argc--;
	if (argc != 2) {
		printf("usage: bin2c <input> <output>\n");
		return 0;
	}

	convert(argv[1], argv[2]);
}

