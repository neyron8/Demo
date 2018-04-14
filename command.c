#include "command.h"
#include <string.h>
#include <stdlib.h>

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
    
    char ch;

		do {
			ch = getc (in);

			if (ch == EOF) {
				return -2;
			}
		} while (ch == ' ' || ch == '\n');

		if (fseek (in, -1, SEEK_CUR)) {
			return -1;
		}

		char code [8];
		uint32_t num;

		if (fgets (code, 8, in) == NULL) {
			if (feof (in)) {
				return -2;
			}

			if (ferror (in)) {
				return -1;
			}
		}

		num = strtol (code, NULL, 16);

		if (encode (num, code_units)) {
			return -1;
		}

    for (int a = 0;;) {
		a = read_next_code_unit (in, code);
		if (a == 0) {
			if (write_code_unit (out, code)) {
				printf(ERROR "OUTPUT ERROR \n" END);
			}
		} else if (a == -1) {
			printf(ERROR "ERROR\n" END);
			break;
		} else if (a == -2) {
            printf(INFO "End of" CBOLD " %s " CINFO "reached\n" END,\
                                                                in_file_name);
			break;
		}
	}

    fclose(in);
    fclose(out);


    return 0;
}
