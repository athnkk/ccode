#include <stdio.h>
#include <stdlib.h>

struct TreeList
{
	int data;
	struct TreeList * p_leftleaf;
	struct TreeList * p_rightleaf;
};

typedef struct TreeList * TreeListPtr;

/** 
 * @ingroup tree
 * @description 在二叉树里插入数据，用递归的方式.形成二叉树不是二叉查找树.
 * 
 * @author athnkk 
 * @date 2018.3.27
 * @param p_leaf 二叉树叶子节点
 * @param data 要插入的数据
 * @return -1 返回异常
 * @since V1
 */ 
unsigned int InsertTreedataWithRecursive(TreeListPtr p_leaf, unsigned int data)
{
	if (p_leaf == 0)
	{
		return -1;
	}

	TreeListPtr p_insert = 0, p_ptr = 0;
	p_insert = (TreeListPtr)malloc(sizeof(struct TreeList));
	if (0 == p_insert)
	{
		return 0;
	}
	p_insert->data = data;
	p_insert->p_rightleaf = 0;
	p_insert->p_leftleaf = 0;

    p_ptr = p_leaf;
	if (data >= p_ptr->data)
	{
		if (p_ptr->p_rightleaf == 0)
		{
			p_ptr->p_rightleaf = p_insert;
			printf("\n insert right leaf, data = %d, parent data = %d", data, p_ptr->data);
			return 0;
		}
		else
		{
			(void)InsertTreedataWithRecursive(p_ptr->p_rightleaf, data);
		}
	}
	if (data < p_ptr->data)
	{
		if (p_ptr->p_leftleaf == 0)
		{
			p_ptr->p_leftleaf = p_insert;
			printf("\n insert left leaf, data = %d, parent data = %d", data, p_ptr->data);
			return 0;
		}
		else
		{
			(void)InsertTreedataWithRecursive(p_ptr->p_leftleaf, data);
		}
	}
	return 0;
}

/** 
 * @ingroup tree
 * @description 在二叉树里插入数据，用查找叶子节点后插入数据的方式.形成二叉树不是二叉查找树.
 * 
 * @author athnkk 
 * @date 2018.3.27 
 * @param p_leaf 二叉树叶子节点
 * @param data 要插入的数据
 * @return -1 返回异常
 * @since V1
 */ 
unsigned int InsertTreedataWithSeek(TreeListPtr p_leaf, unsigned int data)
{
	if (p_leaf == 0)
	{
		return -1;
	}

	TreeListPtr p_insert = 0, p_ptr = 0, p_parent = 0;
	p_insert = (TreeListPtr)malloc(sizeof(struct TreeList));
	if (0 == p_insert)
	{
		return -1;
	}
	p_insert->data = data;
	p_insert->p_rightleaf = 0;
	p_insert->p_leftleaf = 0;

    p_ptr = p_leaf;
	while(0 != p_ptr)
	{
		p_parent = p_ptr;
		if (data >= p_ptr->data)
		{
			p_ptr  = p_ptr->p_rightleaf;
		}
		else
			p_ptr  = p_ptr->p_leftleaf;
	}

	if (data >= p_parent->data)
	{
		p_parent->p_rightleaf = p_insert;
		printf("\n insert right leaf, data = %d, parent data = %d", data, p_parent->data);
	}
	else
	{
		p_parent->p_leftleaf = p_insert;
		printf("\n insert left leaf, data = %d, parent data = %d", data, p_parent->data);
	}
		


	return 0;
}

/** 
 * @ingroup tree
 * @description 前序显示二叉树数据.
 * 
 * @author athnkk 
 * @date 2018.3.27 
 * @param p_leaf 二叉树叶子节点
 * @param data 要插入的数据
 * @return -1 返回异常
 * @since V1
 */ 
void ShowTreeDataPre(TreeListPtr p_leaf)
{
	if (p_leaf != 0)
	{
		printf("\n data = %d", p_leaf->data);
		ShowTreeDataPre(p_leaf->p_leftleaf);
		ShowTreeDataPre(p_leaf->p_rightleaf);
	}
}

