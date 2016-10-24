#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N
/*

*/
//typedef struct {
//
//} ;


int main(){
    char a[31];;
    	while((scanf("%s",a))!=EOF){
    		int num=0;
    		for(int i=0;i<strlen(a);i++){
    			if(a[i]=='1'){
    				int b=1;
    				for(int j=0;j<strlen(a)-i;j++){
    					b*=2;
					}
					num+=b-1;
				}else 
				if(a[i]=='2'){
				int b=1;
				for(int j=0;j<strlen(a)-i;j++){
					b*=2;
				}num+=2*(b-1);
				break;
				} 
			}
    	printf("%d\n",num);	
		};

return 0;
}

