#include <stdio.h>
#include <stdlib.h>

struct NodeList
{
	int data;
	struct NodeList * p_next;
};

typedef struct NodeList * NodeListPtr;

/** 
 * @description 显示链表中数据，输入链表中表头
 * 
 * @author athnkk 
 * @date 2018.3.23 
 * @param p_head 链表表头
 * @return uiseq 返回链表中数据个数
 * @since V1
 */ 
unsigned int ShowNodeList(NodeListPtr p_head)
{
	NodeListPtr p_ptr = 0;
	unsigned int uiseq = 0;
	if(0 == p_head)
		return 0;
	p_ptr = p_head;
	while( 0 != p_ptr)
	{
		printf("\n\t\t%d\t\t\%d", uiseq, p_ptr->data);
		uiseq++;
		p_ptr = p_ptr->p_next;
	}
	return uiseq;
}

/** 
 * @description 插入数据，在表尾插入数据
 * 
 * @author athnkk 
 * @date 2018.3.23 
 * @param p_head 链表表头
 * @param data 插入的数据
 * @return p_head 返回链表表头
 * @since V1
 */ 
NodeListPtr InsertNodeList(NodeListPtr p_head, int data)
{
	unsigned int uiseq = 0;
	NodeListPtr p_ptr = 0;

	if(0 == p_head)
		return 0;
	NodeListPtr p_insert;
	p_insert = (NodeListPtr)malloc(sizeof(struct NodeList));
	if (0 == p_head)
	{
		return p_head;
	}
	p_ptr = p_head;
	while( 0 != p_ptr)
	{
		if (0 == p_ptr->p_next)
		{
			p_ptr->p_next = p_insert;
			p_insert->data = data;
			p_insert->p_next = 0;
			return p_head;
		}
		p_ptr = p_ptr->p_next;

	}
	return p_head;
}

/** 
 * @description 在指定位置插入数据
 * 
 * @author athnkk 
 * @date 2018.3.23 
 * @param p_head 链表表头
 * @param data 插入的数据
 * @param cursor 要插入的数据位置
 * @return p_head 返回链表表头
 * @since V1
 */ 
NodeListPtr InsertNodeListWithCursor(NodeListPtr p_head, int cursor, int data)
{
	unsigned int uiseq = 0;
	NodeListPtr p_ptr = 0,p_temp;

	if(0 == p_head)
		return 0;
	if(0 == cursor)
		return p_head;

	NodeListPtr p_insert;
	p_insert = (NodeListPtr)malloc(sizeof(struct NodeList));
	if (0 == p_insert)
	{
		return p_head;
	}

	p_ptr = p_head;
	while( 0 != p_ptr)
	{
		p_temp = p_ptr->p_next;
		if (uiseq == cursor)
		{
			p_ptr->p_next = p_insert;
			p_insert->data = data;
			p_insert->p_next = p_temp;
			return p_head;
		}
		p_ptr = p_ptr->p_next;
		uiseq++;

	}
	return p_head;
}

/** 
 * @description 查找数据
 * 
 * @author athnkk 
 * @date 2018.3.23 
 * @param p_head 链表表头
 * @param data 要查询的数据
 * @return uiseq 返回链表表序列号
 * @since V1
 */ 
unsigned int FindNodeList(NodeListPtr p_head, int data)
{
	unsigned int uiseq = 0;
	NodeListPtr p_ptr = 0;

	if(0 == p_head)
		return -1;

	p_ptr = p_head;
	while( 0 != p_ptr)
	{
		if (data == p_ptr->data)
		{
			return uiseq;
		}
		p_ptr = p_ptr->p_next;
		uiseq++;

	}
	return uiseq;
}

/** 
 * @description 链表数据排列按照升序排列
 * 
 * @author athnkk 
 * @date 2018.3.23 
 * @param p_head 链表表头
 * @return -1 返回报错
 * @since V1
 */ 
