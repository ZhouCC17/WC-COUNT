#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void CharacterCount(char File[])              //�ַ���ͳ�ƺ���
{
        int count=0;            //�ַ����������� 
        char ch;
        FILE *f=fopen(File,"r");
        if(f==NULL){
                printf("���ļ�����������\n");
                return ;
        }
        while((ch=fgetc(f))!=EOF)
        {
                if(isspace(ch)==0)   //���Բ����Ƿ��ǿո��Ʊ�����з� 
                ++count;
        }
        fclose(f);
        printf("���ļ����ַ���Ϊ:%d\n",count);
        system("pause");
}

void WordCount(char File[]){                //������ͳ�ƺ��� 
        int count=0;            //�������������� 
        char ch;
        FILE *f=fopen(File,"r");
        if(f==NULL){
                printf("���ļ�����������\n");
                return ;
        }
        while((ch=fgetc(f))!=EOF)
        {
                if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                        while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))       //ͨ������Ƿ��������ַ��Ե��ʼ��� 
                        ch=fgetc(f);
                        ++count;
                }
        }
        fclose(f);
        printf("���ļ��ĵ�����Ϊ:%d\n",count);
        system("pause");
}

void LineCount(char File[]){
        int count=0;            //������������ 
        char ch[500];
        FILE *f=fopen(File,"r");
        if(f==NULL){
                printf("���ļ�����������\n");
                return ;
        }
        getc(f);        
        if(feof(f));      //���ǿ��ļ���������� 
		else{
			rewind(f);    //��������ص��ļ���ͷ 
			while(!feof(f)){
                fgets(ch,500,f);
                if(ch[0]=='\0')    break;  //ÿ�п�ͷ��'\0'���ǿ��� 
                count++; 
		   } 
    	}
        fclose(f);
        printf("�ļ�������Ϊ:%d\n",count);
        system("pause");
}

int main()
{
    char parameter;               //������� 
    char file[50];              //��¼�ļ���ַ
    while(1)
    {
        printf("==================================\n");
        printf("      WC-COUNT���ܲ������£�\n");
        printf("wc.exe-c=========>      ͳ���ַ���\n");
        printf("wc.exe-w=========>      ͳ�Ƶ�����\n");
        printf("wc.exe-l=========>      ͳ������\n");
        printf("==================================\n");
		printf("�������������wc.exe-");
        scanf(" %c",&parameter);
        while(parameter!='c'&&parameter!='w'&&parameter!='l'){
            printf("���������������������:");
            scanf(" %c",&parameter); 
        }
        printf("�������ļ���ַ:");
        scanf("%s",file);
        switch(parameter){          //����ѡ��ṹ���д��� 
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

