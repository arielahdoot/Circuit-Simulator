#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

#define gensize 500
#define smallsize 12

int Twopac(int num){
int i;
int j=1;

	for(i=0;i<num;i++){
		j*=2;
	}
return j;
}


void toGrayArray(int* posse, int howmanyinputs){
unsigned int i;
int j;



	for(i=0,j=0;j<howmanyinputs;i++,j++){
		i= (i >> 1) ^ i;
		posse[j]=i;
		i=j;
	}

return;
}

void initmatchUpper(int* capitalnum,char* inputletters,int* numbers,char *capitals,int howmanyinputs){
int count;
int i;
int j;
count=0;
for(i=0;i<howmanyinputs;i++){
	for(j=0;j<26;j++){
		if(inputletters[i]==capitals[j]){
			capitalnum[j]=numbers[count]-'0';
			count++;
		}
	}
}







}


void singlematchUpper(int *capitalnum,char single,int value,char *capitals,char*lowercase,int *lowercasenum){
	int j;
	
	for(j=0;j<26;j++){
		if(single==capitals[j]){
			capitalnum[j]=value;
			return;
		}			
	}
	for(j=0;j<26;j++){
		if(single==lowercase[j]){
		lowercasenum[j]=value;
		return;
		}
	}
	return;
}

int retsingleValue(int* capitalnum,char single,char *capitals,char* lowercase, int* lowercasenum){
	int j;


	for(j=0;j<26;j++){
		if(single==capitals[j]){

			return capitalnum[j];
			
		}
	}
	for(j=0;j<26;j++){
		if(single==lowercase[j]){

			return lowercasenum[j];
			
		}
	}

return 3;
}




void not(int* capitalnum, char* capitals,char *circuitline,char* lowercase, int *lowercasenum){
	char input;
	char result;
	char *directive;
	int inputno;

	directive=(char*)malloc(2*sizeof(char));

	sscanf(circuitline,"%s %c %c",directive,&input,&result);
	



	inputno=retsingleValue(capitalnum,input,capitals,lowercase,lowercasenum);



	if(inputno==1){
	singlematchUpper(capitalnum,result,0,capitals,lowercase,lowercasenum);
		


return;
	}
	else if(inputno==0){
		singlematchUpper(capitalnum,result,1,capitals,lowercase,lowercasenum);
	

return;
	}

	





	return;
}





void and(int* capitalnum, char* capitals,char *circuitline,char* lowercase, int *lowercasenum){
char first;
char second;
char result;
int firstno;
int secondno;
char* directive;
int i;

directive=(char*)malloc(3*sizeof(char));

sscanf(circuitline," %s %c %c %c",directive,&first,&second,&result);




firstno=retsingleValue(capitalnum,first,capitals,lowercase,lowercasenum);
secondno=retsingleValue(capitalnum,second,capitals,lowercase,lowercasenum);


if(firstno==1 && secondno==1){
singlematchUpper(capitalnum,result,1,capitals,lowercase,lowercasenum);

for(i=0;i<26;i++){

	}



return;
}

else if(firstno==0 || secondno==0){
singlematchUpper(capitalnum,result,0,capitals,lowercase,lowercasenum);


for(i=0;i<26;i++){

	}



return;
}

return;
}


void or(int* capitalnum, char* capitals,char *circuitline,char* lowercase, int *lowercasenum){
char first;
char second;
char result;
int firstno;
int secondno;
char* directive;

directive=(char*)malloc(2*sizeof(char));




sscanf(circuitline," %s %c %c %c",directive,&first,&second,&result);




firstno=retsingleValue(capitalnum,first,capitals,lowercase,lowercasenum);
secondno=retsingleValue(capitalnum,second,capitals,lowercase,lowercasenum);

if(firstno==0 && secondno==0){
singlematchUpper(capitalnum,result,0,capitals,lowercase,lowercasenum);


return;
}

else if(firstno==1 || secondno==1){
singlematchUpper(capitalnum,result,1,capitals,lowercase,lowercasenum);

return;
}

return;
}


