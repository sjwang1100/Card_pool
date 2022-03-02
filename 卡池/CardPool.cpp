#include "CardPool.h"
#include <cstdint>
#include <time.h>
#include <stdlib.h>

using namespace std;

unsigned int curr_pos = 0;

//Global Var
type SSR[5] = {
	{"Super", 0.2},
	{"Ultra", 0.2},
	{"Best", 0.2},
	{"God", 0.2},
	{"Titan", 0.2},
};
type SR[10] = {
	{"SR1", 1.5},
	{"SR2", 1.5},
	{"SR3", 1.5},
	{"SR4", 1.5},
	{"SR5", 1.5},
	{"SR6", 1.5},
	{"SR7", 1.5},
	{"SR8", 1.5},
	{"SR9", 1.5},
	{"SR10", 1.5},
};
type R[20] = {
	{"R001", 1.5},
	{"R002", 1.5},
	{"R003", 1.5},
	{"R004", 1.5},
	{"R005", 1.5},
	{"R006", 1.5},
	{"R007", 1.5},
	{"R008", 1.5},
	{"R009", 1.5},
	{"R0010", 1.5},
	{"R0011", 1.5},
	{"R0012", 1.5},
	{"R0013", 1.5},
	{"R0014", 1.5},
	{"R0015", 1.5},
	{"R0016", 1.5},
	{"R0017", 1.5},
	{"R0018", 1.5},
	{"R0019", 1.5},
	{"R0020", 1.5},
};
type N[30] = {
	{ "N001", 1.8 },
	{ "N002", 1.8 },
	{ "N003", 1.8 },
	{ "N004", 1.8 },
	{ "N005", 1.8 },
	{ "N006", 1.8 },
	{ "N007", 1.8 },
	{ "N008", 1.8 },
	{ "N009", 1.8 },
	{ "N0010", 1.8 },
	{ "N0011", 1.8 },
	{ "N0012", 1.8 },
	{ "N0013", 1.8 },
	{ "N0014", 1.8 },
	{ "N0015", 1.8 },
	{ "N0016", 1.8 },
	{ "N0017", 1.8 },
	{ "N0018", 1.8 },
	{ "N0019", 1.8 },
	{ "N0020", 1.8 },
	{ "N0021", 1.8 },
	{ "N0022", 1.8 },
	{ "N0023", 1.8 },
	{ "N0024", 1.8 },
	{ "N0025", 1.8 },
	{ "N0026", 1.8 },
	{ "N0027", 1.8 },
	{ "N0028", 1.8 },
	{ "N0029", 1.8 },
	{ "N0030", 1.8 },
};

id pool[pool_size];

void reset() {
	curr_pos = 0;

	srand((unsigned)time(NULL));

	//Fisher-Yates Shuffle

	//Initial Array / Create Sorted Array
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < (SSR[i].percentage / 100 * pool_size); j++) {
			pool[curr_pos] = SSR[i].ID;
			curr_pos++;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < (SR[i].percentage / 100 * pool_size); j++) {
			pool[curr_pos] = SR[i].ID;
			curr_pos++;
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < (R[i].percentage / 100 * pool_size); j++) {
			pool[curr_pos] = R[i].ID;
			curr_pos++;
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < (N[i].percentage / 100 * pool_size); j++) {
			pool[curr_pos] = N[i].ID;
			curr_pos++;
		}
	}

	//Shuffle Array 

	id temp;
	while (curr_pos)
	{
		int r = rand() % curr_pos;

		temp = pool[curr_pos];
		pool[curr_pos] = pool[r];
		pool[r] = temp;

		//Shuffle Twice
		r = rand() % curr_pos;
		temp = pool[curr_pos];
		pool[curr_pos] = pool[r];
		pool[r] = temp;

		curr_pos--;
	}
}

id result() {
	if (curr_pos == pool_size) {
		id d = { "error" };
		reset();
		return d;
	}
	curr_pos++;
	return pool[curr_pos-1];
}