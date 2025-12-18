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

cell *permuter(cell *L,int a , int b)
{
    if (a==b||L==NULL)
        return L;
    if (a>b)
    {
        int tmp=a;
        a=b;
        b=tmp;
    }
    cell *t=L,*v=L;
    int i;
    for(i=0;i<a;i++,t=t->next);
    for(i=0;i<b;i++,v=v->next);
    if (!t||!v)
        return L;
    int c;
    c=t->val;
    t->val=v->val;
    v->val=c;
    return L;
}

int main()
{
    int n,v,i,a,b;
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
    printf("donner la position des cellules a permuter : ");
    scanf("%d",&a);
    scanf("%d",&b);
    liste=permuter(liste,a,b);
    printf("la liste apres permutation : \n");
    print(liste);
    return 0;
}
