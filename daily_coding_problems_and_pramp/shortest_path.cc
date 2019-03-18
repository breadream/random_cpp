#import <iostream>
#import <vector>
#import <unordered_set>
#import <queue>

using namespace std;

struct Node 
{
  int x, y, dist;
};

const int row[] = {-1, 0, 0, 1};
const int col[] = {0 ,-1, 1, 0}; 

bool isValid (const vector<vector<int>>& grid, int x, int y)
{
  return (x >= 0) && (x < grid.size()) && (y >= 0) && (y < grid[0].size()) 
         && grid[x][y];
}
int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
  int size = 0;
  
  bool visited [grid.size()][grid[0].size()];
  memset(visited, false, sizeof visited);
  
  visited[sr][sc] = true;
  
  queue<Node> queue;
  queue.push({sr, sc, 0});
  
  int minDist = std::numeric_limits<int>::max(); 
  
  while (!queue.empty())
  {
    Node node = queue.front();
    queue.pop();
    int i = node.x;
    int j = node.y;
    int dist = node.dist;
    
    if (i == tr && j == tc)
    {
      minDist = dist;
      break;
    }      
    
    for (int dir = 0; dir < 4; dir++)
    {
      if (isValid(grid, i + row[dir], j + col[dir]) && !visited[i+row[dir]][j+col[dir]])
      {
        visited[i+row[dir]][j+col[dir]] = true;      
        queue.push({i+row[dir], j+col[dir], dist+1});
      }
    }
  }
  return minDist == std::numeric_limits<int>::max() ? -1 : minDist;
}

int main() 
{
	return 0;
}

