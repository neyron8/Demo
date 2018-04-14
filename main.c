#include "coder.h"
#include "command.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	if (((strcmp (argv[1], "encode\0")) == 0)\
			&& (strstr (argv[2], ".txt\0")) && (strstr (argv[3], ".bin\0"))) {
		encode_file(argv[2], argv[3]);
	} else if (((strcmp (argv[1], "decode\0")) == 0)\
	 		&& (strstr (argv[2], ".bin\0")) && (strstr (argv[3], ".txt\0"))) {
		decode_file(argv[2], argv[3]);
	}
	

	return 0;
}
