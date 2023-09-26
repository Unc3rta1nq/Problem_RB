#include <iostream>
#include <vector>
#include <locale>

int trapWater(const std::vector<int>& heights) {
	int n = heights.size();
	if (n <= 2) {
		return 0; // ������ ���� ������, ���� �� ������������
	}

	int left = 0;        // ����� ���������
	int right = n - 1;   // ������ ���������
	int leftMax = 0;     // ������������ ������ �����
	int rightMax = 0;    // ������������ ������ ������
	int water = 0;       // ����� ����

	while (left < right) {
		if (heights[left] < heights[right]) {
			if (heights[left] >= leftMax) {
				leftMax = heights[left];
			}
			else {
				water += leftMax - heights[left];
			}
			left++;
		}
		else {
			if (heights[right] >= rightMax) {
				rightMax = heights[right];
			}
			else {
				water += rightMax - heights[right];
			}
			right--;
		}
	}

	return water;
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<int> heights = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int trappedWater = trapWater(heights);
	std::cout << "����� ����������� ����: " << trappedWater << " ������" << std::endl;

	return 0;
}
