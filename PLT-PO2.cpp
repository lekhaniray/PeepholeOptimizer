#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp;
	char ch;
	fp = fopen("input.txt", "w");
	printf("Enter the data");
	while((ch = getchar()) != EOF) {
		putc(ch, fp);
	}
	fclose(fp);

	fp = fopen("input.txt", "r");

	for(i=0; i!= '\0'; i++)
	{
 		while(fgets(line, i, fp) != NULL)
		{
			if(strstr(line, search_string))
			
	
	

