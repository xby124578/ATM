#include<stdio.h>

struct Account
{
	char name[100];
	char tel[12];
	char idCard[19];
	char username[100];
	char password[7];
	float money;
};

typedef struct Account Account;

void showChinese()
{
	printf("��1������\n");
	printf("��2����¼\n");
}

void showEnglish()
{
	printf("Press 1��Sign Up\n");
	printf("Press 2��Sign In\n");
}

Account a;
void signUp()
{
	printf("���������������\n");
	scanf("%s",a.name); 
	
	printf("��������ĵ绰��\n");
	scanf("%s",a.tel); 
	
	printf("������������֤��\n");
	scanf("%s",a.idCard); 
	
	printf("�������ʺţ�\n");
	scanf("%s",a.username); 
	
	printf("���������룺\n");
	scanf("%s",a.password);
	
	a.money=0.0f;
	
	printf("��ϲ�㣬���ע�ᣡ\n");
} 
void englishsignUp()
{
	printf("Please enter your name��\n");
	scanf("%s",a.name); 
	
	printf("please enter your tel��\n");
	scanf("%s",a.tel); 
	
	printf("please enter your idcard��\n");
	scanf("%s",a.idCard); 
	
	printf("please enter your account��\n");
	scanf("%s",a.username); 
	
	printf("please enter your password��\n");
	scanf("%s",a.password);
	
	a.money=0.0f;
	
	printf("finish it\n");
}

void signIn()
{
	printf("�����������˺ţ�\n");
	scanf("%s",&username);
	if(username==a.username)
	{
         printf("�������������룺\n");
	     scanf("%s",&passeord);
		 if(passeord==a.passeord)
		 {
			 printf("��½�ɹ�\n");
		 }
		 else
		 {
			 printf("�������\n");
			 break;
		 }
	}
	else
	{
		 printf("�˺Ŵ���,�����½���ϵͳ\n");
		 break��
	}
		


} 

void printAccount(Account a)
{
	printf("%s %s %s %s %f\n",a.name,a.tel,a.idCard,a.username,a.money);
}

int main()
{
	printf("��1��������ʾ\n");
	printf("Press 2��Show English\n");
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		showChinese(); 
	}
	else if(n==2) 
	{
		showEnglish();
	}
	
	int k;
	scanf("%d",&k);
	if(k==1)
	{
		if(n==2)
		{
			englishsignUp();
			printAccount(a);
			
		}
		else if(n==1)
		{
			signUp();
			printAccount(a);
		}
	}
	else if(k==2)
	{
		signIn();
	} 
	
	return 0;
}
