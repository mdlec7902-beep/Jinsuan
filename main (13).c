/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define ITEM 5

int main() {
    int id, qty, menu, i;
    int in[ITEM] = {0};       
    int out[ITEM] = {0};       
    int price[ITEM] = {0};     
    int total_sales[ITEM] = {0}; 
    char name[ITEM][50] = {"(미정)", "(미정)", "(미정)", "(미정)", "(미정)"};

    printf("=== 상품 기본정보 입력 ===\n");
    for (i = 0; i < ITEM; i++) {
        printf("%d번 상품명 입력: ", i + 1);
        scanf("%s", name[i]);
        printf("%d번 상품가격 입력: ", i + 1);
        scanf("%d", &price[i]);
    }

    while (1) {
        printf("\n===== 상품 관리 시스템 =====\n");
        printf("1. 입고\n2. 판매\n3. 개별상품정보\n4. 전체상품정보\n5. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);

        if (menu == 1) {  
            printf("입고할 상품 ID (1~%d): ", ITEM);
            scanf("%d", &id);
            if (id < 1 || id > ITEM) {
                printf("잘못된 상품 ID입니다.\n");
                continue;
            }
            printf("입고 수량: ");
            scanf("%d", &qty);
            if (qty < 0) {
                printf("음수는 입력할 수 없습니다.\n");
                continue;
            }
            in[id - 1] += qty;
            printf("입고 완료! (%s 현재 재고: %d개)\n", name[id - 1], in[id - 1] - out[id - 1]);
        }

        else if (menu == 2) {  
            printf("판매할 상품 ID (1~%d): ", ITEM);
            scanf("%d", &id);
            if (id < 1 || id > ITEM) {
                printf("잘못된 상품 ID입니다.\n");
                continue;
            }
            printf("판매 수량: ");
            scanf("%d", &qty);
            if (qty < 0) {
                printf("음수는 입력할 수 없습니다.\n");
                continue;
            }
            int stock = in[id - 1] - out[id - 1];
            if (qty > stock) {
                printf("재고 부족! 현재 재고: %d개\n", stock);
                continue;
            }
            out[id - 1] += qty;
            total_sales[id - 1] += qty * price[id - 1];
            printf("판매 완료! (%s 남은 재고: %d개)\n", name[id - 1], in[id - 1] - out[id - 1]);
        }

        else if (menu == 3) {  
            printf("조회할 상품 ID (1~%d): ", ITEM);
            scanf("%d", &id);
            if (id < 1 || id > ITEM) {
                printf("잘못된 상품 ID입니다.\n");
                continue;
            }
            printf("\n=== 개별 상품 정보 ===\n");
            printf("상품 ID: %d\n", id);
            printf("상품명: %s\n", name[id - 1]);
            printf("상품가격: %d원\n", price[id - 1]);
            printf("입고량: %d개\n", in[id - 1]);
            printf("판매량: %d개\n", out[id - 1]);
            printf("남은 재고: %d개\n", in[id - 1] - out[id - 1]);
            printf("총 판매금액: %d원\n", total_sales[id - 1]);
        }

        else if (menu == 4) {  
            printf("\n=== 전체 상품 현황 ===\n");
            printf("ID\t상품명\t가격\t입고\t판매\t재고\t총판매금액\n");
            for (i = 0; i < ITEM; i++) {
                printf("%d\t%-8s\t%d\t%d\t%d\t%d\t%d\n",
                       i + 1, name[i], price[i],
                       in[i], out[i], in[i] - out[i], total_sales[i]);
            }
        }

        else if (menu == 5) {  
            printf("프로그램을 종료합니다.\n");
            break;
        }

        else {
            printf("잘못된 메뉴입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
