/*li12_1.c����ȫ�ļ�1*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"owner.h"

void printHead( )      /*��ӡ������Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%10s\n","���ƺ�","����","�Ա�","����ʱ��","��ʱ��");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ������Ϣ���� ********\n");
		printf("******** 4. ͣ����Ϣͳ�� ********\n");
		printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ��ӳ�����Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��������Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸ĳ�����Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuInformation( )     /*3��������Ϣ����˵�����*/
{
		printf("@@@@@@@@ 1. ����ͣ����ʱ�� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4��ͣ����Ϣͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ����ͣ���ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 2. ����ͣ�����ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 3. ����ͣ��ƽ��ƽ��ʱ�� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. �����ƺŲ�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Owner own[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*�����ƺŽ��в���ɾ���޸ģ����ƺŲ����ظ�*/
{  
		int choice,t,find[NUM];
     Owner s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readOwn(&s,1);       /*����һ��������ĳ�����¼*/
					 n=insertOwn(own,n,s);   /*���ú������복����¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ���ĳ������ƺ�*/
					 n=deleteOwn(own,n,s);   /*���ú���ɾ��ָ�����ƺŵĳ�����¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵĳ������ƺ�*/
				      t=searchOwn(own,n,s,1,find) ; /*���ú�������ָ�����ƺŵĳ�����¼*/
				      if (t)                 /*����ó��ƺŵļ�¼����*/
					 {
						  readOwn(&s,1);   /*����һ�������ĳ�����¼��Ϣ*/
					      own[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ó��ƺŵļ�¼������*/ 
 printf("this owner is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void informationManage(Owner own[],int n)          /*�ú�����ɳ�����Ϣ������*/
{  
	int choice;
	do
	{
		menuInformatiom( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(own,n);         /*�����г�������ͣ��ʱ��*/
				break;		
			case 0:   break;
		}
	}while(choice);
}