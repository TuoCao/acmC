#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* ans = NULL;
	struct ListNode* t = ans;
	int temp = 0;
	int ac = 0;
	while (l1 != NULL && l2 != NULL) {
		t = (struct ListNode*)malloc(sizeof(struct ListNode));

		temp = l1->val + l2->val + ac;
		t->val = temp / 10;
		ac = temp % 10;
		
		t = t->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	if (l1 == NULL) {
		l1 = l2;
	}

	while (l1 != NULL) {
		t = (struct ListNode*)malloc(sizeof(struct ListNode));
		t = t->next;
		temp = l1->val + ac;
		t->val = temp / 10;
		ac = temp % 10;
		
		l1 = l1->next;
	}
	if (ac == 1) {
		t = (struct ListNode*)malloc(sizeof(struct ListNode));
		t->next = NULL;
		t->val = 1;
	}
	else {
		t = NULL;
	}
	
	return ans;
}

void initListNode(struct ListNode* ln, int* nums) {
	int size = sizeof(nums) / sizeof(int);
	for (int i = 0; i < size; i++) {
		ln = malloc(sizeof(struct ListNode));
		ln->val = nums[i];
		ln->next = NULL;
		ln = ln->next;
	}
}

void freeListNode(struct ListNode* ln) {
	struct ListNode* temp;
	while (ln != NULL) {
		temp = ln;
		ln = ln->next;
		free(temp);
	}
}

void showListNode(struct ListNode* ln) {
	while (ln != NULL) {
		printf("%d", ln->val);
		ln = ln->next;
	}
}

int main() {
	int nums1[] = { 2,4,3 };
	int nums2[] = { 5,6,4 };
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	struct ListNode* res = NULL;
	initListNode(l1, nums1);
	initListNode(l2, nums2);
	res = addTwoNumbers(l1, l2);
	showListNode(res);

	freeListNode(l1);
	freeListNode(l2);
	freeListNode(res);
	return 0;
}