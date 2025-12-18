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

int max_iterative(cell *T)
{
    cell *p=NULL;
    p=T;
    int max=p->val;
    for (p=T;p;p=p->next)
    {
        if (p->val > max)
            max=p->val;
    }
    return max;
}

int max_recursive(cell *T) {
    if (T->next == NULL)
        return T->val;
    int max_suivant = max_recursive(T->next);
    return (T->val > max_suivant) ? T->val : max_suivant;
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
    printf("la valeur maximal (iteratif) est : %d",max_iterative(liste));
    printf("\nla valeur maximal (recursif) est : %d",max_recursive(liste));
    return 0;
}
