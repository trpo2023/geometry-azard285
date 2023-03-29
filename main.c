#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point {
	float x;
	float y;
};

int check_num(char figure[], int* p)
{
    int k = *p;

    char str2[13] = "-.0123456789";

    while (figure[k] == ' ') {
        k++;
    }

    if (figure[k] == '0') {
        if (figure[k + 1] != '.' && strchr(str2, figure[k + 1]) != NULL) {
            printf("Error at column %d: expected '.' \n", k);
            return 0;
        }
    }

    if (strchr(str2, figure[k]) == NULL) {
        printf("Error at column %d: unexpected character\n", k);
        return 0;
    }

    while (strchr(str2, figure[k]) != NULL) {
        k++;
    }

    if (figure[k] == ',' || figure[k] == ')') {
        printf("Error at column %d: expected number\n", k);
        return 0;
    }

    if (figure[k] != ' ') {
        printf("Error at column %d: expected ' '\n", k);
        return 0;
    }

    while (figure[k] == ' ') {
        k++;
    }

    if (figure[k] == '0') {
        if (figure[k + 1] != '.' && strchr(str2, figure[k + 1]) != NULL) {
            printf("Error at column %d: expected '.'\n", k);
            return 0;
        }
    }

    if (strchr(str2, figure[k]) == NULL) {
        printf("Error at column %d: unexpected character\n", k);
        return 0;
    }

    while (strchr(str2, figure[k]) != NULL) {
        k++;
    }
	k++;
    while (figure[k] == ' ') {
        k++;
    }
	while (strchr(str2, figure[k]) != NULL) {
        k++;
    }

	if (figure[k] != ')') {
        printf("Error at column %d: expected ')'\n", k);
		return 0;
    }

    k++;
    *p = k;
    return 1;
}

struct WKTcircle {
	struct Point point;
	float number;
};

int main() {
	FILE *myfile;
	myfile = fopen("values.txt", "r");
	if (!myfile) {puts ("Файл не обнаружен. Работа невозможна."); return 0;}
	char *type;
	char line[100];
	char line1[100];
	int k = 7;
	struct WKTcircle c1;
	while ((fgets(line, 100, myfile)) != 0) {
		strcpy(line1, line);
    		type = strtok(line1, "(");
			if (check_num(line, &k) == 0) {
       			return;
				}
    		if (strcmp(type, "circle") == 0) {
      			if ((sscanf(line, "circle(%f %f, %f)", &c1.point.x, &c1.point.y, &c1.number)) == 3)
        			printf("circle(%f %f, %f)\n", c1.point.x, c1.point.y, c1.number);
      			else
        			printf("incorrect data of points of circle. Expected NUM NUM, NUM \n");
    		}   else
            		printf("Incorrect type of figure format. Expected: \"Circle\" \n");
  		}
        
  return 0;
}
