#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"time.h"
#include"cstdio"
#include"windows.h"
#include"conio.h"


//��������
void Main1();
void InitTraData();
void SignUp(); 
void SignIn();   
void Menu(); 
void SaveMoney(); 
void SaveMoney1();
void WithdrawMoney();  
void WithdrawMoney1(); 
void TransferMoney();   
void TransferMoney1();  
void Inquire();   
void InquireBalance(); 
void InqInformation();  
void InqRecord(); 
void ChangeInformation();  
void ChangeUserName();   
void ChangePhone();   
void ChangePassword(); 
void getPassword(char a[], int b);  
void SysTime();       
void SaveUserData();    
void SaveTransactionData();     
void IniUser_Data();     
void SetPassword();           
void SetPhoneNum();          
void SaveTransaction();      
void WithdrawTransaction();    
void TransferTransaction();      
void HandTransaction();        
void PrintTransaction();   
float HandMoney; 
int QK = 0, CK = 0, ZZ = 0;


struct Account
{
	char name[100];
	char AccountNum[50];
	char PhoneNum[12];
	char password[10];
	float balance;

	struct Account* next;
};

struct Trade
{
	char TAccountNum[50];
	char Time[100];
	char Operation[100];
	float Money;

	struct Trade* Tnext;
};

typedef struct Account Account;
typedef struct Trade Trade;
Account* Pset = (Account*)malloc(sizeof(Account));
Account* head = NULL;
Account* tail = NULL;
Account* curAccount;
Account* curAccountO;
Account ZX;

Trade* THead = NULL;
Trade* TTail = NULL;
Trade* TCurAccount;
Trade TA;


int FindACC(Account IV1)//��¼ʱ���ҵ�ǰ�˻�
{
	Account* curP = head;
	Trade* TcurP = THead;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindPassword(Account IV1)//��¼ʱ���ҵ�ǰ�˻�����
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0 && strcmp(curP->password, IV1.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC2(Account IV)//�����Ƿ������˻�
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC3(Account TT)//����ת���˻�
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curAccount->AccountNum, TT.AccountNum) == 0)
		{
			int a, b = 0;
			printf("\n����\n");
			while (b < 3)
			{
				printf("\n\n1.��������Է��˻�����");
				printf("\n\n2.�������˵�");
				printf("\n\n0.�˳�ϵͳ\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					TransferMoney();
					b = 3;
					break;
				case 2:
					system("cls");
					Menu();
					b = 3;
					break;
				case 0:
					b = 3;
					SaveUserData();
					exit(0);
				default:
					b++;
					break;
				}
			}
		}
		else if (strcmp(curP->AccountNum, TT.AccountNum) == 0)
		{
			curAccountO = curP;//��ǰת�˶����˻�
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}


int Main()
{
	SysTime();
	IniUser_Data();
	InitTraData();
	Main1();
	SaveUserData();
	SaveTransactionData();
	return 0;
}

void main1()
{
	printf("\n�����Ӧѡ�����֣����س���ȷ�ϡ�\n\t\n");
	int a, b = 0;
	while (b != 1)
	{
		printf("\n\t1.�û���¼\n");
		printf("\t2.�û�ע��\n");
		printf("\t0.�˳�\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			SignIn();
			break;
		case 2:
			SignUp();
			break;
		case 0:
			exit(0);
		default:
			b = 1;
			system("cls");
			printf("\n���������밴����ʾ�ٴ�����!");
			break;
		}
	}
}

