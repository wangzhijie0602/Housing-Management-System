#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//������Ϣ
typedef struct{
	char num[10];  //���ݺ�
	char name1[10];  //�۷�������
	char name2[10];  //�н�ְ������
	float money;  //�������ۼ۸� 
}house;

//����
typedef struct Node{
	house data;  //������Ϣ 
	struct Node* next;  //��һ����ַ 
}Node,*link;

//�� 
typedef struct{
	char name[10];	//���� 
	link Link;
}table;

Node* createNode(house data);
void remo(link* Head,Node* node);
Node* findNode(link Head,char name[10]);
void append(link* Head,house data);

//��������ڵ� 
Node* createNode(house data){
	Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//ɾ������ 
void remo(link* Head,Node* node){
	//ɾ������ͷ�ڵ� 
	if(*Head == node){
		*Head = (*Head)->next;
		return;
	}
	//ɾ�������м�ڵ� 
	Node* current = *Head;
	for(;current->next != node;current = current->next);
	current->next = current->next->next;
	return;
}

Node* findNode(link Head,char name[10]){
	for(;Head && strcmp(Head->data.num,name);Head = Head->next);
	return Head;
}

//׷������ 
void append(link* Head,house data){
	
	if(*Head == NULL){
		Node* newNode = createNode(data);
		*Head = newNode;
		return;
	}
	Node* current = *Head;
    //��ȡ���һ��ָ��ĵ�ַ
	for(;current->next != NULL;current = current->next);
    //�����½ڵ�
    Node* newNode = createNode(data);
    //����
    current->next = newNode;
    return;
}
