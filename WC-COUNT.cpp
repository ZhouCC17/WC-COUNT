#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void Character(char File[])              //�ַ���ͳ�ƺ���
{
        int count=0;            //�ַ����������� 
        char c;
        FILE *f=fopen(File,"r");
        if(!f){
                printf("���ļ�����������\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if(!isspace(c))   //���Բ����Ƿ��ǿո��Ʊ�����з� 
                count++;
        }
        fclose(f);
        printf("���ļ����ַ���Ϊ:%d\n",count);
        system("pause");
}

void Word(char File[]){                //������ͳ�ƺ��� 
        int count=0;            //�������������� 
        char c;
        FILE *f=fopen(File,"r");
        if(!f){
                printf("���ļ�����������\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
                	count++;  
                   do{
                   	c=fgetc(f);
				   }while((c>='A'&&c<='Z')||(c>='a'&&c<='z'));      //ͨ������Ƿ��������ַ��Ե��ʼ��� 
                }
        }
        fclose(f);
        printf("���ļ��ĵ�����Ϊ:%d\n",count);
        system("pause");
}

void Line(char File[]){
        int count=0;            //������������ 
        char c[100];
        FILE *f=fopen(File,"r");
        if(!f){
                printf("���ļ�����������\n");
                return ;
        }
        getc(f);        
        if(feof(f));      //���ǿ��ļ���������� 
		else{
			rewind(f);    //��������ص��ļ���ͷ 
			while(!feof(f)){
                fgets(c,100,f);
                if(c[0]=='\0')    break;  //ÿ�п�ͷ��'\0'���ǿ��� 
                count++; 
		   } 
    	}
        fclose(f);
        printf("���ļ�������Ϊ:%d\n",count);
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
                case 'c': Character(file);
                          break;
                case 'w': Word(file);
                          break;
                case 'l': Line(file);
                          break;
                default : break;                                
        }
    }
} 

