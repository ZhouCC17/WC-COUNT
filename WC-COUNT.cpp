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
        fclose(f);
        printf("���ļ��ĵ�����Ϊ:%d\n",num);
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
                       
void Other(char File[]){    //�������ܺ��� 
        int num1=0;        //ע��������
		int num2=0;       //��������
		int num3=0;       //���������� 
        char c[100];
        FILE *f=fopen(File,"r");
        if(!f){
                printf("���ļ����������ԣ�\n");
                return ;
        }
        while(!feof(f)){
                fgets(c,100,f);
                if(strstr(c,"//"))     //ע�Ͳ�ͬ��ʽ�Ĵ�����ʽ 
				num1++;
				else if(strstr(c,"/*")) {
					do{
						num1++;
						fgets(c,100,f);
					}while(!strstr(c,"*/"));
					num1++;	
				}
                else if(strlen(c)<=2)  //ͳ���ַ���ȷ���Ƿ��ǿ��� 
                num2++;
                else
                num3++;    //��������������Ϊ������ 
            }
        fclose(f);
        printf("���ļ���ע��������Ϊ:%d\n",num1);
        printf("���ļ��Ŀ�������Ϊ:%d\n",num2);
        printf("���ļ��Ĵ���������Ϊ:%d\n",num3);
        system("pause");
    }


int main()                     //������ 
{
    char parameter;               //������� 
    char file[50];              //��¼�ļ���ַ
    while(1)
    {
        printf("====================================\n");
        printf("      WC-COUNT���ܲ������£�\n");
        printf("wc.exe-c=========>      ͳ���ַ���\n");
        printf("wc.exe-w=========>      ͳ�Ƶ�����\n");
        printf("wc.exe-l=========>      ͳ������\n");
        printf("wc.exe-o=========>      ͳ���������\n");
        printf("====================================\n");
		printf("�������������wc.exe-");
        scanf(" %c",&parameter);
        while(parameter!='c'&&parameter!='w'&&parameter!='l'&&parameter!='o'){
            printf("���������������������:");
            scanf(" %c",&parameter); 
        }
        printf("�������ļ���ַ:");
        scanf("%s",file);
        switch(parameter){          //����ѡ��ṹ���д��� 
                case 'c': Character(file);   break;
                case 'w': Word(file);    break;
                case 'l': Line(file);    break;
                case 'o': Other(file);   break;
                default :   break;                                
        }
    }
} 

