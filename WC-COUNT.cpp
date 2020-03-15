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
        printf("此文件的单词数为:%d\n",num);
        fclose(f);
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

int main()
{
    char parameter;               //命令参数 
    char file[50];              //记录文件地址
    while(1)
    {
        printf("==================================\n");
        printf("      WC-COUNT功能参数如下：\n");
        printf("wc.exe-c=========>      统计字符数\n");
        printf("wc.exe-w=========>      统计单词数\n");
        printf("wc.exe-l=========>      统计行数\n");
        printf("==================================\n");
		printf("请输入命令参数wc.exe-");
        scanf(" %c",&parameter);
        while(parameter!='c'&&parameter!='w'&&parameter!='l'){
            printf("输入参数出错，请重新输入:");
            scanf(" %c",&parameter); 
        }
        printf("请输入文件地址:");
        scanf("%s",file);
        switch(parameter){          //采用选择结构进行处理 
                case 'c': Character(file);   break;
                case 'w': Word(file);    break;
                case 'l': Line(file);    break;
                default :   break;                                
        }
    }
} 

