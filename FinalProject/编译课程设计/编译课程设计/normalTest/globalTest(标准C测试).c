
#include <stdio.h> 
const int int1 = 666,int2 = +233,int3 = -1000,int4 = 0;
const char char1 = '1',char2 = '_',char3='+',char4 = 'a';


int gInt1,gInt2[10],gInt3[10],gInt4,gInt5[10];
char gCh1,gCh2[10],gCh3[10],gCh4,gCh5[10];

char GGG[10];


void testAllDefine(){
    const int int1=333,int2 = +789,int3 = -7125,int4 = -1;
    
    const char char1 = '0',char2 = '-',char3='*',char4 = 'D',char5 = 'g',
    char6 = '+',char7 = '/',char8 = '9',char9 = 'Z',char10 = 'y';
    
    int gInt1,gInt2[10],gInt3[10],gInt4,gInt5[10];
    
    char gCh1,gCh2[10],gCh3[10],gCh4,gCh5[10];

    int i;
    
    
    gInt1 = 10*1;
    gInt4 = 10*4;
    gCh1 = '0';
    gCh4 = '9';

    i = (0+0*0-0-(0-'a'+'b'-1)*34445);
    while(i<(333-222-111+19-9+gCh4-'8'-1)){
        gInt2[i] = 2*10+i;
        gInt3[i] = 3*10+i;
        gInt5[i] = 5*10+i;
        gCh2[i] = 'a';
        gCh3[i] = 'b';
        gCh5[i] = 'c';
        i = i + '8' - '7';
    }

  
    printf("int1:%d\n",int1);
    printf("int2:%d\n",int2);
    printf("int3:%d\n",int3);
    printf("int4:%d\n",int4);

    printf("char1:%c\n",char1);
    printf("char2:%c\n",char2);
    printf("char3:%c\n",char3);
    printf("char4:%c\n",char4);

    printf("gInt1:%d\n",gInt1);
    printf("gInt4:%d\n",gInt4);

    printf("gCh1:%c\n",gCh1);
    printf("gCh4:%c\n",gCh4);

    i = 0;
    printf("gInt2[]:\n");
    while(i<10){
        i = i + 1;
        printf("%d\n",gInt2[i-1]);
    }
    i = 0;
    printf("gInt3[]:\n");
    while(i<10){
        i = i + 1;
        printf("%d\n",gInt3[i-1]);
    }
    i = 0;
    printf("gInt5[]:\n");
    while(i<10){
        i = i + 1;
        printf("%d\n",gInt5[i-1]);
    }
    
    printf("gCh2[3]:%c\n",gCh2[3]);
    printf("gCh2[6]:%c\n",gCh2[6]);

    printf("gCh3[3]:%c\n",gCh3[3]);
    printf("gCh3[6]:%c\n",gCh3[6]);

    printf("gCh5[3]:%c\n",gCh5[3]);
    printf("gCh5[6]:%c\n",gCh5[6]);

}

void giveValueToGlobalVar(){
    int i;
    
    gInt1 = 100*1;
    gInt4 = 100*4;
    gCh1 = 'D';
    gCh4 = 'F';

    i = 0;
    while(i<10){
        gInt2[i] = 2*100+i;
        gInt3[i] = 3*100+i;
        gInt5[i] = 5*100+i;
        gCh2[i] = 'i';
        gCh3[i] = 'j';
        gCh5[i] = 'k';
        i = i + 'B' - 'A';
    }
}

int returnAdd(int int1,int int2,int int3,int int4,int int5,int int6,int int7,int int8,int int9,int int10){
    int gInt2;
    gInt2 = +int1+int2+int3+int4+int5+int6+int7+int8+int9+int10;
    return (gInt2);
}

