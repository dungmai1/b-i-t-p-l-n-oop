#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include"dohoa.h"
class diem{
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
		float getdc();
		void setdc(float);	
		float getdrl();
		void setdrl(float);
};
void diem::setdtb(float dtb){
	this->dtb = dtb;
}
float diem::getdtb(){
	return dtb;
}
void diem::setdc(float dtb){
	this->dc = dc;
}
float diem::getdc(){
	return dc;
}
void diem::setdrl(float dtb){
	this->drl = drl;
}
float diem::getdrl(){
	return drl;
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
		void xoahocphan();
};
void dkhocphan::nhaphocphan(){
	fflush(stdin);
	cout<<"Nhap so hoc phan muon dang ki : ";
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
		cout<<"Hoc phi (so tien 1 tin chi): ";
		cin>>hocphans[i].hocphi;	
	}
}
void dkhocphan::xuathocphan(){
	for(int i =0; i<sohocphan; i++){
		cout<<left<<setw(10)<<hocphans[i].monhoc<<"\t";
	    cout<<left<<setw(10)<<hocphans[i].sotinchi<<"\t";
		cout<<left<<setw(15)<<hocphans[i].mhp<<"\t";
		cout<<left<<setw(15)<<hocphans[i].hocphi<<"\t"<<endl;
		cout<<left<<setw(3)<<"   "<<"\t"<<left<<setw(30)<<"                              "<<"\t"<<left<<setw(15)<<"               "<<"\t"<<left<<setw(9)<<"         "<<"\t"<<left<<setw(20)<<"                    "<<"\t"<<left<<setw(5)<<"     "<<"\t";
	}	
}
void dkhocphan::tinhtienhoc(){
	int sotien=0;
	for(int i =0; i<sohocphan; i++){
		sotien += (hocphans[i].sotinchi*hocphans[i].hocphi);
	}
	cout<<"Tong so tien cua dang ki hoc phan la: "<<sotien<<endl;
}
void dkhocphan::xoahocphan(){
	string hp;
	fflush(stdin);
	cout<<"Nhap ten hoc phan muon xoa: ";
	getline(cin,hp);
	for(int i = 0; i<sohocphan; i++){
		if(hocphans[i].monhoc==hp)
			hocphans[i] = hocphans[i+1];
	}
	sohocphan--;
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
void display_diem(){
	duong_thang();
	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(12)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(6)<<"DiemTB"<<"\t"<<left<<setw(5)<<"DiemC"<<"\t"<<left<<setw(5)<<"DiemRL"<<endl;
	duong_thang();
}
void display_xeploai(){
	duong_thang1();
	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(12)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(6)<<"DiemTB"<<"\t"<<left<<setw(5)<<"DiemC"<<"\t"<<left<<setw(5)<<"DiemRL"<<"\t"<<left<<setw(15)<<"Xep loai"<<endl;
	duong_thang1();
}
void display(){
	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(15)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<endl;
}
void display_dkhocphan(){
	duong_thangdkhocphan();
	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(15)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(10)<<"Mon hoc"<<"\t"<<left<<setw(10)<<"Tin Chi"<<"\t"<<left<<setw(15)<<"Ma hoc phan"<<"\t"<<left<<setw(15)<<"Hoc Phi"<<endl;
	duong_thangdkhocphan();
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
		void xuat();
		void XoaDau();
		void XoaCuoi();
		void DeleteSV();
		void timkiem_msv();
		void timkiem_ten();
		void Xeploai();
		void DKHP();
		void InDKHP();
		void ghifile();
		void xoahp();	
};
SList::SList(){
	Head = NULL;
	Tail = NULL;
}
SList::~SList(){
}
Node* SList::CreateNode(sinhvien sv){
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
void SList::XoaDau(){
	Node *p = Head;
	Head = Head->next;
	delete p;
	cout <<"Xoa thanh cong"<<endl;
}
void SList::XoaCuoi(){
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
		XoaDau();
		return;
	}	
	if(Tail->data.getten() == xoa){
		XoaCuoi();
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
			cout<<endl;
			duong_thang();
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
			cout<<endl;
			duong_thang();
		}
	}
}
void SList::Xeploai(){
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	int i=1;
	display_xeploai();
	for(Node *p = Head; p != NULL; p = p->next ){
		cout<<i++;
		p->data.xuat_sinhvien();
		p->data.xuatd();
		p->data.xeploai();
		duong_thang1();
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
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	int i=1;
	display_dkhocphan();
	for(Node *p = Head; p != NULL ; p = p->next){
		cout<<i++;
		p->data.xuat_sinhvien();
		p->data.xuathocphan();
		p->data.tinhtienhoc();
		duong_thangdkhocphan();	
	}
}
void SList::xoahp(){
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	string huydkhp;
	fflush(stdin);
	cout<<"Nhap ten sinh vien muon huy dang ki hoc phan: ";
	getline(cin,huydkhp);
	for(Node *p = Head; p != NULL; p = p->next ){
		if( p->data.getten()== huydkhp ){
			p->data.xoahocphan();
		}	
	}
}
void SList::ghifile(){
	sinhvien sv;
	int i=1;
	fstream f;
	if (!f.eof()){
		f.open("sinhvien.txt", ios::app);
		if( Head == Tail && Head == NULL ){
			cout << endl;
			cout<<"\t\t\tDanh sach rong, khong the ghi vao file !!!"<<endl;
		}
		for(Node *p = Head; p!=NULL;p=p->next){
			f<<"Ho va ten: "<< p->data.getten()<<endl;
			f<<"Ma sinh vien: "<< p->data.getmsv()<<endl;
			f<<"Tuoi: "<< p->data.gettuoi()<<endl;
			f<<"Gioi tinh: "<< p->data.getgt()<<endl;
			f<<"Ngay: "<< p->data.getngay()<<endl;
			f<<"Thang: "<< p->data.getthang()<<endl;
			f<<"Nam: "<< p->data.getnam()<<endl;
			f<<"Tuoi: "<<p->data.gettuoi()<<endl;
			f<<"Diem trung binh: "<<p->data.getdtb()<<endl;
			f<<"Diem cong: "<<p->data.getdc()<<endl;
			f<<"Diem ren luyen: "<<p->data.getdrl()<<endl;
			f<<"-------------------------------------------"<<endl;
			f.seekp(1);
			f<<endl;
			cout<<"\tDa ghi sinh vien so "<<i++<<" vao file!!!"<<endl;
		}
	}
}
void SList::xuat(){
	if(Head == Tail && Head == NULL){
		cout <<"Chua co sinh vien"<<endl;
		return;
	}
	int i=1;
	display_diem();
	for(Node *p = Head; p != NULL ; p = p->next){
		cout<<i++;	
		p->data.xuat_sinhvien();
		p->data.xuatd();
		cout<<endl;
		duong_thang();
	}
}
int main()
{
	int n,key;
	SList list;
	sinhvien sv;
	intro();
	bool c = true;
	while(c){
	BangMenu(0,0);
	textcolor(10);
	gotoxy(2,1); 	cout<<"************************************************************";
    gotoxy(2,2); 	cout<<"|----------------------------------------------------------|";
    gotoxy(2,3); 	cout<<"|                    QUAN LY SINH VIEN                     |";
    gotoxy(2,4); 	cout<<"|----------------------------------------------------------|";
   	gotoxy(2,5); 	cout<<"|  I.   SINH VIEN                                          |";
    gotoxy(2,6);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,7); 	cout<<"|  1. Nhap vao sinh vien                                   |";
    gotoxy(2,8);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,9); 	cout<<"|  2. Xuat sinh vien vua nhap                              |";
    gotoxy(2,10);   cout<<"|----------------------------------------------------------|";
    gotoxy(2,11); 	cout<<"|  3. Xep loai sinh vien theo DTB                          |";
    gotoxy(2,12);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,13);	cout<<"|  4. Tim kiem sinh vien bang ma sinh vien                 |";
    gotoxy(2,14);   cout<<"|----------------------------------------------------------|";
    gotoxy(2,15);	cout<<"|  5. Tim kiem sinh vien bang ten                          |";
    gotoxy(2,16);   cout<<"|----------------------------------------------------------|";
    gotoxy(2,17);	cout<<"|  6. Them sinh vien                                       |";
    gotoxy(2,18);   cout<<"|----------------------------------------------------------|";
    gotoxy(2,19);	cout<<"|  7. Cap nhat thong tin sinh vien                         |";
    gotoxy(2,20);   cout<<"|----------------------------------------------------------|";
    gotoxy(2,21);	cout<<"|  8. Xoa sinh vien                                        |";
    gotoxy(2,22);   cout<<"|----------------------------------------------------------|";
    gotoxy(2,23);	cout<<"|  9. Xuat file txt                                        |";
    gotoxy(2,24);   cout<<"|----------------------------------------------------------|";
    gotoxy(2,25);	cout<<"|  II.  DANG KI HOC PHAN                                   |";
    gotoxy(2,26);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,27);	cout<<"|  10. Nhap hoc phan muon dang ki                          |";
    gotoxy(2,28);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,29);	cout<<"|  11. In ra man hinh tong hoc phi                         |";
    gotoxy(2,30);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,31);	cout<<"|  12. Huy hoc phan da dang ki                             |";
    gotoxy(2,32);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,33);	cout<<"|  13. Thoat chuong trinh                                  |";
    gotoxy(2,34);	cout<<"|----------------------------------------------------------|";
    gotoxy(2,35);	cout<<"************************************************************";
    gotoxy(2,37);cout<<"Nhap tuy chon: ";     
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
			list.xuat();
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
			list.Add();
			system("cls");
			break;
		case(7):
			list.xuat();
			system("pause>null");
			system("cls");
			break;
		case(8):
			list.DeleteSV();
			system("pause>null");
			system("cls");
			break;
		case(9):	
			list.ghifile();
			system("pause>null");
			system("cls");
			break;
		case (10):
			list.DKHP();
			system("pause>null");
	       	system("cls");
			break;
	    case (11):
			list.InDKHP();
			system("pause>null");
			system("cls");
			break;
		case(12):
			list.xoahp();
			system("pause>null");
			system("cls");
			break;
		case(13):
			theend();
			default: c = false;
			break;
		};
	}
	return 0;
}
