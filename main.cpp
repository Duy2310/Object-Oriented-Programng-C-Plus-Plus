#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>

// Define a structure for a point in the grid
struct Point {
    int x, y;
    
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Equality operator for comparison
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Custom hash function for Point to use in unordered_map
struct PointHash {
    std::size_t operator()(const Point& p) const {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

// Function to find path from source to destination in a 2D grid
std::vector<Point> findPath(const std::vector<std::vector<int>>& grid, 
                            const Point& source, 
                            const Point& destination) {
    // Check if grid is empty
    if (grid.empty() || grid[0].empty()) {
        return {};
    }
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    // Check if source or destination is out of bounds
    if (source.x < 0 || source.x >= rows || source.y < 0 || source.y >= cols ||
        destination.x < 0 || destination.x >= rows || destination.y < 0 || destination.y >= cols) {
        return {};
    }
    
    // Check if source or destination is an obstacle
    if (grid[source.x][source.y] == 1 || grid[destination.x][destination.y] == 1) {
        return {};
    }
    
    // Define the four possible moves (up, right, down, left)
    const std::vector<std::pair<int, int>> directions = {
        {-1, 0},  // Up
        {0, 1},   // Right
        {1, 0},   // Down
        {0, -1}   // Left
    };
    
    // Queue for BFS
    std::queue<Point> q;
    q.push(source);
    
    // Keep track of visited cells and their parent
    std::unordered_map<Point, Point, PointHash> parent;
    parent[source] = source;  // Mark source as its own parent
    
    // BFS
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        // Check if we've reached the destination
        if (current == destination) {
            break;
        }
        
        // Try all four directions
        for (const auto& dir : directions) {
            Point next(current.x + dir.first, current.y + dir.second);
            
            // Check if next point is valid (in bounds, not an obstacle, not visited)
            if (next.x >= 0 && next.x < rows && next.y >= 0 && next.y < cols && 
                grid[next.x][next.y] == 0 && parent.find(next) == parent.end()) {
                q.push(next);
                parent[next] = current;
            }
        }
    }
    
    // If destination was not reached
    if (parent.find(destination) == parent.end()) {
        return {};
    }
    
    // Reconstruct the path from source to destination
    std::vector<Point> path;
    Point current = destination;
    
    while (!(current == source)) {
        path.push_back(current);
        current = parent[current];
    }
    
    path.push_back(source);  // Add the source to the path
    std::reverse(path.begin(), path.end());  // Reverse to get path from source to destination
    
    return path;
}

// Function to print the path for debugging
void printPath(const std::vector<Point>& path) {
    std::cout << "Path: ";
    for (const auto& point : path) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;
}

// Function to print the grid with the path for visualization
void printGridWithPath(const std::vector<std::vector<int>>& grid, const std::vector<Point>& path) {
    std::vector<std::vector<char>> display = std::vector<std::vector<char>>(
        grid.size(), std::vector<char>(grid[0].size(), ' ')
    );
    
    // Mark obstacles
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                display[i][j] = '#';  // Obstacle
            } else {
                display[i][j] = '.';  // Empty
            }
        }
    }
    
    // Mark path
    for (size_t i = 0; i < path.size(); ++i) {
        display[path[i].x][path[i].y] = '*';  // Path
    }
    
    // Mark source and destination
    if (!path.empty()) {
        display[path.front().x][path.front().y] = 'S';  // Source
        display[path.back().x][path.back().y] = 'D';    // Destination
    }
    
    // Print the grid
    for (const auto& row : display) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

// Example usage
int main() {
    // Example grid: 0 = empty, 1 = obstacle
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    
    Point source(0, 0);
    Point destination(4, 4);
    
    std::vector<Point> path = findPath(grid, source, destination);
    
    if (path.empty()) {
        std::cout << "No path found!" << std::endl;
    } else {
        std::cout << "Path found!" << std::endl;
        printPath(path);
        printGridWithPath(grid, path);
    }
    
    return 0;
}