void decoder(int* capitalnum, char* capitals,char *circuitline,char* lowercase, int *lowercasenum){
int i;
int j;

int howmanyinputs;
char *directive;
char *everything;
int howmanyoutputs;
char *inputs;
char *outputs;
char *jargon;
int *inputnums;
int *outputnums;
int leggo;

jargon=(char*)malloc(gensize*sizeof(char));
directive=(char*)malloc(7*sizeof(char));



sscanf(circuitline,"%s %d %s",directive,&howmanyinputs,jargon);

howmanyoutputs= Twopac(howmanyinputs);

inputs=(char*)malloc(howmanyinputs*sizeof(char));
outputs=(char*)malloc(howmanyoutputs*sizeof(char));
inputnums=(int*)malloc(howmanyinputs*sizeof(int));
outputnums=(int*)malloc(howmanyoutputs*sizeof(int));

toGrayArray(outputnums,howmanyoutputs);




everything=(char*)malloc((howmanyoutputs+howmanyinputs)*sizeof(char));




for(i=0,j=0;i<gensize;i++,j++){


	if((isdigit(circuitline[i]))!=0){

		if((circuitline[i]-'0')==howmanyinputs){
			j=-1;
			continue;
		}
		everything[j]=circuitline[i];

		continue;
	}
	else if((isalpha(circuitline[i]))!=0){
		if(i!=0 && i!=gensize-1){
			if((isalpha(circuitline[i-1]))!=0){							
				j=-1;
				continue;
			}
		}
		if(i==0){
			if((isalpha(circuitline[i+1]))!=0){
				j=-1;
				continue;			
			}
		}

		everything[j]=circuitline[i];
		continue;	
	}
	if(j==howmanyinputs+howmanyoutputs+1){
		break;
	}



	else{
		j--;
	}
}



for(i=0;i<(howmanyinputs+howmanyoutputs);i++){
	if(i<howmanyinputs){
		inputs[i]=everything[i];
	}
	else{
		outputs[i-howmanyinputs]=everything[i];
			
	}
}




for(i=0;i<howmanyinputs;i++){

	inputnums[i]=retsingleValue(capitalnum, inputs[i],capitals,lowercase, lowercasenum);
}


leggo=0;
for(i=1;i<=howmanyinputs;i++){
leggo+= Twopac(howmanyinputs-i)*inputnums[i-1];

}







for(i=0;i<howmanyoutputs;i++){
	for(j=0;j<howmanyinputs;j++){
		if(leggo==outputnums[i]){
			singlematchUpper(capitalnum,outputs[i],1,capitals,lowercase,lowercasenum);	
		
		}
		else{
			singlematchUpper(capitalnum,outputs[i],0,capitals,lowercase,lowercasenum);	
	
		}
	}

}



return;
}