/** 
 * @ingroup tree
 * @description 中序显示二叉树数据.
 * 
 * @author athnkk 
 * @date 2018.3.27 
 * @param p_leaf 二叉树叶子节点
 * @param data 要插入的数据
 * @return -1 返回异常
 * @since V1
 */ 
void ShowTreeDataInfix(TreeListPtr p_leaf)
{
	if (p_leaf != 0)
	{
		ShowTreeDataInfix(p_leaf->p_leftleaf);
		printf("\n data = %d", p_leaf->data);
		ShowTreeDataInfix(p_leaf->p_rightleaf);
	}
}

/** 
 * @ingroup tree
 * @description 中序显示二叉树数据.
 * 
 * @author athnkk 
 * @date 2018.3.27 
 * @param p_leaf 二叉树叶子节点
 * @param data 要插入的数据
 * @return -1 返回异常
 * @since V1
 */ 
void ShowTreeDataPost(TreeListPtr p_leaf)
{
	if (p_leaf != 0)
	{
		ShowTreeDataPost(p_leaf->p_leftleaf);
		ShowTreeDataPost(p_leaf->p_rightleaf);
		printf("\n data = %d", p_leaf->data);
	}
}

int mian_test1(void)
{

	printf("\n[mian_test1]Enter mian_test1.");
	unsigned int uinum = 0;
	unsigned int uiseq = 0;
	TreeListPtr p_root;
	p_root = (TreeListPtr)malloc(sizeof(struct TreeList));
	if (0 == p_root)
	{
		return 0;
	}
	p_root->data = 59;
	(void)InsertTreedataWithRecursive(p_root, 49);
	(void)InsertTreedataWithRecursive(p_root, 76);
	(void)InsertTreedataWithRecursive(p_root, 32);
	(void)InsertTreedataWithRecursive(p_root, 89);
	(void)InsertTreedataWithRecursive(p_root, 70);

	printf("\n====================Show Tree List Pre=============================");
	ShowTreeDataPre(p_root);
	printf("\n===================================================================");

	printf("\n====================Show Tree List Infix===========================");
	ShowTreeDataInfix(p_root);
	printf("\n===================================================================");

	printf("\n====================Show Tree List Post============================");
	ShowTreeDataPost(p_root);
	printf("\n===================================================================");
	
	printf("\n[mian_test1]finish mian_test1.");	

	return 0;
}

int mian_test2(void)
{

	printf("\n[mian_test2]Enter mian_test2.");
	unsigned int uinum = 0;
	unsigned int uiseq = 0;
	TreeListPtr p_root;
	p_root = (TreeListPtr)malloc(sizeof(struct TreeList));
	if (0 == p_root)
	{
		return 0;
	}
	p_root->data = 59;
	(void)InsertTreedataWithSeek(p_root, 49);
	(void)InsertTreedataWithSeek(p_root, 76);
	(void)InsertTreedataWithSeek(p_root, 32);
	(void)InsertTreedataWithSeek(p_root, 89);
	(void)InsertTreedataWithSeek(p_root, 70);

	printf("\n====================Show Tree List Pre=============================");
	ShowTreeDataPre(p_root);
	printf("\n===================================================================");

	printf("\n====================Show Tree List Infix===========================");
	ShowTreeDataInfix(p_root);
	printf("\n===================================================================");

	printf("\n====================Show Tree List Post============================");
	ShowTreeDataPost(p_root);
	printf("\n===================================================================");
	
	printf("\n[mian_test2]finish mian_test2.");	

	return 0;
}

int main(int argc, char* argv[])
{
	unsigned int uiret = 0;

	uiret += mian_test1();// 创建二叉树，插入数据，前中后遍历显示,递归显示
	uiret += mian_test2();// 创建二叉树，插入数据，前中后遍历显示,查找显示

	printf("\n[test]finish test.");
	return 0;
}

