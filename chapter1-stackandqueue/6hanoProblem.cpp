//2019.4.18
//汉诺塔变种问题
//利用堆栈实现 只能在相邻柱之间挪动
#include <iostream>
#include <stack>
#include <string>

//解决办法1，使用递归，并且从左、右两个柱之间可以直接移动
void recursion_1(int n, int &count, std::string left, std::string middle, std::string right)
{
	if (n == 1)
	{
		std::cout << "移动 " << n << " 从 " << left << " 到 " << right << '\n'; 
		count++;
		return;
	}
	else
	{
		recursion_1(n-1, count, left, right, middle);
		std::cout << "移动 " << n << " 从 " << left << " 到 " << right << '\n';
		count++;
		recursion_1(n-1, count, middle, left, right);
	}
}

//解决办法2，使用递归，并且从左、右两个柱之间不能直接移动，需要经过中间柱
void recursion_2(int n, int &count, std::string left, std::string middle, std::string right)
{
	if (n == 1)
	{
		std::cout << "第 " << count+1  << " 步：" << "移动 " << n << " 从 " << left << " 到 " << middle << '\n'; 
		count++;
		std::cout << "第 " << count+1  << " 步：" << "移动 " << n << " 从 " << middle << " 到 " << right << '\n'; 
		count++;
		return;
	}
	else
	{
		recursion_2(n-1, count, left, middle, right);
		std::cout << "第 " << count+1  << " 步：" << "移动 " << n << " 从 " << left << " 到 " << middle << '\n';
		count++;
		recursion_2(n-1, count, right, middle, left);
		std::cout << "第 " << count+1  << " 步：" << "移动 " << n << " 从 " << middle << " 到 " << right << '\n'; 
		count++;
		recursion_2(n-1, count, left, middle, right);
	}
}

void hanoProblem(int n)
{
	int count = 0;
	std::string left = "左";
	std::string middle = "中";
	std::string right = "右";
	//recursion_1(n, count, left, middle, right);
	recursion_2(n, count, left, middle, right);
}

int main(int argc, char** argv)
{
	if (argc != 2)
		std::cout << "未输入汉诺塔的高度（int），请重新输入！！\n";
	hanoProblem(*(argv[1])-'0');
	return 0;
}