int returnMix(char char1,char char2,char char3,char char4,char char5,char char6,char char7,char char8,char char9,char char10){
    int gCh2,i;
    gCh2 = char1+char2+char3+char4+char5-char6*char7+char8-char9+char10/2;
    i = 0;
    while(i<(100/10)){
        switch(i){
            case 0:
                GGG[0] = char1;
                break;
            case 1:
                GGG[1] = char2;
                break;
            case 2:
                GGG[2] = char3;
                break;
            case 3:
                GGG[3] = char4;
                break;
            case 4:
                GGG[4] = char5;
                break;
            case 5:
                GGG[5] = char6;
                break;
            case 6:
                GGG[6] = char7;
                break;
            case 7:
                GGG[7] = char8;
                break;
            case 8:
                GGG[8] = char9;
                break;
            case 9:
                GGG[9] = char10;
                break;
            default:printf("Are you kidding me?\n");break;
        }
        i = i + (100/100);
    }
    return (gCh2);
}

char MixParam(int int1,char char1,int int2,char char2){
    if(int1+char1){
        return ('1');
    }
    else{
        if(int2+char2)
            return ('2');
        else
            return ('0');
    }
}

int calculateFactorial(int item){
    if(item < 0 ){
        printf("The factorial number must >= 0 .\n");
        return (0);
    }else{
        if(item == 0)
            return (1);
        else
            return (calculateFactorial(item-1)*item);
    }
}

int Fibonaci(int n){
    if(n<=2){
        if((n+1)<=1){
            printf("The Fibonaci number must >=1.\n");
            return (0);
        }else{
            ;
       
        }
        return (1);
    }
    else
        return (Fibonaci(n-1)+Fibonaci(n-2));
}


char return100(){
    return ('d');
}

int returnIntValue(){
    return (1 + 'c' + Fibonaci(8) + calculateFactorial(4)); 
}

void complexExpression(){
    int x1,x2,x3,x4,x5;
    
    x1 = (3+4-7*Fibonaci(9))/2-(calculateFactorial(5)-87*2+67)/(return100()-50/3-12)+(34-67)/2*6;
    printf("complex --- x1:%d\n",x1);
    
    x2 = ( 333-222 + ( 1 + ( 2 + ( 3 * ( 89 - 56 * (3-3*6+Fibonaci(7) +Fibonaci(1) -2 ) + calculateFactorial(3) ) -3 ) + 4 ) -0*(0+0-0-0) - 1 ) + 2 ) - calculateFactorial(4)/4*111+Fibonaci(6);
    printf("complex --- x2:%d\n",x2);
   
    x3 = ('a'+90-'0'+(Fibonaci('a'-91))) + calculateFactorial(Fibonaci(Fibonaci(Fibonaci(Fibonaci(2))))) + 666*3/222;
    printf("complex --- x3:%d\n",x3);
   
    x4 = (666+888)/111 - return100()/50 + gInt2[Fibonaci(3)] - gInt5[calculateFactorial(3)] + 5000;
    printf("complex --- x4:%d\n",x4);
   
    x5 = (calculateFactorial(5) - 67)*('a')+ x1 - x3 + 4666 + 2333/32 + 87 +'9' + gCh1 + ('8')*('_') + ('*')/('4') + gInt3[3+'f'-'e'] + return100() + (((((5+5)))))*100 - 100 + Fibonaci(5);
    printf("complex --- x5:%d\n",x5);
}


void complexIf_Else(){
    int i;
    i = 4;
    while(i>=0){
        if(i == 4){
            if(i==4){
                printf("In If-Else i = 4 haha\n");
            }
            printf("In If-Else i = 4\n");
        }else{
            if(i == 3){
                printf("In If-Else i = 3\n");
            }else{
                if(i == 2){
                    printf("In If-Else i = 2\n");
                }else{
                    if(i == 1){
                        printf("In If-Else i = 1\n");
                    }else{
                        printf("Test If-Else Over.\n");
                    }
                }
            }
        }
        i = i - 1;
    }
}

