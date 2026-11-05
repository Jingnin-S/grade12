Status StrAssign(SString T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSTRLEN)
        return ERROR;
    else{
        T[0]=strlen(chars);
        for(i=1;i<=T[0];i++)
        {
            T[i]=*(chars+i-1);
        }
    }
}
Status StrCopy(SString T,SString S)
{
    int i;
    for(i=0;i<=S[0];i++)
    {
        T[i]=S[i];
        
    }
    return OK;

}
Status StrEmpty(SString T)
{
    if(T[0]==0)
        return TRUE;
    else
        return FALSE;
}
Status StrCompare(SString S,SString T)
{
    int i;
    for(i=1;i<=S[0]&&i<=T[0];i++)
    {
        if(S[i]!=T[i])
        {
            return S[i]-T[i];
        }

    }
    return S[0]-T[0];
}
Status StrLength(SString T)
{
    return T[0];
}
Status ClearString (SString S)
{
    S[0]=0;
    return OK;
}
Status Concat(SString T,SString S1,SString S2)
{
    int i;
    if(S1[0]+S2[0]<=MAXSTRLEN)
    {
        for(i=1;i<=S1[0];i++)
        {
            T[i]=S1[i];
        }
        for(i=1;i<=S2[0];i++)
        {
            T[S1[0]+i]=S2[i];
        }

        return OK;
    }
    
    else
    {
        for(i=1;i<=S1[0];i++)
        {
            T[i]=S1[i];
        }
        for(i=1;i<=S2[0];i++)
            T[S1[0]+i]=S2[i];
        T[0]=MAXSTRLEN;
        return FALSE;
    }
Status SubString(SString Sub,SString S,int pos,int len)
{
        int i;
        if(pos<1||pos>S[0]||len>S[0]||len>S[0]-pos+1)
            return ERROR;
        for(i=1;i<=len;i++)
            Sub[i]=S[pos+i-1];
        SUb[0]=len;
        return OK;
}
void StrPrint(SString S)
{
        int i;
        for(i=0;i<S[0];i++)
        {
            printf("%c ",S[i]);

        }
        printf("\n");
}
int Index(SString S,SString T,int pos)
{
    int i,j;
    if(pos>=1&&pos<=S[0])
    {
        i=pos;
        j=1;
        while(i<=S[0]&&j<=T[0])
        {
            if(S[i]==T[i])
            {
                ++i;
                ++j;
            }
            else{
                i=i-j+2;
                j=1;
            }
        }
        if(j>T[0])
            return i-T[0];
        else
            return 0;
    }
    else
        return 0;
}