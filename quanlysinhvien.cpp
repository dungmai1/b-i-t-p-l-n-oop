#include<iostream>
#include<string>
using namespace std;
class ngaysinh
{
	protected:
	    int ngay;
	    int thang;
	    int nam;
};
class nguoi : public ngaysinh
{
    private:
        int msv;
        string ten;
        string gt;
        int tuoi;
    public:
        void nhap_nguoi();
        void xuat_nguoi();
        void timkiem_msv();
};
class diem : public nguoi
{
    private:
        float dtb;
        float drl;
        float dcong;
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
void nguoi::nhap_nguoi(){
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
void nguoi::xuat_nguoi(){
    cout<<"\t"<<ten;
    cout<<"\t\t"<<msv;
    cout<<"\t\t"<<gt;
    cout<<"\t\t"<<ngay<<"/"<<thang<<"/"<<nam;
    cout<<"\t\t"<<tuoi;
}
void nguoi::timkiem_msv(){
}
int main()
{
	int n,key;
	nguoi a[200];
	system("cls");
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
                a[i].nhap_nguoi();
	            }
	        cout <<"\nSTT\tHo va ten\tMa sinh vien\tGioi tinh\tNgay/Thang/Nam\tTuoi\tDTB\tDRL\tDC\tHoc luc";    
	        for(int i=0; i<n;i++){
	            cout<<"\n"<< i + 1;
				a[i].xuat_nguoi();
			}
	    	break;
	    case (2):
	 ; 	
	}
}



