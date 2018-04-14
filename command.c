#include "command.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "coder.h"

int encode_file(const char *in_file_name, const char *out_file_name) {

    FILE *in;
    FILE *out;

    in = fopen ( in_file_name, "rt");
   
    out = fopen ( out_file_name, "wb");
    
    CodeUnits *code = calloc (sizeof (CodeUnits), 1);
    if (code == NULL) {
        printf ("Error of initialization\n");
        return -1;
    }
    

    while(1) 
	{
		char sim;

		do {
			sim = getc (in);

			if (sim == EOF) {
				return -2;
			}
		} while (sim == ' ' || sim == '\n');

		if (fseek (in, -1, SEEK_CUR)) {
			return -1;
		}

		char cod [8];
		uint32_t num;

		if (fgets (cod, 8, in) == NULL) {
			if (feof (in)) {
				return -2;
			}

			if (ferror (in)) {
				return -1;
			}
		}

		num = strtol (cod, NULL, 16);

		if (encode (num, code)) {
			return -1;
		}
    	write_code_unit (out, code);
	}
			

    fclose(in);
    fclose(out);
	return 0;
}

int decode_file(const char *in_file_name, const char *out_file_name) {

    FILE *in;
    FILE *out;

    in = fopen ( in_file_name, "rb");
    
    out = fopen ( out_file_name, "wt");
  

    CodeUnits *code = calloc (sizeof (CodeUnits), 1);
    if (code == NULL) {
        printf ("Error of initialization\n" );
        return -1;
    }

    for (int a = 0;;) {
		a = read_next_code_unit (in, code);
		if (a == 0) {
			uint32_t code_point = 0;

			code_point = decode (code);

			fprintf(out, "%x\n", code_point);
		} else if (a == -1) {
			break;
		} else if (a == -2) {
			break;
		}
}
    free (code);

    fclose(in);
	fclose(out);

    return 0;
}

    

