#include<stdio.h>
#include<stdlib.h>
int i,j;
struct node
{
	int data;
	struct node *link;
	
}*ptr,*pnew,*ptr2,*header=NULL;

void ins_f(int s)
{
	struct node *pnew;
	
	pnew=malloc(sizeof(struct node));
	if(pnew!=NULL)
	{
		ptr=header;
		if(ptr!=NULL)
		{
			
			header=pnew;
			pnew->data=s;
			pnew->link=ptr;
			printf("element inserted\n");
		}
		else
		{
			
			pnew->link=header;
			header=pnew->link;
			pnew->data=s;
			pnew->link=NULL;
			printf("element inserted\n");
		}
	}
	else
	{
		printf("empty");
	}
}
void ins_e(int s)
{
	struct node *pnew;
	pnew=malloc(sizeof(struct node));
	ptr=header;
	if(ptr!=NULL)
	{
		ptr=ptr->link;
	}
	else
	{
		ptr=pnew->link;
		pnew->link=NULL;
		printf("element inserted");
	}	
	
}

void ins_k(int s, int k)
{
	struct node *pnew;
	if(header == NULL){
		printf("List Empty. Inserting at begining\n");
		ins_f(s);
	}else{
		ptr = header;
		while((ptr->link != NULL) & (ptr->data != k)){
			ptr = ptr->link;
		}
		if(ptr->link == NULL){
			printf("Key not found. Inserting at End\n");
			ins_e(s);
		}else{
			pnew = malloc(sizeof(struct node));
			pnew->data = s;
			pnew->link = ptr->link;
			ptr->link = pnew;
			printf("Inserted after %d\n", s);
		}
	}
		
}

void del_f(){
	if(header == NULL){
		printf("List Empty\n");
	}else{
		ptr = header;
		header = header->link;
		free(ptr);
		printf("Deleted\n");
	}
}

void del_e(){
	if(header == NULL){
		printf("List Empty\n");
	}else{
		ptr = header;
		while(ptr->link != NULL){
			ptr2 = ptr;
			ptr = ptr->link;
		}
		if(header == ptr){
			header = NULL;
		}else{
			ptr2->link = NULL;
		}
		free(ptr);
		printf("Deleted\n");
	}
}

void del_k(int key){
	if(header == NULL){
		printf("List Empty\n");
	}else{
		ptr = header;
		while((ptr->link != NULL) & (ptr->data != key)){
			ptr2 = ptr;
			ptr = ptr->link;
		}
		if(ptr->data != key){
			printf("Not found\n");
		}else{
			if(header == ptr){
				header = NULL;
			}else{
				ptr2->link = ptr->link;
			}
			free(ptr);
			printf("%d Deleted\n", key);
		}
	}
}

void dis(){
	ptr = header;
	if(header == NULL){
		printf("List Empty\n");
	}
	while(ptr != NULL){
		printf("%d\t%p\n", ptr->data, ptr->link);
		ptr = ptr->link; 
	}
}


	
	
void main()
{
	int a,k,s,f=1;
	printf("1.insert_front\n2.insert_end\n3.insert_key\n4.delete_end\n5.delete_front\n6.display\n7delete_key\n0.to stop\n");
	do{printf("enter option");
	scanf("%d",&a);
			switch(a)
			{
				case 1:
								printf("enter element");
								scanf("%d",&s);
								ins_f(s);
								break;
						
				case 2:
								printf("enter element");
								scanf("%d",&s);
								ins_e(s);
								break;
				case 3:
								printf("enter element\n");
								printf("enter key");
						
								scanf("%d\n%d",&s,&k);
								ins_k(s,k);
								break;
				case 4:
						
								del_e();
								break;
				case 5: 
						
								del_f();
								break;
				case 6:
						
								dis();
								break;
				case 7:
								printf("enter key");
								scanf("%d",&s);
								del_k(s);
								break;
				case 0 :
							f=0;
							break;
				default: 
								 printf("invalid input");
								 break;
			}
			}while(f!=0);
	
	printf("\n");
}

	
	
	
	
	
