#include<iostream>
#include<cstring>
#include<string>
#include<windows.h>

using namespace std;

void head_tell() {//ͷ��ʾ 
	system("cls");
	cout<<"����ת\"ɫͼ\"(Novel_In_Image)ʹ������"<<endl<<"                       by playeryang01"<<endl<<endl;
	return;
}

void show_loading(int time) {//�ֶ����� 
	head_tell();
	cout<<"loading...";
	Sleep(time);
	system("cls");
	return;
}

void text2pic() {//�����ı���ɫͼ 
	string text,cmd_str;
	char cmd[5200],none;
	head_tell();
	cout<<"������Ҫת��������(����5000������):"<<endl;
	getchar();//ȥ���з� 
	getline(cin,text);//getline���ո� 
	cmd_str="echo "+text+">\"text\"";//�ϳ����txt�ı��ļ� 
	strcpy(cmd,cmd_str.c_str());
	system("chcp 65001");//���Ϊutf-8 
	system(cmd);
	system("chcp 936");
	system("python bin\\nii.py -e text");//����nii.py�ļ���ת��
	system("copy _layout.bmp color_pictures\\text.bmp");//��ͼƬת��color_pictures�ļ��� 
	system("del text _layout.bmp");//ɾ��ԭͼƬ 
	head_tell();//���� 
	cout<<"ת����ɣ��ļ��ѱ���Ϊcolor_pictures�ļ����ڵ�text.bmp������ա�"<<endl<<endl;
	system("pause");
	return;
}

void txt2pic(){//�ı��ļ�תɫͼ��ֱ����pic2txt�ĵģ������������� 
	head_tell();
	string adr_pic,cmd_str,adr_txt,nm_txt;
	char cmd[500],char_adr_txt[500],char_nm_txt[500];
	cout<<"��������ת�����ı����ļ���ַ(ͬ�ļ����¿������ļ���)(б��Ҫ�÷�б��!!!):"<<endl;
	getchar();//ȥ���з� 
	getline(cin,adr_pic);//getline���ո� 
	cmd_str="python bin\\nii.py -e "+adr_pic; //�ϳɵ����ı� 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//����nii.py�ļ���ת��ͼƬ 
	for(int i=adr_pic.length()-1;i>=0;i--){//�õ�ת����ͼƬ��char��ʽ�ļ���ַ 
		if(adr_pic[i]=='.'){
			for(int j=0;j<i;j++){
				char_adr_txt[j]=adr_pic[j];
			}
			break;
		}
	}
	for(int i=adr_pic.length()-1;i>=0;i--){//�õ�ת����ͼƬ��char��ʽ�ļ��� 
		if(adr_pic[i]=='\\'){
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
	adr_txt=char_adr_txt;//charתstring 
	adr_txt=adr_txt+"_layout.bmp";//�õ�������ַ 
	nm_txt=char_nm_txt;//charתstring 
	nm_txt=nm_txt+".bmp";//�õ������ļ��� 
	cmd_str="copy "+adr_txt+" color_pictures\\"+nm_txt;//�ϳ����� 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//��ͼƬת��color_pictures�ļ��� 
	cmd_str="del "+adr_txt;//�ϳ����� 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//ɾ��ԭͼƬ 
	head_tell();//���� 
	cout<<"ת����ɣ��ļ��ѱ���Ϊcolor_pictures�ļ����ڵ�"<<nm_txt<<"������ա�"<<endl<<"��û�У�������������ļ���ַ��"<<endl<<endl;
	system("pause");
	return;
}

void pic2txt(){//ͼƬת�ı��ļ� 
	head_tell();
	string adr_pic,cmd_str,adr_txt,nm_txt;
	char cmd[500],char_adr_txt[500],char_nm_txt[500];
	cout<<"��������ת����ɫͼ���ļ���ַ(ͬ�ļ����¿������ļ���)(б��Ҫ�÷�б��!!!):"<<endl;
	getchar();//ȥ���з� 
	getline(cin,adr_pic);//getline���ո� 
	cmd_str="python bin\\nii.py -d "+adr_pic;//�ϳɵ����ı� 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//����nii.py�ļ���ת���ı� 
	for(int i=adr_pic.length()-1;i>=0;i--){//�õ�ת�����ı���char��ʽ�ļ���ַ 
		if(adr_pic[i]=='.'){
			for(int j=0;j<i;j++){
				char_adr_txt[j]=adr_pic[j];
			}
			break;
		}
	}
	for(int i=adr_pic.length()-1;i>=0;i--){//�õ�ת�����ı���char��ʽ�ļ���
		if(adr_pic[i]=='\\'){
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
	adr_txt=char_adr_txt;//charתstring 
	adr_txt=adr_txt+"_decode.txt";//�õ�������ַ 
	nm_txt=char_nm_txt;//charתstring 
	nm_txt=nm_txt+".txt";//�õ������ļ��� 
	cmd_str="copy "+adr_txt+" texts\\"+nm_txt;//�ϳ����� 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//��ͼƬת��color_pictures�ļ��� 
	cmd_str="del "+adr_txt;//�ϳ����� 
	strcpy(cmd,cmd_str.c_str());
	system(cmd);//ɾ��ԭͼƬ 
	head_tell();//����
	cout<<"ת����ɣ��ļ��ѱ���Ϊtexts�ļ����ڵ�"<<nm_txt<<"������ա�"<<endl<<"��û�У�������������ļ���ַ��"<<endl<<endl;
	system("pause");
	return;
} 

int main() {
	string choice;
	show_loading(800);//�״μټ��� 
	while(true) {
		head_tell();
		cout<<"1 �������ֲ�ת��ɫͼ"<<endl<<endl<<"2 ѡ���ļ���ת��ɫͼ"<<endl<<endl<<"3 ѡ��ɫͼ��ת������"<<endl<<endl<<"0 �˳����"<<endl<<endl;
		cout<<"��ѡ��:";//ѡ��˵� 
		cin>>choice;
		if(choice=="1") {
			show_loading(200);
			text2pic();
		} else if(choice=="2") {
			show_loading(200);
			txt2pic();
		} else if(choice=="3") {
			show_loading(200);
			pic2txt();
		} else if(choice=="0") {
			return 0;
		} else {
			cout<<endl<<"����������������롣";
			Sleep(500);
			continue;
		}//����ת������ 
		show_loading(500);
	}
	return 0;
}
