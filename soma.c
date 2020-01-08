#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// considerando 4 dígitos + 0x0A + 0x00
#define LINE_SIZE	6

int main () {
	FILE *fp;	
	fp = freopen("input3.txt", "r", stdin); 
	
    char buf[LINE_SIZE];
    char* end;
    memset(buf, 0, LINE_SIZE);
	
	if (fp == NULL) {
    	printf("Erro ao abrir arquivo");
    	return(-1);
    }
    else {
        fgets(buf, sizeof buf, fp);
        int n = strtol(buf, NULL, 10);        
        
        if (n != 0) {
        	int soma = 0;
			int i;
			
	        for (i = 1; i <= n; i++) {
	        	fgets(buf, sizeof buf, fp);
	        	
	        	soma += strtol(buf, &end, 10);
	        		        	
	        	if (feof(fp)) {
	        		break;
	        	}
	        }		
	        
			printf("%d", soma);
        }
    }

    fclose(fp);

    return (0);
}