void SignIn()//��¼
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ
	{
		Account IV1;//�˻��м����1
		printf("\n\t�����˺�\n");
		scanf("%s", IV1.AccountNum);
		system("cls");
		if (FindACC(IV1))
		{
			while (n < 3)//3����������뽫�˳�ϵͳ
			{
				printf("\n\t��������\n");
				char storePassword[10] = { '\0' };    //�洢�û����������
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");
				if (FindPassword(IV1))
				{
					m = 3;
					n = 3;
					Menu();
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\t���˺��ѱ�����\n");
						strcpy(curAccount->password, "abc");;
						break;
					}
					else
					{
						printf("\n\t�������\n");
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\tû�в��ҵ����û�!����������\n");
			if (m == 3)
			{
				printf("\n\t�������˳�ϵͳ\n");
				SaveUserData();
				exit(0);
			}
		}
	}
}

void Menu()//���˵�
{
	int a, b = 1;
	while (b)
	{
		b = 0;
		printf("\n\t1.���\n");
		printf("\t2.ȡ��");
		printf("\n\t3.ת��\n");
		printf("\t4.��ѯ\n");
		printf("\t5.�޸�����\n");
		printf("\t0.�˳�ϵͳ\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			SaveMoney();
			break;
		case 2:
			system("cls");
			WithdrawMoney();
			break;
		case 3:
			system("cls");
			TransferMoney();
			break;
		case 4:
			system("cls");
			Inquire();
			break;
		case 5:
			system("cls");
			ChangeInformation();
			break;
		case 0:
			system("cls");
			SaveUserData();
			exit(0);
			break;
		default:
			system("cls");
			printf("\n�������\n");
			b = 1;
			break;
		}
	}
}

void SaveTransaction()//����¼
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "���");
		TP->Money = TA.Money;

		SaveTransactionData();
	}
}

void WithdrawTransaction()//ȡ���¼
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "ȡ��");
		TP->Money = TA.Money;
		SaveTransactionData();
	}
}

void TransferTransaction()//ת�˼�¼
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "ת��");
		TP->Money = TA.Money;
		SaveTransactionData();
	}
	Trade* TPi = (Trade*)malloc(sizeof(Trade));
	TPi->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TPi;
		TTail = TPi;
	}
	else
	{
		TTail->Tnext = TPi;
		TTail = TPi;
		strcpy(TPi->TAccountNum, curAccountO->AccountNum);
		strcpy(TPi->Time, TA.Time);
		strcpy(TPi->Operation, "ת��");
		TPi->Money = -TA.Money;
		SaveTransactionData();
	}
}

void HandTransaction()//�����Ѽ�¼
{
	Trade* HP = (Trade*)malloc(sizeof(Trade));
	HP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = HP;
		TTail = HP;
	}
	else
	{
		TTail->Tnext = HP;
		TTail = HP;
		strcpy(HP->TAccountNum, curAccount->AccountNum);
		strcpy(HP->Time, TA.Time);
		strcpy(HP->Operation, "������");
		HP->Money = -HandMoney;
		SaveTransactionData();
	}
}

void PrintTransaction()//��ӡ��ˮ
{
	int a;
	Trade* HcurP = THead;
	while (HcurP != NULL)//���׼�¼
	{
		if (strcmp(curAccount->AccountNum, HcurP->TAccountNum) == 0)
		{
			a++;
			TCurAccount = HcurP;
			printf("\n\tʱ�䣺%s\t���ࣺ%s\t��%.2f\n", TCurAccount->Time, TCurAccount->Operation, TCurAccount->Money);
		}
		HcurP = HcurP->Tnext;
	}
	if (a == 0)
	{
		printf("\n\t�޽��׼�¼\n\n");
	}
}

void SaveMoney()//���
{
	int a;
	QK = 0;
	printf("\t��ܰ��ʾ�����ʴ��ó���10000��\n");
	printf("\n\n\t��������Ҫ����Ľ�\n");
	scanf("%d", &a);
	if (a > 10000)
	{
		system("cls");
		printf("\n\t���ʴ��ó���10000��\n");
		SaveMoney1();
	}
	else
	{
		SysTime();
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		SaveUserData();
		SaveTransaction();
		printf("\n\t�ɹ�����%.2f!!!!\n", TA.Money);
		CK = 1;
		SaveMoney1();
	}
}

