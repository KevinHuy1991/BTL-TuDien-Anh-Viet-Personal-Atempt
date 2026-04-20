#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tudien.h"

int main() {
    Node* tuDien = NULL;
    const char* fileDuLieu = "dict.txt";
    int luaChon;

    // 1. T? d?ng t?i d? li?u khi v?a b?t chuong tr�nh
    printf("=== DANG KHOI DONG HE THONG ===\n");
    docTuDienTuFile(&tuDien, fileDuLieu);

    do {
        printf("\n======== TU DIEN ANH - VIET ========\n");
        printf("1. Tra cuu tu vung\n");
        printf("2. Them tu moi\n");
        printf("3. Hien thi toan bo tu dien\n");
        printf("0. Thoat va Luu du lieu\n");
        printf("====================================\n");
        printf("Nhap lua chon cua ban (0-3): ");
        scanf("%d", &luaChon);
        
        
        xoaBoNhoDem(); 

        switch(luaChon) {
            case 1: {
                char tuCanTim[100];
                printf("Nhap tu tieng Anh can tra: ");
                fgets(tuCanTim, sizeof(tuCanTim), stdin);
                xoaXuongDong(tuCanTim); // C?t du�i Enter
                
                timKiemTu(tuDien, tuCanTim);
                break;
            }
            case 2: {
                char anh[100], viet[200];
                printf("Nhap tu tieng Anh: ");
                fgets(anh, sizeof(anh), stdin);
                xoaXuongDong(anh);
                
                printf("Nhap nghia tieng Viet (ho tro dau cach): ");
                fgets(viet, sizeof(viet), stdin);
                xoaXuongDong(viet);
                
                themTu(&tuDien, anh, viet);
                printf("-> Da them thanh cong!\n");
                break;
            }
            case 3:
                inTuDien(tuDien);
                break;
            case 0:
                printf("\nDang luu du lieu...\n");
                ghiTuDienRaFile(tuDien, fileDuLieu);
                giaiPhongBoNho(&tuDien); // D?n s?ch RAM tru?c khi t?t m�y
                printf("Tam biet! Hen gap lai.\n");
                break;
            default:
                printf("Loi: Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while(luaChon != 0);

    return 0;
}
