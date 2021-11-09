#include<iostream>
#include<string>
using namespace std;
class sinhvien
{
    private:
        int msv;
        string ten;
        string gt;
        int tuoi;
        int ngay;
	    int thang;
	    int nam;
    public:
        void nhap_sinhvien();
        void xuat_sinhvien();
    	void themsv();
    	void xoasv();
    	void timkiemsv();
    	string ten1(){
    		return ten;
		}
};
class diem : public sinhvien
{
    private:
        float dtb;
        float dcong;
        float drl;
    public:
        diem(){}
        void nhap_diem();
        void in_diem();
        void sapxep();
        void timkiemdiem_dtb(float diemtb);
        void timkiemdiem_masv(int msv);
        void timkiemdiem_ten(char tensv[]);
        void ghi_file();
        void doc_file(int sod);
        float laydtb();
};
class hocluc: public diem
{
 	public:
 		void hocluc1();
 		void sapxephocluc();
};
class dkhocphan
{
	private:
		int tinchi;
		string monhoc;
		int sotinchi;
	public:
		void nhapmonhoc();
		void tinhtienhoc();
		void tongtienhoc();
};
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
    cout<<"\t"<<ten;
    cout<<"\t\t"<<msv;
    cout<<"\t\t"<<gt;
    cout<<"\t\t"<<ngay<<"/"<<thang<<"/"<<nam;
    cout<<"\t\t"<<tuoi;
}
void sinhvien::timkiemsv(){
}
int main()
{
	int n,key;
	string ten1;
	sinhvien a[200], r;
	cout<<"\n***********************MENU****************************";
    cout<<"\n*                 QUAN LY SINH VIEN                   *";
    cout<<"\n*                                                     *";
    cout<<"\n*  I. QUAN LY SINH VIEN                               *";
    cout<<"\n*                                                     *";
    cout<<"\n*  1. Nhap vao sinh vien                              *";
    cout<<"\n*  2. Xuat sinh vien vua nhap                         *";
    cout<<"\n*  3. Tim kiem theo ma so sinh vien                   *";
    cout<<"\n*  4. Tim kiem theo ten sinh vien                     *";
    cout<<"\n*  5. Danh sach sinh vien                             *";
    cout<<"\n*  6. Xoa                                             *";
    cout<<"\nNhap tuy chon: ";
    cin>>key;
    switch(key){
    	case (1):
    		cout<<"So sinh vien ban muon nhap vao la: ";
    		cin>>n;
            for (int i =0; i<n; i++){
                cout << "\nThong tin sinh vien thu " << i + 1 << "\n";
                a[i].nhap_sinhvien();
	            }
	        cout <<"\nSTT\tHo va ten\tMa sinh vien\tGioi tinh\tNgay/Thang/Nam\tTuoi\tDTB\tDRL\tDC\tHoc luc";    
	        for(int i=0; i<n;i++){
	            cout<<"\n"<< i + 1;
				a[i].xuat_sinhvien();
			} 
	    	break;
	    case (2):
	    	cout<<"Nhap ten ban muon tim kiem: ";
	    	getline(cin,ten1);
	    	for(int i =0 ; i<n ; i++){
	    		if (a[i].ten1()==ten1)
        		r = a[i];
            	ten1=a[i].ten1();  
			}
	 		break; 	
	}
}



