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

cell *circulaire(cell *T)
{
    cell *p=T;
    while(p->next)
        p=p->next;
    p->next=T;
    return T;

}

cell *ordonner(cell *T)
{
    if (T->next==T)
        return T;
    cell *p=NULL,*q=NULL;
    for (p=T;;p=p->next)
    {
        for (q=p->next;q!=T;q=q->next)
        {
            if (p->val>q->val) {
                int tmp =p->val;
                p->val=q->val;
                q->val=tmp;
            }
        }
        if (p->next==T)
        break;
    }

}

void print(cell *T)
{
    cell *p=T;
    do
    {
        printf("%d\n",p->val);
        p = p->next;
    }while(p!= T);
}


int main()
{
    int n,v,i;
    cell *liste=NULL,*nouv=NULL;
    do
    {
        printf("saisir la taille de la liste (positif) : ");
        scanf("%d",&n);
    }while (n<=0);;
    for (i=0;i<n;i++)
    {
        printf("\nSaisir l'element %d de la liste : ",i);
        scanf("%d",&v);
        nouv=init(v);
        liste=ajout_tete(liste,nouv);
    }
    liste=circulaire(liste);
    print(liste);
    liste=ordonner(liste);
    printf("la liste ordonnee : \n");
    print(liste);
    return 0;
}
