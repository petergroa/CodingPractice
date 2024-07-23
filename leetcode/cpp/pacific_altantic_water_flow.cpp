/* Leetcode 417.
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 * The island is partitioned into a grid of square cells. You are given an mxn
 * integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 *
 * The island receives a lot of rain, and the rain water can flow to neighboring
 * cells directly north, south, east, and west if the neighboring cell's height
 * is less than or equal to the current cell's height. Water can flow from any
 * cell adjacent to an ocean into the ocean.
 *
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> solve(std::vector<std::vector<int>>& heights) {
            std::vector<std::vector<int>> sol;
            int x = heights[0].size(), y = heights.size();
            bool p[x][y], a[x][y];

            fprintf(stdout, "P matrix");
            // Calculate p matrix
            for(int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (i == 0 || j == 0)
                        p[i][j] = true;
                    else if (heights[i][j] > heights[i-1][j] && p[i-1][j])
                        p[i][j] = true;
                    else if (heights[i][j] > heights[i][j-1] && p[i][j-1])
                        p[i][j] = true;
                    else p[i][j] = false;

                    (p[i][j])? fprintf(stdout, "true "): fprintf(stdout, "false");
                }
                fprintf(stdout, "\n");
            }

            fprintf(stdout, "\nA matrix");
            for(int i = (y-1); i >= 0; i--) {
                for (int j = (x-1); j >= 0; j--) {
                    if (i == (y-1) || j == (x-1))
                        a[i][j] = true;
                    else if (heights[i][j] > heights[i+1][j] && a[i+1][j])
                        a[i][j] = true;
                    else if (heights[i][j] > heights[i][j+1] && a[i][j+1])
                        a[i][j] = true;
                    else a[i][j] = false;

                    // Add to vector if it reaches both seas
                    if (a[i][j] && p[i][j])
                        sol.push_back({j, i});
                    (p[i][j])? fprintf(stdout, "true "): fprintf(stdout, "false");
                }
                fprintf(stdout, "\n");
            }

            return sol;
        }
};

int main(int argc, char *argv[]) {
    int dimx, dimy;
    std::vector<int> v(dimx, 0);
    std::vector<std::vector<int>> heights(dimy, v);
    fscanf(stdin, "%i %i", &dimx, &dimy);

    for (int i = 0; i < dimy; i++)
        for (int j = 0; j < dimx; j++)
            fscanf(stdin, "%i ", &heights[i][j]);

    fprintf(stdout, "\n");
    for (int i = 0; i < dimy; i++)
        for (int j = 0; j < dimx; j++)
            fprintf(stdout, "%i ", heights[i][j]);
    fprintf(stdout, "\n\n");

    Solution sol;
    sol.solve(heights);
    return 0;
}
