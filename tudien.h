#ifndef TUDIEN_H
#define TUDIEN_H

// C?u trúc 1 t? v?ng (1 Node)
typedef struct Node {
    char word[100];       // T? ti?ng Anh
    char meaning[200];    // Nghia ti?ng Vi?t (r?ng rãi d? ch?a nhi?u ch?)
    struct Node* next;
} Node;

// --- CÁC HÀM X? LÝ T? V?NG ---
void themTu(Node** head, char* tuAnh, char* nghiaViet);
void inTuDien(Node* head);
void timKiemTu(Node* head, char* tuAnh);
void giaiPhongBoNho(Node** head);

// --- CÁC HÀM X? LÝ T?P TIN ---
void docTuDienTuFile(Node** head, const char* tenFile);
void ghiTuDienRaFile(Node* head, const char* tenFile);

// --- CÁC HÀM TI?N ÍCH (Quan tr?ng d? không b? l?i) ---
void xoaXuongDong(char* str);
void xoaBoNhoDem();

#endif
