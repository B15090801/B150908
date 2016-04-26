/*li12_1.c����ȫ�ļ�2*/
void printTimetableCourse(char *s,double m[1][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
                                                   /*0��1��2�ֱ��Ӧ�ʱ�䡢���ʱ�䡢ƽ��ʱ��*/
{                 
    printf(s);                                  /*�����s����������ʱ�����ʾ��Ϣ*/
	printf("%10.2lf",m[1][k]);
	printf("\n");
}

void countManage(Owner own[],int n)               /*�ú������ͣ����Ϣͳ�ƹ���*/
{
		int choice;
		double timetable[1][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuTimetable(timetable,own,n);                 /*���ô˺������ʱ�䡢���ʱ�䡢ƽ��ʱ��*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printTimetableCourse("�ʱ����:\n",timetable,0);  /*����ʱ��*/
				      break;
				case 2:   printTimetableCourse("���ʱ����:\n",timetable,1);  /*������ʱ��*/
				      break;
				case 3:   printTimetableCourse("ƽ��ʱ����:\n",timetable,2);  /*���ƽ��ʱ��*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Owner own[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
	Owner s;
	do
	{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a owner\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ�����ĳ��ƺ�*/
					  break;
				case 2:   printf("Input a owner\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ����������*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchOwn(own,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
						 printOwn(&own[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
					printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	   
	}while (choice);
}

int runMain(Owner own[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
	switch(choice)
	{
	case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
		printOwn(own,n);          /*�����ƺ�����˳��������м�¼*/
		break;
	case 2: n=baseManage(own,n);    /* 2. ������Ϣ����*/
		break;
	case 3: informationManage(own,n);     /* 3. ������Ϣ����*/
		break;
	case 4: countManage(own,n);     /* 4. ͣ����Ϣͳ��*/
		break;
	case 5: searchManage(own,n);     /* 5. ����������ѯ*/
		break;
	case 0: break;
	}
	return n;
}

int main( )
{
	Owner own[NUM];                /*����ʵ��һά����洢������¼*/
	int choice,n;
	n=readFile(own);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	{
		n=createFile(own);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
	}	 	 
	do
	{
		menu();                      /*��ʾ���˵�*/
		printf("Please input your choice: ");
		scanf("%d",&choice);
		if (choice>=0&&choice<=5)
			n=runMain(own,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
		else 
			printf("error input,please input your choice again!\n");
	} while (choice); 
	saveFile(own,n);                   /*����������ļ�*/
	return 0;
}
