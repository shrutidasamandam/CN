#include <stdio.h>
#include <string.h>
#define N strlen(gen)
char modif[28],checksum[28],gen[28];
int a,e,c,b;
void xor()
{
for(c=1;c<N;c++)
checksum[c]=((checksum[c]==gen[c])?'0':'1');
}
void crc()
{
for(e=0;e<N;e++)
checksum[e]=modif[e];
do
{
if(checksum[0]=='1')
xor();
for(c=0;c<N-1;c++)
checksum[c]=checksum[c+1];
checksum[c]=modif[e++];
}while(e<=a+N-1);
}
int main()
{
int flag=0;
strcpy(gen,"10001000000100001");
printf("\nEnter data:");
scanf("%s",modif);
printf("\nGenerating polynomial:%s\n",gen);
a=strlen(modif);
for(e=a;e<a+N-1;e++)
modif[e]='0';
printf("Modified data is:%s\n",modif);
crc();
printf("Checksum is:%s\n",checksum);
for(e=a;e<a+N-1;e++)
modif[e]=checksum[e-a];
printf("\nFinal codeword is : %s\n",modif);
printf("\nTest error detection 0(yes) 1(no)?:");
scanf("%d",&e);
if(e==0)
{
do{
printf("\nEnter the position where error is to be inserted:");
scanf("%d",&e);
}
while(e==0||e>a+N-1);
modif[e-1]=(modif[e-1]=='0')?'1':'0';
printf("\nError data:%s\n",modif);
}
crc();
for(e=0;(e<N-1)&&(checksum[e]!='1');e++);
if(e<N-1)
printf("Error detected\n\n");
else
printf("\nNo error detected \n\n");
}
