#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "errno.h"

/* 
 * Returns a pointer to a command struct with the command line arguments separated
 * or NULL if there's a parse error setting errno EINVAL
 */
command_t* parse_command_line_args(int argc, char *argv[]) {
	command_t* command = (command_t *) malloc(sizeof(command_t));
	if (command == NULL) {
		return NULL;
	}	

	int i = 1;
	while (i < argc) {
		if (strcmp(argv[i], "-f") == 0) {
			if (i + 1 >= argc) {
				// No file given
				errno = EINVAL;
				return NULL;
			}
			command->filename = argv[i + 1];
			i += 2;	
		} else {
			// Command not recognized
			errno = EINVAL;
			return NULL;
		}
	}	

	return command;
}

void free_command(command_t *command) {
	free(command);
}

void* parseInstruction(uint32_t *code) {
	// Test the code for each type of instruction and return the type it matches
	// Branch and Exchange type
	branch_and_exchange_t* bx = (branch_and_exchange_t*) code;
	if (bx->id == 1245169) {
		printf("branch and exchange: ");
	}

	branch_t* b = (branch_t*) code;
	if (b->id == 5) {
		printf("branch: ");
	}

	data_processing_t* data = (data_processing_t*) code;
	if (data->id == 0) {
		printf("data processing: ");
	}

	return NULL;
}
