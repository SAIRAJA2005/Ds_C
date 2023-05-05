/*Polynomial represenew_termation using linked lists

    =>create polynomial()
    takes nothing --> no arguemenew_terms
    returns head pointer to the created polynomial

    =>insert_a_term()
    takes head, coeff, expo values
    creates a new_term
    inserts it
    and returns the head back
    
    =>display_polynomial()
    takes head
    prints the polynomial
*/
#include<stdio.h>
#include<stdlib.h>
struct NODE{
    float coeff;
    int exp;
    struct NODE *next;
};
typedef struct NODE node;
node* insert_a_term(node *head, float co, int ex){
    node *new_term=(node *)malloc(sizeof(node));
    new_term->coeff=co;
    new_term->exp = ex;
    new_term->next = NULL;

    if(head == NULL || new_term->exp>head->exp){
    	new_term->next=head;
        head=new_term;
    }
    else{
        node *temp = head;
        while (temp->next != NULL && temp->next->exp>new_term->exp){
            temp = temp->next;
        }
        new_term->next=temp->next;
        temp->next= new_term;
    }
    return head;
}
node* create_polynomial()
{
    node 
	*head =NULL;
    int n,i;
    printf("enter no. of terms: ");
    scanf("%d",&n);
    for( i = 1; i<=n ; i++){
        float co;
        int ex;
        printf("Enter coeff for term %d: ",i);
        scanf("%f",&co);
        printf("Enter exp for term %d: ",i);
        scanf("%d",&ex);
        head = insert_a_term(head,co,ex);
    }
    return head;
}
void display_polynomial(node *head){
    node *temp = head;
    while(temp!= NULL){
        printf("(%.fx^%d)",temp->coeff,temp->exp);
        if(temp->next!=NULL)
		{
            printf(" + ");
        }
        else
		{
            printf("\n");
        }
        temp= temp->next;
    }
}
int main()
{
    //takeinput();
    printf("Polyomial:\n");
    node *poly=create_polynomial();
    display_polynomial(poly);
}
