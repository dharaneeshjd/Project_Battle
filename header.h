#include<stdio.h>
#define bufferSize 200
#define tempSize   50
#define direction_count  4
#define day_count 3
#define testCase_count 1

int dir[direction_count];

enum directions {
	NORTH,
	EAST,
	WEST,
	SOUTH
};
int temp[direction_count];
int success_count;

struct unitTest
{
	char name[bufferSize];
	int output;
};

struct unitTest results[testCase_count] ={
				 	{"Sample testcase1",                                   6},
				 	{"Sample testcase2",                                   6},
				 	{"All Zero inputs",                                    0},
				 	{"All negative inputs",                                0},
				 	{"Same direction in a whole day",                      10},
				 	{"Mixing positive,negative and same direction attack", 13},
				 	{"Same direction in all 3 days",                       7},
				 	{"Large valued strengths",                             5}
					 	
				 };
void init();

void start(char *inputFile,char *outputFile,struct unitTest *ExpectedOutputs);

void splitStringByColon(char *str);

void getDirectionAndStrength(char *str);

void updateShadowHeights(char direction,int strength);

void updateOriginalHeights();

void unitTestResults(int output,int test_count,struct unitTest *expectedOutput);
