/*
** @author:止水清潇menghuanlater
** @date:2017-11-22
** @location:BUAA
*/
//实现文件
#include "LexicalAnalysis.h"
#include <iostream>
#include <fstream>//文件操作
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;
//初始化
LexicalAnalysis::LexicalAnalysis(const Error & error):myError(error){
    fileLength = 0;
    index = 0;
    globalChar = '\0';
    globalNumber = 0;
    lineCount = 1;
    finish = false;
    isNextSym = false;
}
//文件读取
void LexicalAnalysis::readFile(string FilePath){
    ifstream fileIn(FilePath,ios::in);
    if(!fileIn){
		cout<<"Sorry,File Not exist."<<endl;
		exit(EXIT_SUCCESS);
    }
    //读取文件全部内容到fileContents中
	istreambuf_iterator<char>beg(fileIn), end;
	fileContents = string(beg, end);
	fileIn.close();
    fileLength = fileContents.size();
	//检测文本是否存在中文日文...--->char值小于-1
	for(int i=0;i<fileLength;i++){
		if(fileContents[i]<-1){
			cout<<"Found not ascii char\'s existence,the file may conclude Chinese,Japanese or other char.Please solve this problem."<<endl;
			exit(EXIT_SUCCESS);
		}
	}
    //输出提示
    cout<<"read file succeed,the file size is: "<<fileLength<<" Bytes."<<endl;
}
//返回true代表读取了下一个单词,返回false代表读取完毕
bool LexicalAnalysis::nextSym(){
    //首先判断实际需不需要读取
    if(isNextSym){
        isNextSym = false;
        return true;
    }
    //index已经超出内容范围,返回false
    if(index >= fileLength){
        finish = true;////此时代表已经完全分析完所有的词法成分,而且预读的也已经全部处理了
        return false;
    }
    //否则,进行单词读取
	char Array[maxWordLength] = {'\0'};
    char temp = getChar();
	//空白字符跳过
	while(isspace(temp)){
        if(temp=='\n')//换行
            lineCount++;
		temp = getChar();
    }
	//读到文件结束
	if(temp==EOF){
        finish = true;//此时代表已经完全分析完所有的词法成分,而且预读的也已经全部处理了
		return false;
	}
	if(isalpha(temp) || temp=='_'){//标识符或者保留字
		while(isalnum(temp) || temp=='_'){
            Array[strlen(Array)] = temp;
            temp = getChar();
        }
		if(temp != EOF){
            retract();
		}
        int resultValue = reserver(Array);
        if(resultValue == 0){
            globalSymbol = IDENTIFIER;
            //全体小写化,统一处理
            toLow(Array);
            globalString = Array;
        }else{
            globalSymbol = (SymbolCode)(resultValue-1);
        }
    }else if(isdigit(temp)){//数字
        while(isdigit(temp)){
            Array[strlen(Array)] = temp;
            temp = getChar();
        }
        if(temp != EOF)
            retract();
        globalNumber = atoi(Array);
        globalSymbol = INTNUM;
    }else if(temp=='+'){
        globalChar = '+';
        globalSymbol = ADD;
    }else if(temp=='-'){
        globalChar = '-';
        globalSymbol = SUB;
    }else if(temp=='*'){
        globalChar = '*';
        globalSymbol = MULT;
    }else if(temp=='/'){
        globalChar = '/';
        globalSymbol = DIV;
    }else if(temp=='<'){
        temp = getChar();
        if(temp!='='){
            globalChar = '<';
            globalSymbol = LESS;
            retract();
        }else{
            globalString = "<=";
            globalSymbol = LESSEQ;
        }
    }else if(temp=='>'){
        temp = getChar();
        if(temp!='='){
            globalChar = '>';
            globalSymbol = MORE;
            retract();
        }else{
            globalString = ">=";
            globalSymbol = MOREEQ;
        }
    }else if(temp=='!'){
        temp = getChar();
        if(temp!='='){
            myError.LexicalAnalysisError(NotEqualSymIllegal,lineCount);
            while(temp!='\n' && temp!=';'){
                temp = getChar();
            }
            if(temp=='\n')
                retract();
            nextSym();
            return false;
        }else{
            globalString = "!=";
            globalSymbol = NOTEQ;
        }
    }else if(temp==','){
        globalChar = ',';
        globalSymbol = COMMA;
    }else if(temp==':'){
        globalChar = ':';
        globalSymbol = COLON;
    }else if(temp==';'){
        globalChar = ';';
        globalSymbol = SEMI;
    }else if(temp=='('){
        globalChar = '(';
        globalSymbol = LSBRACKET;
    }else if(temp==')'){
        globalChar = ')';
        globalSymbol = RSBRACKET;
    }else if(temp=='['){
        globalChar = '[';
        globalSymbol = LMBRACKET;
    }else if(temp==']'){
        globalChar = ']';
        globalSymbol = RMBRACKET;
    }else if(temp=='{'){
        globalChar = '{';
        globalSymbol = LBBRACKET;
    }else if(temp=='}'){
        globalChar = '}';
        globalSymbol = RBBRACKET;
    }else if(temp=='='){
        temp = getChar();
        if(temp!='='){
            globalChar = '=';
            globalSymbol = ASSIGN;
            retract();
        }else{
            globalString = "==";
            globalSymbol = EQUAL;
        }
    }else if(temp=='\''){
        temp = getChar();
        if(temp=='+'||temp=='-'||temp=='*'||temp=='/'|| temp=='_'||
            (temp>='A' && temp<='Z') || (temp>='a' && temp<='z') || (temp>='0' && temp<='9')){
            globalChar = temp;
            temp = getChar();
            if(temp!='\''){
                myError.LexicalAnalysisError(SingleCharIllegal,lineCount);
                while(temp!='\n' && temp!=';'){
                    temp = getChar();
                }
                if(temp=='\n')
                    retract();
                nextSym();
                return false;
            }
            globalSymbol = CHAR;
        }else{
            myError.LexicalAnalysisError(SingleCharIllegal,lineCount);
            while(temp!='\n' && temp!=';'){
                temp = getChar();
            }
            if(temp=='\n')
                retract();
            nextSym();
            return false;
        }
    }else if(temp=='"'){
        temp = getChar();
        while(temp==CHAR1 || temp==CHAR2 || (temp>=CHAR3 && temp<=CHAR4)){
            Array[strlen(Array)] = temp;
            temp = getChar();
        }
        if(temp=='"'){
            globalString = Array;
            globalSymbol = STRING;
        }else{
            myError.LexicalAnalysisError(StringIllegal,lineCount);
            while(temp!='\n' && temp!=';'){
                temp = getChar();
            }
            if(temp=='\n')
                retract();
            nextSym();    
            return false;
        }
    }else{
        myError.LexicalAnalysisError(ContentIllegal,lineCount);
        return false;
    }
    return true;
}
//查找保留字
int LexicalAnalysis::reserver(char* target){
    for(int i=0;i<KEY_NUM;i++){
        if(_stricmp(keyWordsArr[i],target)==0){
            return (i+1);//为了与0区分开来
        }
    }
    return 0;
}
//小写化字母
void LexicalAnalysis::toLow(char* target){
    for(;*target!='\0';){
        if(*target>='A' && *target<='Z')
            *target = *target + 'a' - 'A';
        target++;
    }
}
//跳读函数
void LexicalAnalysis::skipRead(char end){
    if(globalChar != end){
        char x = getChar();
        while(!(x==EOF || x==end || x=='\n'))
            x = getChar();
        if(x == '\n'){
            retract();
        }
    }
    nextSym();
}