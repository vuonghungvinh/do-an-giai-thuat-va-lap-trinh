#include <iostream>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;
struct Room {
	string type;
	string num;
	int status;
	vector<int> from;
	vector<int> to;
};
struct Data {
	Room rm;
	struct Data *next;
};
struct Hotel{
	char bill_no[18];
	char name[19];
	char identity_card[15];
	char gender[6];
	char room_no[5];
	char room_type;
	float unit_price;
	int from_date;
	int leave_date;
	float total;	
};
struct NODE
{
    Hotel data;
    struct NODE* next;
};
struct LIST
{
    NODE *head;
    NODE *tail;
};
// khoi tao NODE Hotel
NODE* CreateNode (Hotel x)
{
    NODE *p; 
    p=new NODE;
    if(p==NULL)  exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
vector<string> split(string str, string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}
// them node p vao cuoi danh sach lien ket
void AddLast (LIST &L, NODE *p)
{
    if(L.head==NULL)  L.head=L.tail=p;
    else
    {
        L.tail->next=p;
        L.tail=p;
    }
}
// ham them mot node vao dau danh sach
void AddFirst(LIST &L, NODE*p)
{	
	p->next=L.head;
	L.head=p;
}
//Now time
int NowDay(){
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    return now->tm_mday;
}
// ham nhap
void Nhap (LIST &L, Data* &room)
{
	int i;
    Hotel x; 
    NODE *p;
    Data *tmp1;
    char tmp[50];
    char kiemtra;   
    vector<int> frtmp;
    vector<int> totmp;
    cout<<endl<<"Nhan phim bat ki de tiep tuc nhap.";
    cout<<endl<<"Nhan 0 de dung nhap."<<endl;
    do
    {
    	fflush(stdin);
        kiemtra=getch();
        if(kiemtra=='0')  break;
        cout<<endl<<"Ma hoa don:       ";  fflush(stdin); gets(x.bill_no);  	
	    cout<<endl<<"Ten khach hang:   ";  fflush(stdin); gets(x.name);
	    do{
	    	i=0;
            cout<<endl<<"So CMND:          ";  fflush(stdin); gets(x.identity_card);
            for(int j=0;j<=strlen(x.identity_card)-1;j++){
            	if( (int)x.identity_card[j] < 48 ||  (int)x.identity_card[j] > 57 ){
            		cout<<endl<<"Khong hop le, moi nhap lai:"<<endl; i=1; break;
				}
			}
        }
        while(i);
      	do{
	    	i=0;
            cout<<endl<<"Gioi tinh:        ";  fflush(stdin); gets(x.gender);
            if(strcmpi(x.gender,"Nam")!=0 && strcmpi(x.gender,"Nu")!=0 ){
        	cout<<endl<<"Khong hop le, moi nhap lai:"; i=1;
	 	    }
        }
        while(i);
	    do{
	    	i=0;
	    	tmp1 = room;
            cout<<endl<<"So phong:         ";  fflush(stdin); gets(x.room_no); 
            while(tmp1 !=NULL){
            	string str1 = (tmp1->rm.type + tmp1->rm.num);
            	string str2 = x.room_no;
            	if( (str1.compare(0,str2.length(),str2) ==0 ) ){
            		frtmp = tmp1->rm.from;
            		totmp = tmp1->rm.to;
            		//if(tmp->rm.status == 0){
            		if(0){
            			cout<<endl<<"Phong dang ban vui long chon lai: " ; i=1; break;
					}
					else if(tmp1->rm.status == 2){
						cout<<endl<<"Phong bi hu hong chon lai: " ; i=1 ;break;
					}
					else{//truong hop phong hu nua?
            	    	tmp1->rm.status = 0;
            	    	break;
                	}
				}
				else
					tmp1=tmp1->next;
			}
			if(tmp1 == NULL){
				
			   cout<<endl<<"Khong hop le, moi nhap lai:"; i=1; continue; 	
			}
        }while(i);
        nhaplai:;
	    do{
	    	i=0;
            cout<<endl<<"Ngay den:         "; 
            fflush(stdin); gets(tmp);
			sscanf(tmp, "%d",    & x.from_date); //doi chuoi tmp thanh int
			
            if( x.from_date<=0 || x.from_date>31 || x.from_date < NowDay()){
        		cout<<endl<<"Khong hop le, moi nhap lai:"; 
				i=1;
	 	    }
        }
        while(i);
        do{
	    	i=0;
            cout<<endl<<"Ngay di:          ";
            fflush(stdin);
			gets(tmp);
			sscanf(tmp, "%d",    &x.leave_date);
            if(x.leave_date<=0 || x.leave_date>31 || x.leave_date < x.from_date){
        	cout<<endl<<"Khong hop le, moi nhap lai:"; i=1;
		    }
        }
        while(i);
        cout<<endl<<endl;
        
        int check = 0;
	 	if(frtmp.size()>0){
	 		for(size_t l=0;l<totmp.size();l++){
	 			if((frtmp[l] <= x.from_date && totmp[l] >= x.from_date) || (frtmp[l] <= x.leave_date && totmp[l] >= x.leave_date) || (frtmp[l] >= x.from_date && totmp[l] <= x.leave_date)){
	 				check=1;
	 				break;
				 }
			}
		}
		if(check){
			cout<<endl<<"Thoi gian ban chon da co nguoi dat moi nhap lai: ";
			goto nhaplai;
		}
		tmp1->rm.from.push_back(x.from_date);
		tmp1->rm.to.push_back(x.leave_date);	
        p=CreateNode(x);
        AddLast(L,p);
        
        //Xu ly du lieu
        p->data.room_type = p->data.room_no[0];
    	if        (p->data.room_type=='A') p->data.unit_price=400;
    	else if   (p->data.room_type=='B') p->data.unit_price=300;
    	else       p->data.unit_price=250;
    	p->data.total = p->data.unit_price * (p->data.leave_date - p->data.from_date + 1);
    } 
	while (1);
}
// ham xuat du lieu
void output(Hotel &x){
	cout<<"  |"<<setw(12)<<x.bill_no<<" |"<<setw(24)<<x.name<<" |"<<setw(13)<<x.identity_card<<" |"<<setw(13)<<x.gender<<" |"<<setw(13)<<x.room_no<<" |"<<setw(13)<<x.room_type<<" |"<<setw(13)<<x.unit_price<<"VND"<<" |"<<setw(13)<<x.from_date<<" |"<<setw(13)<<x.leave_date<<" |"<<setw(13)<<x.total<<"VND |";	
}
void Xuat (LIST &L)
{
	//int Stt=1;
    NODE *p;
    p=L.head;
    cout<<endl<<"Danh sach khach hang "<<endl; 
    cout<<"   _____________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    cout<<"  |"<<setw(12)<<"Ma so"<<" |"<<setw(24)<<"Ten"<<" |"<<setw(13)<<"CMND"<<" |"<<setw(13)<<"Gioi tinh"<<" |"<<setw(13)<<"So phong"<<" |"<<setw(13)<<"Loai phong"<<" |"<<setw(16)<<"Don gia"<<" |"<<setw(13)<<"Ngay den"<<" |"<<setw(13)<<"Ngay di"<<" |"<<setw(16)<<"Tong tien"<<" |"<<endl;
    cout<<"  |_____________|_________________________|______________|______________|______________|______________|_________________|______________|______________|_________________|"<<endl;
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    while(p!=NULL)
    {
    	output(p->data);  cout<<endl; 
        p=p->next;
    }
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    cout<<"  |_____________|_________________________|______________|______________|______________|______________|_________________|______________|______________|_________________|"<<endl<<endl;
}
void Search(LIST &L)
{   
    NODE *p;    
    char tmp[19]; 
	int i=0;; 
    p=L.head;
    cout<<endl<<"Nhap thong tin khach hang can tim: ";  fflush(stdin); gets(tmp);
    cout<<endl<<"Ket qua tim kiem "<<endl;
    cout<<"   _____________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    cout<<"  |"<<setw(12)<<"Ma so"<<" |"<<setw(24)<<"Ten"<<" |"<<setw(13)<<"CMND"<<" |"<<setw(13)<<"Gioi tinh"<<" |"<<setw(13)<<"So phong"<<" |"<<setw(13)<<"Loai phong"<<" |"<<setw(16)<<"Don gia"<<" |"<<setw(13)<<"Ngay den"<<" |"<<setw(13)<<"Ngay di"<<" |"<<setw(16)<<"Tong tien"<<" |"<<endl;
    cout<<"  |_____________|_________________________|______________|______________|______________|______________|_________________|______________|______________|_________________|"<<endl;
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    while(p!=NULL)
    {           
        if       (strcmp(p->data.name,tmp)==0){             output(p->data); cout<<endl; i++; }  // ham strcmp dung de so sanh hai sau string xem giong nhau khong, neu giong tra ve 0
        else if  (strcmp(p->data.bill_no,tmp)==0){          output(p->data); cout<<endl; i++; break ;}
		else if  (strcmp(p->data.identity_card,tmp)==0){    output(p->data); cout<<endl; i++; break;}
		else if  (strcmp(p->data.room_no,tmp)==0){          output(p->data); cout<<endl; i++; break;}
		p=p->next;           
    }
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    cout<<"  |_____________|_________________________|______________|______________|______________|______________|_________________|______________|______________|_________________|"<<endl<<endl;
    if (p==NULL && i==0)  cout<<endl<<" Khong co khach hang nay trong danh sach";    
}
void DelFirst(LIST &L)
{	NODE *tam;
	tam=L.head;

	L.head=L.head->next;
	free(tam);
}
void Delete(LIST &L,int pos)
{
	int i;
	NODE *cur,*tam;
	cur=L.head;
	if (pos==1) DelFirst(L);
	else
	{
		for(i=1;i<pos-1;i++)
			cur=cur->next;
		tam=cur->next;
		cur->next=tam->next;
		free(tam);
	}
}
void Remove(LIST &L)
{   
    int pos=1,i=0;NODE *p;    
    char t[19];  
    p=L.head;
    cout<<endl<<"Nhap ten sinh vien can xoa: ";  fflush(stdin); gets(t);
    while(p!=NULL)
    {         
        if(strcmp(p->data.name,t)==0){ 
	// ham strcmp dung de so sanh hai sau string xem giong nhau khong, neu giong tra ve 0
          Delete(L,pos);i++;
          p=p->next;
          continue;             
       }  
       pos++;
       p=p->next;
    }
    if (i==0) cout<<endl<<"Khong co sinh vien ten %s de xoa"<<t;
}
void ListQSort(LIST &L,int n){
	NODE *p,*X;
	LIST L1,L2;
	if(L.head==L.tail) return;	
	L1.head=L1.tail=NULL;
	L2.head=L2.tail=NULL;
	X=L.head;
	L.head=X->next;
	while(L.head!=NULL){	
		p=L.head;
		L.head=p->next;
		p->next=NULL;
		if(n==1){
		    if(p->data.total >= X->data.total) AddLast(L1,p);
	    	else AddLast(L2,p);
     	}
     	else if(n==2){
     		if((p->data.leave_date - p->data.from_date) >= (X->data.leave_date - X->data.from_date)) AddLast(L1,p);
	    	else AddLast(L2,p);
		 }
		 else {
		 	if(p->data.unit_price >= X->data.unit_price) AddLast(L1,p);
	    	else AddLast(L2,p);
     	    }
	}
	ListQSort(L1,n);
	ListQSort(L2,n);
	if(L1.head!=NULL) {
		L.head=L1.head; L1.tail->next=X;
     }
    else L.head=X;
    X->next=L2.head;
    if(L2.head!=NULL) L.tail=L2.tail;
    else L.tail=X;
}
void Listed(LIST &L,int n){
	NODE *p;    
	int i=0;; 
    p=L.head;
    cout<<"   _____________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    cout<<"  |"<<setw(12)<<"Ma so"<<" |"<<setw(24)<<"Ten"<<" |"<<setw(13)<<"CMND"<<" |"<<setw(13)<<"Gioi tinh"<<" |"<<setw(13)<<"So phong"<<" |"<<setw(13)<<"Loai phong"<<" |"<<setw(16)<<"Don gia"<<" |"<<setw(13)<<"Ngay den"<<" |"<<setw(13)<<"Ngay di"<<" |"<<setw(16)<<"Tong tien"<<" |"<<endl;
    cout<<"  |_____________|_________________________|______________|______________|______________|______________|_________________|______________|______________|_________________|"<<endl;
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    while(p!=NULL)
    {           
          if(n==1 && p->data.room_type=='A')     { output(p->data);  cout<<endl; i++;
		  }
		  else if(n==2 && p->data.room_type=='B') { output(p->data);  cout<<endl; i++;
		  }
		  else if(n==3 && p->data.room_type!= 'A' && p->data.room_type!= 'B') { output(p->data); cout<<endl; i++;
		  }	    
		  p=p->next; 
    }
    cout<<"  |             |                         |              |              |              |              |                 |              |              |                 |"<<endl;
    cout<<"  |_____________|_________________________|______________|______________|______________|______________|_________________|______________|______________|_________________|"<<endl<<endl;
    if (p==NULL && i==0)  cout<<endl<<"Khong phong loai nay";    
}
void listroom(Data *dt){
	Data *d;
	d = dt;
	string str1,str2,str3;
	str1 = "Phong con trong";
	str2 = "Phong da co nguoi thue";
	str3 = "Phong bi hong dang sua chua";
	while(d != NULL){
		cout<<d->rm.type<<":"<<d->rm.num<<":"<<(d->rm.status==1?str1:(d->rm.status==0?str2:str3))<<endl; 
		d=d->next;
	}
}
Data *createData(Room room) {
	Data *da;
	da = new Data;
	da->next = NULL;
	da->rm = room;
	return da;
}
//xu li file
void ReadFile(Data* &dt) {
	ifstream myfile ("data.txt");
   	string line;
   	dt = NULL;
   	Data *tmp;
   	if(myfile.is_open()) {
   		while(getline(myfile, line))
		{
			string str2 = "null";
			Room rm;
			vector<string> arr;
			arr = split(line, ":");
			line = arr[0].c_str();
			rm.type = line.substr(0,1);
			rm.num = line.substr(1,line.length()-1);
			rm.status = atoi(arr[1].c_str());
			if(arr[2].compare("null") != 0) {
				vector<string> fr = split(arr[2].c_str(),",");
				for(size_t i=0;i<fr.size();i++){
					rm.from.push_back(atoi(fr[i].c_str()));
				}
			}
			if(arr[2].compare("null") != 0) {
				vector<string> to = split(arr[3].c_str(),",");
				for(size_t i=0;i<to.size();i++){
					rm.to.push_back(atoi(to[i].c_str()));
				}
			}
			if(dt == NULL){
				dt = createData(rm);
				tmp = dt;
			}else {
				tmp->next = createData(rm);
				tmp = tmp->next;
			}
		}
		myfile.close();
	}else{
		cout<<"file not found!!!\n";		
	}
}
//end xu li file
main()
{   
    int n;
    Hotel x;
    Data *dt;
    while(1)
    {
    LIST L;
    L.head=L.tail=NULL;
    char chon;
    ReadFile(dt);
    do
    {
        cout<<endl<<setw(40)<<" "<<"************************************MENU***********************************";
		cout<<endl<<setw(40)<<" "<<"*                                                                         *";
		cout<<endl<<setw(40)<<" "<<"*         1. Nhap danh sach                                               *";
        cout<<endl<<setw(40)<<" "<<"*         2. In ra thong tin                                              *";
        cout<<endl<<setw(40)<<" "<<"*         3. Tim kiem(ten, CMND, mahoa don, so phong)                     *";
        cout<<endl<<setw(40)<<" "<<"*         4. Xoa tat ca cac khach hang co ten nhap vao                    *";
        cout<<endl<<setw(40)<<" "<<"*         5. Sap xep                                                      *";
        cout<<endl<<setw(40)<<" "<<"*         6. Liet ke theo loai phong                                      *";
        cout<<endl<<setw(40)<<" "<<"*         7. Liet ke danh sach phong                                      *";
        cout<<endl<<setw(40)<<" "<<"*                                                                         *";
        cout<<endl<<setw(40)<<" "<<"***************************************************************************"<<endl<<endl;
        chon=getch();
        switch(chon)
        {   
            case '1': { Nhap(L,dt);             break;}
			case '2': { Xuat(L);            break;}	
			case '3': { Search(L);            break;}	
			case '4': { Remove(L);
			            cout<<endl<<"Ket qua sau khi xoa:";
			            Xuat(L);
			            break;}
			case '5': { int n;
			            cout<<endl<<"Moi ban nhap: "<<endl<<"* 1.De sap xep theo giam dan tong tien "<<endl<<"* 2.De giam dan so ngay o "<<endl<<"* 3.Giam dan theo gia phong"<<endl;
			            cin>>n;
			            ListQSort(L,n);
			            cout<<endl<<"Ket qua sau khi xoa:";
			            Xuat(L);
			             break;}
			case '6': { int n;
			            cout<<endl<<"Moi ban nhap "<<endl<<"* 1.Liet ke tat ca phong loai A "<<endl<<"* 2.Tat ca phong loai B "<<endl<<"* 3.Tat ca con lai\n";
			            cin>>n;;
			            Listed(L,n);
			            cout<<endl<<"\nKet qua";
			             break;}
			case '7': {
				listroom(dt); break;
			}			 			   			     
            case '0': exit(1);
            default: cout<<endl<<"Nhap lai.";
        }
    } while (chon!='0');
     
        getch();
    }
}
