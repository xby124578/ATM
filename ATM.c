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
	printf("按1，开户\n");
	printf("按2，登录\n");
}

void showEnglish()
{
	printf("Press 1，Sign Up\n");
	printf("Press 2，Sign In\n");
}

Account a;
void signUp()
{
	printf("请输入你的姓名：\n");
	scanf("%s",a.name); 
	
	printf("请输入你的电话：\n");
	scanf("%s",a.tel); 
	
	printf("请输入你的身份证：\n");
	scanf("%s",a.idCard); 
	
	printf("请设置帐号：\n");
	scanf("%s",a.username); 
	
	printf("请设置密码：\n");
	scanf("%s",a.password);
	
	a.money=0.0f;
	
	printf("恭喜你，完成注册！\n");
} 
void englishsignUp()
{
	printf("Please enter your name：\n");
	scanf("%s",a.name); 
	
	printf("please enter your tel：\n");
	scanf("%s",a.tel); 
	
	printf("please enter your idcard：\n");
	scanf("%s",a.idCard); 
	
	printf("please enter your account：\n");
	scanf("%s",a.username); 
	
	printf("please enter your password：\n");
	scanf("%s",a.password);
	
	a.money=0.0f;
	
	printf("finish it\n");
}

void signIn()
{   
	char username,password;
	printf("请输入您的账号：\n");
	scanf("%s",&username);
	if(username==a.username)
	{
         printf("请输入您的密码：\n");
	     scanf("%s",&passeord);
		 if(password==a.password)
		 {
			 printf("登陆成功\n");
                         printAccount(a);
			 return 0；
		 }
		 else
		 {
			 printf("密码错误\n");
			 return 0；
		 }
	}
	else
	{
		 printf("账号错误,请重新进入系统\n");
		 return 0；
	}
		

void englishsignIn()
{   
	char username,password;
	printf("please enter your account：\n");
	scanf("%s",&username);
	if(username==a.username)
	{
         printf("please enter your password：\n");
	     scanf("%s",&passeord);
		 if(password==a.password)
		 {
			 printf("Login success!\n");
                         return 0；
			
		 }
		 else
		 {
			 printf("wrong paswerd!\n");
			 return 0；
		 }
	}
	else
	{
		 printf("wrong accounts!\n");
		 return 0；
	}
		
} 

void printAccount(Account a)
{
	printf("%s %s %s %s %f\n",a.name,a.tel,a.idCard,a.username,a.money);
}

int main()
{
	printf("按1，中文显示\n");
	printf("Press 2，Show English\n");
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
		if(n==2)
		{
			englishsignIn();	
		}
		else if(n==1)
		{
			signIn();
		}

		
	} 
	
	return 0;
}
