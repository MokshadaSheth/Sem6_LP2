#include <bits/stdc++.h>
using namespace std;
int goalX = 2;
int goalY = 2; // Global goal for this game
class Node
{
    int x, y;
    int value;
    int g, h, f;

public:
    friend class Puzzle;
    Node(int v, int x, int y) : value(v), x(x), y(y), g(0), h(-1), f(-1) {}
    void calH()
    { // Manhattan Heuristic method
        h = abs(x - goalX) + abs(y - goalY);
    }
    void calF()
    {
        f = g + h;
    }
};
class Puzzle
{
    Node *grid[9];
    map<pair<int, int>, int> gridMatrixMap;
    int startX, startY;

public:
    Puzzle()
    {
        cout << "\nEnter the initial grid for the game\nNote: Put 0 for tile\n\n";
        int gridPos = 0, val;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "Enter {" << i << "," << j << "}: " << endl;
                cin >> val;

                grid[gridPos] = new Node(val, i, j);
                // if (val == 0) // this is the tile
                // {
                //     startX = i;
                //     startY = j;
                // }

                gridMatrixMap[{i, j}] = gridPos;
                // gridMatrixMap[gridPos] = {i,j};
                gridPos++;
            }
        }
        cout<<"\nEnter starting coordinates: ";
        cin>>startX>>startY;
        cout<<"\nEnter final position: ";
        cin>>goalX>>goalY;
    }
    void display()
    {
        cout << "\nInitial State:\n\n";
        for (int i = 0; i < 9; i++)
        {
            cout << " " << grid[i]->value; //<<" {"<<grid[i]->x<<","<<grid[i]->y<<"}";
            if (i == 2 || i == 5 || i == 8)
                cout << "\n";
        }
    }
    void solve()
    {
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int step = 0;
        int prevX = startX;
        int prevY = startY;
        vector<bool>visited(9,false);
        visited[gridMatrixMap[{prevX,prevY}]] = true;
        // for(int i=0;i<3;i++)
        // {
        //     for(int j=0; j<3;j++)
        //     {
        //         cout<<" "<<gridMatrixMap[{i,j}];
        //     }
        //     cout<<"\n";
        // }
        
        while (true)
        {
            cout<<"\nagain in";
            step++;
            int minF = INT_MAX;
            int nextPos,prevPos;
            for (int i = 0; i < 4; i++)
            {
                int currX = prevX + dx[i];
                int currY = prevY + dy[i];

                if(currX>=0 && currX<=2 && currY>=0 && currY<=2 && visited[gridMatrixMap[{currX,currY}]] == false)
                {
                    int gridPos = gridMatrixMap[{currX,currY}];
                    if(grid[gridPos]->value == 0)  continue;
                    cout<<"\nChecking for: "<<grid[gridPos]->value;

                    grid[gridPos]->g = step;
                    grid[gridPos]->calH();
                    grid[gridPos]->calF();
                    if(grid[gridPos]->f < minF)
                    {
                        minF = grid[gridPos]->f;
                        nextPos = gridPos;
                        
                    }
                }
            }
            prevPos = grid[gridMatrixMap[{prevX,prevY}]]->value;
            int temp = grid[prevPos]->value;
            grid[prevPos]->value = grid[nextPos]->value;
            grid[nextPos]->value = temp;
            prevX = grid[nextPos]->x;
            prevY = grid[nextPos]->y;
            visited[gridMatrixMap[{prevX,prevY}]] = true;
            cout<<"\nSelected square: {"<<prevX<<","<<prevY<<"}";
            if(prevX==goalX && prevY==goalY) return;
        }
            
    }
};
int main()
{
    Puzzle obj;
    obj.display();
    obj.solve();
    obj.display();
    return 0;
}