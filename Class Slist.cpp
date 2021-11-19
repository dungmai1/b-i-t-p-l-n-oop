#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
class diem {
	protected:
		float dtb,dc,drl;
	public:
		diem();
		~diem();
		void nhapd();
		void xuatd();
		float getdtb();
		void setdtb(float);
		void xeploai();
};
void diem::setdtb(float dtb){
	this->dtb = dtb;
}
float diem::getdtb(){
	return dtb;
}
diem::diem(){
	dtb = 0;
	drl = 0;
	dc = 0;
}
diem::~diem(){	
}
void diem::nhapd(){
	cout<<"\nNhap diem trung binh: "; 
	cin>>dtb;
	cout<<"\nNhap diem ren luyen: "; 
	cin>>drl;
	cout<<"\nNhap diem cong: "; 
	cin>>dc;
}
void diem::xuatd(){
    cout<<left<<setw(6)<<dtb<<"\t";
    cout<<left<<setw(5)<<dc<<"\t";
	cout<<left<<setw(5)<<drl<<"\t";
}
void diem::xeploai(){
	if(dtb>=8.0){
		cout<<left<<setw(15)<<"Gioi"<<endl;	
	}
	else if(dtb >=7.0){
		cout<<left<<setw(15)<<"Kha"<<endl;	
	}
	else if(dtb>=5.0){
		cout<<left<<setw(15)<<"TB"<<endl;	
	}	
	else if  (dtb < 5.0){
		cout<<left<<setw(15)<<"Yeu"<<endl;	
	}	
}
struct hocphan{
	float hocphi;
	string monhoc,mhp;
	int sotinchi;
	float tth;
};
class dkhocphan {
	private:
		int sohocphan;
		hocphan hocphans[100];
	public:
		void nhaphocphan();
		void xuathocphan();
		void tinhtienhoc();
};
void dkhocphan::nhaphocphan(){
	fflush(stdin);
	cout<<"Nhap so hoc phan: ";
	cin>>sohocphan;
	for(int i =0; i<sohocphan; i++){
		fflush(stdin);
		cout<<"Nhap ten hoc phan: ";
		getline(cin,hocphans[i].monhoc);
		cout<<"So tin chi: ";
		cin>>hocphans[i].sotinchi;
		fflush(stdin);
		cout<<"Ma hoc phan: ";
		getline(cin,hocphans[i].mhp);
		cout<<"Hoc phi: ";
		cin>>hocphans[i].hocphi;	
	}
}
void dkhocphan::xuathocphan(){
	for(int i =0; i<sohocphan; i++){
		cout<<left<<setw(10)<<hocphans[i].monhoc<<"\t";
	    cout<<left<<setw(10)<<hocphans[i].sotinchi<<"\t";
		cout<<left<<setw(15)<<hocphans[i].mhp<<"\t";
		cout<<left<<setw(15)<<hocphans[i].hocphi<<"\t"<<endl;
	}	
}
void dkhocphan::tinhtienhoc(){
	int sotien=0;
	for(int i =0; i<sohocphan; i++){
		sotien += (hocphans[i].sotinchi*hocphans[i].hocphi);
	}
	cout<<"Tong so tien cua dang ki hoc phan la: "<<sotien<<endl;
}
class sinhvien : public dkhocphan,public diem 
{
    private:
        string ten;
        string gt;
        string msv;
        int tuoi,ngay,thang,nam;
    public:
        void nhap_sinhvien();
        void xuat_sinhvien();
        void intro();
        void loading();
        void animation(char q[]);
        void thanhviennhom();
        string getten();
        void setten(string);
        string getgt();
        void setgt(string);
        string getmsv();
        void setmsv(string);
        int getngay();
        void setngay(int);
        int getthang();
        void setthang(int);
        int getnam();
        void setnam(int);
        int gettuoi();
        void settuoi(int);
};
int sinhvien::gettuoi(){
	return tuoi;
}
void sinhvien::settuoi(int tuoi){
	this->tuoi=tuoi;
}
int sinhvien::getngay(){
	return ngay;
}
void sinhvien::setngay(int ngay){
	this->ngay=ngay;
}
int sinhvien::getthang(){
	return thang;
}
void sinhvien::setthang(int thang){
	this->thang=thang;
}
int sinhvien::getnam(){
	return nam;
}
void sinhvien::setnam(int nam){
	this->nam=nam;
}
void sinhvien::setmsv(string msv){
	this->msv=msv;
}
string sinhvien::getmsv(){
	return msv;
}
void sinhvien::setgt(string gt){
	this->gt=gt;
}
string sinhvien::getgt(){
	return gt;
}
void sinhvien::setten(string ten){
	this->ten=ten;
}
string sinhvien::getten(){
	return ten;
}
void sinhvien::nhap_sinhvien(){
	cin.ignore();
	cout<<"\nNhap ho ten sinh vien: ";
	getline(cin,ten);
	fflush(stdin);
	cout<<"\nNhap ma so sinh vien: ";
	getline(cin,msv);
	fflush(stdin);
	cout<<"\nNhap gioi tinh: ";
	getline(cin,gt);
	cout<<"\nNhap vao ngay, thang, nam (dd/mm/yyyy):  "<<endl;
	do{
		cout<<"Nhap ngay: ";
		cin>>ngay;
		if(ngay<=0||ngay>31)
			cout<<"Ngay khong hop le vui long nhap lai!"<<endl;
	}while(ngay<=0||ngay>31);
	do{
		cout<<"Nhap thang: ";
		cin>>thang;
		if(thang<=0||thang>12)
			cout<<"Thang khong hop le vui long nhap lai!"<<endl;
	}while(thang<=0||thang>12);
	do{
		cout<<"Nhap nam: ";
		cin>>nam;
		if(nam<1990||nam>2021)
			cout<<"Nam khong hop le vui long nhap lai!"<<endl;
	}while(nam<1990||nam>2021);
	cout<<"\nNhap tuoi: ";
	cin>>tuoi;
}
void sinhvien::xuat_sinhvien(){
	cout<<"\t"<<left<<setw(30)<<ten<<"\t";
    cout<<left<<setw(12)<<msv<<"\t";
    cout<<left<<setw(9)<<gt<<"\t";
    cout<<left<<setw(0)<<ngay<<"/"<<thang<<"/"<<nam<<left<<setw(9)<<"\t";
    cout<<left<<setw(5)<<tuoi<<"\t";
}
void sinhvien::loading(){
	char x=219;
	cout << "Loading ";
    for(int i=0;i<=40;i++){
    Sleep(40);
    cout<<x;
	}
}
void sinhvien::animation(char q[100]){
	for ( int i =0 ; q[i]!='\0'; i++){
		for (double k=0; k<12000000; k++);
		cout<<q[i];
	}
}
void sinhvien::thanhviennhom(){
	animation("\tCHUONG TRINH QUAN LY SINH VIEN NHOM 9");
	cout<<"\n                                                          ";
	animation("\nThanh vien nhom:    Mai Danh Dung       6151071038 ");
	cout<<"\n                                                          ";
	animation("\n                    Nguyen Nhat Truong  6151071110 ");
	cout<<"\n                                                          ";
	animation("\n                    Tran Hoang Trieu    6151071107 ");
	cout<<endl;
}
void sinhvien::intro(){
	thanhviennhom();
	system("pause");
	cout<<"\t";
	loading();
	system("cls");
}
void display_diem(){
	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(12)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(6)<<"DiemTB"<<"\t"<<left<<setw(5)<<"DiemC"<<"\t"<<left<<setw(5)<<"DiemRL"<<endl;

}
void display_xeploai(){
	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(12)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(6)<<"DiemTB"<<"\t"<<left<<setw(5)<<"DiemC"<<"\t"<<left<<setw(5)<<"DiemRL"<<"\t"<<left<<setw(15)<<"Xep loai"<<endl;

}
void display(){
	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(15)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<endl;

}
void display_dkhocphan(){
	cout<<left<<setw(10)<<"Mon hoc"<<"\t"<<left<<setw(10)<<"Tin Chi"<<"\t"<<left<<setw(15)<<"Ma hoc phan"<<"\t"<<left<<setw(15)<<"Hoc Phi"<<endl;
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;  
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };  
	SetConsoleCursorPosition(h,c);
}
class Node{
	private:
		sinhvien data;
		Node *next;
	public:
		friend class SList;
};
int size = 0;
class SList{
	private:
		Node *Head;
		Node *Tail;
	public:
		SList();
		~SList();
		Node *CreateNode(sinhvien  sv);
		void Add();
		void XuatDS();
		void DeleteFirst();
		void DeleteLast();
		void DeleteSV();
		void timkiem_msv();
		void timkiem_ten();
		void Xeploai();
		void DKHP();
		void InDKHP();
				
};
SList::SList(){
	Head = NULL;
	Tail = NULL;
}
SList::~SList(){
}
Node* SList::CreateNode(sinhvien sv){
	size++;
	Node* p =new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}
