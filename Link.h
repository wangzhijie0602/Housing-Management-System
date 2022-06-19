#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//房屋信息
typedef struct{
	char num[10];  //房屋号
	char name1[10];  //售房者姓名
	char name2[10];  //中介职工姓名
	float money;  //房屋销售价格 
}house;

//链表
typedef struct Node{
	house data;  //房屋信息 
	struct Node* next;  //下一跳地址 
}Node,*link;

//表 
typedef struct{
	char name[10];	//表名 
	link Link;
}table;

Node* createNode(house data);
void remo(link* Head,Node* node);
Node* findNode(link Head,char name[10]);
void append(link* Head,house data);

//创建链表节点 
Node* createNode(house data){
	Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//删除数据 
void remo(link* Head,Node* node){
	//删除的是头节点 
	if(*Head == node){
		*Head = (*Head)->next;
		return;
	}
	//删除的是中间节点 
	Node* current = *Head;
	for(;current->next != node;current = current->next);
	current->next = current->next->next;
	return;
}

Node* findNode(link Head,char name[10]){
	for(;Head && strcmp(Head->data.num,name);Head = Head->next);
	return Head;
}

//追加数据 
void append(link* Head,house data){
	
	if(*Head == NULL){
		Node* newNode = createNode(data);
		*Head = newNode;
		return;
	}
	Node* current = *Head;
    //获取最后一个指针的地址
	for(;current->next != NULL;current = current->next);
    //建立新节点
    Node* newNode = createNode(data);
    //链接
    current->next = newNode;
    return;
}
