#include "stdio.h"    
#include "stdlib.h"   
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */
#define OVERFLOW 3

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode	/* 结点结构 */
{
	int data;	/* 结点数据 */
	struct BiTNode *lchild, *rchild;	/* 左右孩子指针 */
} BiTNode, *BiTree;

/* 构造空二叉树T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

int idx_s = 0;
int arr[] = {1,2,4,0,0,5,7,0,0,0,3,0,6,0,0};

void CreateBiTree(BiTree *T)
{ 
	int ch;

	ch = arr[idx_s++];
	if(ch == 0) 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; /* 生成根结点 */
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
}

void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%d\t",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%d\t",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%d\t",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}

main()
{

    BiTree T;
    printf("初始化结果：%d\n",InitBiTree(&T));

	CreateBiTree(&T);
    
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");

}