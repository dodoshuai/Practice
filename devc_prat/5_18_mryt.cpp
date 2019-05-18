//#include<stdio.h>
//#include<iostream>
//#include<string>
// using namespace std;
// //public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
// string  GetPwdSecurityLevel(string pPasswordStr){
// 	int str_char=0;//字符数 
// 	int str_big_letter=0;//大字母数 
// 	int str_small_letter=0;//小字母数 
// 	int str_num=0;//数字数 
// 	int str_size=pPasswordStr.size();//总数 
// 	//string array_str={"VERY_WEAK","WEAK","AVERAGE","STRONG","VERY_STRONG","SECURE","VERY_SECURE"}; 
//	 for(int i=0;i<str_size;++i){
// 		if(pPasswordStr[i]>=33&&pPasswordStr[i]<=126){
//			 if(pPasswordStr[i]>='0'&&pPasswordStr[i]<='9'){
//	 			++str_num;			
//	 		}
//	 		else if(pPasswordStr[i]>='a'&&pPasswordStr[i]<='z'){
//	 			++str_small_letter;
//	 		}
//	 		else if(pPasswordStr[i]>='A'&&pPasswordStr[i]<='Z'){
//	 			++str_big_letter;
//	 		}else {
//			  ++str_char;
//		 	} 
// 		}
// 	}
// 	int score=0;//得分
//	if(str_char==0){
//		score+=0;
//	} else if(str_char==1){
//		score+=10;
//	} else if(str_char>1){
//		score+=20;
//	}
//	
// 	if(str_small_letter==0&&str_big_letter==0){
//		score+=0;
//	} else if(str_small_letter==0||str_big_letter==0){
//		score+=10;
//	} else {
//		score+=20;
//	}
//	
//	if(str_num==0){
//		score+=0;
//	} else if(str_num==1){
//		score+=10;
//	} else if(str_num>1){
//		score+=25;
//	}
// 	
// 	if(str_size>=8){
// 		score+=25;
// 	}else if(str_size<8&&str_size>4){
// 		score+=10; 
// 	}else if(str_size<=4){
// 		score+=5; 
// 	}
// 	
// 	if(str_small_letter!=0&&str_big_letter!=0&&str_num!=0&&str_char!=0){
// 		
// 	}else if((str_small_letter!=0||str_big_letter!=0)&&str_num!=0&&str_char!=0){
// 		score+=3;
// 	}else if((str_small_letter!=0||str_big_letter!=0)&&str_num!=0){
// 		score+=2;
// 	}
// 	//printf("num=%d\nchar=%d\nsmall_letter=%d\nbig_letter=%d\n",str_num,str_char,str_small_letter,str_big_letter);
// 	string ret=NULL;
// 	if(score>=90){
// 		ret="VERY_SECURE";	
// 	}else if(score>=80){
// 		ret="SECURE";
// 	}else if(score>=70){
// 		ret="VERY_STRONG";
// 	}
// 	else if(score>=60){
// 		ret="STRONG";
// 	}
// 	else if(score>=50){
// 		ret="AVERAGE";
// 	}
// 	else if(score>=25){
// 		ret="WEAK";
// 	}
// 	else if(score>=0){
// 		ret="VERY_WEAK";
// 	}
// 	return ret;
// } 
// int main(void){
// 	//string a="38$@NoNoNo";
// 	string a="abcd";
// 	cout<<GetPwdSecurityLevel(a)<<endl;
// 	
// 	return 0; 
// } 
#include<iostream>
#include <string>
using namespace std;
string GetPwdSecurityLevel(string pPasswordStr){
 	int str_char=0;//字符数 
 	int str_big_letter=0;//大字母数 
 	int str_small_letter=0;//小字母数 
 	int str_num=0;//数字数 
 	int str_size=pPasswordStr.size();//总数 
 	
	 for(int i=0;i<pPasswordStr.size();++i){
 		if(pPasswordStr[i]>=33&&pPasswordStr[i]<=126){
			 if(pPasswordStr[i]>='0'&&pPasswordStr[i]<='9'){
	 			++str_num;			
	 		}
	 		else if(pPasswordStr[i]>='a'&&pPasswordStr[i]<='z'){
	 			++str_small_letter;
	 		}
	 		else if(pPasswordStr[i]>='A'&&pPasswordStr[i]<='Z'){
	 			++str_big_letter;
	 		}else {
			  ++str_char;
		 	} 
 		}
 	}
 	int score=0;//得分
	if(str_char==0){
		score+=0;
	} else if(str_char==1){
		score+=10;
	} else if(str_char>1){
		score+=20;
	}
	
 	if(str_small_letter==0&&str_big_letter==0){
		score+=0;
	} else if(str_small_letter==0||str_big_letter==0){
		score+=10;
	} else {
		score+=20;
	}
	
	if(str_num==0){
		score+=0;
	} else if(str_num==1){
		score+=10;
	} else if(str_num>1){
		score+=25;
	}
 	
 	if(str_size>=8){
 		score+=25;
 	}else if(str_size<8&&str_size>4){
 		score+=10; 
 	}else if(str_size<=4){
 		score+=5; 
 	}
 	
 	if(str_small_letter!=0&&str_big_letter!=0&&str_num!=0&&str_char!=0){
 		
 	}else if((str_small_letter!=0||str_big_letter!=0)&&str_num!=0&&str_char!=0){
 		score+=3;
 	}else if((str_small_letter!=0||str_big_letter!=0)&&str_num!=0){
 		score+=2;
 	}
 	string ret=NULL;
 	if(score>=90){
 		ret="VERY_SECURE";	
 	}else if(score>=80){
 		ret="SECURE";
 	}else if(score>=70){
 		ret="VERY_STRONG";
 	}
 	else if(score>=60){
 		ret="STRONG";
 	}
 	else if(score>=50){
 		ret="AVERAGE";
 	}
 	else if(score>=25){
 		ret="WEAK";
 	}
 	else if(score>=0){
 		ret="VERY_WEAK";
 	}
 	return ret;
 } 

int main(){
 	//string a="38$@NoNoNo";
 	string a;
    cin>>a;
 	cout<<GetPwdSecurityLevel(a)<<endl;
 	return 0; 
 } 
