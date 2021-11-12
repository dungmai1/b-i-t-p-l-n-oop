#include<iostream>
#include<string>
#include<iomanip> 
using namespace std;
class sinhvien
{
    private:
        string ten;
        string gt;
        int tuoi,ngay,thang,nam,msv;
    public:
    	sinhvien();
    	~sinhvien();
        void nhap_sinhvien();
        void xuat_sinhvien();
};
sinhvien :: sinhvien(){
	ten = "";
	msv = 0;
	gt = "";
	ngay = 0;
	thang = 0;
	nam = 0;
	tuoi = 0;
}
sinhvien :: ~sinhvien(){
	
}
void sinhvien::nhap_sinhvien(){
	cin.ignore();
	cout<<"\nNhap ho ten sinh vien: ";
	getline(cin,ten);
	cout<<"\nNhap ma so sinh vien: ";
	cin>>msv;
	fflush(stdin);
	cout<<"\nNhap gioi tinh: ";
	getline(cin,gt);
	cout<<"\nNhap vao ngay, thang, nam (dd/mm/yyyy):  ";
	cin>>ngay>>thang>>nam;
	cout<<"\nNhap tuoi: ";
	cin>>tuoi;
}
void sinhvien::xuat_sinhvien(){
	cout<<"\t"<<left<<setw(30)<<ten<<"\t";
    cout<<left<<setw(12)<<msv<<"\t";
    cout<<left<<setw(9)<<gt<<"\t";
    cout<<left<<setw(0)<<ngay<<"/"<<thang<<"/"<<nam<<left<<setw(17)<<"\t";
    cout<<left<<setw(5)<<tuoi<<"\t";
}
class diem : public sinhvien{
	private:
	    float dtb,dc,drl;
	public:
		diem();
		~diem();
		void nhapd();
		void xuatd();
};
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



diem::diem(){
	dtb = 0;
	drl = 0;
	dc = 0;
}
diem::~diem(){	
}

int main()
{
	int n,key,sohocphan;
	sinhvien a[200];
	diem d[200];
	bool c = true;
	while(c){
	cout<<"\n***********************MENU****************************";
    cout<<"\n*                 QUAN LY SINH VIEN                   *";
    cout<<"\n*                                                     *";
    cout<<"\n*  I. QUAN LY SINH VIEN                               *";
    cout<<"\n*                                                     *";
    cout<<"\n*  1. Nhap vao sinh vien                              *";
    cout<<"\n*  2. Xuat sinh vien vua nhap                         *";
    cout<<"\nNhap tuy chon: ";     
	cin>>key; 
    switch(key){
    	case (1):
    		cout<<"So sinh vien ban muon nhap vao la: ";
    		cin>>n;
            for (int i =0; i<n; i++){
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
		case (8):
			break;
			default: c = false;
			break; 
		};
	}
	return 0;
}




