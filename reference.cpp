//matching

int Search_in_File(char *fname, char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	
	if((fopen_s(&fp, fname, "r")) != NULL) {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			printf("A match found on line: %d\n", line_num);
			printf("\n%s\n", temp);
			find_result++;
		}
		line_num++;
	}

	if(find_result == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   	return(0);
}



-----------------------------------

//copying to a new file


#include <stdio.h>
      int main() {
        FILE *fp1, *fp2;
        //consider 40 character string to store filename
        char filename[40];
        char c;
        int del_line, temp = 1;
        //asks user for file name
        printf("Enter file name: ");
        //receives file name from user and stores in 'filename'
        scanf("%s", filename);
        //open file in read mode
        fp1 = fopen(filename, "r");
        c = getc(fp1);
        //until the last character of file is obtained
        while (c != EOF)
        {
          printf("%c", c);
          //print current character and read next character
          c = getc(fp1);
        }
        //rewind
        rewind(fp1);
        printf(" \n Enter line number of the line to be deleted:");
        //accept number from user.
        scanf("%d", &del_line);
        //open new file in write mode
        fp2 = fopen("copy.c", "w");
        c = getc(fp1);
        while (c != EOF) {
          c = getc(fp1);
          if (c == '\n')
          temp++;
          //except the line to be deleted
          if (temp != del_line)
          {
            //copy all lines in file copy.c
            putc(c, fp2);
          }
        }
        //close both the files.
        fclose(fp1);
        fclose(fp2);
        //remove original file
        remove(filename);
        //rename the file copy.c to original name
        rename("copy.c", filename);
        printf("\n The contents of file after being modified are as  follows:\n");
        fp1 = fopen(filename, "r");
        c = getc(fp1);
        while (c != EOF) {
            printf("%c", c);
            c = getc(fp1);
        }
        fclose(fp1);
        return 0;
      }
