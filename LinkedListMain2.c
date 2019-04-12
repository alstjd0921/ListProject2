#include <stdio.h>
#include "LinkedList2.h"

int main(int argc, const char *argv[]) {
    List list1, list2;

    Init_DL(&list1);

    Insert(&list1, 1, 'A');
    Insert(&list1, 2, 'C');
    Insert(&list1, 3, 'E');
    Insert(&list1, 2, 'B');
    Insert(&list1, 1, 'D');

    printf("[ 삽입연산 후 리스트1 ]\n");
    Display(&list1);

    Delete(&list1, 3);
    printf("\n[ 3번째 데이터 삭제 후 리스트1 ]\n");
    Display(&list1);

    printf("\n[ 리스트1 2번째 위치의 데이터 찾기 ]\n");
    printf("%d번째 항목 %c\n", 2, Retrieve(&list1, 2));

    // 과제2
    printf("\n[ 리스트1 역순으로 보여주기 ]\n");
    Display_R(&list1);

    printf("\n[ 리스트1 모두 삭제하기 ]\n");
    Delete_all(&list1);

    // 과제2, 3
    Init_CDL(&list2);

    Insert(&list2, 1, 'A');
    Insert(&list2, 2, 'B');
    Insert(&list2, 3, 'C');

    printf("\n[ 삽입연산 후 리스트2 ]\n");
    Display(&list2);

    // 선택과제1
    printf("\n[ 리스트2 7회 보여주기 ]\n");
    Display_T(&list2, 7);

    // 선택과제2
    printf("\n[ 리스트2 조세퍼스 순열(7,3) ]\n");
    Insert(&list2, 4, 'D');
    Insert(&list2, 5, 'E');
    Insert(&list2, 6, 'F');
    Insert(&list2, 7, 'G');
    Display(&list2);
    Josephus(&list2, 7, 3);

    printf("\n[ 리스트2 모두 삭제하기 ]\n");
    Delete_all(&list2);

    printf("\n");
    return 0;
}