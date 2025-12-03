#include<stdio.h>
#include<string.h>
/*end为posorder中根节点的*/
void trans(char*inorder,char*posorder,char*preorder,int*pindex,int len)
{
    if(len<=0)
    {
        return;
    }
    char root=posorder[len-1];//根为posorder最后一位
    preorder[(*pindex)]=root;//先序中index位改为根
    (*pindex)++;//index索引加一

    int root_dig=0;//查找根节点在中序中的下标
    while(inorder[root_dig]!=root)
    {
        root_dig++;
    }

    int len_left=root_dig;//中序左树长度
    int len_right=len-root_dig-1;//中序右树长度

    trans(inorder,posorder,preorder,pindex,len_left);
    trans(inorder+root_dig+1,posorder+len_left,preorder,pindex,len_right);
    
}

int main()
{
    char inorder[10];
    char posorder[10];
    char preorder[10];
    scanf("%s%s",inorder,posorder);
    int len=strlen(inorder);
    int index=0;
    trans(inorder,posorder,preorder,&index,len);
    preorder[len]='\0';
    printf("%s",preorder);
    return 0;
}