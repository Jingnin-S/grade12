/*几种排序的算法*/
//插入排序
void InsertSort(int a[])//直接插入排序
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        a[0]=a[i];
        j=i-1;
        while(a[0]<a[j])
        {
            a[j+1]=a[j--];
        }
        a[j+1]=a[0];
    }
}//时间复杂度O（n²）


/*交换排序*/
void BubbleSort(int a[],int n)//冒泡排序
{
    int i,j,flag;
    rectype t;
    for(i=0;i<n;i++)
    {
        flag=1;
        for(j=n-2;j>=i;j--)
        {
            if(a[j+1]<a[j])
            {
                t=a[j+1];
                a[j+1]=1[j];
                a[j]=t;
                flag=-1;
            }
            if(flag)
                break;
        }
    }
}//时间复杂度O（n²）

int quickSrot(int a[],int low,int high)//快速排序步骤一
{
    int i,j;
    RecType t;
    i=low;
    j=high;
    t=a[i];
    do{
        while(a[j]>t&&i<j)
            j--;
        if(i<j)
            a[i++]=a[j];
        while(a[i]<t&&i<j)
            i++;
        if(i<j)
            a[j--]=a[i];
        
    }while(i<j);
    a[i]=t;
    return i;
}
void quickSort2(int a[],int low, int high)//对a[low]到a[high]进行快速排序步骤二
//对整个文件a[0]到a[n-1]排序，只需调用quickSort2(a,0,n-1)即可
{
    int i;
    if(low<high)
    {
        i=quickSrot(a,low,high);
        quickSort2(a,low,i-1);
        quickSort2(a,i+1,high);
        //分别递归处理左区间和右区间
    }
}//时间复杂度O（n²）

void SelectSort(int a[],int n)//简单选择排序
{
    int i,j,k;
    RecType t;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;i++)
        {
            if(a[j]<a[k])
                k=j;
        }
        if(k!=i)
        {
            t=a[i];
            a[i]=a[k];
            a[k]=t;
        }
    }

}//时间复杂度O（n²）


/*查找算法————顺序查找，二分查找，二叉排序树，简单哈希表*/
int SqSearch(int R[],int k,int n)//顺序查找
{
    int i;
    R[0]=k;
    for(i=n;R[i]!=k;i--)
    return i;
}//时间复杂度O[n]

int BinSearch(int R[],int k,int n)//二分查找
{
    int low,mid,high;
    low;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(k==R[mid])
            return mid;
        if(k<R[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

void SearchBST(BiTree &T,KeyType key,BiTree f, BiTree &p,Status &flag) { 
    /*二叉树查找1*/
  //若查找成功，则指针p指向该数据元素结点，并返回TRUE，否则指针p指
  //向查找路径上访问的最后一个结点并返回FALSE,指针f指向T的双亲，其初
  //始调用值为NULL
   if(!T) {p=f; flag=FALSE; } // 查找不成功
   else if EQ(key,T->data.key) 
  {p=T; flag=TRUE;}  //查找成功
   else if LT(key,T->data.key)
    // 在左子树中继续查找
     SearchBST(T->lchild,key,T,p,flag); 
   else
     //在右子树中继续查找
     SearchBST(T->rchild,key,T,p,flag);
 }
Status InsertBST(BiTree &T, ElemType e)
/*二叉树查找2*/
 { //当二叉排序树T中不存在关键字等于e.key的数据元素时，插入e并返回
   //TRUE，否则返回FALSE。
   SearchBST(T, e.key, NULL, p, flag);
   if(!flag) { // 查找不成功
     s=(BiTree)malloc(sizeof(BiTNode));
     s->data=e;  s->lchild=s->rchild=NULL;
     if(!p)  T=s; // 被插结点*s为新的根结点
     else if LT(e.key,p->data.key)
       p->lchild=s; // 被插结点*s为左孩子
     else  p->rchild=s; // 被插结点*s为右孩子
     return TRUE;
   }
   else // 树中已有关键字相同的结点，不再插入
   return FALSE; 
}





void ShellSort(Seqlist R,int d[])//希尔排序 不考
{
    int i,j,k,h;
    rectype temp;
    int maxint =32767;
    for(i=0;i<d[0];i++)
    {
        R[i].key=-maxint;//设置哨兵

    }
    k=0;
    do{
    h=d[k];//取本躺增量
    for(i=h+d[i];i<n+d1;i++)
    {
        temp=R[i];
        j=i-n;
        while(temp.key<R[j].key)
        {
            R[j+h]=R[j];
            j=j-h;
        }
        R[j+h]=temp;
    }
    k++;
    }while(h!=1)

}