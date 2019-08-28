#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;
	int* re = (int*)malloc(2 * sizeof(int));
	returnSize = (int*)malloc(1 * sizeof(int));
	if (re == NULL || returnSize==NULL) {
		return NULL;
	}
	else {
		for (i = 0; i < numsSize - 1; i++) {
			for (j = i + 1; j < numsSize; j++) {
				if (nums[i] + nums[j] == target) {
					*returnSize = 2;
					re[0] = i;
					re[1] = j;
					return re;
				}
			}
		}
	}
	*returnSize = 0;
	return NULL;
}

int main() {
	int nums[] = { 11,15,2,7};
	int target = 9;
	int numSize = sizeof(nums) / sizeof(int);
	int* re = NULL;
	int* returnSize = NULL;
	re = twoSum(nums, numSize, target, returnSize);
	if (re != NULL) {
		printf("%d,%d\n", re[0], re[1]);
	}
	else {
		printf("error\n");
	}
	free(re);
	return 0;
}