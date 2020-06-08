#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num_new_inst = 0b000001;
int num_inst_with_fun = 0b000001;

///Writing in command program for the instructions
 void new_instruction(FILE *foutput) {

	int zaf=0;
    char inst[50]; ///user writes all code in inst
    foutput = fopen("SourceFileInstruction.txt", "w");

    printf("\n Please Enter The Code\n");//// asking user to write the code in machine language
//// program waits until the assemble is written for the break:
    for(zaf=0;strcmp(inst,"assemble");zaf++) {
      fgets(inst, sizeof(inst), stdin);
      fprintf(foutput, "%s\n", inst);
      if (strcmp(inst,"assemble\n")==0) break;
	} 
    fclose(foutput);
    batching(); //calling the write function to text file
}
 
 ///function is using the input as foutput to write the fuction to file
int assem()
{
FILE* foutput;
	new_instruction(foutput);
}

////This function takes the instruction from the user and gives back the function part of the machine code in binary 
void getinstfunc(char inst[],FILE *fp) {
	char func[6]={0};/// trying to get the function
		int i=0;
 		while((inst[i]!=' ')&&(inst[i]!=':')) {
 		func[i]=inst[i];
 		i++;
 	}
 	
 	int x = 0;
	char new_inst[1000];
	char new_inst1[50]={0};
	FILE *foutputNew;
	foutputNew = fopen("NewInstruction.txt", "r");
	fgets(new_inst,100,foutputNew);
	
	while(new_inst[x]!=';'){
	        new_inst1[x]=new_inst[x];
	        x++;}
	x++;
	
	if ((strcmp(func,"add"))==0)
	{printf("100000");fprintf(fp,"%d",100000);} ///function of add is 20 in hex
	if ((strcmp(func,"move"))==0)
	{printf("100000");fprintf(fp,"%d",100000);} ///function of move is 20 in hex pseudocode for add
	if ((strcmp(func,"sub"))==0)
	{printf("100010");fprintf(fp,"%d",100010);} ///function of substract is 22 in hex
	if ((strcmp(func,"mult"))==0)
	{printf("011000");fprintf(fp,"%d",011000);} ///function of add is 18 in hex
	if ((strcmp(func,"div"))==0)
    {printf("011010");fprintf(fp,"%d",011010);}
    if ((strcmp(func,"multi"))==0)
	{printf("011000");fprintf(fp,"%d",011000);}
	if ((strcmp(func,"and"))==0)
	{printf("100100");fprintf(fp,"%d",100100);}
	if ((strcmp(func,"or"))==0)
	{printf("100101");fprintf(fp,"%d",100101);}
	if ((strcmp(func,"nor"))==0)
	{printf("100111");fprintf(fp,"%d",100111);}
	if ((strcmp(func,"xor"))==0)
	{printf("101000");fprintf(fp,"%d",101000);}
	if ((strcmp(func,"srav"))==0)
	{printf("000111");fprintf(fp,"%d",000111);}
	if ((strcmp(func,"srlv"))==0)
	{printf("000110");fprintf(fp,"%d",000110);}
	if ((strcmp(func,"sllv"))==0)
	{printf("000100");fprintf(fp,"%d",000100);}
	if ((strcmp(func,"sra"))==0)
	{printf("000011");fprintf(fp,"%d",000011);}
	if ((strcmp(func,"srl"))==0)
	{printf("000010");fprintf(fp,"%d",000010);}
	if ((strcmp(func,"sll"))==0)
	{printf("000000");fprintf(fp,"%d",000000);}
	if ((strcmp(func,"jalr"))==0)
	{printf("001001");fprintf(fp,"%d",001001);}
	if ((strcmp(func,"addu"))==0)
	{printf("100001");fprintf(fp,"%d",100001);} ///function of unsigned add is 21 in hex
	if ((strcmp(func,"subu"))==0)
	{printf("100011");fprintf(fp,"%d",100011);} ///function of add is 23 in hex
	if ((strcmp(func,"multu"))==0)
	{printf("011001");fprintf(fp,"%d",011001);}
	if ((strcmp(func,"divu"))==0)
	{printf("011011");fprintf(fp,"%d",011011);}
	if ((strcmp(func,"sltu"))==0)
	{printf("101011");fprintf(fp,"%d",101011);}
	if ((strcmp(func,"slt"))==0)
	{printf("101010");fprintf(fp,"%d",101010);}
	if ((strcmp(func,"jr"))==0)
	{printf("001000");fprintf(fp,"%d",001000);}
	if ((strcmp(func,"mfc0"))==0)
	{printf("000000");fprintf(fp,"%d",000000);}
	if ((strcmp(func,"mtc0"))==0)
	{printf("000000");fprintf(fp,"%d",000000);}


	
	if ((strcmp(func,new_inst1))==0){
		    	
		    	
		    	while(new_inst[x]!=';'){x++;}x++;
	            while(new_inst[x]!=';'){x++;};
	            x++;
	            int y = 0;
		    	while(new_inst[x]!='/'){
		           new_inst1[y]=new_inst[x];
		           y++;
		           x++;
	                }
	            printf("%s",new_inst1);fprintf(fp,"%s",new_inst1);}
	                
	            
	           	
		    
	            
}