unsigned int SortNodeListAesc(NodeListPtr p_head)
{
	NodeListPtr p_ptr = 0, p_pmin = 0;
	unsigned int uitemp = 0;
	unsigned int uimin = 0;

	if(0 == p_head)
		return -1;

	p_ptr = p_head;
	p_pmin = p_head;
	while(0 != p_ptr)
	{
		while(0 != p_pmin)
		{
			if (p_pmin->data < p_ptr->data)
			{
				uitemp = p_pmin->data;
				p_pmin->data = p_ptr->data;
				p_ptr->data = uitemp;
			}
			p_pmin = p_pmin->p_next;
		}
		p_ptr = p_ptr->p_next;
		p_pmin = p_ptr;
	}
	return 0;
}

/** 
 * @description 链表数据排列按照升序排列
 * 
 * @author athnkk 
 * @date 2018.3.23 
 * @param p_head 链表表头
 * @return -1 返回报错
 * @since V1
 */ 
unsigned int DeleteNodeList(NodeListPtr* p_head)
{
	NodeListPtr p_ptr = 0;

	if(0 == p_head)
		return -1;

	p_ptr = *p_head;
	while(0 != *p_head)
	{	
		p_ptr = *p_head;
		*p_head = (*p_head)->p_next;
		free(p_ptr);
		
	}
	return 0;
}


int mian_test1(void)
{

	printf("\n[mian_test1]Enter mian_test1.");
	unsigned int uinum = 0;
	unsigned int uiseq = 0;
	NodeListPtr p_head;
	p_head = (NodeListPtr)malloc(sizeof(struct NodeList));
	if (0 == p_head)
	{
		return 0;
	}
	p_head->data = 0;
	p_head = InsertNodeList(p_head, 121);
	p_head = InsertNodeList(p_head, 243);
	p_head = InsertNodeList(p_head, 312);
	p_head = InsertNodeList(p_head, 42);
	p_head = InsertNodeList(p_head, 576);
	printf("\n====================Show Node List=============================");
	printf("\n\t\tSeq\t\tValue");
	uinum = ShowNodeList(p_head);
	printf("\n[mian_test1]List Node num = %d.", uinum);
	uiseq = FindNodeList(p_head, 42);
	printf("\n[mian_test1]List Node seq = %d.", uiseq);

	p_head = InsertNodeListWithCursor(p_head, 2,2221);
	p_head = InsertNodeListWithCursor(p_head, 2,2222);
	p_head = InsertNodeListWithCursor(p_head, 2,2223);
	printf("\n====================Insert Node List=============================");
	printf("\n\t\tSeq\t\tValue");
	uinum = ShowNodeList(p_head);
	printf("\n[mian_test1]List Node num = %d.", uinum);	
	uiseq = FindNodeList(p_head, 42);
	printf("\n[mian_test1]List Node seq = %d.", uiseq);

	printf("\n====================Sort Node List=============================");
	printf("\n\t\tSeq\t\tValue");
	(void)SortNodeListAesc(p_head);
	uinum = ShowNodeList(p_head);
	printf("\n[mian_test1]List Node num = %d.", uinum);	
	uiseq = FindNodeList(p_head, 42);
	printf("\n[mian_test1]List Node seq = %d.", uiseq);

	printf("\n====================Delete Node List=============================");
	printf("\n\t\tSeq\t\tValue");
	(void)DeleteNodeList(&p_head);
	uinum = ShowNodeList(p_head);
	printf("\n[mian_test1]List Node num = %d.", uinum);	
	uiseq = FindNodeList(p_head, 42);
	printf("\n[mian_test1]List Node seq = %d.", uiseq);

	printf("\n[mian_test1]finish mian_test1.");	

	return 0;
}

int main(int argc, char* argv[])
{
	unsigned int uiret = 0;

	uiret += mian_test1();// 创建链表，显示数据，插入数据，升序排序，删除数据

	printf("\n[test]finish test.");
	return 0;
}

