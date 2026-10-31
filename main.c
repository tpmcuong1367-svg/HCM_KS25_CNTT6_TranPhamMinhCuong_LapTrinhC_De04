#include <stdio.h>
#include <string.h>

#define MAX 50

struct MatHang {
    int maHang;
    char tenHang[50];
    int soLuong;
    float donGia;
};

struct MatHang ds[MAX];
int n = 0;

int docSoNguyen() {
    char s[100];
    int x = 0;
    fgets(s, 100, stdin);
    sscanf(s, "%d", &x);
    return x;
}

float docSoThuc() {
    char s[100];
    float x = 0;
    fgets(s, 100, stdin);
    sscanf(s, "%f", &x);
    return x;
}

void docChuoi(char s[]) {
    fgets(s, 50, stdin);
    s[strcspn(s, "\n")] = 0;
}

int timTheoMa(struct MatHang ds[], int n, int ma) {
    int i;
    for (i = 0; i < n; i++) {
        if (ds[i].maHang == ma)
            return i;
    }
    return -1;
}

void nhapThongTin(struct MatHang ds[], int vt) {
    int sl;
    float gia;

    printf("Nhap ten mat hang: ");
    docChuoi(ds[vt].tenHang);

    do {
        printf("Nhap so luong: ");
        sl = docSoNguyen();
        if (sl < 0)
            printf("Loi: so luong phai lon hon hoac bang 0!\n");
    } while (sl < 0);
    ds[vt].soLuong = sl;

    do {
        printf("Nhap don gia: ");
        gia = docSoThuc();
        if (gia <= 0)
            printf("Loi: don gia phai lon hon 0!\n");
    } while (gia <= 0);
    ds[vt].donGia = gia;
}

void inTieuDe() {
    printf("%-8s %-30s %-10s %-12s %-14s\n",
           "Ma", "Ten mat hang", "So luong", "Don gia", "Thanh tien");
}

void inDong(struct MatHang m) {
    printf("%-8d %-30s %-10d %-12.0f %-14.0f\n",
           m.maHang, m.tenHang, m.soLuong, m.donGia, m.soLuong * m.donGia);
}

int themMatHang(struct MatHang ds[], int n) {
    int ma;

    if (n >= MAX) {
        printf("Danh sach da day\n");
        return n;
    }

    printf("Nhap ma mat hang: ");
    ma = docSoNguyen();
    if (timTheoMa(ds, n, ma) != -1) {
        printf("Ma mat hang da ton tai\n");
        return n;
    }

    ds[n].maHang = ma;
    nhapThongTin(ds, n);
    printf("Them mat hang thanh cong\n");
    return n + 1;
}

void hienThiDanhSach(struct MatHang ds[], int n) {
    int i;
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }
    inTieuDe();
    for (i = 0; i < n; i++)
        inDong(ds[i]);
}

void capNhatMatHang(struct MatHang ds[], int n) {
    int ma, vt;

    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("Nhap ma can sua: ");
    ma = docSoNguyen();
    vt = timTheoMa(ds, n, ma);
    if (vt == -1) {
        printf("Khong tim thay mat hang\n");
        return;
    }

    nhapThongTin(ds, vt);
    printf("Cap nhat thanh cong\n");
}

int xoaMatHang(struct MatHang ds[], int n) {
    int ma, vt, i;

    if (n == 0) {
        printf("Danh sach rong\n");
        return n;
    }

    printf("Nhap ma can xoa: ");
    ma = docSoNguyen();
    vt = timTheoMa(ds, n, ma);
    if (vt == -1) {
        printf("Khong tim thay mat hang\n");
        return n;
    }

    for (i = vt; i < n - 1; i++)
        ds[i] = ds[i + 1];

    printf("Xoa thanh cong\n");
    return n - 1;
}

void timTheoTen(struct MatHang ds[], int n) {
    char ten[50];
    int i, dem = 0;

    printf("Nhap ten can tim: ");
    docChuoi(ten);

    for (i = 0; i < n; i++) {
        if (strcmp(ds[i].tenHang, ten) == 0) {
            if (dem == 0)
                inTieuDe();
            inDong(ds[i]);
            dem++;
        }
    }
    if (dem == 0)
        printf("Khong tim thay mat hang\n");
}

int main() {
    int chon;

    do {
        printf("=====QUAN LY MAT HANG=====\n");
        printf("1. Them mat hang\n");
        printf("2. Hien thi danh sach mat hang\n");
        printf("3. Cap nhat mat hang theo ma\n");
        printf("4. Xoa mat hang theo ma\n");
        printf("5. Tim mat hang theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        chon = docSoNguyen();

        if (chon == 1) n = themMatHang(ds, n);
        else if (chon == 2) hienThiDanhSach(ds, n);
        else if (chon == 3) capNhatMatHang(ds, n);
        else if (chon == 4) n = xoaMatHang(ds, n);
        else if (chon == 5) timTheoTen(ds, n);
        else if (chon == 6) { }
        else if (chon == 0) printf("Tam biet!\n");
        else printf("Lua chon khong hop le\n");
    } while (chon != 0);

    return 0;
}
