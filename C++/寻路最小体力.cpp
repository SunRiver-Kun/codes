
//nxn的地图，从(0, 0)到(n - 1, n - 1)，0不可走  正数表示从这点出发消耗的体力，可以上下左右，问到终点时的最小消耗的体力
int minstrength_bfs(vector<vector<int>>& tiles, int x, int y){
	int tilewidth = tiles.size();	//x轴
	int tileheight = tiles.front().size();	//y轴
	vector<vector<int>> lastvals(tileheight, vector<int>(tileheight, INT32_MAX));	//到达x,y需要的最少体力
	queue<pair<int, int>> nodes;	//最小体力变化后，需要更新的点
	lastvals[x][y] = 0;
	nodes.push(make_pair(x, y));

	const int movesize = 4;
	int dxy[movesize][2] = {{0,1},{0,-1},{1,0},{-1,0}};

	while(nodes.size()){	
		int n = nodes.size();
		unordered_map<int, unordered_map<int, bool>> nextvisit;
		while(n--)
		{
			pair<int, int> v = nodes.front();
			nodes.pop();

			int lastval = lastvals[v.first][v.second] + tiles[v.first][v.second];
			for(int i = 0; i < movesize; ++i){
				x = v.first + dxy[i][0];
				y = v.second + dxy[i][1];
				if(0 <= x && x < tilewidth && 0 <= y && y < tileheight && tiles[x][y] &&	//可走的点
					lastval < lastvals[x][y]){	//到(x,y)的最小体力更新了
					lastvals[x][y] = lastval;
					if(!nextvisit[x][y]){	//避免重复插入节点
						nextvisit[x][y] = true;
						nodes.push(make_pair(x, y));						}
				}
			}
		}
	}

	return lastvals.back().back();
}