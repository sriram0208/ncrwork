#include<stdio.h>
int main()
{
	char text[81];
	int i,letters=0,blank=0,digits=0,tab=0;
	printf("enter string :");
	//scanf("%s",text);
	gets(text);
	for(i=0;text[i]!='\0';i++)
	{
		if((text[i]>='a' && text[i]<='z')||(text[i]>='A' && text[i]<='Z'))
			letters++;
		else if(text[i]==' ')
			blank++;
		else if(text[i]>='0' && text[i]<='9')
			digits++;
		else if(text[i]=='\t')
			tab++;
	}
	//printf("%d",letters);
	printf("letters : %d\nblank : %d\ndigits : %d\ntab : %d\n",letters,blank,digits,tab);
}