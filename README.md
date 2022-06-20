# 房屋销售信息管理系统

##### **开发语言：C语言**

**开发工具：Dev c++ v5.11**

## 一、系统界面

![image-20220620135805082](https://oracle.wangzhijie.club/2022/06/7bb1251942d9098c6e2e5ab0967671cf.png)

## 二、系统功能

1. 创建房屋管理信息表
2. 添加房屋管理信息记录
3. 查找记录
4. 修改记录
5. 删除记录
6. 显示所有记录

## 三、系统的实现

系统中分为共有三个结构体,分别为**存储数据的house**,**链表的节点Node**以及**存储链表的表的table**,系统可以创建多个表来存储数据,存储链表的"工作簿"table使用的是顺序表(数组)

```c
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

//工作簿
typedef struct{
	char name[10];	//表名 
	link Link;
}table;
```

