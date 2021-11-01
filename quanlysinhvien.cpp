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
	int n;
	cout <<"\n\STT\tHo va ten\tMa sinh vien\tGioi tinh\tNgay/Thang/Nam\tTuoi\tDTB\tDRL\tDC\tHoc luc";
	for(int i = 0; i < n; i++) {
        cout<<"\n"<< i + 1;
        cout<<"\t"<<ten;
        cout<<"\t\t"<<msv;
        cout<<"\t\t"<<gt;
        cout<<"\t\t"<<ngay<<"/"<<thang<<"/"<<nam;
        cout<<"\t\t"<<tuoi;
	}
}
void nguoi::timkiem_msv(){
}
int main()
{
	int n,x;
	nguoi ns;
	cout<<"\n***********************MENU****************************";
    cout<<"\n*                 QUAN LY SINH VIEN                   *";
    cout<<"\n*                                                     *";
    cout<<"\n*  I. QUAN LY SINH VIEN                               *";
    cout<<"\n*                                                     *";
    cout<<"\n*  1. Nhap vao sinh vien                              *";
    cout<<"\n*  2. Tim kiem theo ma so sinh vien                   *";
    cout<<"\n*  3. Tim kiem theo ten sinh vien                     *";
    cout<<"\n*  4. Danh sach sinh vien                             *";
    cout<<"\n*  5. Xoa                                             *";
    cout<<"\n\Nhap tuy chon: ";
    cin>>n;
    switch(n){
    		case (1):{
    			cout<<"Nhap so luong sinh vien muon nhap vao: ";
    			cin>>x;
    			for( int i = 0; i < x ; i++){
    				cout<<"\tThong tin sinh vien thu "<<i+1;
    				ns.nhap_nguoi();
						}
    			ns.xuat_nguoi();
            		}
            		break;
            case(2):{
				ns.timkiem_msv();
			}		
	}



}


