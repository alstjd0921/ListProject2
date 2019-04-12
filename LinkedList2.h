#pragma once

#ifndef LISTPROJECT2_LINKEDLIST2_H
#define LISTPROJECT2_LINKEDLIST2_H

/* 이중연결리스트 ADT - 데이터 타입 정의 */
typedef char Item;                // 노드의 데이터 타입 Item형 지정

typedef struct _Node {            /* 노드 구조체(자기참조 구조체) */
    Item data;                    // 노드 데이터
    struct _Node *next;            // 다음 노드에 대한 포인터
    struct _Node *prev;            // 이전 노드에 대한 포인터
} Node;

typedef struct _DLinkedList {    /* 연결리스트 구조체 */
    int size;                    // 연결리스트 항목수
    Node *head;                    // head포인터 - head 더미노드를 가리킴
    Node *tail;                    // tail포인터 - tail 더미노드를 가리킴
} DLinkedList;

typedef DLinkedList List;        // DLinkedList 타입명을 List로 재정의

/* 이중연결리스트 ADT - 연산 선언 */
/* 과제1 */
void Init_DL(List *list);        // 이중연결리스트 초기화
int isEmpty(List *list);        // 리스트가 비어있는지 확인
int getSize(List *list);        // 리스트 항목 수

void Insert(List *list, int position, Item item);    // 원하는 위치에 노드 삽입
void Delete(List *list, int position);                // 원하는 위치의 노드 삭제
Item Retrieve(List *list, int position);            // 원하는 위치의 노드 데이터값 탐색
void Display(List *list);                            // 전체 리스트 내용 보여줌

/* 과제2 */
void Display_R(List *list);                        // 전체 리스트 내용을 역순으로 보여줌
void Delete_all(List *list);                        // 리스트의 모든 노드 삭제, 삭제하는 노드의 데이터 출력

/* 과제3 */
void Init_CDL(List *list);                            // 원형이중연결리스트 초기화
void Display_T(List *list, int times);                // 원형이중연결리스트 데이터 지정된 횟수만큼 보여줌
void Josephus(List *list, int n, int m);            // 원형이중연결리스트 이용하여 조세퍼스 순열 출력

#endif //LISTPROJECT2_LINKEDLIST2_H
