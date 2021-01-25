#include <stdio.h>

int main() {
	int size, n;
	scanf("%d %d", &size, &n);

	int pNum;
	int cache[10] = { 0 };		//캐시
	bool isProcessExist[101] = { false };	//작업번호
	int actual_size = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &pNum);

		//cache miss
		if (isProcessExist[pNum] == false) {
			isProcessExist[pNum] = true;

			for (int j = actual_size - 1; j >= 0; j--) {
				//삭제되는 캐시
				if (j == size - 1) {
					int deletedNum = cache[j];
					isProcessExist[deletedNum] = false;
					continue;
				}
				cache[j + 1] = cache[j];
			}
			cache[0] = pNum;

			if (actual_size < size) actual_size++;
			else actual_size = size;
		}
		//cache hit
		else {
			int position = 0;
			for (int j = 0; j < size; j++) {
				if (cache[j] == pNum) {
					position = j;
					break;
				}
			}
			for (int j = position - 1; j >= 0; j--) {
				cache[j + 1] = cache[j];
			}
			cache[0] = pNum;
		}
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", cache[i]);
	}

	return 0;
}
