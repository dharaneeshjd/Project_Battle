
#include "header.h"


void start(char *inputFile,char *outputFile,struct unitTest *ExpectedOutputs)
{
	int count = 0,testcase_count = 0;
	FILE *inputReader = NULL;     
	FILE *outputWriter = NULL;   
	char buffer[bufferSize];  
	char output[tempSize];
	
	inputReader = fopen(inputFile,"r"); 
	outputWriter = fopen(outputFile,"w");
	
	if(inputReader) 
	{

		while(fgets(buffer,bufferSize,inputReader)) 
		{
			count++;
			splitStringByColon(buffer); 
			updateOriginalHeights(); 
			
			if(count % day_count == 0) 
			{
			

			    unitTestResults(success_count,testcase_count,&ExpectedOutputs[testcase_count]);
				sprintf(output,"%d\n",success_count); 
				fputs(output,outputWriter); 
				init(); 
				count = 0; 
				testcase_count++;      
			}
		}
	}

	fclose(inputReader);
	fclose(outputWriter);
}

void init()
{
	int i;
	for(i=0;i<direction_count;i++)
	{
		dir[i] = 0;
		temp[i] = 0;
	}
	success_count = 0;
}

void splitStringByColon(char *str)
{
	char temp[tempSize];
	int i,count = 0,skipCount = 0;
	
	for(i=0;str[i];i++)
	{
		if(str[i] != ':')
		{
			if(str[i] != ' ')
	        	temp[count++] = str[i];
	        
	    }
	    else
	    {
	        temp[count] = '\0';
	        skipCount++;
	        if(skipCount > 1)
	            getDirectionAndStrength(temp);
	        
	        count = 0;
	    }
	}

	temp[count] = '\0';

	getDirectionAndStrength(temp);
}

void getDirectionAndStrength(char *str)
{
	int i,Strength;
	int flag = 0,count = 0;
	char temp[tempSize],Direction;
	
	for(i=0;str[i];i++)
	{
		if(str[i] == '-' && flag == 0)
		{
			flag = 1;
			Direction = str[i+1]; 
			i+=3;                
		}
		if(flag == 1)
			temp[count++]=str[i];
	}
	temp[count]='\0';
	Strength = atoi(temp); 
	
	updateShadowHeights(Direction,Strength); 
}

void updateShadowHeights(char direction,int strength)
{	
	if(direction == 'N' || direction == 'n')
	{
		if(strength > dir[NORTH])
		{
			temp[NORTH] = strength;
			success_count++;
		}
	}
	if(direction == 'E' || direction == 'e')
	{
		if(strength > dir[EAST])
		{
			temp[EAST] = strength;
			success_count++;
		}
	}
	if(direction == 'W' || direction == 'w')
	{
		if(strength > dir[WEST])
		{
			temp[WEST] = strength;
			success_count++;
		}
	}
	if(direction == 'S' || direction == 's')
	{
		if(strength > dir[SOUTH])
		{
			temp[SOUTH] = strength;
			success_count++;
		}
	}
}

void updateOriginalHeights()
{
	if(dir[NORTH] < temp[NORTH])
		dir[NORTH] = temp[NORTH];
	if(dir[EAST] < temp[EAST] )
	    dir[EAST] = temp[EAST];
	if(dir[WEST] < temp[WEST])
	    dir[WEST] = temp[WEST];
	if(dir[SOUTH] < temp[SOUTH])
	    dir[SOUTH] = temp[SOUTH];

	temp[NORTH]=temp[EAST]=temp[WEST]=temp[SOUTH]=0;
}

void unitTestResults(int output,int test_count,struct unitTest *expectedOutput)
{
	printf("Name:\t%s\n",expectedOutput->name); 
	
	if(!(output ^ expectedOutput->output)) 
		printf("Result:\tPassed\n\n");
	else
		printf("Result:\tFailed\n\n");
		
	printf("-----------------------------------------------------------\n\n");
}
