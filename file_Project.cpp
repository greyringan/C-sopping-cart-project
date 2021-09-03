#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item{
	char itemName[100];
	int itemPrice;
	int itemQty;
};

typedef struct Item list;

void addMenu(struct Item *list, int *i);

void removeMenu(struct Item *list, int i);

void viewMenu(struct Item *list, int *i);

int searchItem(struct Item *list, int left, int right, char name[]);

void mergeSort(struct Item *list, int left, int right);

void merge(struct Item *list, int left, int mid, int right);

int linearSearch(struct Item *list, char *name);

int main(){
	int choice = -1, i = 0;
	list shop[100];
	FILE *fptr;
	for(int k=0; k<100; k++){
		strcpy(shop[k].itemName, "Empty");
		shop[k].itemPrice = shop[k].itemQty = 0;
	}
	do{
		puts("Shopping Cart Program");
		puts("1. Add Item");
		puts("2. Remove Item");
		puts("3. View List and Store Item");
		puts("4. Exit");
		printf("Pick a menu >> ");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1:{
//				addMenu(itemList, &i);
				char name[100];
				int price;
				int qty;
				int len;
				do{
					printf("Input Item Name [6-35 character]: ");
					scanf("%[^\n]", name);
					len = strlen(name);
					getchar();
				}while(len < 6 || len > 35);
	
	do{
		printf("Input Item price [1000 - 100000]: ");
		scanf("%d", &price);
		getchar();
	}while(price < 1000 || price > 100000);
	
	do{
		printf("Input Item price [1 - 10]: ");
		scanf("%d", &qty);
		getchar();
	}while(qty < 1 || qty > 10);
	
	strcpy(shop[i].itemName, name);
	shop[i].itemPrice = price;
	shop[i].itemQty = qty;
	
	i += 1;
//				printf("%d\n", i);
//				mergeSort(shop, 0, 100);
				break;
}
			case 2:{
//				removeMenu(itemList, i);
char name[100];
	int loc = -1;
	
	do{
		printf("Input Item Name [6-35 character]: ");
		scanf("%[^\n]", name);
		getchar();
	}while(strlen(name) < 6 && strlen(name) > 35);
	
	loc = linearSearch(shop, name);//searchItem(shop, 0, 99, name);//
	
	if(loc == -1){
		puts("Item not available in list!");
	}
	else{
		strcpy(shop[loc].itemName, "Empty");
		shop[loc].itemPrice = shop[loc].itemQty = 0;
	}
	i--;
				break;
			}
			case 3:{
//				viewMenu(itemList, &i);/
				for(int j=0; j<100; j++){
						printf("element %d: %s %d %d\n", j+1, shop[j].itemName, shop[j].itemPrice, shop[j].itemQty);
			}
				fptr = fopen("shoppinglist.txt", "w");
				if(fptr == NULL){
					puts("Error in opening file !");
					exit(1);
				}
				for(int k=0; k<100; k++){
					fprintf(fptr, "Element#%d:%s,%d,%d\n", k+1, shop[k].itemName, shop[k].itemPrice, shop[k].itemQty);
				}
				
				fclose(fptr);
				puts("shopping list has been stored");
				break;
			}
			case 4:
				puts("Terimakasih telah menggunakan aplikasi ini");
//				free(itemList);
//				itemList = NULL; 
				break;
		}
	}while(choice != 4);
	
	return 0;
}


//void addMenu(struct Item* list, int *i){
//	char name[100];
//	int price;
//	int qty;
//	int len;
//	do{
//		printf("Input Item Name [6-35 character]: ");
//		scanf("%[^\n]", name);
//		len = strlen(name);
//		getchar();
//	}while(len < 6 || len > 35);
//	
//	do{
//		printf("Input Item price [1000 - 100000]: ");
//		scanf("%d", &price);
//		getchar();
//	}while(price < 1000 || price > 100000);
//	
//	do{
//		printf("Input Item price [1 - 10]: ");
//		scanf("%d", &qty);
//		getchar();
//	}while(qty < 1 || qty > 10);
//	
//	strcpy(list[*(i)-1].itemName, name);
//	list[*(i)-1].itemPrice = price;
//	list[*(i)-1].itemQty = qty;
//	
//	*(i) += 1;
//}

//void removeMenu(struct Item *list, int i){
//	char name[100];
//	int loc = -1;
//	
//	do{
//		printf("Input Item Name [6-35 character]: ");
//		scanf("%[^\n]", name);
//		getchar();
//	}while(strlen(name) < 6 && strlen(name) > 35);
//	
//	loc = /*searchItem(list, 0, i-1, name)*/linearSearch(list, i);
//	
//	if(loc == -1){
//		puts("Item not available in list!");
//	}
//	else{
//		list[loc].itemPrice = list[loc].itemQty = 0;
//		strcpy(list[loc].itemName, "Empty");
//	}
//}

int searchItem(struct Item *list, int left, int right, char *name){
	int mid = (left+(right-1))/2;
	printf("%d\n", mid);
	if(left < right){
		if(strcmp(list[mid].itemName, name)) return mid;
		searchItem(list, left, mid-1, name);
		searchItem(list, mid+1, right, name);
	}
	return -1;
}

void mergeSort(struct Item *list, int left, int right){
	
	if(left < right){
		int mid = (left + (right-1)) / 2;
		printf("%d\n", mid);
		mergeSort(list, left, mid);
		mergeSort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}

void merge(struct Item *list, int left, int mid, int right){
	int n = (right-left+1);
	struct Item tempList[n];
	int i,j,k;
	i = left;
	j = mid+1;
	k = 0;
	
	while(i<=mid && j<=right){
		if(strcmp(list[i].itemName, list[j].itemName) < 0 /*&& ((strcmp(list[i].itemName, "Empty") != 0) && (strcmp(list[j].itemName, "Empty")))*/){
			tempList[k] = *(list+i);
			++k;
			++i;
		}
		else if(strcmp(list[i].itemName, list[j].itemName) > 0 /*&& ((strcmp(list[i].itemName, "Empty") != 0) && (strcmp(list[j].itemName, "Empty")))*/){
			tempList[k] = *(list+j);
			++k;
			++j;
		}
	}
	
	while(i<=mid){
		strcpy(tempList[k].itemName, list[i].itemName);
			tempList[k] = *(list+i);
			++k;
			++i;
	}
	while(j<=right){
		tempList[k] = *(list+j);
			++k;
			++j;
	}
	
	int ind = 0;
	for(int i = left; i<mid; i++){
		*(list+i) = tempList[ind];
			++i;
			++ind;
	}
	
	for(int j=mid+1; j<right; j++){
		*(list+j) = tempList[ind];
		++j;
		ind++;
	}
}

int linearSearch(struct Item *list, char* name){
	for(int k=0; k<100; k++){
		if(strcmp(list[k].itemName, name) == 0){
			printf("%d\n", k);
			return k;
		} 
	}
	return -1;
}

