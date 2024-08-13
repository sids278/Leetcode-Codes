class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int gc = 0;

    int numComps(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        int cnt =0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {

                    cnt++;

                    q.push({i,j});
                    vis[i][j] = 1;

                    while(!q.empty())
                    {
                        int r = q.front().first;
                        int c = q.front().second;

                        q.pop();
                        gc++;

                        for(int i=0;i<4;i++)
                        {
                            int nx = r + dx[i];
                            int ny = c + dy[i];

                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 1 && !vis[nx][ny])
                            {
                                q.push({nx,ny});
                                vis[nx][ny] = 1;
                            }
                        }


                    }
                    
                }
            }
        }


        return cnt;

    }
     //max days are 2 and can be less than this if you see
        // you can take 2 days and make the two island cooordinates into water that is the last one k upar wala and uske left wala toh the last wala becomes seperated from the rest now there are disconnected--> so ultimatedly our goal is to check if we can do it in less than two days
    
        // [....""
        //  ..."".//<-- now this dot is seperated
        // ]
    int minDays(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int tot = numComps(grid);

        if(tot==1 && gc ==1)
        {
            return 1;
        }
        if(tot > 1 || tot==0)
        {
            return 0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;

                    int cnt = numComps(grid);

                    if(cnt >1)
                    {
                        return 1;
                    }

                    grid[i][j] =1;
                }
            }
        }

        return 2;

    }
};