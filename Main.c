#include<stdio.h>
#include"Menu.h"
#include"Link.h"

table sheet[10];  //表

int isSheetNameRepart(char name[10]);  //判断表名是否重复 
void create();  //创建表
link* seleteLink();  //选择要操作的表 
void printHouse(house data);  //格式化输出House 
void refresh();  //刷新页面 
void add();  //添加元素 
int findHouseNumber(link temp[1]);  //根据房屋号查找对应区块 
void find();  //查找记录
void del();  //删除记录 
void edit();  //编辑记录 
void list();  //显示所有记录 
int isHouseNumberRepart(link linked,char name[10]);  //判断房屋号是否重复 

//判断表名是否重复 
int isSheetNameRepart(char name[10]){
	int i = 0;
	for(;i <= 9 && strcmp(sheet[i].name,name);i++);
	return i == 10 ? 0 : 1;
}

//判断房屋号是否重复 
int isHouseNumberRepart(link linked,char name[10]){
	if(!strcmp(name,"\0") || findNode(linked,name)){
		printf("房屋号为空或者与已存在的记录重复,请更换房屋号后重试\n");
		return 1;
	}
	return 0;
}

//1.创建房屋管理信息表
void create(){
	char name[10];
	printf("请输入表名.\n");
	if(!strcmp(gets(name),"\0") || isSheetNameRepart(name)) {
		printf("表名为空或重复,请重新输入\n");
		return;
	}
	int i = 0;
	//找到顺序表中还未创建表的位置. 
	for(;i <= 9 && strcmp(sheet[i].name,"\0");i++);
	if(i == 10){
		printf("无法创建,以达到可创建表的最大数(10/10).\n");
		return;
	}
	strcpy(sheet[i].name,name);
	sheet[i].Link = NULL;
	printf("已成功创建表<%s>.\n",name);
	return;
}

//选择要操作的表 
link* seleteLink(){
	if(!strcmp(sheet[0].name,"\0")){
		printf("系统当前无可操作表,请先创建表.\n");
		return NULL;
	}
	printf("请选择要操作的表.(序号)\n");
	int i = 0;
	for(;i <= 9 && strcmp(sheet[i].name,"\0");i++){
		printf("%d. %s\n",i,sheet[i].name);
	}
	return &sheet[i = getch()].Link;
}

//格式化输出house信息
void printHouse(house data){
	printf("%s,%s,%s,%f\n",data.num,data.name1,data.name2,data.money);
	return;
}

//刷新 
void refresh(){
	system("pause");  //暂停
	system("cls");    //清屏
	return;
}

//2.添加记录 
void add(){
	link* linked;
	char name[10];
	linked = seleteLink();
	house data;
	printf("请输入房屋号\n");
	scanf("%s",name);
	scanf("%*[^\n]%*c");  //清空缓存区 
	if(isHouseNumberRepart(*linked,name)){
		return;
	}
	strcpy(data.num,name);
	printf("请输入售房者姓名\n");
	scanf("%s",data.name1);
	scanf("%*[^\n]%*c");
	printf("请输入中介职工姓名\n");
	scanf("%s",data.name2);
	scanf("%*[^\n]%*c");
	printf("请输入房屋销售价格\n");
	scanf("%f",&data.money);
	scanf("%*[^\n]%*c");
	append(linked,data);
	printf("添加成功\n%s,%s,%s,%f/n",data.num,data.name1,data.name2,data.money); 
	return;
} 

//根据房屋号查找对应区块 
int findHouseNumber(link temp[1]){
	temp[0] = *seleteLink();
	char name[10];
	printf("请输入要操作的房屋号\n");
	scanf("%s",name);
	scanf("%*[^\n]%*c");
	temp[1] = findNode(temp[0],name);
	if(!temp[1]){
		return 1;
	}
	return 0;
}

//3.查找记录
void find(){
	link temp[1];
	findHouseNumber(temp);
	printHouse(temp[1]->data);
	return;
}

//5.删除记录 
void del(){
	link* linked = seleteLink();
	if(!*linked){
		return;
	}
	char name[10];
	printf("请输入要删除的房屋号\n");
	scanf("%s",name);
	scanf("%*[^\n]%*c");
	//这里缺少判断输入的被删除的房屋号是否存在
	//如果删除不存在的房屋号就会报错 
	Node* noded = findNode(*linked,name);
	remo(linked,noded);
	return;
}

//4.编辑记录 
void edit(){
	link temp[1];
	if(findHouseNumber(temp)){
		printf("房屋号不存在.\n");
		return;
	}
	house* data = &temp[1]->data;
	editMenu(); 
	char ch = getch();
	switch(ch){
		case '1':
			printf("请输入修改后的房屋号\n");
			char name[10];
			scanf("%s",name);
			scanf("%*[^\n]%*c");
			if(isHouseNumberRepart(temp[0],name)){
				return;
			}
			strcpy(data->num,name);
			break;
		case '2':
			printf("请输入修改后的售房者姓名\n");
			scanf("%s",data->name1);
			scanf("%*[^\n]%*c");
			break;
		case '3':
			printf("请输入修改后的中介职工姓名\n");
			scanf("%s",data->name2);
			scanf("%*[^\n]%*c");
			break;
		case '4':
			printf("请输入修改后的价格\n");
			scanf("%f",&data->money);
			scanf("%*[^\n]%*c");
			break;
		case '0':
			return;
		default:
			printf("输入有误，没有该功能\n\n");
			return;
	}	
	return;
} 

//6.显示所有记录 
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
		case '1'://1.创建房屋管理信息表
			create();
			refresh();
			break;
		case '2'://2.添加房屋管理信息记录
			add();
			refresh();
			break;
		case '3'://3.查找记录
			find();
			refresh();
			break;
		case '4'://4.修改记录
			edit();
			refresh();
			break;
		case '5'://5.删除记录
			del();
			refresh();
			break;
		case '6'://6.显示所有记录
			list();
			refresh();
			break;
		case '0'://0.退出系统
			return 0;
			break;
		default:
			printf("输入有误，没有该功能\n\n");
			refresh();
			break;
		}
	}	
	return 0;
} 
