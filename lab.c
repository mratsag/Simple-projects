#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	
	int data;
	struct node *next;
	
};
//listenin baþýna ekleme
struct node *addfront(struct node *head,int x){
	
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	
	temp->next=head;
	temp->data=x;
	head=temp;
	return head;

}
//listenin sonuna ekleme
struct node *addlast(struct node *head,int x){
	
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	
	temp->data=x;
	temp->next=NULL;
	
		if(head==NULL){
			head=temp;
		}
		else{
			struct node *last=head;
			
			while(last->next!=NULL){
				
				last=last->next;
			}
			last->next=temp;		
		}return head;
			
}


//belirli bir döðüm silme 
struct node *delete(struct node *head, int key){
	if(head!=NULL){
		struct node *temp=head;
		if(head->data==key){
			head=head->next;
			free(temp);
		}
		else{
			while(temp->next!=NULL && temp->next->data!=key){
				temp=temp->next;
			}
			if(temp->next!=NULL){
				struct node *del=temp->next;
				temp->next=del->next;
				free(del);
			}
		}
	}
	return head;
}

//liste elemanlarýný listeleme
void print(struct node *head){
	
	if(head==NULL){
		printf("there is no element in the list");
	}
	else{
		while(head!=NULL){
			printf("%d ",head->data);
			head=head->next;
		}
	}
}

void print_reverse(struct node *head){
	
		if(head==NULL){
			return;
		}
		print_reverse(head->next);
		printf("%d ",head->data);
		
}




int main(int argc, char *argv[]) {
	
	struct node *head=NULL;

	head=addfront(head,2);
	head=addlast(head,4);
	head=addfront(head,5);
	head=addlast(head,9);
	
	
	print(head);
	printf("\n");
	print_reverse(head);
	printf("\n\n");
	
	
	
	int choice, data;


	do {
        printf("\n----   Menu   ----\n");
        printf("1 - Add Front\n");
        printf("2 - Add Last\n");
        printf("3 - Print\n");
        printf("4 - Print in Reverse Order\n");
        printf("5 - Delete a Node\n");
        printf("6 - Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to add at the front: ");
                scanf("%d", &data);
                head = addfront(head, data);
                break;

            case 2:
                printf("Enter the data to add at the last: ");
                scanf("%d", &data);
                head = addlast(head, data);
                break;

            case 3:
                printf("List elements: ");
                print(head);
                printf("\n\n");
                break;

            case 4:
                printf("List elements in reverse order: ");
                print_reverse(head);
                printf("\n\n");
                break;

            case 5:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                head = delete(head, data);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

    } while (choice != 6);
	
	return 0;
}


