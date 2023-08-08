#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

//nxn的地图，从(0, 0)到(n - 1, n - 1)，0不可走  1可走，可以上下左右，问到终点时的最小步数
int levelcount_bfs(vector<vector<int>>& tiles, int x, int y){
	int tilewidth = tiles.size();	//x轴
	int tileheight = tiles.front().size();	//y轴
	
	int count = 0;
	queue<pair<int, int>> nodes;
	tiles[x][y] = 0;
	nodes.push(make_pair(x, y));

	const int movesize = 4;
	int dxy[movesize][2] = {{0,1},{0,-1},{1,0},{-1,0}};

	while(nodes.size()){
		int n = nodes.size();	//上一层的坐标数
		while(n--){
			pair<int, int> v = nodes.front();
			nodes.pop();
			if(v.first == tilewidth - 1 && v.second == tileheight - 1) { return count; }

			for(int i = 0; i < movesize; ++i){
				x = v.first + dxy[i][0];
				y = v.second + dxy[i][1];
				if(0 <= x && x < tilewidth && 0 <= y && y < tileheight && tiles[x][y]){
					tiles[x][y] = 0;
					nodes.push(make_pair(x, y));
				}
			}
		}
		++count;	//层数累加
	}
	return -1;	//无法到达目标点
}
