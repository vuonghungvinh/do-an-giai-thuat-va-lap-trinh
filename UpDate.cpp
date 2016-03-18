#include <iostream>
#include<conio.h>
#include<math.h>
#include <string>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct Data_Room{
    string A[21] = {"A900", "A101", "A102", "A103", "A104", "A105", "A106", "A107", "A108", "A109", "A110", "A111", "A112", "A113", "A114", "A115", "A116", "A117", "A118", "A119", "A120"};
	string B[21] = {"B200", "B201", "B202", "B203", "B204", "B205", "B206", "B207", "B208", "B209", "B210", "B211", "B212", "B213", "B214", "B215", "B216", "B217", "B218", "B219", "B220"};
	string C[21] = {"C300", "C301", "C302", "C303", "C304", "C305", "C306", "C307", "C308", "C309", "C310", "C311", "C312", "C313", "C314", "C315", "C316", "C217", "C318", "C319", "C320"};
	string D[21] = {"D400", "D401", "D402", "D403", "D404", "D405", "D406", "D407", "D408", "D409", "D410", "D411", "D412", "D413", "D414", "D415", "D416", "D417", "D418", "D419", "D420"};
};
struct Hotel{
	char bill_no[9];
	char name[19];
	char identity_card[13];
	char gender[6];
	char room_no[5];
	char room_type;
	float unit_price;
	int from_date;
	int leave_date;
	float total;	
	Data_Room info;
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
// ham nhap
void Nhap (LIST &L)
{
	int i;
    Hotel x; 
    NODE *p;
    char *tmp;
    char kiemtra;   
    printf("\nNhan phim bat ki de tiep tuc nhap.");
    printf("\nNhan 0 de dung nhap.\n");
    do
    {
        kiemtra=getch();
        if(kiemtra=='0')  break;
        printf("\nMa hoa don:       ");  fflush(stdin); gets(x.bill_no);  	
	    printf("\nTen khach hang:   ");  fflush(stdin); gets(x.name);
	    do{
	    	i=0;
            printf("\nSo CMND:          ");  fflush(stdin); gets(x.identity_card);
            for(int j=0;j<=strlen(x.identity_card)-1;j++){
            	if( (int)x.identity_card[j] < 48 ||  (int)x.identity_card[j] > 57 ){
            		printf("\nKhong hop le, moi nhap lai:\n"); i=1; break;
				}
			}
        }
        while(i);
      	do{
	    	i=0;
            printf("\nGioi tinh:        ");  fflush(stdin); gets(x.gender);
            if(strcmpi(x.gender,"Nam")!=0 && strcmpi(x.gender,"Nu")!=0 ){
        	printf("\nKhong hop le, moi nhap lai:"); i=1;
	 	    }
        }
        while(i);
	    do{
	    	i=0;
            printf("\nSo phong:         ");  fflush(stdin); gets(x.room_no); 
            if(x.room_no[0]=='A'){
            	for(int a=0; a <= sizeof(x.info.A)/sizeof(x.info.A[0])-1;a++){
            		if(x.room_no==x.info.A[a]) break;	
            		else if(a == sizeof(x.info.A)/sizeof(x.info.A[0])-1) {
					printf("\nKhong hop le, moi nhap lai:"); i=1; continue; 
					}
				}
	 	    }
	 	    else if(x.room_no[0]=='B'){
            	for(int a=0; a <= sizeof(x.info.B)/sizeof(x.info.B[0])-1;a++){
            		if(x.room_no==x.info.B[a]) break;
            		else if(a == sizeof(x.info.B)/sizeof(x.info.B[0])-1) {
					printf("\nKhong hop le, moi nhap lai:"); i=1; continue; 
					}
				}
	 	    }
	 	    else if(x.room_no[0]=='C'){
            	for(int a=0; a <= sizeof(x.info.C)/sizeof(x.info.C[0])-1;a++){
            		if(x.room_no==x.info.C[a]) break;
            		else if(a == sizeof(x.info.C)/sizeof(x.info.C[0])-1) {
					printf("\nKhong hop le, moi nhap lai:"); i=1; continue; 
					}
				}
	 	    }
	 	    else if(x.room_no[0]=='D'){
            	for(int a=0; a <= sizeof(x.info.D)/sizeof(x.info.D[0])-1;a++){
            		if(x.room_no==x.info.D[a]) break;
            		else if(a == sizeof(x.info.D)/sizeof(x.info.D[0])-1) {
					printf("\nKhong hop le, moi nhap lai:"); i=1; continue; 
					}
				}
	 	    }
			else{
				printf("\nKhong hop le, moi nhap lai:"); i=1; continue;
			}
        }while(i);
	    do{
	    	i=0;
            printf("\nNgay den:         "); 
            fflush(stdin);
            gets(tmp);
			sscanf(tmp, "%d",    &x.from_date);
            if(x.from_date<=0 || x.from_date>31){
        	printf("\nKhong hop le, moi nhap lai:"); i=1;
	 	    }
        }
        while(i);
        do{
	    	i=0;
            printf("\nNgay di:          ");
            fflush(stdin);
			gets(tmp);
			sscanf(tmp, "%d",    &x.leave_date);
            if(x.leave_date<=0 || x.leave_date>31 || x.leave_date < x.from_date){
        	printf("\nKhong hop le, moi nhap lai:"); i=1;
		    }
        }
        while(i);
        printf("\n\n");
        
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
	printf("Bill No:%9s  Name:%18s   Identity Card:%13s  Gender:%6s   Room No:%5s   Room Type:%1c   Unit Price:%6.0f (VND)   From Date:%2d   Leave Date:%2d   Total:%10.0f (VND)", x.bill_no, x.name, x.identity_card, x.gender, x.room_no, x.room_type, x.unit_price, x.from_date, x.leave_date, x.total);	
}
void Xuat (LIST &L)
{
	int Stt=1;
    NODE *p;
    p=L.head;
    printf("\nDanh sach khach hang \n"); 
    while(p!=NULL)
    {
    	printf("STT:%3d  ",Stt); output(p->data);  printf("\n"); 
        //printf("\nSTT:%d  Bill No:%9s  Name:%18s   Identity Card:%13s  Gender:%6s   Room No:%5s   Room Type:%1c   Unit Price:%6.0f (VND)   From Date:%2d   Leave Date:%2d   Total:%10.0f (VND)",Stt , p->bill_no, p->name, p->identity_card, p->gender, p->room_no, p->room_type, p->unit_price, p->from_date, p->leave_date, p->total);
        p=p->next; Stt++;
    }
}

void Search(LIST &L)
{   
    NODE *p;    
    char tmp[19]; 
	int i=0;; 
    p=L.head;
    printf("\nNhap thong tin khach hang can tim: ");  fflush(stdin); gets(tmp);
    printf("\nKet qua tim kiem ");
    while(p!=NULL)
    {           
        if       (strcmp(p->data.name,tmp)==0){             output(p->data); printf("\n"); i++; }  // ham strcmp dung de so sanh hai sau string xem giong nhau khong, neu giong tra ve 0
        else if  (strcmp(p->data.bill_no,tmp)==0){          output(p->data); printf("\n"); i++; break ;}
		else if  (strcmp(p->data.identity_card,tmp)==0){    output(p->data); printf("\n"); i++; break;}
		else if  (strcmp(p->data.room_no,tmp)==0){          output(p->data); printf("\n"); i++; break;}
		p=p->next;           
    }
    if (p==NULL && i==0)  printf("\Khong co khach hang nay trong danh sach");    
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
    printf("\nNhap ten sinh vien can xoa: ");  fflush(stdin); gets(t);
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
    if (i==0) printf("\nKhong co sinh vien ten %s de xoa",t);
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
    while(p!=NULL)
    {           
          if(n==1 && p->data.room_no[0]=='A'){ output(p->data); printf("\n"); i++;
		  }
		  else if(n==2 && p->data.room_no[0]=='B'){ output(p->data); printf("\n"); i++;
		  }
		  else if(n==3 && p->data.room_no[0]!='A' && p->data.room_no[0]!='B'){ output(p->data); printf("\n"); i++;
		  }	    
		  p=p->next; 
    }
    if (p==NULL && i==0)  printf("\Khong phong loai nay");    
}
main()
{   
    int n;
    Hotel x;
    while(1)
    {
    LIST L;
    L.head=L.tail=NULL;
    char chon;
    do
    {
        printf("\n\t\t\t\t  ______________________________MENU_______________________________________\t");
		printf("\n\t\t\t\t | 1. Nhap danh sach                                                       |");
        printf("\n\t\t\t\t | 2. In ra thong tin                                                      |");
        printf("\n\t\t\t\t | 3. Tim kiem(ten, CMND, mahoa don, so phong)                             |");
        printf("\n\t\t\t\t | 4. Xoa tat ca cac khach hang co ten nhap vao                            |");
        printf("\n\t\t\t\t | 5. Sap xep                                                              |");
        printf("\n\t\t\t\t | 6. Liet ke theo loai phong                                              |");
        printf("\n\t\t\t\t |_________________________________________________________________________|\n\n");
        chon=getch();
        switch(chon)
        {   
            case '1': { Nhap(L);             break;}
			case '2': { Xuat(L);            break;}	
			case '3': { Search(L);            break;}	
			case '4': { Remove(L);
			            printf("\nKet qua sau khi xoa:");
			            Xuat(L);
			            break;}
			case '5': { int n;
			            printf("\nMoi ban nhap \n1 de sap xep theo giam dan tong tien \n2 de giam dan so ngay o \n3 giam dan theo gia phong:\n");
			            scanf("%d",&n);
			            ListQSort(L,n);
			            printf("\nKet qua sau khi xoa:");
			            Xuat(L);
			             break;}
			case '6': { int n;
			            printf("\nMoi ban nhap \n1 liet ke tat ca phong loai A \n2 tat ca phong loai B \n3 tat ca con lai\n");
			            scanf("%d",&n);
			            Listed(L,n);
			            printf("\nKet qua");
			             break;}			 			   			     
            case '0': exit(1);
            default: printf("\nNhap lai.");
        }
    } while (chon!='0');
     
        getch();
    }
}
