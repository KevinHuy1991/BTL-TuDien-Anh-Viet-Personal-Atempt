#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tudien.h"

// 1. H�m ti?n �ch: X�a ph�m Enter (k� t? \n) b? th?a khi d�ng fgets
void xoaXuongDong(char* str) {
    str[strcspn(str, "\n")] = 0;
}

// 2. H�m ti?n �ch: D?n r�c b? nh? d?m (ch?ng tr�i l?nh khi nh?p s? xong chuy?n sang nh?p ch?)
void xoaBoNhoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 3. H�m th�m t? m?i
void themTu(Node** head, char* tuAnh, char* nghiaViet) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, tuAnh);
    strcpy(newNode->meaning, nghiaViet);
    
    // Th�m v�o d?u danh s�ch
    newNode->next = *head;
    *head = newNode;
}

// 4. H�m hi?n th?
void inTuDien(Node* head) {
    if (head == NULL) {
        printf("Tu dien dang trong!\n");
        return;
    }
    Node* temp = head;
    printf("\n%-20s | %s\n", "TU TIENG ANH", "NGHIA TIENG VIET");
    printf("--------------------------------------------------\n");
    while (temp != NULL) {
        printf("%-20s | %s\n", temp->word, temp->meaning);
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
}

// 5. H�m t�m ki?m
void timKiemTu(Node* head, char* tuAnh) {
    Node* temp = head;
    while (temp != NULL) {
        // H�m strcasecmp gi�p so s�nh kh�ng ph�n bi?t hoa thu?ng (Apple = apple)
        if (strcasecmp(temp->word, tuAnh) == 0) {
            printf("=> Ket qua: %s nghia la '%s'\n", temp->word, temp->meaning);
            return;
        }
        temp = temp->next;
    }
    printf("=> Khong tim thay tu '%s' trong tu dien.\n", tuAnh);
}

// 6. H�m �?c d? li?u t? File (B?n n�ng c?p T? d?ng sinh thu vi?n)
void docTuDienTuFile(Node** head, const char* tenFile) {
    FILE* f = fopen(tenFile, "r");
    
    // N?u chua c� file, t? d?ng t?o file v� n?p t? v?ng m?c d?nh
    if (f == NULL) {
        printf("=> Lan chay dau tien: Dang tao thu vien mac dinh...\n");
        f = fopen(tenFile, "w");
        if (f != NULL) {
            fprintf(f, "Hello|Xin chao\n");
            fprintf(f, "Apple|Qua tao\n");
            fprintf(f, "Banana|Qua chuoi\n");
            fprintf(f, "Computer|May tinh\n");
            fprintf(f, "Software|Phan mem\n");
            fprintf(f, "Student|Sinh vien\n");
            fprintf(f, "Teacher|Giao vien\n");
            fprintf(f, "University|Truong dai hoc\n");
            fprintf(f, "Programming|Lap trinh\n");
            fprintf(f, "Algorithm|Thuat toan\n");
            fprintf(f, "Data Structure|Cau truc du lieu\n");
            fprintf(f, "Dictionary|Tu dien\n");
            fprintf(f, "Love|Tinh yeu\n");
            fprintf(f, "Family|Gia dinh\n");
            fprintf(f, "Money|Tien bac\n");
            // --- NHÓM CÔNG NGHỆ & LẬP TRÌNH NÂNG CAO ---
fprintf(f, "Artificial Intelligence|Tri tue nhan tao\n");
fprintf(f, "Machine Learning|Hoc may\n");
fprintf(f, "Cloud Computing|Dien toan dam may\n");
fprintf(f, "Big Data|Du lieu lon\n");
fprintf(f, "Cybersecurity|An ninh mang\n");
fprintf(f, "Blockchain|Chuoi khoi\n");
fprintf(f, "Virtual Reality|Thuc te ao\n");
fprintf(f, "Automation|Tu dong hoa\n");
fprintf(f, "Algorithm|Thuat toan\n");
fprintf(f, "Framework|Khung lam viec\n");
fprintf(f, "Library|Thu vien\n");
fprintf(f, "Repository|Kho chua code\n");
fprintf(f, "Version Control|Quan ly phien ban\n");
fprintf(f, "Deployment|Trien khai\n");
fprintf(f, "Documentation|Tai lieu huong dan\n");
fprintf(f, "Optimization|Toi uu hoa\n");
fprintf(f, "Architecture|Kien truc phan mem\n");
fprintf(f, "Integration|Tich hop\n");
fprintf(f, "Simulation|Mo phong\n");
fprintf(f, "Binary|Nhi phan\n");
fprintf(f, "Hexadecimal|Thap luc phan\n");
fprintf(f, "Syntax|Nu phap\n");
fprintf(f, "Parameter|Tham so\n");
fprintf(f, "Argument|Doi so\n");
fprintf(f, "Constructor|Ham khoi tao\n");
fprintf(f, "Destructor|Ham huy\n");
fprintf(f, "Inheritance|Ke thua\n");
fprintf(f, "Polymorphism|Da hinh\n");
fprintf(f, "Encapsulation|Dong goi\n");
fprintf(f, "Abstraction|Truu tuong hoa\n");

// --- NHÓM THIẾT BỊ & PHẦN CỨNG ---
fprintf(f, "Motherboard|Bo mach chu\n");
fprintf(f, "Processor|Bo vi xu ly\n");
fprintf(f, "Graphics Card|Card do hoa\n");
fprintf(f, "Hard Drive|O cung\n");
fprintf(f, "Solid State Drive|O cung the ran\n");
fprintf(f, "Power Supply|Nguon may tinh\n");
fprintf(f, "Cooling System|He thong tan nhiet\n");
fprintf(f, "Monitor|Man hinh\n");
fprintf(f, "Resolution|Do phan giai\n");
fprintf(f, "Peripherals|Thiet bi ngoai vi\n");
fprintf(f, "Scanner|May quet\n");
fprintf(f, "Projector|May chieu\n");
fprintf(f, "Router|Thiet bi dinh tuyen\n");
fprintf(f, "Switch|Thiet bi chuyen mach\n");
fprintf(f, "Modem|Bo giai ma tin hieu\n");
fprintf(f, "Cable|Day cap\n");
fprintf(f, "Wireless|Khong day\n");
fprintf(f, "Bluetooth|Ket noi bluetooth\n");
fprintf(f, "Sensor|Cam bien\n");
fprintf(f, "Battery|Pin\n");

// --- NHÓM VĂN PHÒNG & KINH DOANH ---
fprintf(f, "Contract|Hop dong\n");
fprintf(f, "Signature|Chu ky\n");
fprintf(f, "Proposal|De xuat\n");
fprintf(f, "Strategy|Chien luoc\n");
fprintf(f, "Marketing|Tiep thi\n");
fprintf(f, "Invoice|Hoa don\n");
fprintf(f, "Salary|Luong\n");
fprintf(f, "Bonus|Tien thuong\n");
fprintf(f, "Promotion|Thang chuc\n");
fprintf(f, "Meeting|Cuoc hop\n");
fprintf(f, "Presentation|Bai thuyet trinh\n");
fprintf(f, "Deadline|Han chot\n");
fprintf(f, "Experience|Kinh nghiem\n");
fprintf(f, "Interview|Phong van\n");
fprintf(f, "Resume|So yeu ly lich\n");
fprintf(f, "Customer|Khach hang\n");
fprintf(f, "Profit|Loi nhuan\n");
fprintf(f, "Revenue|Doanh thu\n");
fprintf(f, "Investment|Dau tu\n");
fprintf(f, "Market|Thi truong\n");

// --- NHÓM ĐỒ ĂN & SINH HOẠT ---
fprintf(f, "Breakfast|Bua sang\n");
fprintf(f, "Lunch|Bua trua\n");
fprintf(f, "Dinner|Bua toi\n");
fprintf(f, "Snack|Do an nhe\n");
fprintf(f, "Kitchen|Nha bep\n");
fprintf(f, "Bedroom|Phong ngu\n");
fprintf(f, "Bathroom|Phong tam\n");
fprintf(f, "Living room|Phong khach\n");
fprintf(f, "Garden|San vuon\n");
fprintf(f, "Balcony|Ban cong\n");
fprintf(f, "Furniture|Noi that\n");
fprintf(f, "Fridge|Tu lanh\n");
fprintf(f, "Oven|Lo nuong\n");
fprintf(f, "Microwave|Lo vi song\n");
fprintf(f, "Washing machine|May giat\n");
fprintf(f, "Dishwasher|May rua bat\n");
fprintf(f, "Air conditioner|May dieu hoa\n");
fprintf(f, "Television|Ti vi\n");
fprintf(f, "Telephone|Dien thoai ban\n");
fprintf(f, "Lamp|Den ngu\n");

// --- NHÓM THIÊN NHIÊN & THỜI TIẾT ---
fprintf(f, "Universe|Vu tru\n");
fprintf(f, "Galaxy|Thien ha\n");
fprintf(f, "Planet|Hanh tinh\n");
fprintf(f, "Earth|Trai dat\n");
fprintf(f, "Forest|Rung ram\n");
fprintf(f, "Ocean|Dai duong\n");
fprintf(f, "River|Con song\n");
fprintf(f, "Lake|Ho nuoc\n");
fprintf(f, "Island|Hon dao\n");
fprintf(f, "Desert|Sa mac\n");
fprintf(f, "Storm|Con bao\n");
fprintf(f, "Thunder|Sam set\n");
fprintf(f, "Rainbow|Cau vong\n");
fprintf(f, "Sunshine|Anh nang\n");
fprintf(f, "Environment|Moi truong\n");
fprintf(f, "Pollution|O nhiem\n");
fprintf(f, "Climate|Khi hau\n");
fprintf(f, "Disaster|Thien tai\n");
fprintf(f, "Energy|Nang luong\n");
fprintf(f, "Nature|Tu nhien\n");

// --- NHÓM ĐỘNG VẬT ---
fprintf(f, "Mammal|Dong vat co vu\n");
fprintf(f, "Reptile|Loai bo sat\n");
fprintf(f, "Amphibian|Loai luong cu\n");
fprintf(f, "Insect|Con trung\n");
fprintf(f, "Dolphin|Ca heo\n");
fprintf(f, "Shark|Ca map\n");
fprintf(f, "Whale|Ca voi\n");
fprintf(f, "Eagle|Chim dai bang\n");
fprintf(f, "Owl|Con cu\n");
fprintf(f, "Penguin|Chim canh cut\n");
fprintf(f, "Giraffe|Huu cao co\n");
fprintf(f, "Zebra|Ngua van\n");
fprintf(f, "Kangaroo|Chuot tui\n");
fprintf(f, "Crocodile|Con ca sau\n");
fprintf(f, "Tiger|Con ho\n");
fprintf(f, "Elephant|Con voi\n");
fprintf(f, "Lion|Su tu\n");
fprintf(f, "Wolf|Con soi\n");
fprintf(f, "Rabbit|Con tho\n");
fprintf(f, "Deer|Con nai\n");

// --- NHÓM DU LỊCH & ĐỊA ĐIỂM ---
fprintf(f, "Airport|San bay\n");
fprintf(f, "Station|Gia tau\n");
fprintf(f, "Hospital|Benh vien\n");
fprintf(f, "Pharmacy|Hieu thuoc\n");
fprintf(f, "Library|Thu vien\n");
fprintf(f, "Museum|Bao tang\n");
fprintf(f, "Cinema|Rap chieu phim\n");
fprintf(f, "Restaurant|Nha hang\n");
fprintf(f, "Hotel|Khach san\n");
fprintf(f, "Stadium|Van dong truong\n");
fprintf(f, "Park|Cong vien\n");
fprintf(f, "Bridge|Cay cau\n");
fprintf(f, "Tower|Toa thap\n");
fprintf(f, "Castle|Toa lau dai\n");
fprintf(f, "Palace|Cung dien\n");
fprintf(f, "Church|Nha tho\n");
fprintf(f, "Temple|Ngoi den\n");
fprintf(f, "Village|Ngoi lang\n");
fprintf(f, "Province|Tinh thanh\n");
fprintf(f, "Capital|Thu do\n");

// --- NHÓM TÍNH TỪ & TRẠNG THÁI ---
fprintf(f, "Creative|Sang tao\n");
fprintf(f, "Patient|Kien nhan\n");
fprintf(f, "Brave|Dung cam\n");
fprintf(f, "Honest|Trung thuc\n");
fprintf(f, "Generous|Hao phong\n");
fprintf(f, "Confident|Tu tin\n");
fprintf(f, "Flexible|Linh hoat\n");
fprintf(f, "Efficient|Hieu qua\n");
fprintf(f, "Reliable|Dang tin cay\n");
fprintf(f, "Aggressive|Hung hang\n");
fprintf(f, "Stubborn|Buong binh\n");
fprintf(f, "Nervous|Lo lang\n");
fprintf(f, "Curious|To mo\n");
fprintf(f, "Serious|Nghiem tuc\n");
fprintf(f, "Funny|Hai huoc\n");
fprintf(f, "Famous|Noi tieng\n");
fprintf(f, "Perfect|Hoan hao\n");
fprintf(f, "Complex|Phuc tap\n");
fprintf(f, "Simple|Don gian\n");
fprintf(f, "Dangerous|Nguy hiem\n");

// --- NHÓM ĐỘNG TỪ THÔNG DỤNG ---
fprintf(f, "Organize|To chuc\n");
fprintf(f, "Analyze|Phan tich\n");
fprintf(f, "Identify|Xac dinh\n");
fprintf(f, "Develop|Phat trien\n");
fprintf(f, "Design|Thiet ke\n");
fprintf(f, "Construct|Xay dung\n");
fprintf(f, "Destroy|Pha huy\n");
fprintf(f, "Compare|So sanh\n");
fprintf(f, "Imagine|Tuong tuong\n");
fprintf(f, "Explore|Kham pha\n");
fprintf(f, "Achieve|Dat duoc\n");
fprintf(f, "Succeed|Thanh cong\n");
fprintf(f, "Improve|Cai thien\n");
fprintf(f, "Maintain|Bao tri\n");
fprintf(f, "Prevent|Ngan chan\n");
fprintf(f, "Protect|Bao ve\n");
fprintf(f, "Encourage|Khuyen khich\n");
fprintf(f, "Recommend|De xuat\n");
fprintf(f, "Describe|Mo ta\n");
fprintf(f, "Explain|Giai thich\n");

// --- NHÓM CƠ THỂ & SỨC KHỎE ---
fprintf(f, "Muscle|Co bap\n");
fprintf(f, "Bone|Xuong\n");
fprintf(f, "Heart|Trai tim\n");
fprintf(f, "Brain|Noo bo\n");
fprintf(f, "Stomach|Da day\n");
fprintf(f, "Health|Suc khoe\n");
fprintf(f, "Medicine|Thuoc\n");
fprintf(f, "Symptom|Trieu chung\n");
fprintf(f, "Disease|Benh tat\n");
fprintf(f, "Infection|Nhiem trung\n");
fprintf(f, "Treatment|Dieu tri\n");
fprintf(f, "Recovery|Hoi phuc\n");
fprintf(f, "Insurance|Bao hiem\n");
fprintf(f, "Emergency|Khan cap\n");
fprintf(f, "Surgery|Phau thuat\n");
fprintf(f, "Exercise|Tap the duc\n");
fprintf(f, "Nutrition|Dinh duong\n");
fprintf(f, "Vitamin|Vi ta min\n");
fprintf(f, "Physical|The chat\n");
fprintf(f, "Mental|Tam tri\n");
            fclose(f);
        }
        // M? l?i file d? d?c sau khi d� t?o xong
        f = fopen(tenFile, "r");
    }
    
    char dong[300];
    // �?c t?ng d�ng trong file v� n?p v�o danh s�ch li�n k?t
    while (fgets(dong, sizeof(dong), f)) {
        xoaXuongDong(dong);
        // C?t chu?i b?i d?u g?ch d?ng '|'
        char* tuAnh = strtok(dong, "|");
        char* nghiaViet = strtok(NULL, "|");
        
        if (tuAnh != NULL && nghiaViet != NULL) {
            themTu(head, tuAnh, nghiaViet);
        }
    }
    fclose(f);
    printf("=> Da tai thanh cong thu vien tu vung!\n");
}

// 7. H�m Ghi d? li?u ra File
void ghiTuDienRaFile(Node* head, const char* tenFile) {
    FILE* f = fopen(tenFile, "w");
    if (f == NULL) {
        printf("Loi: Khong the luu file!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        // Luu theo d?nh d?ng: TuTiengAnh|NghiaTiengViet
        fprintf(f, "%s|%s\n", temp->word, temp->meaning);
        temp = temp->next;
    }
    fclose(f);
    printf("Da luu toan bo du lieu vao '%s'.\n", tenFile);
}

// 8. H�m gi?i ph�ng b? nh? (Quy t?c b?t bu?c c?a m�n h?c)
void giaiPhongBoNho(Node** head) {
    Node* temp = *head;
    Node* next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}
