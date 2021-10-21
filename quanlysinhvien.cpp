#include<iostream>
using namespace std;
class ngaysinh
{
	private:
	    int ngay;
	    int thang;
	    int nam;
	public:
	    void nhap_ns();
	    void xuat_ns();
};
class nguoi : public ngaysinh
{
    private:
        int masv;
        char ten[30];
        ngaysinh ns;
        int gt;
    public:
        void nhap_nguoi();
        void xuat_nguoi();
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
void ngaysinh::nhap_ns()
{
	char ch;
	cout<<"Nhap vao ngay, thang, nam (dd/mm/yyyy):  ";
	cin>>ngay>>thang>>nam;
}
void ngaysinh::xuat_ns()
{
	cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}
int main()
{
	cout<<"\n*******************************************************";
    cout<<"\n*                 QUAN LY SINH VIEN                   *";
    cout<<"\n*                                                     *";
}


