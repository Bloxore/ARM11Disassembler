#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>

typedef struct {
	uint32_t rn:4;
	uint32_t id:24; // should be 1245169
	uint32_t cond:4;
} branch_and_exchange_t;

typedef struct {
	uint32_t offset:24;
	uint32_t link:1;
	uint32_t id:3; // should be 5
	uint32_t cond:4;
} branch_t;

typedef struct {
	uint32_t op2:12;
	uint32_t rd:4;
	uint32_t rn:4;
	uint32_t s:1;
	uint32_t op:4;
	uint32_t i:1;
	uint32_t id:2; // should be 0
	uint32_t cond:4;	
} data_processing_t;

#endif
