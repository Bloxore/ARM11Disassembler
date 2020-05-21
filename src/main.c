#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include "helpers.h"
#include "main.h"

int main(int argc, char *argv[]) {
	command_t* command = parse_command_line_args(argc, argv);
	if (command == NULL) {
		perror(USAGE);
		exit(EXIT_FAILURE);
	}
	
	FILE* binary_file = fopen(command->filename, "r");
	if (binary_file == NULL) {
		perror("File failed to open");
		exit(EXIT_FAILURE);
	}
	
	
	/*
	 * Instructions of one of three sizes:
	 * 32 bits in ARM State
	 * 16 bits in Thumb State
	 * <variable length> (multiples of 8 bits) in Jazelle State
	 *
	 * There are 4 types of instructions:
	 * 1. Data processing instructions
	 * 2. Load and Store instructions
	 * 3. Branch Instructions
	 * 4. Coprocessor Instructions
	 *
	 * There are 37 32bit registers:
	 * 31 general purpose
	 * 6  dedicated
	 *
	 * Only 16 are visible at a time
	 *
	 * The thumb instruction set is practically the same as reg ARM state,
	 * 	but reduced in size
	 * 
	 *
	 */
	
	uint32_t *inbuf = (uint32_t *) malloc(4);
	if (inbuf == NULL) {
		perror("Not enough memory");	
		// Clean up when everything is done
		errno = 0;
		if (fclose(binary_file) == EOF) {
			perror("Error closing file");
			free_command(command);
			exit(EXIT_FAILURE);
		}
		free_command(command);
	}

	errno = 0;
	int readcount = 0;
	while (readcount = fread(inbuf, 1, 4, binary_file)) {
		parseInstruction(inbuf);
		printf("%#010X\n", *inbuf);	
	}

	free(inbuf);

	// Clean up when everything is done
	errno = 0;
	if (fclose(binary_file) == EOF) {
		perror("Error closing file");
		free_command(command);
		exit(EXIT_FAILURE);
	}
	free_command(command);
	exit(EXIT_SUCCESS);
}
