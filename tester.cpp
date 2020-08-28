
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<process.h>
#include <windows.h>
#include <wincon.h>

void mover(int i,int j,int k=0)
{	
COORD newPosition;
 newPosition = { j+13,i+2  };
	char str[10];
	//	system("cls");
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
	if(k==1)
		printf(" ");
}
void save(char a[10][100],int i)
{
	printf("\n \n \t \t \t Enter THE FILE name with path : ");
	char f[100];
	scanf("%s",f);
	FILE* fp;
	fp=fopen(f,"w+");
	int n;
	for(n=0;n<=i;n++)
		fprintf(fp,"%s \n",a[n]);
	fclose(fp);
	printf("\n \n \t \t \t \tFILE SAVED!!!!!!!!!");
	getch();
	exit(0);
}

void backs(char a[10][100],int i,int &j,int l){
int n;
for(n=j+1;n<=l;n++)
	a[i][n]=a[i][n+1];
mover(i-1,0);
printf("\n \t %d. %s ",i+1,a[i]);	
mover(i,j);
	
	}
void slider(char ch[10][100],char a[10][100],int &i,int j,int m[10],int f){
	int n,l,s;
	char sen[100];
	
	

	for(n=f-1;n>i;n--)
	{	for(s=0;s<m[n+1];s++)
			{a[n+1][s]=' ';
			
			}
			
		strcpy(a[n+1],a[n]);
	
	m[n+1]=m[n];
	}l=i+1;
	if(j<m[i]-1)
	{			
	for(n=j+1,s=0;n<m[i];n++,s++){
	
	a[i+1][s]=a[i][n];
	a[i][n]=' ';
	m[n]--;
	mover(i,n-1);
}
	a[i][n]='\0';
	}

	mover(i,0);
	printf("\n \t %d. %s %s",i+2,a[i+1],sen);
	for(n=i+2;n<=f;n++)
		printf("\n \t %d. %s                           ",n+1,a[n]);

	++++i;
	
}
void displayer(char ch[10][100],char a[10][100],int i,int j,int m){
			int n;
	for(n=j+1;n<m;n++){
	
	printf("%c",ch[i][n]);
	a[i][n]=ch[i][n];}
}
void shifter(char ch[10][100],int i,int j,int m){
	int n;
	
char a;
a=ch[i][j];
//printf("\n \n \n \tk:%d char :%c",i,a);
	for(n=m-1;n>=j-1;n--)
	{	ch[i][n+1]=ch[i][n];
			
	}

//printf("\n.%s",ch[i]);


	
}

	

void editor()
{ 	char ch[10][100],a[10][100];

	int i,j,k=0,n=0,m=0,l[10],f=0;
	int c;
	char ch1, ch2;
	printf("PRESS Esc to EXIT || PRESS ctrl+s TO SAVE \n");

	for(i=0;i<4;)
	{   l[i]=0;printf("\n \t %d. ",i+1);f++;
		for(j=0;j<100;j++){

				
			ch[i][j]=getch();
			
			c=(int)(ch[i][j]);
				if(c==13)
			{	if(i<f-1)
			{	slider(ch,a,i,j,l,f);
			}i++; 
				break;	}
				if(c==19)
				{	save(a,i);
				}
			if(c==-32)
			{		n=1;
					k=1;
			}
		if(c==8)
		{	
		if(j==0&&i>0)
			{	n=1;
				i--;
				
			}
			else if(j<l[i]-1)
			{mover(i,----j,1);
		mover(i,j);
		n=1;
		l[i]--;
		backs(a,i,j,l[i]);	
			}
		
		else {
		mover(i,----j,1);
		mover(i,j);
		n=1;
		l[i]--;}
		}
			if(c==27)
			{	exit(0);
			}
				if(n==0){
					l[i]++;
				a[i][j]=ch[i][j];
			printf("%c",ch[i][j]);
					if(m==1){
					displayer(ch,a,i,j,l[i]);
					mover(i,j);
					m=0;}
					}
		if(c==8)
		n=0;
				if(c==(72)&&k==1&&i>0&&j>=0){
				k=0;j-=2;
						n=0;

						mover(--i,j);
					
					}
					else if(c==75&&k==1&&i>=0&&j>0)
					{k=0;	j-=2; n=0;
						mover(i,--j);
						
							}
							else if(c==77&&k==1&&i>=0&&j>=0)
					{	j-=2; k=0;n=0;
						mover(i,++j);
							}
							else if(c==80&&k==1&&i>=0&&j>=0)
					{	j-=2;k=0;n=0;
						mover(++i,j);
							}
								
		
			
			if(j<l[i]-1)
			{		m=1; 
					shifter(ch,i,j,l[i]);}
				}
				
 	
			
	}

		for(j=0;j<3;j++)
	{   printf("\n \t %d. ",j+1);
	printf("%s",a[j]);}
}
int main()
//{	FILE *fpr;
//	fpr=fopen("editor.txt","w+");
{
		
	editor();
	return 0;
}
