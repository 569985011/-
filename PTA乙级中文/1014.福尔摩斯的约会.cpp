#include<stdio.h>
#include<string.h>
#define N
int main() {
	char a[61];
	char b[61];
	char c[61];
	char d[61];
	gets(a);
	gets(b);
	gets(c);
	gets(d);
	//printf("%s\n%s\n%s\n%s",a,b,c,d);
	int cnt=0;
	for(int i=0; i<=strlen(a); i++) {
		if(cnt==2)break;
		if(cnt==1)
			if(a[i]==b[i]&&(a[i]>='A'&&a[i]<='N'||a[i]>='0'&&a[i]<='9')) {
				cnt=2;
				if(a[i]>='A'&&a[i]<='N') {
					//printf("%c-%d\n",a[i],a[i]-'A');
					switch(a[i]-'A') {
						case 0:
							printf("10:");
							break;
						case 1:
							printf("11:");
							break;
						case 2:
							printf("12:");
							break;
						case 3:
							printf("13:");
							break;
						case 4:
							printf("14:");
							break;
						case 5:
							printf("15:");
							break;
						case 6:
							printf("16:");
							break;
						case 7:
							printf("17:");
							break;
						case 8:
							printf("18:");
							break;
						case 9:
							printf("19:");
							break;
						case 10:
							printf("20:");
							break;
						case 11:
							printf("21:");
							break;
						case 12:
							printf("22:");
							break;
						case 13:
							printf("23:");
							break;
						default :
							printf("Hour´í");
							break;
					}
				} else if(a[i]>='0'&&a[i]<='9') {
					printf("%02d:",a[i]-'0');
				}
			}
		if(cnt==0)
			if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G') {
				cnt=1;
				switch(a[i]-'A'+1) {
					case 7:
						printf("SUN");
						break;
					case 1:
						printf("MON");
						break;
					case 2:
						printf("TUE");
						break;
					case 3:
						printf("WED");
						break;
					case 4:
						printf("THU");
						break;
					case 5:
						printf("FRI");
						break;
					case 6:
						printf("SAT");
						break;
					default :
						printf("ĞÇÆÚ´í");
						break;
				}
				printf(" ");
			}
	}
	for(int i=0; i<strlen(c); i++) {
		if(c[i]>='a'&&c[i]<='z'||c[i]>='A'&&c[i]<='Z')
			if(c[i]==d[i]) {
				printf("%02d",i);
				break;
			}


	}
	return 0;
}

