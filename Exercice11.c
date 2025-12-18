#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int val;
    struct cel *next;
} cell;

cell * init(int v)
{
    cell * nouv=NULL;
    nouv = (cell*)malloc(sizeof(cell));
    nouv-> val=v;
    nouv->next=NULL;
    return nouv;
}

cell * ajout_tete(cell * T,cell * n)
{
    n->next=T;
    T=n;
    return T;
}

cell *ajout_queue(cell *T, cell *n) {
    cell *p;
    p=T;
    if (T==NULL)
        T=n;
    else
    {
        while (p->next!=NULL)
            p=p->next;
        p->next=n;
    }
    return T;
}

cell *inverserPile(cell *T)
{
    cell *inv=NULL,*p=NULL;
    for (p=T;p;p=p->next)
        inv=ajout_tete(inv,init(p->val));
    return inv;
}

cell *inverserFile(cell *T) {
    cell *pile=NULL,*inv = NULL,*p=NULL;
    for (p=T;p;p=p->next)
        pile=ajout_tete(pile, init(p->val));
    for (p=pile;p;p=p->next)
        inv=ajout_queue(inv,init(p->val));
    return inv;
}

void print(cell *T)
{
    cell * p=NULL;
    p=T;
    while (p!=NULL)
    {
        printf("%d \n",p->val);
        p=p->next;
    }
}



int main()
{
    int n,i,v;
    cell *pile=NULL,*file=NULL,*pinv=NULL,*finv=NULL,*nouv=NULL;
    do
    {
        printf("saisir la taille de la pile (positif) : ");
        scanf("%d",&n);
    }while (n<=0);
    for (i=0;i<n;i++)
    {
        printf("\nSaisir l'element %d de la pile : ",i);
        scanf("%d",&v);
        nouv=init(v);
        pile=ajout_tete(pile,nouv);
    }
    pinv=inverserPile(pile);

    printf("pile originale : \n");
    print(pile);
    printf("pile inverse  : \n");
    print(pinv);
    printf("\n");
    do
    {
        printf("saisir la taille de la file (positif) : ");
        scanf("%d",&n);
    }while (n<=0);
    for (i=0;i<n;i++)
    {
        printf("\nSaisir l'element %d de la file : ",i);
        scanf("%d",&v);
        nouv=init(v);
        file=ajout_queue(file,nouv);
    }
    finv=inverserPile(file);
    printf("pile originale : \n");
    print(file);
    printf("pile inverse  : \n");
    print(finv);
    return 0;
}
