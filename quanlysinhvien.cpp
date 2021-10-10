#include<iostream>
using namespace std;
class ngaysinh
{
private:
    int ngay;
    int thang;
    int nam;
public:
    ngaysinh(int ngay, int thang, int nam);
    ~ngaysinh();
    void nhapns();
    void hienns();
};
class nguoi : public ngaysinh
{
    private:
        int masv;
        char ten[30];
        ngaysinh ns;
        int gt;
    public:
        void nhapn();
        void inn();
};
class diem : public nguoi
{
    private:
        float dtb;
        float drl;
        float dcong;
    public:
        diem(){}
        void nhapd();
        void ind();
        void sapxep();
        void timkiemdiem_dtb(float diemtb);
        void timkiemdiem_masv(int msv);
        void timkiemdiem_ten(char tensv[]);
        void ghi_file();
        void doc_file(int sod);
        int diem::dem();
        float laydtb();
};
class hocluc: 
{
}
