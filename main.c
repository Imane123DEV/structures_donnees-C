#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int val;
    struct list *next;
}cell;

cell *init(int v)
{
    cell * nouv=NULL;
    nouv = (cell*)malloc(sizeof(cell));
    nouv-> val=v;
    nouv->next=NULL;
    return nouv;
}

cell *ajout_tete(cell *T,cell * v)
{
    v->next=T;
    T=v;
    return T;
}

cell *ajout_queue(cell *T,cell * v)
{
    cell *p=NULL;
    p=T;
    if (T==NULL)
        T=v;
    else
    {
        while(p->next)
            p=p->next;
        p->next=v;
    }
    return T;
}

void printL(cell *T)
{
    cell * p=NULL;
    p=T;
    while (p!=NULL)
    {
        printf("%d \n",p->val);
        p=p->next;
    }
}

int puiss(int x,int n)
{
    int p=1;
    for(int i=0;i<n;i++)
        p*=x;
    return p;
}

int poly(cell *T, int x)
{
    int s=0,i;
    cell *p=T;
    for(i=0,p=T;p;p=p->next,i++)
    {
        s+=p->val*puiss(x,i);
    }
    return s;
}

int main()
{
    int v,n,i,x;
    cell *T=NULL,*nouv=NULL,*T2=NULL;
    printf("saisir le degre de poly : ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("saisir le coef degre %d : ",i);
        scanf("%d",&v);
        nouv=init(v);
        T=ajout_queue(T,nouv);
    }
    printL(T);
    printf("saisir x : ");
    scanf("%d",&x);
    printf("P(%d) = %d",x,poly(T,x));
    return 0;
}
