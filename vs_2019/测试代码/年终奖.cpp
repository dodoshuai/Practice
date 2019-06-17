#include<iostream>
#include<vector>
using namespace std;

int getMost(vector<vector<int> > board) {
	int a[6][6] = { 0 };
	a[0][0] = board[0][0];
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			int t = 0;
			int l = 0;
			if (i > 0) {
				t = board[i - 1][j];
			}

			if (j > 0) {
				l= board[i][j - 1];
			}

			if (t > l) {
				a[i][j] =a[i-1][j]+t;
			}
			else {
				a[i][j] = a[i][j-1]+l;
			}
			
		/*	if (i == 0 && j == 0) {
				//如果是起点坐标，不做任何处理。
			}
			else if (i == 0) {
				//这里我们看的是当前能到达这个该点的路径。因为第一行是没有上面的元素可以到        
				//达的，但是有他左边的元素可以到达。所以可以理解为他只能向右走，可能我的表 
				//述有问题，同理第一列也是这个意思
				//如果走在行的临界边，也就是第一行，那么他只能向右走
				//向右走的时候该点就要将后面的值加起来。
				board[i][j] += board[i][j - 1];
			}
			else if (j == 0) {
				//如果走在列的临界边，也就是第一列，那么他只能向下走
				//向下走的时候该点就要将上面的值加起来。
				board[i][j] += board[i - 1][j];
			}
			else {
				//核心点在这，除去两个临界边，剩下的就是既能向右走，也能向下走，
				//那么这时候就要考虑走到当前点的所有可能得情况，也就是走到当前点
				//各自路径的和是不是这些所有到达该点路径当中最大的了。
				//temup用来存储从该点上面走下来的最大路径和。
				//templeft用来存储从该点左边走过来的最大路径的和，
				int temup = board[i - 1][j];
				int templeft = board[i][j - 1];
				//这两者肯定只能选其一，进行比较，那个大，就把这个值加给当前点，
				//因为从一开始我们就进行了大小的比较，每一个点存储的都是到达当前点
				//的最大值。所以直到最后一个点为止，她的值就是当前最大值的和。只要返回
				//最后一个点的内容就可以了。
				if (temup > templeft) {
					board[i][j] += temup;
				}
				else {
					board[i][j] += templeft;
				}
			}
			*/
		}
	}
	return a[board.size()-1][board[0].size()-1];
	//	return  board[board.size() - 1][board[0].size() - 1];
}

int main() {
	
}