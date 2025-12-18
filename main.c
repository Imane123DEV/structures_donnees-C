#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int val;
    struct cel *next;
}cell;

cell *init(int v)
{
    cell *nouv=NULL;
    nouv=(cell*)malloc(sizeof(cell));
    nouv->val=v;
    nouv->next=NULL;
    return nouv;
}

cell * ajout_tete(cell *T, cell *n)
{
    n->next=T;
    T=n;
    return T;
}

void print(cell *T)
{
    cell *p=NULL;
    for (p=T;p;p=p->next)
    {
        printf("%d \n",p->val);
    }
}

cell *inverse_iteratif(cell *T)
{
    cell *p=NULL,*q=T,*next=NULL;
    while(q)
    {
        next=q->next;
        q->next=p;
        p=q;
        q=next;
    }
    return p;
}

cell *inverse_recursif(cell *T) {
    if (T==NULL||T->next==NULL)
        return T;
    cell *reste=inverse_recursif(T->next);
    T->next->next=T;
    T->next=NULL;
    return reste;
}

int main()
{
    int n,v,i;
    cell *liste=NULL,*nouv=NULL;
    do
    {
        printf("saisir la taille de la liste (positif) : ");
        scanf("%d",&n);
    }while (n<=0);
    for (i=0;i<n;i++)
    {
        printf("\nSaisir l'element %d de la liste : ",i);
        scanf("%d",&v);
        nouv=init(v);
        liste=ajout_tete(liste,nouv);
    }
    print(liste);
    liste=inverse_iteratif(liste);
    printf("la liste inverse (iteratif): \n");
    print(liste);
    liste=inverse_recursif(liste);
    printf("la liste inverse (recursif): \n");
    print(liste);
    return 0;
}