void multiplexer(int *capitalnum,char* capitals,char* circuitline,char* lowercase,int *lowercasenum){
	int i;
	int j;
	char result;
	int index;
	int howmanyinputs;
	char *directive; 
	char *jargon;
	int howmanyselectors;
	char *inputs;
	char *selectorletters;
	int* posse;
	int* selectornums;
	int leggo;
	char betti;
	int brian;
	char *everything;
	
	
	directive=(char*)malloc(gensize*sizeof(char));
	jargon=(char*)malloc(gensize*sizeof(char));


	sscanf(circuitline,"%s %d %s",directive,&howmanyinputs,jargon);

	inputs=(char*)malloc(howmanyinputs*sizeof(char));
	posse=(int*)malloc(howmanyinputs*sizeof(int));

	toGrayArray(posse,howmanyinputs);

	if(howmanyinputs==2){
	howmanyselectors=1;
	}
	else if(howmanyinputs==4){
	howmanyselectors=2;
	}
	else if(howmanyinputs==8){
	howmanyselectors=3;
	}
	else if(howmanyinputs==16){
	howmanyselectors=4;
	}
	else if(howmanyinputs==32){
	howmanyselectors=5;
	}
	else if(howmanyinputs==64){
	howmanyselectors=6;
	}
	
	everything=(char*)malloc((howmanyselectors+howmanyinputs)*sizeof(char));

	selectorletters=(char*)malloc(howmanyselectors*sizeof(char));
	selectornums=(int*)malloc(howmanyselectors*sizeof(int));

	for(i=0,j=0;i<500;i++,j++){
		if((isdigit(circuitline[i]))!=0){
			if((circuitline[i]-'0')==howmanyinputs){
				j=-1;
				continue;
			}
			everything[j]=circuitline[i];
			continue;
		}
		else if((isalpha(circuitline[i]))!=0){
			if(i!=0 && i!=500-1){
				if((isalpha(circuitline[i-1]))!=0){							
					j=-1;
					continue;
				}
			}
			if(i==0){
				if((isalpha(circuitline[i+1]))!=0){
					j=-1;
					continue;			
				}
			}
			everything[j]=circuitline[i];
			continue;	
		}
		if(j==howmanyinputs+howmanyselectors+1){
			break;
		}
		else{
			j--;
		}
	}

	for(i=0;i<(howmanyinputs+howmanyselectors+1);i++){
		if(i<howmanyinputs){
			inputs[i]=everything[i];
		}
		else if(i>=howmanyinputs && i<(howmanyinputs+howmanyselectors)){
			selectorletters[i-howmanyinputs]=everything[i];			
		}
		else{
			result=everything[i];
		}
	}

	for(i=0;i<howmanyselectors;i++){
		selectornums[i]=retsingleValue(capitalnum,selectorletters[i],capitals,lowercase, lowercasenum);
	}
	
	leggo=0;
	for(i=1;i<=howmanyselectors;i++){
		leggo+= Twopac(howmanyselectors-i)*selectornums[i-1];
	}

	for(i=0;i<howmanyinputs;i++){
		if(leggo==posse[i]){
			index=i;
			break;
		}

	}

	betti= inputs[index];

	if(isalpha(betti)!=0){
		brian= retsingleValue(capitalnum,betti,capitals,lowercase, lowercasenum);
		singlematchUpper(capitalnum,result,brian,capitals,lowercase,lowercasenum);
	}
	else{
		singlematchUpper(capitalnum,result,betti-'0',capitals,lowercase,lowercasenum);
	}
	return;

}



