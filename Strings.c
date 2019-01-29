#include<stdio.h>
#include<stdlib.h>

int Character_Count(char *String);
void Reverse_String(char *Reverse,int count);
int Compare_Strings(char *s1,char *s2);
int Search_String(char *sub, char *s, int count);
void Print_Out(int count, int compare, int search);
/* The program will show character count in a string, reverse the string, compare the two strings to see which comes first, and searches one screen for the other*/
int main(int argv, char **argc)
{
	int i, j;
	char s1[100];
	char s2[100];
	printf("Enter s1: \n");
        fgets(s1, 100, stdin); 
        printf("Enter s2: \n");
        fgets(s2, 100, stdin);
	int count = Character_Count(s1);
	Reverse_String(s1,count);
	int compare = compare_strings(s1, s2);
	int search = Search_String(s1, s2, count);
	Print_Out(count, compare, search);
	return 0;
}
/* counts the number of letters in the string by looping until it hits the null terminator*/
int Character_Count(char *String)
{
	int count = 0;
	while(*(String+count) != '\0')
		count++;
	printf("The number of characters in string 1 is: %d\n", count - 1);
	return count;
}
/*Reverses the string by printing it out from right to left */
void Reverse_String(char *Reverse,int count)
{
	int i;
	printf("s1 reversed is: ");
	for(i = count - 1; i >= 0; i--)
		printf("%c", *(Reverse+i));
	printf("\n");
	
}
/*Compares the two Strings, if the strings have upper case letters it converts them to lower case, then compares to see which comes before the other*/
int compare_strings(char *s1, char *s2)
{
	int i;
	for(i = 0; *(s1+i) != '\0' && *(s2+i) != '\0'; i++){
		if(*(s1+i)<= 64 && *(s1+i)>=89)
			*(s1+i) = *(s1+i) + 32;
		if((*s2+i)<=64 && *(s2+i)>=89)
			*(s2+i) = *(s2+i) + 32;
	}
	for(i = 0; *(s1+i) == *(s2+i); i++){
		if(*(s1+i) == '\0' && *(s2+i) == '\0')
			return 0;
	}
	if(*(s1+i) > *(s2+i))
		return 1;
	 if(*(s1+i) < *(s2+i))
		return -1;
}
/*Searches the one String to see if it includes another String by checking the first value,
 then if there is a match it compares the rest of the values, returns 1 if true and 0 if false*/
int Search_String(char *sub, char *s, int count)
{
	int i;
	for(i = 0; *(s+i) != '\0'; i++){
		int k = 1;
		if(*(s+i) == *(sub)){
			while(*(sub+k) == *(s+k+i)){
				k++;
				if(k == count - 1)
					return 1;
			}
		}
	}
	return 0;
}
/* This just prints out based on the values to make the main look less ugly*/
void Print_Out(int count, int compare, int search)
{
	if(compare == -1)
		printf("s1 comes before s2\n");
	else if(compare == 1)
		printf("s2 comes before s1\n");
	else
		printf("both s1 and s2 are equal\n");
	if(search == 1)
		printf("s1 was found within s2\n");
	else
		printf("s1 was NOT found within s2\n");
}