void SList::Add(){
	sinhvien sv;
	sv.nhap_sinhvien();
	sv.nhapd();
	Node*p = CreateNode(sv);
	if(Head == Tail && Head == NULL){
		Tail = Head = p;
		Tail->next = NULL;
		Head->next = NULL;
	}
	else{
		Tail->next = p;
		Tail =p;
	}
}
void SList::DeleteFirst(){
	Node *p = Head;
	Head = Head->next;
	delete p;
	cout <<"Xoa thanh cong"<<endl;
}
void SList::DeleteLast(){
	Node *p;
	for( Node *k = Head; k!= NULL; k = k->next){
		if(k == Tail){		
			Tail = p;
			Tail->next = NULL;
			delete k;
			cout <<"Xoa thanh cong"<<endl;
			return;
		}
		p = k;
	}
}
void SList::DeleteSV(){
	string xoa;
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	fflush(stdin);
	cout <<"\t\tNhap ten sinh vien muon xoa: ";
	getline(cin,xoa);
	if(Head->data.getten() == xoa ){
		DeleteFirst();
		return;
	}	
	if(Tail->data.getten() == xoa){
		DeleteLast();
		return;
	}
	Node *p;
	for(Node *k = Head; k != NULL; k = k->next){
		if( k->data.getten() == xoa ){
			p->next = k->next; 
			delete k;
			cout <<"Xoa thanh cong"<<endl;
			return;	
		}
		p = k; 
	}
}
void SList::timkiem_msv(){
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	string masinhvien;
	fflush(stdin);
	cout <<"Nhap ma sinh vien muon tim kiem: ";
	getline(cin,masinhvien);
	display_diem();
	int i=1;
	for(Node *p = Head; p != NULL; p = p->next ){
		if( p->data.getmsv()== masinhvien ){
			cout<<i++;
			p->data.xuat_sinhvien();
			p->data.xuatd();
		}
	}
}
void SList::timkiem_ten(){
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	string name;
	fflush(stdin);
	cout <<"Nhap ten sinh vien muon tim kiem: ";
	getline(cin,name);
	display_diem();
	int i=1;
	for(Node *p = Head; p != NULL; p = p->next ){
		if( p->data.getten()== name ){
			cout<<i++;
			p->data.xuat_sinhvien();
			p->data.xuatd();
		}
	}
}
void SList::Xeploai(){
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	sinhvien sv;
	int i=1;
	display_xeploai();
	for(Node *p = Head; p != NULL; p = p->next ){
		cout<<i++;
		p->data.xuat_sinhvien();
		p->data.xuatd();
		sv.xeploai();
	}
}
void SList::DKHP(){
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	string name3;
	fflush(stdin);
	cout<<"Nhap sinh vien muon dang ki hoc phan: ";
	getline(cin,name3);
	int i=1;
	for(Node *p = Head; p != NULL; p = p->next ){
		if( p->data.getten()== name3 ){
			p->data.nhaphocphan();
		}	
	}
}
void SList::InDKHP(){
	display_dkhocphan();
	for(Node *p = Head; p != NULL ; p = p->next){
		p->data.xuathocphan();
		cout<<endl;
		p->data.tinhtienhoc();
		cout<<endl;
	}
}
void SList::XuatDS(){
	int i=1;
	display_diem();
	for(Node *p = Head; p != NULL ; p = p->next){
		cout<<i++;	
		p->data.xuat_sinhvien();
		p->data.xuatd();
		cout<<endl;
	}
}
int main()
{
	int n,key, sohocphan;
	sinhvien sv;
	SList list;
	system("color 0A ");
	sv.intro();
	bool c = true;
	while(c){
	gotoxy(50,0);cout<<"********************** MENU ***************************";
    gotoxy(50,1);cout<<"*                                                     *";
    gotoxy(50,2);cout<<"*                 QUAN LY SINH VIEN                   *";
    gotoxy(50,3);cout<<"*                                                     *";
    gotoxy(50,4);cout<<"*  I.   SINH VIEN                                     *";
    gotoxy(50,5);cout<<"*                                                     *";
    gotoxy(50,6);cout<<"*  1. Nhap vao sinh vien                              *";
    gotoxy(50,7);cout<<"*  2. Xuat sinh vien vua nhap                         *";
    gotoxy(50,8);cout<<"*  3. Xep loai sinh vien theo DTB                     *";
    gotoxy(50,9);cout<<"*  4. Tim kiem sinh vien bang ma sinh vien            *";
    gotoxy(50,10);cout<<"* 5. Tim kiem sinh vien bang ten                     *";
    gotoxy(50,11);cout<<"*  6. Them sinh vien                                 *";
    gotoxy(50,12);cout<<"*  7. Cap nhat thong tin sinh vien                   *";
    gotoxy(50,13);cout<<"*  8. Xoa sinh vien                                 *";
    gotoxy(50,14);cout<<"*                                                     *";
    gotoxy(50,15);cout<<"*  II.  DANG KI HOC PHAN                             *";
    gotoxy(50,16);cout<<"*                                                    *";
    gotoxy(50,17);cout<<"*  9. Nhap hoc phan muon dang ki                     *";
    gotoxy(50,18);cout<<"*  10. In ra man hinh tong hoc phi                    *";
    gotoxy(50,19);cout<<"*  11. Thoat chuong trinh                            *";
    gotoxy(50,20);cout<<"Nhap tuy chon: ";     
	cin>>key; 
    switch(key){
    	case (1):
    		system("cls");
    		cout<<"So sinh vien ban muon nhap vao la: ";
    		cin>>n;
            for (int i = 0; i<n; i++){
                cout << "\nThong tin sinh vien thu " << i + 1 << "\n";
				list.Add(); 
	            }
    		system("cls");
	        break;
		case (2):
			list.XuatDS();
			system("pause>null");
			system("cls");
			break;
		case (3):
			list.Xeploai();
			system("pause>null");
			system("cls");
			break;
		case (4):
			list.timkiem_msv();
			system("pause>null");
			system("cls");
			break;
		case (5):
			list.timkiem_ten();
			system("pause>null");
			system("cls");
			break;
		case (6):
			list.DKHP();
	       	system("cls");
			break;
	    case (7):
			list.InDKHP();
			system("pause>null");
			system("cls");
			break;
		case (8):
			list.Add();
			system("cls");
			break;
		case(9):
			list.XuatDS();
			system("pause>null");
			system("cls");
			break;
		case(10):
			list.DeleteSV();
			system("pause>null");
			system("cls");
			break;
		case(11):
			default: c = false;
			break; 
		};
	}
	return 0;
}




