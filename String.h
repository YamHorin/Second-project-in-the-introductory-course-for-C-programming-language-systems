#ifndef __STRING__
#define __STRING__
#define MAX_STR_LEN 255


char*	getString(const char* msg);
char*	getsStrFixSize(char* buffer, int size, const char* msg);
char*	myGets(char* buffer, int size);
char*	getDynStr(char* str);
char**	splitCharsToWordsBySpace(char* str, int* pCount, int* pTotalLength);
char**	splitCharsToWords(char* str, int* pCount, const char* del);
int compareTwoString(const char a[], const char b[]);
char* Mygets(char* buf, int size);


#endif