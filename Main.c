#include<stdio.h>
#include"Menu.h"
#include"Link.h"

table sheet[10];  //��

int isSheetNameRepart(char name[10]);  //�жϱ����Ƿ��ظ� 
void create();  //������
link* seleteLink();  //ѡ��Ҫ�����ı� 
void printHouse(house data);  //��ʽ�����House 
void refresh();  //ˢ��ҳ�� 
void add();  //���Ԫ�� 
int findHouseNumber(link temp[1]);  //���ݷ��ݺŲ��Ҷ�Ӧ���� 
void find();  //���Ҽ�¼
void del();  //ɾ����¼ 
void edit();  //�༭��¼ 
void list();  //��ʾ���м�¼ 
int isHouseNumberRepart(link linked,char name[10]);  //�жϷ��ݺ��Ƿ��ظ� 

//�жϱ����Ƿ��ظ� 
int isSheetNameRepart(char name[10]){
	int i = 0;
	for(;i <= 9 && strcmp(sheet[i].name,name);i++);
	return i == 10 ? 0 : 1;
}

//�жϷ��ݺ��Ƿ��ظ� 
int isHouseNumberRepart(link linked,char name[10]){
	if(!strcmp(name,"\0") || findNode(linked,name)){
		printf("���ݺ�Ϊ�ջ������Ѵ��ڵļ�¼�ظ�,��������ݺź�����\n");
		return 1;
	}
	return 0;
}

//1.�������ݹ�����Ϣ��
void create(){
	char name[10];
	printf("���������.\n");
	if(!strcmp(gets(name),"\0") || isSheetNameRepart(name)) {
		printf("����Ϊ�ջ��ظ�,����������\n");
		return;
	}
	int i = 0;
	//�ҵ�˳����л�δ�������λ��. 
	for(;i <= 9 && strcmp(sheet[i].name,"\0");i++);
	if(i == 10){
		printf("�޷�����,�Դﵽ�ɴ�����������(10/10).\n");
		return;
	}
	strcpy(sheet[i].name,name);
	sheet[i].Link = NULL;
	printf("�ѳɹ�������<%s>.\n",name);
	return;
}

//ѡ��Ҫ�����ı� 
link* seleteLink(){
	if(!strcmp(sheet[0].name,"\0")){
		printf("ϵͳ��ǰ�޿ɲ�����,���ȴ�����.\n");
		return NULL;
	}
	printf("��ѡ��Ҫ�����ı�.(���)\n");
	int i = 0;
	for(;i <= 9 && strcmp(sheet[i].name,"\0");i++){
		printf("%d. %s\n",i,sheet[i].name);
	}
	return &sheet[i = getch()].Link;
}

//��ʽ�����house��Ϣ
void printHouse(house data){
	printf("%s,%s,%s,%f\n",data.num,data.name1,data.name2,data.money);
	return;
}

//ˢ�� 
void refresh(){
	system("pause");  //��ͣ
	system("cls");    //����
	return;
}

//2.��Ӽ�¼ 
void add(){
	link* linked;
	char name[10];
	linked = seleteLink();
	house data;
	printf("�����뷿�ݺ�\n");
	scanf("%s",name);
	scanf("%*[^\n]%*c");  //��ջ����� 
	if(isHouseNumberRepart(*linked,name)){
		return;
	}
	strcpy(data.num,name);
	printf("�������۷�������\n");
	scanf("%s",data.name1);
	scanf("%*[^\n]%*c");
	printf("�������н�ְ������\n");
	scanf("%s",data.name2);
	scanf("%*[^\n]%*c");
	printf("�����뷿�����ۼ۸�\n");
	scanf("%f",&data.money);
	scanf("%*[^\n]%*c");
	append(linked,data);
	printf("��ӳɹ�\n%s,%s,%s,%f/n",data.num,data.name1,data.name2,data.money); 
	return;
} 

//���ݷ��ݺŲ��Ҷ�Ӧ���� 
int findHouseNumber(link temp[1]){
	temp[0] = *seleteLink();
	char name[10];
	printf("������Ҫ�����ķ��ݺ�\n");
	scanf("%s",name);
	scanf("%*[^\n]%*c");
	temp[1] = findNode(temp[0],name);
	if(!temp[1]){
		return 1;
	}
	return 0;
}

//3.���Ҽ�¼
void find(){
	link temp[1];
	findHouseNumber(temp);
	printHouse(temp[1]->data);
	return;
}

//5.ɾ����¼ 
void del(){
	link* linked = seleteLink();
	if(!*linked){
		return;
	}
	char name[10];
	printf("������Ҫɾ���ķ��ݺ�\n");
	scanf("%s",name);
	scanf("%*[^\n]%*c");
	//����ȱ���ж�����ı�ɾ���ķ��ݺ��Ƿ����
	//���ɾ�������ڵķ��ݺžͻᱨ�� 
	Node* noded = findNode(*linked,name);
	remo(linked,noded);
	return;
}

//4.�༭��¼ 
void edit(){
	link temp[1];
	if(findHouseNumber(temp)){
		printf("���ݺŲ�����.\n");
		return;
	}
	house* data = &temp[1]->data;
	editMenu(); 
	char ch = getch();
	switch(ch){
		case '1':
			printf("�������޸ĺ�ķ��ݺ�\n");
			char name[10];
			scanf("%s",name);
			scanf("%*[^\n]%*c");
			if(isHouseNumberRepart(temp[0],name)){
				return;
			}
			strcpy(data->num,name);
			break;
		case '2':
			printf("�������޸ĺ���۷�������\n");
			scanf("%s",data->name1);
			scanf("%*[^\n]%*c");
			break;
		case '3':
			printf("�������޸ĺ���н�ְ������\n");
			scanf("%s",data->name2);
			scanf("%*[^\n]%*c");
			break;
		case '4':
			printf("�������޸ĺ�ļ۸�\n");
			scanf("%f",&data->money);
			scanf("%*[^\n]%*c");
			break;
		case '0':
			return;
		default:
			printf("��������û�иù���\n\n");
			return;
	}	
	return;
} 

//6.��ʾ���м�¼ 
void list(){
	link* linked;
	linked = seleteLink();
	Node* current = *linked;
	int i = 0;
	while(current){
		printf("%d. ",i++);
		printHouse(current->data);
		current = current->next;
	}
	return; 
}

int main(){
	
	while(1){
		Menu();
		char ch = getch();
		switch(ch){
		case '1'://1.�������ݹ�����Ϣ��
			create();
			refresh();
			break;
		case '2'://2.��ӷ��ݹ�����Ϣ��¼
			add();
			refresh();
			break;
		case '3'://3.���Ҽ�¼
			find();
			refresh();
			break;
		case '4'://4.�޸ļ�¼
			edit();
			refresh();
			break;
		case '5'://5.ɾ����¼
			del();
			refresh();
			break;
		case '6'://6.��ʾ���м�¼
			list();
			refresh();
			break;
		case '0'://0.�˳�ϵͳ
			return 0;
			break;
		default:
			printf("��������û�иù���\n\n");
			refresh();
			break;
		}
	}	
	return 0;
} 
