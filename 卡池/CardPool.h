#pragma once

//Define Constant
#define pool_size 100		//How many object in a pool

//Create types
typedef struct id { char x[6]; } id;
typedef struct type {
	id ID;
	float percentage;		
} type;



//Member Functions
void reset();
id result();