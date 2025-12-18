#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int val;
    struct cel *next;
    struct cel *prec;
}cell;

cell *init(int v) {
    cell *nouv = malloc(sizeof(cell));
    nouv->val=v;
    nouv->next=NULL;
    nouv->prec=NULL;
    return nouv;
}

cell *ajout_tete(cell *T, cell *n) {
    n->next=T;
    if (T != NULL)
        T->prec=NULL;
    return n;
}

void print(cell *T)
{
    cell *p=NULL;
    for (p=T;p;p=p->next)
        printf("%d \n",p->val);
}

void chainage_arriere(cell *T)
{
    if (T==NULL)
        return;
    cell *p=T;
    p->prec=NULL;
    while (p->next)
    {
        p->next->prec=p;
        p=p->next;
    }
}

void print_arriere(cell *T) {
    cell *p=T;
    while (p->next!=NULL)
        p=p->next;
    printf("chainage arriere : \n");
    while (p)
    {
        printf("%d \n",p->val);
        p=p->prec;
    }
}

int main()
{
    int n,i,v;
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
    chainage_arriere(liste);
    print_arriere(liste);
    return 0;
}
