//shiftparser.c
#include <stdio.h>
#include <string.h>
//initializing first element in stk as $
char stack[50]="$", input[50];
char lhs[10], rhs[10][10]; // stores left side production and right side production into the array
int top=0, n;
/* reduction */
int reduce()
{   int i,len,pos;
    for(i=0;i<n;i++)
    {   len=strlen(rhs[i]);
        pos=top-len+1;
        if(pos>=1 && strncmp(&stack[pos],rhs[i],len)==0)
//pos>=1 -- to ignore the $ sym , and compare with stl[1..3]==rhs[] then reduce else keep checking with rest prod rules
        {
            stack[pos]=lhs[i];
            stack[pos+1]='\0';
            top=pos;
            printf("%-10s %-10s REDUCE %c->%s\n", stack,input,lhs[i],rhs[i]);
            return 1;
        }  }
    return 0;
}
int main()
{   int i,ip=0;
    printf("ENTER NO: OF PRODUCTIONS: ");
    scanf("%d",&n);
    printf("ENTER PRODUCTIONS (E->E+E):\n");
    for(i=0;i<n;i++)
    {//prod is used as temp to help rhs and lhs store stuff
        char prod[20]; 
        scanf("%s",prod);

        lhs[i]=prod[0];
        strcpy(rhs[i],prod+3);
    }
    printf("ENTER INPUT STRING -end with $ : ");
    scanf("%s",input);
    printf("\nSTACK      INPUT      ACTION\n");
    printf("--------------------------------\n");
    while(input[ip]!='$')
    {
        stack[++top]=input[ip++];
        stack[top+1]='\0';
        printf("%-10s %-10s SHIFT\n", stack,input+ip);
        while(reduce());
    }
    while(reduce());
    if(top==1)
        printf("\nSTRING ACCEPTED\n");
    else
        printf("\nSTRING REJECTED\n");
    return 0; }
