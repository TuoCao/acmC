#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode head = { 0,NULL };
	struct ListNode* t = &head;
	int temp = 0;
	int ac = 0;
	while (l1 != NULL && l2 != NULL) {
		t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp = l1->val + l2->val + ac;
		t->next->val = temp % 10;
		ac = temp / 10;

		t = t->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	if (l1 == NULL) {
		l1 = l2;
	}

	while (l1 != NULL) {
		t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		
		temp = l1->val + ac;
		t->next->val = temp % 10;
		ac = temp / 10;
		t = t->next;
		l1 = l1->next;
	}
	if (ac == 1) {
		t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		t->next->val = 1;
		t->next->next = NULL;
	}
	else {
		t->next = NULL;
	}
	return head.next;
}

void showListNode(struct ListNode* ln) {
	while (ln != NULL) {
		printf("%d", ln->val);
		ln = ln->next;
	}
}

void initListNode(struct ListNode* ln, int* nums,int size) {
	struct ListNode* t = ln;
	for (int i = 0; i < size; i++) {
		t->next = malloc(sizeof(struct ListNode));
		t->next->val = nums[i];
		t = t->next;
	}
	t->next = NULL;
}

void freeListNode(struct ListNode* ln) {
	struct ListNode* temp;
	while (ln != NULL) {
		temp = ln;
		ln = ln->next;
		free(temp);
	}
}

int main() {
	int nums1[] = { 2,4,3 };
	int nums2[] = { 5,6,4 };
	struct ListNode l1 = {0,NULL};
	struct ListNode l2 = {0,NULL};
	struct ListNode* res;
	initListNode(&l1, nums1,sizeof(nums1)/sizeof(int));
	initListNode(&l2, nums2,sizeof(nums2)/sizeof(int));
	res = addTwoNumbers(l1.next, l2.next);
	showListNode(res);

	freeListNode(l1.next);
	freeListNode(l2.next);
	freeListNode(res);
	return 0;
}