void SaveMoney1()//���ѡ��
{
	int k = 0, b;
	while (k < 3)
	{
		if (CK)
			printf("\n\t1.�ٴδ��");
		else
			printf("\n\t1.����������");
		printf("\n\t2.�������˵�\n");
		printf("\n\t0.�˳�ϵͳ\n");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			SaveMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void WithdrawMoney()//ȡ��
{
	int a;
	CK = 0;
	printf("\t��ܰ��ʾ������ȡ��ó���10000��\n");
	printf("\n\n��������Ҫȡ���Ľ�");
	scanf("%d", &a);
	if (a > 10000)
	{
		system("cls");
		printf("\n\t����ȡ��ó���10000��\n");
		WithdrawMoney1();
	}
	else
	{
		SysTime();
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			system("cls");
			printf("\n\t����!!!!\n");
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			SaveUserData();
			WithdrawTransaction();
			printf("\n\tȡ��ɹ�!!!!\n");
			QK = 1;
		}
		WithdrawMoney1();
	}
}

void WithdrawMoney1()//ȡ��ѡ��
{
	int k = 0, b;
	while (k < 3)
	{
		if (QK)
			printf("\n\n1.�ٴ�ȡ��");
		else
			printf("\n\n1.����������");
		printf("\n\t2.�������˵�");
		printf("\n\t0.�˳�ϵͳ");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			WithdrawMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void TransferMoney()//ת��
{
	int a;
	ZZ = 0;
	printf("\t��ܰ��ʾ��1.����ȡ��ó���10000��\n");
	printf("\t        2.ת�˽���ȡ2%%�������ѡ�\n\t\n");
	printf("\n\n��������Ҫת�������˻���");
	Account TT;
	scanf("%s", &TT.AccountNum);
	if (FindACC3(TT))
	{
		system("cls");
		printf("\n��������Ҫת���Ľ�");
		scanf("%d", &a);
		if (a > 10000)
		{
			printf("\n\t����ת�˲��ó���10000��\n");
			TransferMoney1();
		}
		else
		{
			SysTime();
			TA.Money = a * -1.00;
			HandMoney = 0.02 * a;
			if (curAccount->balance + TA.Money - HandMoney < 0)
			{
				system("cls");
				printf("\n\t����!!!!\n");
			}
			else
			{
				system("cls");
				curAccount->balance = curAccount->balance + TA.Money - HandMoney;
				curAccountO->balance = curAccountO->balance - TA.Money;
				TransferTransaction();
				HandTransaction();
				SaveUserData();
				printf("\n\tת�˳ɹ�!!!!\n");
				ZZ = 1;
			}
			TransferMoney1();
		}
	}
	else
	{
		system("cls");
		printf("\n\t�Է��˻������ڣ�������");
		TransferMoney1();
	}

}

void TransferMoney1()//ת��ѡ��
{
	int k = 0, b;
	while (k < 3)
	{
		if (ZZ)
			printf("\n\n1.�ٴ�ת��");
		else
			printf("\n\n1.����ת��");
		printf("\n\t2.�������˵�");
		printf("\n\t0.�˳�ϵͳ\n");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			TransferMoney();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void Inquire()//��ѯҳ
{

	int a, b = 0;
	while (b < 3)
	{
		printf("\n\t1.��ѯ���");
		printf("\n\t2.��ѯ���׼�¼\n");
		printf("\t3.��ѯ������Ϣ");
		printf("\n\t4.�������˵�\n");
		printf("\t0.�˳�ϵͳ\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			InquireBalance();
			b = 3;
			break;
		case 3:
			system("cls");
			InqInformation();
			b = 3;
			break;
		case 2:
			system("cls");
			InqRecord();
			b = 3;
			break;
		case 4:
			system("cls");
			Menu();
			b = 3;
			break;
		case 0:
			system("cls");
			b = 3;
			SaveUserData();
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InquireBalance()//��ѯ�˻�
{
	SysTime();
	printf("\n\t�������Ϊ\n%.2f\n", curAccount->balance);
	int a, b = 0;
	while (b < 3)
	{
		printf("\n1.������һҳ");
		printf("\t2.�������˵�\n");
		printf("\n0.�˳�ϵͳ\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			b = 3;
			break;
		case 2:
			system("cls");
			Menu();
			b = 3;
			break;
		case 0:
			b = 3;
			SaveUserData();
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InqInformation()//��ѯ������Ϣ
{
	printf("\n\t������\n%s\n", curAccount->name);
	printf("\n\t�˺ţ�\n%s\n", curAccount->AccountNum);
	printf("\n\tԤ���ֻ��ţ�\n%s\n", curAccount->PhoneNum);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1.������һҳ");
		printf("\t2.�������˵�\n");
		printf("\n\t0.�˳�ϵͳ\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void InqRecord()//��ѯ���׼�¼
{
	PrintTransaction();
	int a, k = 0;
	while (k < 3)
	{
		printf("\n1.������һҳ");
		printf("\t2.�������˵�\n");
		printf("\n0.�˳�ϵͳ\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void ChangeInformation()//�޸���Ϣ�˵�
{
	system("cls");
	int a, b = 1;
	while (b)
	{
		printf("\n\t1.�޸��û�\n");
		printf("\t2.�޸ĵ绰\n");
		printf("\t3.�޸�����");
		printf("\n\t4.������һҳ\n");
		printf("\t0.�˳�ϵͳ\n");
		
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			ChangeUserName();
			b = 0;
			break;
		case 2:
			system("cls");
			ChangePhone();
			b = 0;
			break;
		case 3:
			system("cls");
			ChangePassword();
			b = 0;
			break;
		case 4:
		    system("cls");			
			Menu();
			b = 0;
			break;
		case 0:
			SaveUserData();
			exit(0);
		default:
			system("cls");
			printf("�������\t�밴����ʾ��������\n");
			break;
		}
	}
}

void ChangeUserName()//�޸��û�
{
	int a, b = 0, c = 0;
	while (b < 3)
	{
		system("cls");
		printf("\n\t���������û�����:");
		scanf("%s", curAccount->name);
		system("cls");
		printf("\n\t�û������޸ĳɹ���\n");
		SaveUserData();
		b = 3;
		while (c < 3)
		{
			printf("\n1.������һҳ");
			printf("\t2.�������˵�\n");
			printf("\n0.�˳�ϵͳ\n");
			
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();
				b = 3;
				break;
			case 2:
				system("cls");
				Menu();
				b = 3;
				break;
			case 0:
				b = 3;
				SaveUserData();
				exit(0);
			default:
				b++;
				break;
			}
		}
	}
}

void ChangePhone()//�޸ĵ绰
{
	system("cls");
	int a, b = 0, c = 0;
	while (b < 3)
	{
		printf("\n\t����������ϵ�绰����");
		scanf("%s", curAccount->PhoneNum);
		system("cls");
		printf("\n\t��ϵ�绰�޸ĳɹ���\n");
		SaveUserData();
		b = 3;
		while (c < 3)
		{
			printf("\n1.������һҳ");
			printf("\t2.�������˵�\n");
			printf("\n0.�˳�ϵͳ\n");
			
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();
				c = 3;
				break;
			case 2:
				system("cls");
				Menu();
				c = 3;
				break;
			case 0:
				c = 3;
				SaveUserData();
				exit(0);
			default:
				c++;
				break;
			}
		}
	}
}

void ChangePassword()//�޸�����
{
	system("cls");
	int a, b = 0, c = 0;
	char Password[100];
	while (b < 3)
	{
		printf("\n\n\t������ԭʼ���룺");
		char storePassword[10] = { '\0' };
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n������������:");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n�޸ĳɹ���\n");
			SaveUserData();
			b = 3;
			while (c < 3)
			{
				printf("\n1.������һҳ");
				printf("\t2.�������˵�\n");
				printf("\n0.�˳�ϵͳ\n");		
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					ChangeInformation();
					c = 3;
					break;
				case 2:
					system("cls");
					Menu();
					c = 3;
					break;
				case 0:
					c = 3;
					SaveUserData();
					exit(0);
				default:
					c++;
					break;
				}
			}
		}
		else
		{
			b++;
			system("cls");
			printf("\n\t�������!\n");
		}
	}
}

void getPassword(char* storePw, int maxPwLen)//��������
{
	char c = '\0';
	char* pc = storePw;
	int pwlen = 0;

	while (1)
	{
		c = getch();
		if (c == '\r')
			break;
		if (pwlen >= 0 && pwlen < maxPwLen - 1 && c)
		{
			*pc = c;
			pc++;
			pwlen++;
			putchar('*');
		}
	}
}

void SysTime()//ϵͳʱ��
{
	time_t t = time(0);
	char tmp[20];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X", localtime(&t));
	strcpy(TA.Time, tmp);
}

void SaveUserData()
{
	FILE* fp = fopen("D:/�û�.txt", "w");//�����û�����
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%f\n", curP->AccountNum, curP->name, curP->PhoneNum, curP->password, curP->balance);
			curP = curP->next;
		}
		fclose(fp);
	}
}

void SaveTransactionData()
{
	FILE* Tfp = fopen("D:/����.txt", "at+");//���潻������
	if (Tfp != NULL)
	{
		Trade* TcurP = THead;
		while (TcurP != NULL)
		{
			if (TcurP->Tnext == NULL)
			{
				fprintf(Tfp, "%s\t%s\t%s\t%f\n", TcurP->TAccountNum, TcurP->Time, TcurP->Operation, TcurP->Money);
			}
			TcurP = TcurP->Tnext;
		}
		fclose(Tfp);
	}
}

void IniUser_Data()//��ʼ���û�
{
	FILE* fp = fopen("D:/�û�.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\t%f\n", newNodeP->AccountNum, newNodeP->name, newNodeP->PhoneNum, newNodeP->password, &newNodeP->balance);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

void InitTraData()//��ʼ��������Ϣ
{
	FILE* Tfp = fopen("D:/����.txt", "r");
	if (Tfp != NULL)
	{
		while (!feof(Tfp))
		{
			Trade* TnewNodeP = (Trade*)malloc(sizeof(Trade));
			fscanf(Tfp, "%s\t%s\t%s\t%f\n", TnewNodeP->TAccountNum, TnewNodeP->Time, TnewNodeP->Operation, &TnewNodeP->Money);
			TnewNodeP->Tnext = NULL;

			if (THead == NULL)
			{
				THead = TnewNodeP;
				TTail = TnewNodeP;
			}
			else
			{
				TTail->Tnext = TnewNodeP;
				TTail = TnewNodeP;
			}
		}
		fclose(Tfp);
	}
}

void SignUp()//ע�ắ��
{
	int a, k = 0;
	system("cls");
	Pset->next = NULL;//Account* Pset = (Account*)malloc(sizeof(Account));//�Ѷ���
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;//������ǵ�һ�������Ľ�㣬��ͷ βָ��ָ��������
	}
	else
		tail->next = Pset; //������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
	printf("\n������������\n");
	scanf("%s", ZX.name);
	strcpy(Pset->name, ZX.name);
	int ACCountNum = 10000;
	itoa(ACCountNum, ZX.AccountNum, 10);
	while (FindACC2(ZX))
	{
		ACCountNum++;
		itoa(ACCountNum, ZX.AccountNum, 10);
		break;
	}
	strcpy(Pset->AccountNum, ZX.AccountNum);
	SetPhoneNum();
	SetPassword();
	Pset->balance = 0;
	SaveUserData();
	while (k < 3)
	{
		system("cls");
		printf("\nע��ɹ�!\n");
		printf("\n����˺�Ϊ%s\n", Pset->AccountNum);
		printf("\t0.�˳�ϵͳ\n");
		scanf("%d", &a);
		exit(0);
	}
}

void SetPassword()//��������
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("\n�������˻�����\n");
		char storePassword[10] = { '\0' };
		getPassword(storePassword, 10);
		strcpy(ZX.password, storePassword);
		if (strlen(ZX.password) == 6)
		{
			strcpy(Pset->password, ZX.password);
			break;
		}
		else
		{
			printf("\n����Ϊ��λ��������������\n����������\n");
		}
	}
}

void SetPhoneNum()//�����ֻ���
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("������绰����\n");
		scanf("%s", ZX.PhoneNum);
		if (strlen(ZX.PhoneNum) == 11)
		{
			strcpy(Pset->PhoneNum, ZX.PhoneNum);
			break;
		}
		else
		{
			system("cls");
			printf("\n��������\n����������\n");
		}
	}
}