void complexSwitch_Case(){
    int k;
    k = 1;
    while(k<=4){
        switch(k){
            case 1:{
                printf("Welcome\n");
                printf("Welcome\n");
                break; 
            }
            case 2:{
                if(k-2){
                    printf("False\n");
                }else{
                    printf("True\n");
                }
                break;
            }
            case 3:{
                gInt1 = 3;
                while(gInt1){
                    printf("Tiga\n");
                    gInt1 = gInt1 - 1;
                }
                break;
            }
            case 4:{
                switch(k+1){
                    case 2:printf("Sally\n");break;
                    case 3:printf("TAT_-_\n");break;
                    case 4:printf("My Sniper\n");break;
                    default:printf("CoCo\n");break;
                }
                break;
            }
        }
        k = k + 1;
    }
}

void complexWhile(){
    int i,j,k;
    i = 0;
    while(i<3){
        j = 0;
        while(j<3){
            k = 0;
            while(k < 3){
                printf("At test While:%d\n",i*9 + j*3 + k+1);
                k = k + 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }
}

int _Multi_layer(int a1,int a2){
    return (a1+a2);
}

int main(){
    
    int returnScanfSymbol;
    int _giveValueToGlobalVar;
    int _testAllDefine[10];
    char _calculateFactorial;
    char _Fibonaci[10];
    int i;
    int int1,int2,int3,char1,char2,char3;

    giveValueToGlobalVar();
    testAllDefine();
    
    printf("many params1:%d\n",returnAdd(1,26,33,445,512,656,744,834,954,1021));
    printf("many params2:%d\n",returnMix('a','b','c','4','e','+','-','*','/','_'));
    
    i = 0;
    printf("The All Value Of GGG:\n");
    while(i<10){
        printf("%c\n",GGG[i]);
        i = i + 1;
    }

    
    printf("Hello Boy, you need to be careful\n");
    printf("If you input 0 ---> end the procedure\n");
    printf("If you input 1 ---> we return the number of 1+1\n");
    printf("If you input 2 ---> we return the number of 2*2\n");
    printf("If you input others ---> we carry out the next procedure\n");
    printf("Hey,Input int number to choose:\n");
    scanf("%d",&returnScanfSymbol);
    if(returnScanfSymbol == 0){
        printf("You mean to exit.Ok -_-\n");
        return 0;
    }else{
        if(returnScanfSymbol == 1){
            printf("The result 1+1 is:%d\n",1+1);
            return 0;
        }else{
            if(returnScanfSymbol == 2){
                printf("The result 2*2 is:%d\n",2*2);
                return 0;
            }else{
                printf("Next the trip.\n");
            }
        }
    }

	
	complexExpression();
    
    printf("complex expression add --- > x6:%d\n",(3*'*'+'/'-'-'+'a'*'+'+909/'_'+'/'*3+'+'*3));
    
    printf("Test scanf\n");
    scanf("%d %d %d",&int1,&int2,&int3);
    printf("int1:%d\n",int1);
    printf("int2:%d\n",int2);
    printf("int3:%d\n",int3);
	getchar();
    scanf("%c%c%c",&char1,&char2,&char3);
    printf("char1:%c\n",char1);
    printf("char2:%c\n",char2);
    printf("char3:%c\n",char3);

	scanf("%d",&int1);
	getchar();
	scanf("%c",&char1);
	scanf("%d",&int2);
	getchar();
	scanf("%c",&char2);
	scanf("%d",&int3);
	getchar();
	scanf("%c",&char3);
    printf("int1:%d\n",int1);
    printf("int2:%d\n",int2);
    printf("int3:%d\n",int3);
   	printf("char1:%c\n",char1);
    printf("char2:%c\n",char2);
    printf("char3:%c\n",char3);

    
    printf("Test printf character\n");
    printf("return100:%c\n",return100());
    printf("gCh2[1]:%c\n",gCh2['b'-'a']);
    printf("gCh1:%c\n",gCh1);
    printf("const1:%c\n",'y');
    printf("const2:%c\n",char4);

    printf("multi_layer:%d\n",_Multi_layer(Fibonaci(calculateFactorial(3)),_Multi_layer(_Multi_layer(_Multi_layer(2333,6666+'a'),calculateFactorial(7)),Fibonaci(8))));

    complexIf_Else();
   
    complexWhile();

    complexSwitch_Case();
    printf("Congratulations,you passed all tests.\n");
    
    return 0;
}
