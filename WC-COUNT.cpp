#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void CharacterCount(char File[])              //字符数统计函数
{
        int count=0;            //字符数计数变量 
        char c;
        FILE *f=fopen(File,"r");
        if(f==NULL){
                printf("打开文件出错，请重试\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if(isspace(c)==0)   //测试参数是否是空格、制表符或换行符 
                ++count;
        }
        fclose(f);
        printf("此文件的字符数为:%d\n",count);
        system("pause");
}

void WordCount(char File[]){                //单词数统计函数 
        int count=0;            //单词数计数变量 
        char c;
        FILE *f=fopen(File,"r");
        if(f==NULL){
                printf("打开文件出错，请重试\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
                        while((c>='A'&&c<='Z')||(c>='a'&&c<='z'))       //通过检测是否是连续字符对单词计数 
                        c=fgetc(f);
                        count++; 
                }
        }
        fclose(f);
        printf("此文件的单词数为:%d\n",count);
        system("pause");
}

void LineCount(char File[]){
        int count=0;            //行数计数变量 
        char c[100];
        FILE *f=fopen(File,"r");
        if(f==NULL){
                printf("打开文件出错，请重试\n");
                return ;
        }
        getc(f);        
        if(feof(f));      //考虑空文件的特殊情况 
		else{
			rewind(f);    //将光标跳回到文件开头 
			while(!feof(f)){
                fgets(c,100,f);
                if(c[0]=='\0')    break;  //每行开头是'\0'则是空行 
                count++; 
		   } 
    	}
        fclose(f);
        printf("此文件的行数为:%d\n",count);
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
                case 'c': CharacterCount(file);
                          break;
                case 'w': WordCount(file);
                          break;
                case 'l': LineCount(file);
                          break;
                default : break;                                
        }
    }
} 

