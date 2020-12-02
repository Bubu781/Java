#include <stdio.h>
#include <time.h>
#include <malloc.h>

int *convo(int *sig, int sizeSig, int *mask, int sizeMask) {
	int i, j, acc;
	int *result, sizeResult;
	
	sizeResult=sizeSig-sizeMask;
	result=(int *)malloc(sizeResult*sizeof(int));
	
	for(i=0; i<sizeResult; i++) {
			acc=0;
			for(j=0; j<sizeMask; j++) acc+=sig[i+j]*mask[j];
			result[i]=acc;
	}
	
	return result;
}

#define SIGTAB_SIZE 1000000
#define MASKTAB_SIZE 1024
int sigTab[SIGTAB_SIZE];
int maskTab[MASKTAB_SIZE];

int main() {
	int i;
	int *result;
	clock_t startTime, stopTime;
	float time;

	for(i=0;i<SIGTAB_SIZE;i++) sigTab[i]=1;
	for(i=0;i<MASKTAB_SIZE;i++) maskTab[i]=1;

	startTime=clock();
	result=convo(sigTab,SIGTAB_SIZE, maskTab, MASKTAB_SIZE);
	stopTime=clock();

	time=(stopTime-startTime)/(float)CLOCKS_PER_SEC;

	printf("PureC convo time=%f\n", time);
}
