#include<stdio.h>
void rotate_four_bits(val)
{
	int temp=val&0x000F;
	temp=temp<<12;
	int temp2=val>>4;
	printf("%x\n",(temp|temp2));
}

void last_four_bits(int val)
{
	int temp=0x000F,cnt=0,i;
	temp=val&temp;
	for(i=0;i<4;i++)
	{
		cnt=cnt+temp%2;
		temp=temp>>1;
	}
	
	if(cnt>=3)
		printf("Yes\n");
	else
		printf("No\n");
}
void reverse_byte_order(int val)
{
	int temp1=val,temp2=val;
	temp1=val>>8;
	temp2=val<<8;
	printf("%x\n",((temp1|temp2)&0xFFFF));
}
void main()
{
	int val=0xCAFE;
	reverse_byte_order(val);
	last_four_bits(val);
	rotate_four_bits(val);
	getch();
}