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
        ngaysinh ns;
        string gt;
    public:
        void nhap_nguoi();
        void xuat_nguoi();
        void nhap_ns();
	    void xuat_ns();
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
void nguoi::nhap_ns()
{
	char ch;
	cout<<"Nhap vao ngay, thang, nam (dd/mm/yyyy):  ";
	cin>>ngay>>thang>>nam;
}
void nguoi::xuat_ns()
{
	cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}
void nguoi::nhap_nguoi(){
	cout<<"\nNhap ho ten sinh vien: ";
	getline(cin,ten);
	fflush(stdin);
	cout<<"\nNhap ma so sinh vien: ";
	cin>>msv;
	fflush(stdin);
	cout<<"\nNhap gioi tinh: ";
	getline(cin,gt);
}
void nguoi::xuat_nguoi(){
	cout<<"\nThong tin sinh vien ban vua nhap la: ";
	cout<<"\nHo va ten: "<<ten;
	cout<<"\nMa sinh vien: "<<msv;
	cout<<"\nGioi tinh: "<<gt;
}
int main()
{
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
    nguoi ns;
    ns.nhap_nguoi();
    ns.xuat_nguoi();
}


