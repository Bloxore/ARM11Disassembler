#include <stdint.h>
#include "instructions.h"

typedef struct {
	char* filename;
} command_t;

command_t* parse_command_line_args(int argc, char *argv[]);

void free_command(command_t* command);

void* parseInstruction(uint32_t *code);
