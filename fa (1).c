#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mebelniymagazin {
	char n[100];
	char p[100];
	int cena;
} mebelniymagazin;
void add(mebelniymagazin **arr, int *r){
	FILE*f=fopen("b.bin", "rb");
        if(!f){
                return;
        }
        int t;
        fseek(f,0,SEEK_END);
        size_t size =ftell(f);
        rewind(f);
        t=size/sizeof(mebelniymagazin);
	*arr=(mebelniymagazin *)calloc(t,sizeof(mebelniymagazin));
	fread(*arr,sizeof(mebelniymagazin),t,f);
	fclose(f);
	printf("skolko dobavit?\n");
        while(scanf("%i",r)!=1){
                printf("vvedite cifru\n");
                while(getchar() !='\n');
        }
	f=fopen("b.bin", "wb");
	int q=*r;
	int c=q+t;
	*arr=(mebelniymagazin *)realloc(*arr,c*sizeof(mebelniymagazin));
	mebelniymagazin*temp=*arr;
	for(int i=t; i<c; i++){
		printf("%ivedite: nazvanie proizvod and cena tovara\n",i+1);
		scanf("%s %s  ",temp[i].n,temp[i].p);
		while(scanf("%i",&temp[i].cena)!=1){
                	printf("vvedite cifru\n");
                	while(getchar() !='\n');
        	}
	}
	fwrite(*arr,c,sizeof(mebelniymagazin),f);
	fclose(f);
}
void  output(mebelniymagazin**arr,int *r){
	FILE*f=fopen("b.bin", "rb");
        if(!f){
                return;
        }
	int q;
	fseek(f,0,SEEK_END);
        size_t size =ftell(f);
        rewind(f);
        q=size/sizeof(mebelniymagazin);
	*arr=(mebelniymagazin *)calloc(q,sizeof(mebelniymagazin));
	fread(*arr,sizeof(mebelniymagazin),q,f);
	mebelniymagazin*temp=*arr;
	printf("BD:\n");
	for(int i=0;i<q;i++){
		printf("%i\t %s\t\t %s\t\t %i\t\t\n",i+1, temp[i].n, temp[i].p, temp[i].cena);
	}
	fclose(f);
}
void search(mebelniymagazin**arr,int *r){
	FILE*f=fopen("b.bin", "rb");
	if(!f){
		return;
	}
	int q=*r;
	fseek(f,0,SEEK_END);
	size_t size =ftell(f);
	rewind(f);
	q=size/sizeof(mebelniymagazin);
	*arr=(mebelniymagazin*)calloc(q,sizeof(mebelniymagazin));
	mebelniymagazin*temp = *arr;
	fread(*arr, sizeof(mebelniymagazin),q,f);
	int d,t;
	char y[50];
	printf("priznak\n1 nazvanie\n2 proizv\n3 chena\n");
        while(scanf("%i",&d)!=1){
	        printf("vvedite cifru\n");
        	while(getchar() !='\n');
        }
	printf("chto ishem\n");
	if (d!=3){
		scanf("%s",y);
	} else {
	        while(scanf("%i",&t)!=1){
        	        printf("vvedite cifru\n");
                	while(getchar() !='\n');
        	}
	}
	switch(d){
		case 1:
			for(int i = 0; i < q; i++){
				if(strcmp(y, temp[i].n) == 0){
					printf("строка удовлетворяющая условиям поиска:\n");
					printf("%i\t %s\t %s\t %i\t\n", i + 1, temp[i].n, temp[i].p, temp[i].cena);
				}
			}
			break;
		case 2:
			for(int i = 0; i < q; i++){
				if(strcmp(y, temp[i].p) == 0){
					printf("строка удовлетворяющая условиям поиска:\n");
					printf("%i\t %s\t %s\t %i\t\n", i + 1, temp[i].n, temp[i].p, temp[i].cena);
				}
			}
		break;
		case 3:
			for(int i = 0; i < q; i++){
				if(t == temp[i].cena){
					printf("строка удовлетворяющая условиям поиска:\n");
					printf("%i\t %s\t %s\t %i\t\n", i + 1, temp[i].n, temp[i].p, temp[i].cena);
				}
			}
		break;
	}
	fclose(f);
}
void swap(mebelniymagazin**arr, int *r){
	FILE*f=fopen("b.bin","rb");
	if(!f){
		return;
	}
	int q=*r;
	fseek(f,0,SEEK_END);
	size_t size =ftell(f);
	rewind(f);
	q=size / sizeof(mebelniymagazin);
	*arr=(mebelniymagazin*)calloc(q,sizeof(mebelniymagazin));
	mebelniymagazin*temp=*arr;
	fread(*arr,sizeof(mebelniymagazin),q,f);
	int j,o;
	printf("kakyu iz strok izmenim\n");
        while(scanf("%i",&o)!=1){
                printf("vvedite cifru\n");
                while(getchar() !='\n');
        }
	printf("chto meniaem\n 1 nazvanie\n 2 proizv\n 3 cena\n");
	        while(scanf("%i",&j)!=1){
                printf("vvedite cifru\n");
                while(getchar() !='\n');
        }
	switch(j){
		case 1:
			printf("na chto zamenim?\n");
			scanf("%s",temp[o-1].n);
			printf("%i\t %s\t %s\t %i\t\n", o, temp[o-1].n, temp[o-1].p, temp[o-1].cena);
		break;
		case 2:
			printf("na chto zamenim?\n");
			scanf("%s",temp[o-1].p);
			printf("%i\t %s\t %s\t %i\t\n", o, temp[o-1].n, temp[o-1].p, temp[o-1].cena);
		break;
		case 3:
			printf("na chto zamenim?\n");
		        while(scanf("%i",&temp[o-1].cena)!=1){
                		printf("vvedite cifru\n");
               			while(getchar() !='\n');
        		}
			printf("%i\t %s\t %s\t %i\t\n", o, temp[o-1].n, temp[o-1].p, temp[o-1].cena);
		break;
		default:
			printf("net takogo pynkta\n");
	}
	fclose(f);
	f=fopen("b.bin","wb");
	if(!f){
		return;
	}
	fwrite(*arr,q,sizeof(mebelniymagazin),f);
	fclose(f);
}
void delit(mebelniymagazin**arr, int *r){
	FILE*f=fopen("b.bin","rb");
	if(!f){
		return;
	}
	int q = *r;
	fseek(f, 0, SEEK_END);
	size_t size = ftell(f);
	rewind(f);
	q = size / sizeof(mebelniymagazin);
	*arr = (mebelniymagazin*)calloc(q, sizeof(mebelniymagazin));
	mebelniymagazin*temp = *arr;
	fread(*arr, sizeof(mebelniymagazin), q, f);
	fclose(f);
	int o;
	printf("kogo ydalit\n");
        while(scanf("%i",&o)!=1){
                printf("vvedite cifru\n");
                while(getchar() !='\n');
        }
	if(o<=q && o>0){
		for (int y = o - 1; y < q - 1; y++){
			temp[y] = temp[y + 1];
		}
		FILE*f=fopen("b.bin", "wb");
		if (!f){
			return;
		}
		fwrite(*arr, q - 1, sizeof(mebelniymagazin), f);
		fclose(f);
		*arr = (mebelniymagazin*)calloc(q - 1, sizeof(mebelniymagazin));
	} else {
		printf("нет такой строки!\n");
		return;
	}
}
int main(){
FILE *f=fopen("b.bin","wb");
if(!f)
return 0;
fclose(f);
int r;
int ff;
mebelniymagazin*s;
while (1) {
	printf("выберите действие:\n");
	printf("1-добавление\n");
	printf("2-вывод\n");
	printf("3-поиск\n");
	printf("4-изменение\n");
	printf("5-удаление\n");
	printf("6-выход\n");
	while(scanf("%i",&ff)!=1){
                printf("vvedite cifru\n");
                while(getchar() !='\n');
        }
	switch (ff){
		case 1:
			add(&s,&r);
			break;
		case 2:
			output(&s,&r);
			break;
		case 3:
			search(&s,&r);
			break;
		case 4:
			swap(&s,&r);
			break;
		case 5:
			delit(&s,&r);
			break;
		case 6:
			printf("goodbye\n");
			return 0;
			break;
		default:
			printf("net takogo varianta\n");
			break;
	}
}
free(s);
return 0;
}
