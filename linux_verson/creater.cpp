#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<unistd.h>

using namespace std;

void head_tell() {//头告示 
	system("clear");
	cout<<"文字转\"色图\"(Novel_In_Image)使用助手"<<endl<<"                       by playeryang01"<<endl<<endl;
	return;
}

void loading_tell(){
	head_tell();
	cout<<"loading..."<<endl<<endl;
}

void show_loading(int time) {//手动加载
	loading_tell();
	sleep(0);
	sleep(time);
	system("clear");
	return;
}

void text2pic() {//输入文本到色图 
	string text,cmd_str;
	char cmd[5200],none;
	head_tell();
	cout<<"请输入要转换的内容(上限5000字左右):"<<endl;
	getchar();//去换行符 
	getline(cin,text);//getline防空格 
	cmd_str="echo "+text+">\"text\"";//合成输出txt文本文件 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);
	system("python bin/nii.py -e text");//调用nii.py文件以转换
	system("cp _layout.bmp color_pictures/text.bmp");//将图片转到color_pictures文件夹 
	system("rm text _layout.bmp");//删除原图片 
	head_tell();//清屏 
	cout<<"转换完成，文件已保存为color_pictures文件夹内的text.bmp，请查收。"<<endl<<endl;
	cout<<"Press an key to continue...";
	getchar();
	return;
}

void txt2pic(){//文本文件转色图，直接由pic2txt改的，变量名有问题 
	head_tell();
	string adr_pic,cmd_str,adr_txt,nm_txt;
	char cmd[500],char_adr_txt[500],char_nm_txt[500];
	cout<<"请输入需转换的文本的文件地址(同文件夹下可输入文件名):"<<endl;
	getchar();//去换行符 
	getline(cin,adr_pic);//getline防空格 
	cmd_str="python bin/nii.py -e "+adr_pic; //合成调用文本 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//调用nii.py文件以转换图片 
	for(int i=adr_pic.length()-1;i>=0;i--){//得到转换的图片的char格式文件地址 
		if(adr_pic[i]=='.'){
			for(int j=0;j<i;j++){
				char_adr_txt[j]=adr_pic[j];
			}
			break;
		}
	}
	for(int i=adr_pic.length()-1;i>=0;i--){//得到转换的图片的char格式文件名 
		if(adr_pic[i]=='/'){
			bool flag=true;
			for(int j=i+1;j<adr_pic.length();j++){
				if(adr_pic[j]=='.'){
					flag=false;
				}
				if(flag){
					char_nm_txt[j-i-1]=adr_pic[j];
				}
			}
			break; 
		}
	}
	adr_txt=char_adr_txt;//char转string 
	adr_txt=adr_txt+"_layout.bmp";//得到完整地址 
	nm_txt=char_nm_txt;//char转string 
	nm_txt=nm_txt+".bmp";//得到完整文件名 
	cmd_str="cp "+adr_txt+" color_pictures/"+nm_txt;//合成命令 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//将图片转到color_pictures文件夹 
	cmd_str="rm "+adr_txt;//合成命令 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//删除原图片 
	head_tell();//清屏 
	cout<<"转换完成，文件已保存为color_pictures文件夹内的"<<nm_txt<<"，请查收。"<<endl<<"若没有，请检查您输入的文件地址。"<<endl<<endl;
	cout<<"Press an key to continue...";
	getchar();
	return;
}

void pic2txt(){//图片转文本文件 
	head_tell();
	string adr_pic,cmd_str,adr_txt,nm_txt;
	char cmd[500],char_adr_txt[500],char_nm_txt[500];
	cout<<"请输入需转换的色图的文件地址(同文件夹下可输入文件名):"<<endl;
	getchar();//去换行符 
	getline(cin,adr_pic);//getline防空格 
	cmd_str="python bin/nii.py -d "+adr_pic;//合成调用文本 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//调用nii.py文件以转换文本 
	for(int i=adr_pic.length()-1;i>=0;i--){//得到转换的文本的char格式文件地址 
		if(adr_pic[i]=='.'){
			for(int j=0;j<i;j++){
				char_adr_txt[j]=adr_pic[j];
			}
			break;
		}
	}
	for(int i=adr_pic.length()-1;i>=0;i--){//得到转换的文本的char格式文件名
		if(adr_pic[i]=='/'){
			bool flag=true;
			for(int j=i+1;j<adr_pic.length();j++){
				if(adr_pic[j]=='.'){
					flag=false;
				}
				if(flag){
					char_nm_txt[j-i-1]=adr_pic[j];
				}
			}
			break;
		}
	}
	adr_txt=char_adr_txt;//char转string 
	adr_txt=adr_txt+"_decode.txt";//得到完整地址 
	nm_txt=char_nm_txt;//char转string 
	nm_txt=nm_txt+".txt";//得到完整文件名 
	cmd_str="cp "+adr_txt+" texts/"+nm_txt;//合成命令 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//将图片转到color_pictures文件夹 
	cmd_str="rm "+adr_txt;//合成命令 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//删除原图片 
	head_tell();//清屏
	cout<<"转换完成，文件已保存为texts文件夹内的"<<nm_txt<<"，请查收。"<<endl<<"若没有，请检查您输入的文件地址。"<<endl<<endl;
	cout<<"Press an key to continue...";
	getchar();
	return;
} 

int main() {
	string choice;
	show_loading(5);//首次假加载 
	while(true) {
		head_tell();
		cout<<"1 输入文字并转换色图"<<endl<<endl<<"2 选择文件并转换色图"<<endl<<endl<<"3 选择色图并转换文字"<<endl<<endl<<"0 退出软件"<<endl<<endl;
		cout<<"请选择:";//选择菜单 
		cin>>choice;
		if(choice=="1") {
			show_loading(2);
			text2pic();
		} else if(choice=="2") {
			show_loading(2);
			txt2pic();
		} else if(choice=="3") {
			show_loading(2);
			pic2txt();
		} else if(choice=="0") {
			return 0;
		} else {
			cout<<endl<<"输入错误，请重新输入。";
			sleep(1);
			continue;
		}//调用转换函数 
		show_loading(3);
	}
	return 0;
}
