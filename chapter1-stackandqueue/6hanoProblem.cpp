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
		std::cout << "第 " << count+1  << " 步：移动 " << n << " 从 " << left << " 到 " << right << '\n'; 
		count++;
		return;
	}
	else
	{
		recursion_1(n-1, count, left, right, middle);
		std::cout << "第 " << count+1  << " 步：移动 " << n << " 从 " << left << " 到 " << right << '\n';
		count++;
		recursion_1(n-1, count, middle, left, right);
	}
}

//解决办法2，使用递归，并且从左、右两个柱之间不能直接移动，需要经过中间柱
void recursion_2(int n, int &count, std::string left, std::string middle, std::string right)
{
	if (n == 1)
	{
		std::cout << "第 " << count+1  << " 步：移动 " << n << " 从 " << left << " 到 " << middle << '\n'; 
		count++;
		std::cout << "第 " << count+1  << " 步：移动 " << n << " 从 " << middle << " 到 " << right << '\n'; 
		count++;
		return;
	}
	else
	{
		recursion_2(n-1, count, left, middle, right);
		std::cout << "第 " << count+1  << " 步：移动 " << n << " 从 " << left << " 到 " << middle << '\n';
		count++;
		recursion_2(n-1, count, right, middle, left);
		std::cout << "第 " << count+1  << " 步：移动 " << n << " 从 " << middle << " 到 " << right << '\n'; 
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

//解决办法3，使用堆栈，非递归，并且相邻柱之间移动，不能跨柱
//借用了左老师的思路，合法的移动行为是大片上放小片以及不能与上一动作互为逆动作
enum action{
	NoAction,
	LtoM,
	MtoL,
	MtoR,
	RtoM
};

action checkValidAction(std::stack<int> &left, std::stack<int> &middle, std::stack<int> &right, action preAction)
{
	action curAction;
	switch (preAction){
	case LtoM:
		if (right.empty() || middle.top() < right.top())
			curAction = MtoR;
		else
			curAction = RtoM;
		break;
	
	case MtoL:
		if (!middle.empty() && (right.empty() || middle.top() < right.top()))
			curAction = MtoR;	
		else
			curAction = RtoM;
		break;
	
	case MtoR:
		if (!middle.empty() && (left.empty() || middle.top() < left.top()))
			curAction = MtoL;
		else
			curAction = LtoM;
		break;

	default:
		if (left.empty() || middle.top() < left.top())
			curAction = MtoL;
		else
			curAction = LtoM;
		break;
	}
	return curAction;
}

void hanoProblemWithStack(int n)
{
	std::stack<int>	left;
	for (int i = n; i > 0; --i)
		left.push(i);
	std::stack<int> middle;
	std::stack<int> right;
	action preAction;
	action curAction = LtoM;	
	int count = 0;
	while (1)
	{		
		switch (curAction){
		case LtoM:
			std::cout << "第 " << count+1 << " 步：移动 " << left.top() << " 从左到中\n";
			middle.push(left.top());
			left.pop();
			count++;
			break;
		case MtoL:
			std::cout << "第 " << count+1 << " 步：移动 " << middle.top() << " 从中到左\n";
			left.push(middle.top());
			middle.pop();
			count++;
			break;
		case MtoR:
			std::cout << "第 " << count+1 << " 步：移动 " << middle.top() << " 从中到右\n";
			right.push(middle.top());
			middle.pop();
			count++;
			break;
		default:
			std::cout << "第 " << count+1 << " 步：移动 " << right.top() << " 从右到中\n";
			middle.push(right.top());
			right.pop();
			count++;
			break;
		}
		preAction = curAction;
		curAction = checkValidAction(left, middle, right, preAction);
		if (left.empty() && middle.empty() && right.size() == n)
			break;
	}	
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "未输入汉诺塔的高度（int），请重新输入！！\n";
		return 0;
	}
	hanoProblem(*argv[1] - '0');
	//hanoProblmeWithStack(*argv[1] - '0');
	return 1;
}
