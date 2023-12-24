#include <iostream>

/*
                        Q. print the matrix in spiral manner

                explanation - we will be given an n*m matrix and we have print all the elements in clockwise spiral manner

                                1   2   3   4   5   6
                               20  21  22  23  24   7
                               19  32  33  34  25   8
                               18  31  36  35  26   9
                               17  30  29  28  27  10
                               16  15  14  13  12  11

                        there is no brute solution for this question only optimal one

            optimal sol -  from the given matrix we can say that the matrix moves like -
                                right -> down -> left -> up         - in the 1st layer (i.e outer part)
                                right -> down -> left -> up         - in the 2nd layer
                                right -> down -> left               - in the 3rd layer (i.e inner layer)

                    we also see that the indexes,  top = 0,  bottom = 5
                                                   left = 0,  right = 5

                    firstly we are printing [1  2  3  4  5  6],  then printing [7  8  9  10  11], 
                            then [12  13  14  15  16],  then [17  18  19  20]

        pseudo code
// for the 1st layer (outer layer)
// for 'right'
for(i=left->right)
    a[top][i]
top++                       // down should not start from element 6

// for 'down'
for(i=top->down)
    print(a[i][right])

// for 'left'
for(i=right->left)
    print(a[down][i])
down--                      // up should not start from element 16

// for 'up'
for(i=down->top)
    print(a[i][left])
left++                      // 2nd layer should not start from element 20


        Actual code
vector<int> spiralMatrix(vector<vector<int>>&mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while(top <= bottom && left <= right)
    {
        // right
        for(int i = left; i <= right; i++)
        {
            ans.pushback(mat[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;
        
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        
        if(left <= right)
        {
            for(int i = bottom; i>= top; i++)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}


                TC - O(n*m)
                SC - O(n*m)
*/

int main()
{
    std::cout << "Hello World!\n";
}