void run(int *numbers, char*circuitfilename,int howmanyinputs,int howmanyoutputs){
char *directive;
char *remainder;
int i;
int j;
FILE *fpcircuit;
char* inputletters;
char* circuitline;
char* outputletters;
int capitalnum [26];
int lowercasenum [26];
char capitals[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lowercase[26]="abcdefghijklmnopqrstuvwxyz";
inputletters=(char*)malloc(howmanyinputs*sizeof(char));
outputletters=(char*)malloc(howmanyoutputs*sizeof(char));

for(i=0;i<26;i++){
		capitalnum[i] = 6;
		lowercasenum[i]=6;
}

directive=(char*)malloc(gensize*sizeof(char));
remainder=(char*)malloc(gensize*sizeof(char));
circuitline=(char*)malloc(gensize*sizeof(char));

fpcircuit=fopen(circuitfilename,"r");

if( fpcircuit == NULL){
	printf("error\n");
	exit(0);
}



fgets(circuitline,gensize,fpcircuit);




for(i=0,j=0;i<gensize;i++,j++){
	inputletters[j]=circuitline[i];
	if(isalpha(inputletters[j])==0){
		j--;
		continue;
	}
	else if(isalpha(inputletters[j])!=0){
		if(i!=0){
			if(isalpha(circuitline[i-1])!=0){							
				j=-1;
				continue;
			}
		}
	}
	if(j==howmanyinputs-1 && i!=gensize-1){		
		if(isalpha(circuitline[i+1])!=0){							
				j=-1;
				continue;
		}		

		break;	
	}

}

initmatchUpper(capitalnum,inputletters,numbers,capitals,howmanyinputs);

fgets(circuitline,gensize,fpcircuit);



for(i=0,j=0;i<gensize;i++,j++){
	outputletters[j]=circuitline[i];
	if(isalpha(outputletters[j])==0){
		j--;
		continue;
	}
	else if(isalpha(outputletters[j])!=0){
		if(i!=0){
			if(isalpha(circuitline[i-1])!=0){							
				j=-1;
				continue;
			}
		}
	}
	if(j==howmanyoutputs-1 && i!=gensize-1){		
		if(isalpha(circuitline[i+1])!=0){							
				j=-1;
				continue;
		}		

		break;	
	}
}

while(fgets(circuitline,gensize,fpcircuit)!=NULL){

	sscanf(circuitline,"%s %s",directive,remainder);
	if(strcmp(directive,"AND")==0){

		and(capitalnum, capitals,circuitline,lowercase,lowercasenum);
		continue;
	}
	else if(strcmp(directive,"NOT")==0){

		not(capitalnum, capitals,circuitline,lowercase,lowercasenum);
		continue;		
	
	}
	else if(strcmp(directive,"OR")==0){

		or(capitalnum, capitals,circuitline,lowercase,lowercasenum);		
		continue;
	}	
	else if(strcmp(directive,"MULTIPLEXER")==0){	

		multiplexer(capitalnum, capitals,circuitline,lowercase,lowercasenum);
	}
	else if(strcmp(directive,"DECODER")==0){	

		decoder(capitalnum, capitals,circuitline,lowercase,lowercasenum);
	}

		else{
			break;
		}
	
}



for(i=0;i<howmanyoutputs;i++){
	for(j=0;j<26;j++){
		if(outputletters[i]==capitals[j]){
			if(i!=howmanyoutputs-1){
				printf("%d ",capitalnum[j]);
			}
			else{
				printf("%d",capitalnum[j]);
			}
		}
	}
}
printf("\n");
}




int main(int argc, char **argv){
FILE *fpcircuit;
FILE *fpinput;

char *circuit;
char *input;
int i;
int howmanyinputs;
int howmanyoutputs;
char *jargon;
char *jargon1;
int *numbers;
char* originputline;
char* origoutputline;

circuit= argv[1];
input= argv[2];

fpcircuit=fopen(circuit,"r");

fpinput=fopen(input,"r");

jargon=(char*)malloc(gensize*sizeof(char));
jargon1=(char*)malloc(gensize*sizeof(char));
originputline=(char*)malloc(gensize*sizeof(char));
origoutputline=(char*)malloc(gensize*sizeof(char));

if(fpcircuit==NULL || fpinput==NULL){
	printf("error\n");
	exit(0);
}


fgets(originputline,gensize,fpcircuit);

sscanf(originputline,"%s %d %s",jargon,&howmanyinputs,jargon1);



numbers=(int*)malloc(howmanyinputs*sizeof(int));





fgets(origoutputline,gensize,fpcircuit);

sscanf(origoutputline,"%s %d %s",jargon,&howmanyoutputs,jargon1);






while(!feof(fpinput)){
	i=0;
	while(i<howmanyinputs){
		numbers[i]=fgetc(fpinput);
		if (!isdigit(numbers[i])){
			i--;
		if(feof(fpinput)){
			break;		
		}		
		}
	if(i==howmanyinputs-1){
	
		for(i=0;i<howmanyinputs;i++){

		}
	
		run(numbers,circuit,howmanyinputs,howmanyoutputs);

		break;
	}
	i++;
	}
}


free(numbers);
free(jargon);
free(jargon1);
free(originputline);
free(origoutputline);
exit (0);
}