////This function takes the instruction from the user and gives back the opcode part of the machine code in binary
int getinstopcode(char inst[], FILE *fp,char label[], int ddd,int *funct_length) {
	char opcode[6]={0};
	int i=0;
	
 		while(inst[i]!=' ') {
 		opcode[i]=inst[i];
 		i++;
 	}
 	
 	
 	int x = 0;
	char new_inst[50];
	char new_inst1[50]={0};
	FILE *foutputNew;
	int cc;
	foutputNew = fopen("NewInstruction.txt", "r");
	fgets(new_inst,100,foutputNew);
	
	while(new_inst[x]!=';'){
	        new_inst1[x]=new_inst[x];
	        x++;}
	x++;
 	
 	if ((strcmp(opcode,"add"))==0) { 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"sub"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"mult"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 14;
    }
    if ((strcmp(opcode,"div"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 14;
	}
	if ((strcmp(opcode,"slt"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"and"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"nor"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"xor"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"or"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
		if ((strcmp(opcode,"srav"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"addu"))==0) { 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"subu"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"multu"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 14;
	}
	
	if ((strcmp(opcode,"divu"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 14;
	}
	
	if ((strcmp(opcode,"sltu"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}

	if ((strcmp(opcode,"srlv"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"sllv"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 1;
	}
	if ((strcmp(opcode,"sra"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 2;
	}
	if ((strcmp(opcode,"srl"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 2;
	}
	if ((strcmp(opcode,"sll"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 2;
	}
	if ((strcmp(opcode,"jalr"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 6;
	}
	if ((strcmp(opcode,"jr"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 7;
	}
	if ((strcmp(opcode,"mfc0"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 9;
	}
	if ((strcmp(opcode,"mtc0"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 10;
	}
	if ((strcmp(opcode,"j"))==0){ 
	printf("000010");fprintf(fp,"000010");
	return 8;
	}
	if ((strcmp(opcode,"jal"))==0){ 
	printf("000011");fprintf(fp,"000011");
	return 8;
	}
	
	if ((strcmp(opcode,"blez"))==0){ 
	printf("000110");fprintf(fp,"000110");
	return 5;
	}
	if ((strcmp(opcode,"bgtz"))==0){ 
	printf("000111");fprintf(fp,"000111");
	return 5;
	}
	if ((strcmp(opcode,"lui"))==0){ 
	printf("001111");fprintf(fp,"001111");
	return 0;
	}
	if ((strcmp(opcode,"sh"))==0){ 
	printf("101001");fprintf(fp,"101001");
	return 4;
	}
	if ((strcmp(opcode,"sb"))==0){ 
	printf("101000");fprintf(fp,"101000");
	return 4;
	}
	if ((strcmp(opcode,"lhu"))==0){ 
	printf("100101");fprintf(fp,"100101");
	return 4;
	}
	if ((strcmp(opcode,"lbu"))==0){ 
	printf("100100");fprintf(fp,"100100");
	return 4;
	}
	if ((strcmp(opcode,"lh"))==0){ 
	printf("100001");fprintf(fp,"100001");
	return 4;
	}
	if ((strcmp(opcode,"lb"))==0){ 
	printf("100000");fprintf(fp,"100000");
	return 4;
	}
	if ((strcmp(opcode,"sw"))==0){ 
	printf("101011");fprintf(fp,"101011");
	return 4;
	}
	if ((strcmp(opcode,"lw"))==0){ 
	printf("100011");fprintf(fp,"100011");
	return 4;
	}
	if ((strcmp(opcode,"bne"))==0){ 
	printf("000101");fprintf(fp,"000101");
	return 3;
	}
	if ((strcmp(opcode,"beq"))==0){ 
	printf("000100");fprintf(fp,"000100");
	return 3;
	}
	if ((strcmp(opcode,"xori"))==0){ 
	printf("001110");fprintf(fp,"001110");
	return 3;
	}
	if ((strcmp(opcode,"ori"))==0){ 
	printf("001101");fprintf(fp,"001101");
	return 3;
	}
	if ((strcmp(opcode,"andi"))==0){ 
	printf("001100");fprintf(fp,"001100");
	return 3;
	}
	if ((strcmp(opcode,"sltiu"))==0){ 
	printf("001011");fprintf(fp,"001011");
	return 3;
	}
	if ((strcmp(opcode,"slti"))==0){ 
	printf("001010");fprintf(fp,"001010");
	return 3;
	}
	if ((strcmp(opcode,"addiu"))==0){ 
	printf("001001");fprintf(fp,"001001");
	return 3;
	}
	if ((strcmp(opcode,"addi"))==0){ 
	printf("001000");fprintf(fp,"001000");
	return 3;
	}
	if ((strcmp(opcode,"multi"))==0){ 
	printf("001000");fprintf(fp,"001000");
	return 13;
    }
	if ((strcmp(opcode,"move"))==0){ 
	printf("000000");fprintf(fp,"000000");
	return 12;
	}
	if ((strcmp(opcode,"assemble"))==0){ 
	return 11;
	}
	
    if ((strcmp(opcode,new_inst1))==0){
		    	
		    	int y = 0;
		    	while(new_inst[x]!=';'){
		           new_inst1[y]=new_inst[x];
		           y++;
		           x++;
	                }
	                x++;
	            cc = atoi(new_inst1);
	            y = 0;
		    	while(new_inst[x]!=';'){
		           new_inst1[y]=new_inst[x];
		           y++;
		           x++;
	                }
	                
					
					printf("%s",new_inst1);fprintf(fp,"%s",new_inst1);
					 return cc;
					}     
	           
	           	
		    
	           

	////the last else code happens when the instruction does not exist, so it checks if it is a mistake or a label
	////mistake --> prints invalid instruction
	else {
	     if(opcode[strlen(opcode)-1]==':')
	      {strncpy (label, opcode,strlen(opcode)-1);
		   char fmp[70]={};
		   int j=0; 
		   while(inst[j]!=' ') 
		     {j++;}
		     *funct_length = j;
		   j++;
		   int fi=0;
		   while(inst[j]!=' ') 
		     {fmp[fi]=inst[j];	
			  j++; 
			  fi++;} 
			strcpy (opcode,fmp);
			char dmp=' ';
			strcat(opcode,&dmp); 
			int std=getinstopcode(opcode,fp,label,ddd, funct_length);
			return std;	

		  } 
			else {
			printf("invalid instruction"); return 11;}
		 }
	
}

/////this function take the instruction from the user and define the used register where it brings back the register address 
void registercomp(char reg[], FILE *fp) { ///register addresses are defined in here from 0 to ra
 	    if (((strcmp(reg,"$0"))==0)||((strcmp(reg,"$zero"))==0)) 
		 {printf("00000"); fprintf(fp,"00000");}
else	if (((strcmp(reg,"$1"))==0)||((strcmp(reg,"$at"))==0)) 
         {printf("00001"); fprintf(fp,"00001");}
else	if (((strcmp(reg,"$2"))==0)||((strcmp(reg,"$v0"))==0)) 
         {printf("00010"); fprintf(fp,"00010");}
else	if (((strcmp(reg,"$3"))==0)||((strcmp(reg,"$v1"))==0))
         {printf("00011"); fprintf(fp,"00011");}
else	if (((strcmp(reg,"$4"))==0)||((strcmp(reg,"$a0"))==0)) 
         {printf("00100"); fprintf(fp,"00100");}
else	if (((strcmp(reg,"$5"))==0)||((strcmp(reg,"$a1"))==0)) 
         {printf("00101"); fprintf(fp,"00101");}
else	if (((strcmp(reg,"$6"))==0)||((strcmp(reg,"$a2"))==0)) 
         {printf("00110"); fprintf(fp,"00110");}
else	if (((strcmp(reg,"$7"))==0)||((strcmp(reg,"$a3"))==0)) 
         {printf("00111"); fprintf(fp,"00111");}
else	if (((strcmp(reg,"$8"))==0)||((strcmp(reg,"$t0"))==0)) 
         {printf("01000"); fprintf(fp,"01000");}
else	if (((strcmp(reg,"$9"))==0)||((strcmp(reg,"$t1"))==0)) 
         {printf("01001"); fprintf(fp,"01001");}
else	if (((strcmp(reg,"$10"))==0)||((strcmp(reg,"$t2"))==0)) 
         {printf("01010"); fprintf(fp,"01010");}
else	if (((strcmp(reg,"$11"))==0)||((strcmp(reg,"$t3"))==0)) 
         {printf("01011"); fprintf(fp,"01011");}
else	if (((strcmp(reg,"$12"))==0)||((strcmp(reg,"$t4"))==0)) 
         {printf("01100"); fprintf(fp,"01100");}
else	if (((strcmp(reg,"$13"))==0)||((strcmp(reg,"$t5"))==0)) 
         {printf("01101"); fprintf(fp,"01101");}
else	if (((strcmp(reg,"$14"))==0)||((strcmp(reg,"$t6"))==0)) 
         {printf("01110"); fprintf(fp,"01110");}
else	if (((strcmp(reg,"$15"))==0)||((strcmp(reg,"$t7"))==0)) 
         {printf("01111"); fprintf(fp,"01111");}
else	if (((strcmp(reg,"$16"))==0)||((strcmp(reg,"$s0"))==0)) 
         {printf("10000"); fprintf(fp,"10000");}
else	if (((strcmp(reg,"$17"))==0)||((strcmp(reg,"$s1"))==0)) 
         {printf("10001"); fprintf(fp,"10001");}
else	if (((strcmp(reg,"$18"))==0)||((strcmp(reg,"$s2"))==0)) 
         {printf("10010"); fprintf(fp,"10010");}
else	if (((strcmp(reg,"$19"))==0)||((strcmp(reg,"$s3"))==0)) 
         {printf("10011"); fprintf(fp,"10011");}
else	if (((strcmp(reg,"$20"))==0)||((strcmp(reg,"$s4"))==0)) 
         {printf("10100"); fprintf(fp,"10100");}
else	if (((strcmp(reg,"$21"))==0)||((strcmp(reg,"$s5"))==0)) 
         {printf("10101"); fprintf(fp,"10101");}
else	if (((strcmp(reg,"$22"))==0)||((strcmp(reg,"$s6"))==0)) 
         {printf("10110"); fprintf(fp,"10110");}
else	if (((strcmp(reg,"$23"))==0)||((strcmp(reg,"$s7"))==0)) 
         {printf("10111"); fprintf(fp,"10111");}
else	if (((strcmp(reg,"$24"))==0)||((strcmp(reg,"$t8"))==0)) 
         {printf("11000"); fprintf(fp,"11000");}
else	if (((strcmp(reg,"$25"))==0)||((strcmp(reg,"$t9"))==0)) 
         {printf("11001"); fprintf(fp,"11001");}
else	if (((strcmp(reg,"$26"))==0)||((strcmp(reg,"$k0"))==0)) 
         {printf("11010"); fprintf(fp,"11010");}
else	if (((strcmp(reg,"$27"))==0)||((strcmp(reg,"$k1"))==0)) 
         {printf("11011"); fprintf(fp,"11011");}
else	if (((strcmp(reg,"$28"))==0)||((strcmp(reg,"$gp"))==0)) 
         {printf("11100"); fprintf(fp,"11100");}
else	if (((strcmp(reg,"$29"))==0)||((strcmp(reg,"$sp"))==0)) 
         {printf("11101"); fprintf(fp,"11101");}
else	if (((strcmp(reg,"$30"))==0)||((strcmp(reg,"$fp"))==0)) 
         {printf("11110"); fprintf(fp,"11110");}
else	if (((strcmp(reg,"$31"))==0)||((strcmp(reg,"$ra"))==0)) 
         {printf("11111"); fprintf(fp,"11111");}
}


/////This function is getting the register with starting $ until the comma, closing paranthesis or putting space
int getregister(char reg[],char inst[],int i) { 
	int a = 0;
	while(inst[i]!='$') {
		i++;
	}
	while((inst[i]!=',')&&(inst[i]!=' ')&&(inst[i]!=')')) {
	reg[a]=inst[i];
	i++; a++;}

	return i;
}


int get_number(char inst[],int i,int sd, FILE *fp, int ddd) {
	char tmp[70];
	int a = 0,ff=0;
	i++;
	while((inst[i]!='(')&&(inst[i]!=' ')) {
	tmp[a]=inst[i];
	i++; a++;}
if((tmp[0]!='-')&&(tmp[0]!='0')&&(tmp[0]!='1')&&(tmp[0]!='2')&&(tmp[0]!='3')&&(tmp[0]!='4')&&(tmp[0]!='5')&&(tmp[0]!='6')&&(tmp[0]!='7')&&(tmp[0]!='8')&&(tmp[0]!='9')) 
{
	printf("Missing immediate number.Insure that there is no space before your immediate number. Error!!!");
	return i;
}
///////If the immediate number is exceeding the limit it gives error message after the function
    int dec = atoi(tmp); ////converts the string argument str to an integer
    if(dec<0){ff=1;dec =-1 * dec;}
	itoa(dec,tmp,2);////converts int data type to string data type
	if ((strlen(tmp) > sd)) {printf("   Number above limit!!! :( \n" );}
	if (ff==1){	dec =-1 * dec;itoa(dec,tmp,2);char gmp[70]={};	strcpy(gmp, tmp+32-sd);	strcpy(tmp, gmp);}

	int dd =strlen(tmp);
	while ( dd< sd) {
		char smp[70]={"0"};
		strcat(smp,tmp);
	strcpy(tmp, smp);
	dd++;
   }
    printf("%s", tmp);fprintf(fp,"%s",tmp);
	return i;
}
//////This function reads the code in text file and converts into machine code in binary   
int batching(){
	char a[32]={0};
	char inst[25];
	char reg[5]={0};
	char reg_1[5]={0};
	char reg_2[5]={0};
	int zaf=0,sd;
	int funct_length = 0;
	char label[25];
	int ddd,flag=0;
	FILE *fptr;
	FILE *fp;
	FILE *foutputNew;
	

    if ((fptr = fopen("SourceFileInstruction.txt", "r")) == NULL)
    {
        printf("Error! opening file");
    
        exit(1);         
    }
        if ((foutputNew = fopen("NewInstruction.txt", "r")) == NULL)
    {
        printf("Error! opening file");
    
        exit(1);         
    }
    if ((fp = fopen("MachineCode.txt", "w")) == NULL)
    {
        printf("Error! opening file");
    
        exit(1);         
    }
	

	
	for(zaf=0;strcmp(inst,"assemble");zaf++) {
	fgets(inst,50,fptr);
	if (strcmp(inst,"assemble")==0) break;
    if (strcmp(inst,"\n")==0) continue;
	int length=strlen(inst);
	inst[length-1]=0;
	printf("\n ");fprintf(fp,"\n ");
    ddd =zaf+1;
	int cas=getinstopcode(inst,fp,label,ddd,&funct_length); 
	int i=funct_length;
		
		if (funct_length)
		{	
			char inst_tmp[25];
			int tmp = funct_length+1;
			int tmp_2 = 0;
			while (inst[tmp] != '\0')
			{
				inst_tmp[tmp_2] = inst[tmp];
				tmp++; tmp_2++;
			}
		
			strcpy(inst, inst_tmp);
		}	
	strcpy(a,inst);
    if (cas==0) {	              ///case 0 : "load upper immediate $R1, num"
        printf("00000");fprintf(fp,"00000");
		i=getregister(reg,inst,i);
		registercomp(reg,fp);
		sd = 16;
        get_number(inst,i,sd,fp,ddd);
}
	if (cas==1) {                /////case1 :  "instruction $R1, $R2 ,$R3"
    i=getregister(reg,inst,i);
    strcpy (reg_1,reg);
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	registercomp(reg_1,fp);
	printf("00000");fprintf(fp,"00000");
	getinstfunc(a,fp);
}
	if (cas==2) {	             /////case2 : "instruction $R1, $R2 ,num"	I-type
		printf("00000");fprintf(fp,"00000");
		i=getregister(reg,inst,i);
     	strcpy (reg_1,reg);
    	i=getregister(reg,inst,i);
    	registercomp(reg,fp);
        registercomp(reg_1,fp);
        sd = 5;
        get_number(inst,i,sd,fp,ddd);
        getinstfunc(a,fp);
}

    if (cas==3) {	              //case 3 : "instruction $R1, $R2 ,num" branch function checks
		i=getregister(reg,inst,i);
     	strcpy (reg_1,reg);
    	i=getregister(reg,inst,i);
    	registercomp(reg,fp);
        registercomp(reg_1,fp);
        sd = 16;
       get_number(inst,i,sd,fp,ddd);
}
    
    if (cas==4) {                ////case 4 : "instruction $R1, number($R2)"
    	i=getregister(reg,inst,i);
    	strcpy (reg_1,reg);
    	int sss =i;
    	i=getregister(reg,inst,i);
    	registercomp(reg,fp);
        registercomp(reg_1,fp);
        i= sss;
    	sd = 16;
        get_number(inst,i,sd,fp,ddd);
        
}
	 if (cas==5) {	              /////case 5 : "instruction $R1, num*"
		i=getregister(reg,inst,i);
		registercomp(reg,fp);
		printf("00000");fprintf(fp,"00000");
		sd = 16;
       get_number(inst,i,sd,fp,ddd);
}
    if (cas==6) {	              ////case  6 : "instruction $R1, $R2" (jalr)
		i=getregister(reg,inst,i);
     	strcpy (reg_1,reg);
    	i=getregister(reg,inst,i);
    	registercomp(reg,fp);
    	printf("00000");fprintf(fp,"00000");
       registercomp(reg_1,fp);
        printf("00000");fprintf(fp,"00000");
        getinstfunc(a,fp);
}   
    if (cas==7) {	              /////case 7 :  "inst $R1" (jr)
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	printf("00000");printf("00000");printf("00000");fprintf(fp,"00000");fprintf(fp,"00000");fprintf(fp,"00000");
	getinstfunc(a,fp);
}   
if (cas==8) {	              ///case 8 : "inst  num*" 
	while(inst[i]!=' ') {
		i++;
	}
	sd = 26;
   get_number(inst,i,sd,fp,ddd);
}   
if (cas==9) {	              ///case  9 : "inst $R1, $R2" (mfc0)
	printf("00000");fprintf(fp,"00000");
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	printf("00000");fprintf(fp,"00000");
	getinstfunc(a,fp);
}   
if (cas==10) {	              ///case  10 : "inst $R1, $R2" (mtc0)
	printf("00100");fprintf(fp,"00000");
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	printf("00000");fprintf(fp,"00000");
	getinstfunc(a,fp);
}   
if (cas==11) { main(); }    ///going back to asking 
if (cas==12) { 
 i=getregister(reg,inst,i);
    strcpy (reg_1,reg);
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
    printf("00000");fprintf(fp,"00000");
	registercomp(reg_1,fp);
	printf("00000");fprintf(fp,"00000");
	getinstfunc(a,fp);}
if (cas==13) { 
 i=getregister(reg,inst,i);
     	strcpy (reg_1,reg);
    	i=getregister(reg,inst,i);
    	strcpy (reg_2,reg);
    	printf("00000");fprintf(fp,"00000");
    	printf("00001");fprintf(fp,"00001");
        sd = 16;
       get_number(inst,i,sd,fp,ddd);
       	printf("\n 000000");fprintf(fp,"\n 000000");
       registercomp(reg_1,fp);
       	registercomp(reg_2,fp);
       	printf("00000");fprintf(fp,"00000");
	printf("00000");fprintf(fp,"00000");
       	getinstfunc(a,fp);
       	printf("\n 000000");fprintf(fp,"\n 000000");
       	printf("00000");fprintf(fp,"00000");
       	printf("00000");fprintf(fp,"00000");
       	registercomp(reg_1,fp);
       	printf("00000");fprintf(fp,"00000");
       	printf("010010");fprintf(fp,"010010");
       	printf("\n 000000");fprintf(fp,"\n 000000");
       registercomp(reg_1,fp);
       	printf("00001");fprintf(fp,"00001");
       	printf("00000");fprintf(fp,"00000");
	printf("00000");fprintf(fp,"00000");
       	getinstfunc(a,fp);
		   }
if (cas==14) {
 i=getregister(reg,inst,i);
	registercomp(reg,fp);
	i=getregister(reg,inst,i);
	registercomp(reg,fp);
	printf("00000");fprintf(fp,"00000");
	printf("00000");fprintf(fp,"00000");
	getinstfunc(a,fp);
	}
		   fclose(fp);
		   fp=fopen("MachineCode.txt","a+");

}
}


int main(){
	int Exit=1,choice;
while(Exit)
{
	printf("\nMIPS MCC Project by Zafer and Burak\n\n");
	printf("Type the number that you want: \n1)Source File(Batch Mode,Machine Code should be in SourceFileInstruction.txt)\n2)Interactive Mode(This option is to write machine code to here)\n3)Add extra new instruction\n4)Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{	
		case 1:
		batching();
		break;
		case 2:
		assem();
		break;
		case 3:
		add_new_inst();
		break;
		case 4:
		Exit = 0;
		break;
	}
	printf("\n");
}
return 0;
}

void add_new_inst(){
	char new_inst[30]={0};
	int  inst_case;
	int  inst_opcode;
	char  inst_Opcode[6]={0};
	int  inst_func;
	char  inst_Func[6]={0};
	FILE *foutputNew;
	
	foutputNew = fopen("NewInstruction.txt", "w");
	
	printf("Insert the name of the new instruction:");
	scanf("%s",new_inst);
	fprintf(foutputNew, "%s", new_inst);
    fprintf(foutputNew, "%s",";");
    
    printf("case 0  --> inst $R1, num         e.g.(lui)\n");
    printf("case 1  --> inst $R1, $R2 ,$R3    e.g.(add)\n");
    printf("case 2  --> inst $R1, $R2 ,num    e.g.(addi)\n");
    printf("case 3  --> inst $R1, $R2 ,label  e.g.(bne)\n");
    printf("case 4  --> inst $R1, num($R2)    e.g.(sw)\n");
    printf("case 5  --> inst $R1, label       e.g.(blez)\n");
    printf("case 6  --> inst $R1, $R2         e.g.(jalr)\n");
    printf("case 7  --> inst $R1              e.g.(jr)\n");
    printf("case 8  --> inst label            e.g.(j)\n");
    printf("case 9  --> inst $R1              e.g.(mfc0)\n");
    printf("case 10 --> inst $R1, $R2         e.g.(mtc0)\n");
    printf("case 12 --> inst $R1, $R2         e.g.(move)\n");
    printf("case 13 --> inst $R1, $R2 ,num    e.g.(multi)\n");
    printf("case 14 --> inst $R1, $R2 ,$R3    e.g.(mult)\n");

    
	printf("\nChoose from the above cases the format for your new instruction:");
	scanf("%d",&inst_case);
	
	fprintf(foutputNew, "%d", inst_case);
	fprintf(foutputNew, "%s",";");
	
	if ((inst_case==1)||(inst_case==2)||(inst_case==6)||(inst_case==7)||(inst_case==9)||(inst_case==10)||(inst_case==12)||(inst_case==14)){
	inst_func = 0b101100+num_inst_with_fun;
	
	fprintf(foutputNew, "000000");
	fprintf(foutputNew, "%s",";");
	
	itoa(inst_func,inst_Func,2);
	fprintf(foutputNew, "%s", inst_Func);
	
	num_inst_with_fun= num_inst_with_fun+ 0b000001 ;
	}
	
	else if((inst_case==0)||(inst_case==3)||(inst_case==4)||(inst_case==5)||(inst_case==8)||(inst_case==13)){
		inst_opcode = 0b110000+num_new_inst;
		
	itoa(inst_opcode,inst_Opcode,2);
	fprintf(foutputNew, "%s", inst_Opcode);
	}
	
	else{
		printf("\nwrong case");
	}
	
	
	fprintf(foutputNew, "%s","/");
	
	fclose(foutputNew);
	num_new_inst=num_new_inst+0b000001;
	
}
