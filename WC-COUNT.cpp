#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void Character(char File[])              //字符数统计函数
{
        char c;
		int num=0;            //字符数计数变量 
        FILE *f=fopen(File,"r");
        if(!f){
                printf("打开文件出错，请重试!\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if(!isspace(c))   //测试参数是否是空格、制表符或换行符 
                num++;
        }
        printf("此文件的字符数为:%d\n",num);
        fclose(f);
        system("pause");
}

void Word(char File[]){                //单词数统计函数 
        char c;
        int num=0;            //单词数计数变量 
        FILE *f=fopen(File,"r");
        if(!f){
                printf("打开文件出错，请重试!\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
                	num++;  
                   do{
                   	c=fgetc(f);
				   }while((c>='A'&&c<='Z')||(c>='a'&&c<='z'));      //通过检测是否是连续字符对单词计数 
                }
        }
        fclose(f);
        printf("此文件的单词数为:%d\n",num);
        system("pause");
}

void Line(char File[]){
	    char c[100];
        int num=0;            //行数计数变量 
        FILE *f=fopen(File,"r");
        if(!f){
                printf("打开文件出错，请重试!\n");
                return ;
        }
        getc(f);        
        if(feof(f));      //考虑空文件的特殊情况 
		else{
			rewind(f);    //将光标跳回到文件开头 
			while(!feof(f)){
                fgets(c,100,f);
                if(c[0]=='\0')    break;  //每行开头是'\0'则是空行 
                num++; 
		   } 
    	}
        fclose(f);
        printf("此文件的行数为:%d\n",num);
        system("pause");
}
                       
void Other(char File[]){    //其他功能函数 
        int num1=0;        //注释行行数
		int num2=0;       //空行行数
		int num3=0;       //代码行行数 
        char c[100];
        FILE *f=fopen(File,"r");
        if(!f){
                printf("打开文件出错，请重试！\n");
                return ;
        }
        while(!feof(f)){
                fgets(c,100,f);
                if(strstr(c,"//"))     //注释不同形式的处理形式 
				num1++;
				else if(strstr(c,"/*")) {
					do{
						num1++;
						fgets(c,100,f);
					}while(!strstr(c,"*/"));
					num1++;	
				}
                else if(strlen(c)<=2)  //统计字符数确认是否是空行 
                num2++;
                else
                num3++;    //不是其他种类则为代码行 
            }
        fclose(f);
        printf("此文件的注释行行数为:%d\n",num1);
        printf("此文件的空行行数为:%d\n",num2);
        printf("此文件的代码行行数为:%d\n",num3);
        system("pause");
    }


int main()                     //主函数 
{
    char parameter;               //命令参数 
    char file[50];              //记录文件地址
    while(1)
    {
        printf("====================================\n");
        printf("      WC-COUNT功能参数如下：\n");
        printf("wc.exe-c=========>      统计字符数\n");
        printf("wc.exe-w=========>      统计单词数\n");
        printf("wc.exe-l=========>      统计行数\n");
        printf("wc.exe-o=========>      统计其他情况\n");
        printf("====================================\n");
		printf("请输入命令参数wc.exe-");
        scanf(" %c",&parameter);
        while(parameter!='c'&&parameter!='w'&&parameter!='l'&&parameter!='o'){
            printf("输入参数出错，请重新输入:");
            scanf(" %c",&parameter); 
        }
        printf("请输入文件地址:");
        scanf("%s",file);
        switch(parameter){          //采用选择结构进行处理 
                case 'c': Character(file);   break;
                case 'w': Word(file);    break;
                case 'l': Line(file);    break;
                case 'o': Other(file);   break;
                default :   break;                                
        }
    }
} 

