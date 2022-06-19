//菜单
void Menu() {
	printf("*************************************************\n");
	printf("*\t\t欢迎使用房屋管理信息系统\t*\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.创建房屋管理信息表\t\t*\n");  //Create() 
	printf("*\t\t2.添加房屋管理信息记录\t\t*\n");  //Add()
	printf("*\t\t3.查找记录\t\t\t*\n");  //Find()
	printf("*\t\t4.修改记录\t\t\t*\n");  //Alter()
	printf("*\t\t5.删除记录\t\t\t*\n");  //Delete()
	printf("*\t\t6.显示所有记录\t\t\t*\n");  //List()
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("*************************************************\n");
	return;
}

void editMenu(){
	printf("请输入要修改的内容\n");
	printf("1.修改房屋号\n");
	printf("2.修改售房者姓名\n");
	printf("3.修改中介职工姓名\n");
	printf("4.修改价格\n");
	printf("0.退出系统\n");
	return;
}
