#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>
using namespace std;
class sinhvien{
	private:
		char hoten[30];
		int mssv, gioitinh;
		int ngay, thang, nam;
	public:
		masosv();
		hovaten();
		void nhapsv();
		void xuatsv();	
};
void sinhvien::nhapsv(){
	cout<<"Nhap ho ten sinh vien: ";
	cin.get(hoten,30);
	cout<<"Nhap ma so sinh vien: "; cin>>mssv;
	cin.ignore(1);
	cout<<"Nhap ngay thang nam sinh: "; cin>>ngay>>thang>>nam;
	cout<<"Nhap gioi tinh (Nam 1 / Nu 0) :";
	cin>>gioitinh;
}
void sinhvien::xuatsv(){
	cout<<"\n---------------------------------------";
	cout<<"\nHo va ten: "<<hoten;
	cout<<"\nNgay sinh: "<<ngay<<thang<<nam;
	cout<<"\nGioi tinh: ";
	if(gioitinh==1)
		cout<<"Nam";
	else
		cout<<"Nu";	
}
class diem : public sinhvien{
	private:
		float diemtrungbinh, diemrenluyen;
		float diemcong;
	public:
		diem();
		void nhapd();
		void xuatd();
		void sapxep();
		void timkiemdiem_tb(float diemtb);
		void timkiemdiem_ten(char hotensv[]);
		void timkiemdiem_mssv(int massv);
		void docfile(int sod);
		void ghifile();
		int diem::dem();
		float laydiemtrungbinh();
};
void diem::nhapd(){
	nhapsv();
	cout<<"\nNhap diem trung binh: "; cin>>diemtrungbinh;
	cout<<"\nNhap diem ren luyen: "; cin>>diemrenluyen;
	cout<<"\nNhap diem cong: "; cin>>diemcong;
}
void diem::xuatd(){
	xuatsv();
	cout<<"\nDiem trung binh: "<<diemtrungbinh;
	cout<<"\nDiem ren luyen: "<<diemrenluyen;
	cout<<"\nDiem cong: "<<diemcong;
}
void diem::timkiemdiem_tb(float diemtb){
	diem d;
	int so = diem::dem();
	for (int i=0; i<=so; i++){
		d.docfile(i);
		if(diemtrungbinh == diemtb)
			d.xuatd();
	}
}
void diem::timkiemdiem_mssv(int massv)
{
    diem d;
    int so=diem::dem();
    for(int i=0;i<so;i++)
    {
        d.docfile(i);
        if(masosv == massv)
            d.xuatd();
    }
}
void diem::timkiemdiem_ten(char hotensv[]){
    diem d;
    int so=diem::dem();
    for(int i=0;i<so;i++)
    {
        d.docfile(i);
        if(hovaten == hotensv)
            d.xuatd();
    }
}
void diem::docfile(int sod){
    fstream f;
    f.open("DIEM.TXT",ios::binary|ios::in);
    f.seekg( sod * sizeof(diem) );
    f.read((char*)this,sizeof(*this));
    f.close();
}
 
void diem::ghifile()
{
    fstream f;
    f.open("DIEM.TXT", ios::binary|ios::app|ios::out);
    f.write((char*)this, sizeof(*this));
    f.close(); 
	}
int diem::dem(){
	ifstream f;
    f.open("Diem.TXT", ios::binary);
    f.seekg(0, ios::end);
    if(!f)
        return 0;
    else
        return (int)f.tellg() / sizeof(diem);
}

int main(){
    sinhvien sv();
    diem d();

}














