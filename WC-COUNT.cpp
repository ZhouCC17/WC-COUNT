#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void Character(char File[])              //�ַ���ͳ�ƺ���
{
        char c;
		int num=0;            //�ַ����������� 
        FILE *f=fopen(File,"r");
        if(!f){
                printf("���ļ�����������!\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if(!isspace(c))   //���Բ����Ƿ��ǿո��Ʊ�����з� 
                num++;
        }
        printf("���ļ����ַ���Ϊ:%d\n",num);
        fclose(f);
        system("pause");
}

void Word(char File[]){                //������ͳ�ƺ��� 
        char c;
        int num=0;            //�������������� 
        FILE *f=fopen(File,"r");
        if(!f){
                printf("���ļ�����������!\n");
                return ;
        }
        while((c=fgetc(f))!=EOF)
        {
                if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
                	num++;  
                   do{
                   	c=fgetc(f);
				   }while((c>='A'&&c<='Z')||(c>='a'&&c<='z'));      //ͨ������Ƿ��������ַ��Ե��ʼ��� 
                }
        }
        printf("���ļ��ĵ�����Ϊ:%d\n",num);
        fclose(f);
        system("pause");
}

void Line(char File[]){
	    char c[100];
        int num=0;            //������������ 
        FILE *f=fopen(File,"r");
        if(!f){
                printf("���ļ�����������!\n");
                return ;
        }
        getc(f);        
        if(feof(f));      //���ǿ��ļ���������� 
		else{
			rewind(f);    //��������ص��ļ���ͷ 
			while(!feof(f)){
                fgets(c,100,f);
                if(c[0]=='\0')    break;  //ÿ�п�ͷ��'\0'���ǿ��� 
                num++; 
		   } 
    	}
        fclose(f);
        printf("���ļ�������Ϊ:%d\n",num);
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
                case 'c': Character(file);   break;
                case 'w': Word(file);    break;
                case 'l': Line(file);    break;
                default :   break;                                
        }
    }
} 

