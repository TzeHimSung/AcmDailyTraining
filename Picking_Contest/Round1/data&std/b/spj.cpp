#include <bits/stdc++.h>
using namespace std;

#define AC 0
#define WA 1
#define ERROR -1

int spj(FILE *input, FILE *user_output);

void close_file(FILE *f){
	if(f != NULL){
		fclose(f);
	}
}

int main(int argc, char *args[]){
	FILE *input = NULL, *user_output = NULL;
	int result;
	if(argc != 3){
		printf("Usage: spj x.in x.out\n");
		return ERROR;
	}
	input = fopen(args[1], "r");
	user_output = fopen(args[2], "r");
	if(input == NULL || user_output == NULL){
		printf("Failed to open output file\n");
		close_file(input);
		close_file(user_output);
		return ERROR;
	}

	result = spj(input, user_output);
	printf("result: %d\n", result);

	close_file(input);
	close_file(user_output);
	return result;
}

int a[1000*1000+10];
char x[10000];
int spj(FILE *input, FILE *user_output){
	/*
		parameter: 
		- input，标程输入的文件指针
		- user_output，用户输出文件的指针
		return: 
		- 如果用户答案正确，返回AC
		- 如果用户答案错误返回WA
		- 如果主动捕获到自己的错误，如内存分配失败，返回ERROR
		请用户完成此函数.
		demo:
		int a, b;
		while(fscanf(f, "%d %d", &a, &b) != EOF){
			if(a -b != 3){
				return WA;
			}
		}
		return AC;
	*/
	int T;
	fscanf(input,"%d",&T);
	while(T--){
		int n;
		fscanf(input,"%d",&n);
		char s[10];
		fscanf(user_output,"%s",s);

		int len=strlen(s);
		if(s[0]!='Y'||s[1]!='E'||s[2]!='S'||len!=3)return WA;

		int sum=-1,cnt=0;
		for(int i=1;i<=n;i++){
			int tmp=0;
			char x[100];
			for(int j=1;j<=n;j++){
				fscanf(user_output,"%s",x+1);
				len=strlen(x+1);
				if(len>7)return WA;
				int cur=0;
				for(int k=1;k<=len;k++){
					if(x[k]>='0'&&x[k]<='9')cur=cur*10+x[k]-'0';
					else return WA;
				}
					
				if(cur<1||cur>n*n)return WA;
				a[++cnt]=cur;
				tmp+=cur;
			}
			if(sum==-1)sum=tmp;
			else if(sum!=tmp)return WA;
		}
		if(cnt!=n*n)return WA;
		sort(a+1,a+1+cnt);
		for(int i=2;i<=cnt;i++)
			if(a[i-1]==a[i])return WA;
	}
	return AC;
}