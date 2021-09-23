#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
int main(){
	string str[39];
	string filename="example.txt"; //文件名 
	// 文件流 
	ifstream infile;
	infile.open(filename.c_str());
	
    for(int i=0;i<39;i++){
    	getline(infile,str[i]);
	}
	/*for(int i=0;i<39;i++){
		cout<<str[i]<<endl;
	}*/
	
	string keyword[32]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short",
	"signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
	
	int tt_num=0;
	int dou_num=0;
	for(int i=0;i<32;i++){
		for(int k=0;k<39;k++){
			if((str[k].find(keyword[i]))!=string::npos){
				tt_num++;
			}
		}
	}
	for(int k=0;k<39;k++){
			if((str[k].find("double"))!=string::npos){
				dou_num++;
			}
		}
	cout<<"total number is"<<tt_num-dou_num<<endl;
	int switch_num=0;
	int if_num=0;
	int elseif_num=0;
	int case_num[3]={0};
	int j=0;


    for(int i=0;i<39;i++){
    	if((str[i].find("switch"))==string::npos){
             
		}
		else{
			switch_num+=1;
			j++;
			
		}
		if((str[i].find("case"))==string::npos){
         
		}
		else{
			case_num[j]+=1;


		}
	}
	cout<<"switch number is"<<switch_num<<endl<<"case number is"<<case_num[1]<<case_num[2]<<endl;
        for(int i=38;i>=0;i--){
    	if(((str[i].find("else"))!=string::npos)&&((str[i].find("else if"))==string::npos)){
         for(int k=i;k>=0;k--){
         	if(((str[k].find("if"))!=string::npos)&&((str[k].find("else if"))==string::npos)){
         		if_num++;
         		break;
			 }
            else if((str[k].find("else if"))!=string::npos){
            	elseif_num++;
            	break;
			}
		 }
		}
	}
	cout<<"if-else number is"<<if_num<<endl<<"if-else-if number is"<<elseif_num;
	
	infile.close();
	return 0; 
}

