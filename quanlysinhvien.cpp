#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
class sinhvien
{
	protected:
		float dtb,dc,drl;
    private:
    	char x = 219;
        string ten;
        string gt;
        string msv;
        int tuoi,ngay,thang,nam;
    public:
        void nhap_sinhvien();
        void xuat_sinhvien();
        void loading();
        void animation(char q[]);
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
	}while(ngay<=0||ngay>31);
	do{
		cout<<"Nhap thang: ";
		cin>>thang;
	}while(thang<=0||thang>12);
	do{
		cout<<"Nhap nam: ";
		cin>>nam;
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
class diem : public sinhvien{
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
class dkhocphan : public sinhvien  
{
	private:
		float hocphi;
		string monhoc,mhp;
		int sotinchi;
		float tth;
	public:
		dkhocphan();
    	~dkhocphan();
		void nhaphocphan();
		void xuathocphan();
		void tinhtienhoc();
		float gettinchi(){
			return hocphi;
		};
		int getsotinchi(){
			return sotinchi;
		};
		void settinchi(float);
		void setsotinchi(int);			
};
void dkhocphan::nhaphocphan(){
	fflush(stdin);
	cout<<"Nhap ten hoc phan: ";
	getline(cin,monhoc);
	cout<<"So tin chi: ";
	cin>>sotinchi;
	fflush(stdin);
	cout<<"Ma hoc phan: ";
	getline(cin,mhp);
	cout<<"Hoc phi: ";
	cin>>hocphi;
}
void dkhocphan::xuathocphan(){
	cout<<left<<setw(10)<<monhoc<<"\t";
    cout<<left<<setw(10)<<sotinchi<<"\t";
	cout<<left<<setw(15)<<mhp<<"\t";
	cout<<left<<setw(15)<<hocphi<<"\t";
}
dkhocphan::dkhocphan(){
	monhoc = "";
	mhp = "";
	sotinchi = 0;
	tth = 0;
}
dkhocphan::~dkhocphan(){	
}
void dkhocphan::tinhtienhoc(){
	tth = sotinchi*hocphi;
	cout<<left<<setw(15)<<tth<<endl;
}
void dkhocphan::settinchi(float hocphi){
	this->hocphi=hocphi;
}
void dkhocphan::setsotinchi(int sotinchi){
	this->sotinchi=sotinchi;
} 
int main()
{
	int n,key,sohocphan;
	string name;
	system("color 0A ");
	sinhvien a[200], sv;
	dkhocphan dkhp[200];
	diem d[200],e;
	sv.animation("\tCHUONG TRINH QUAN LY SINH VIEN NHOM 9");
	cout<<"\n                                                          ";
	sv.animation("\nThanh vien nhom:    Mai Danh Dung       6151071038 ");
	cout<<"\n                                                          ";
	sv.animation("\n                    Nguyen Nhat Truong  6151071110 ");
	cout<<"\n                                                          ";
	sv.animation("\n                    Tran Hoang Trieu    6151071107 ");
	cout<<endl; 
	system("pause");
	cout<<"\t";
	sv.loading();
	system("cls");
	bool c = true;
	while(c){
	cout<<"\n\t\t********************** MENU ***************************";
    cout<<"\n\t\t*                                                     *";
    cout<<"\n\t\t*                 QUAN LY SINH VIEN                   *";
    cout<<"\n\t\t*                                                     *";
    cout<<"\n\t\t*  I.   SINH VIEN                                     *";
    cout<<"\n\t\t*                                                     *";
    cout<<"\n\t\t*  1. Nhap vao sinh vien                              *";
    cout<<"\n\t\t*  2. Xuat sinh vien vua nhap                         *";
    cout<<"\n\t\t*  3. Xep loai sinh vien theo DTB                     *";
    cout<<"\n\t\t*  4. Tim kiem sinh vien bang ten                     *";
    cout<<"\n\t\t*                                                     *";
    cout<<"\n\t\t*  II.  DANG KI HOC PHAN                              *";
    cout<<"\n\t\t*                                                     *";
    cout<<"\n\t\t*  5. Nhap hoc phan muon dang ki                      *";
    cout<<"\n\t\t*  6. In ra man hinh tong hoc phi                     *";
    cout<<"\n\t\t*                                                     *";
    cout<<"\n\t\t*  III.                                               *";
    cout<<"\n\t\t*                                                     *";
    cout<<"\nNhap tuy chon: ";     
	cin>>key; 
    switch(key){
    	case (1):
    		cout<<"So sinh vien ban muon nhap vao la: ";
    		cin>>n;
            for (int i = 0; i<n; i++){
                cout << "\nThong tin sinh vien thu " << i + 1 << "\n";
                a[i].nhap_sinhvien();
                d[i].nhapd();
	            }
	       	system("cls");
	        break;
		case (2):
			cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(12)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(6)<<"DiemTB"<<"\t"<<left<<setw(5)<<"DiemC"<<"\t"<<left<<setw(5)<<"DiemRL"<<endl;
	        for(int i=0; i<n;i++){
	        	cout<<i+1;
				a[i].xuat_sinhvien();
				d[i].xuatd();
				cout<<endl;
			}
			system("pause>null");
			system("cls");
			break;
		case (3):
			cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(12)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(6)<<"DiemTB"<<"\t"<<left<<setw(15)<<"Xep loai"<<endl;
			for(int i=0; i<n;i++){
				cout<<i+1;
				a[i].xuat_sinhvien();
				cout<<d[i].getdtb()<<"\t";
				d[i].xeploai();
			}
			system("pause>null");
			system("cls");
			break;
		case (4):
			fflush(stdin);
			cout<<"NHap ten tim kiem: ";
    		getline(cin,name);
			for (int i = 0; i<n; i++){
				if(a[i].getten()==name){ 
					cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(15)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<endl;
					cout<<i+1;
					cout<<"\t"<<left<<setw(30)<<a[i].getten()<<"\t";
				    cout<<left<<setw(12)<<a[i].getmsv()<<"\t";
				    cout<<left<<setw(9)<<a[i].getgt()<<"\t";
				    cout<<left<<setw(0)<<a[i].getngay()<<"/"<<a[i].getthang()<<"/"<<a[i].getnam()<<left<<setw(9)<<"\t";
				    cout<<left<<setw(5)<<a[i].gettuoi()<<"\t";
				}
			}
			break;
		case (5):
			cout<<"Nhap so hoc phan muon dang ki: ";
			cin>>sohocphan;
	    	for(int i=0; i<sohocphan;i++){
	    		cout<<endl; 
	    		dkhp[i].nhaphocphan();
			}
	       	system("cls");
			break;
	    case (6):
	    	cout<<left<<setw(3)<<"STT"<<"\t"<<left<<setw(30)<<"Ho va Ten"<<"\t"<<left<<setw(15)<<"MSV"<<"\t"<<left<<setw(9)<<"Gioi tinh"<<"\t"<<left<<setw(20)<<"Ngay/Thang/Nam"<<"\t"<<left<<setw(5)<<"Tuoi"<<"\t"<<left<<setw(10)<<"Mon hoc"<<"\t"<<left<<setw(10)<<"Tin Chi"<<"\t"<<left<<setw(15)<<"Ma hoc phan"<<"\t"<<left<<setw(15)<<"Hoc Phi"<<"\t"<<left<<setw(15)<<"Tong Tien"<<endl;
	    	for(int i=0; i<sohocphan;i++){
	    		cout<<i+1;
				a[i].xuat_sinhvien();
				dkhp[i].xuathocphan();
				dkhp[i].tinhtienhoc();
			}
			system("pause>null");
			system("cls");
			break;
		case (7):
			break;
		case (8):
			break;
			default: c = false;
			break; 
		};
	}
	return 0;
}




