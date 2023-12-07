from typing import List

class FindMinGrid:
    # 迷宫地图
    MAZE = (
        (0, 0, 0, 0, 0, 0, 0),
        (0, 0, 0, 1, 0, 0, 0),
        (0, 0, 0, 1, 0, 0, 0),
        (0, 0, 0, 1, 0, 0, 0),
        (0, 0, 0, 0, 0, 0, 0)
    )
    
    #A*寻路主逻辑
    @staticmethod
    def a_star_search(start: "Grid", end: "Grid") -> "Grid":
        open_list: List["Grid"] = []
        close_list: List["Grid"] = []

        # 把起点加入 open_list
        open_list.append(start)

        # 主循环，每一轮检查1个当前方格节点
        while len(open_list) > 0:
            # 在 open_list 中查找 F 值最小的节点，将其作为当前方格节点
            current_grid = min(open_list, key=lambda x: x.f)

            # 将当前方格节点从 open_list 中移除
            open_list.remove(current_grid)

            # 当前方格节点进入 close_list
            close_list.append(current_grid)

            # 找到所有邻近节点
            neighbors = FindMinGrid.find_neighbors(current_grid, open_list, close_list)

            for grid in neighbors:
                if grid not in open_list:
                    # 邻近节点不在 open_list 中，标记“父节点”、G、H、F，并放入 open_list
                    grid.init_grid(current_grid, end)
                    open_list.append(grid)
                else:
                    # 邻近节点已经在 open_list 中，比较新的路径是否更优，如果更优，则更新父节点和 G 值
                    index = open_list.index(grid)
                    if grid.g > current_grid.g + 1:
                        grid.parent = current_grid
                        grid.g = current_grid.g + 1
                        grid.f = grid.g + grid.h
                        open_list[index] = grid

            # 如果终点在 open_list 中，直接返回终点格子
            for grid in open_list:
                if grid.x == end.x and grid.y == end.y:
                    return grid

        # open_list 用尽，依然找不到终点，说明终点不可到达，返回空
        return None

    @staticmethod
    def find_neighbors(grid: "Grid", open_list: List["Grid"], close_list: List["Grid"]) -> List["Grid"]:
        grid_list = []

        for x_off, y_off in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
            x = grid.x + x_off
            y = grid.y + y_off

            if FindMinGrid.is_valid_grid(x, y, open_list, close_list):
                grid_list.append(Grid(x, y))

        return grid_list

    @staticmethod
    def is_valid_grid(x: int, y: int, open_list: List["Grid"], close_list: List["Grid"]) -> bool:
        # 是否超过边界
        if x < 0 or x >= len(FindMinGrid.MAZE) or y < 0 or y >= len(FindMinGrid.MAZE[0]):
            return False

        # 是否有障碍物
        if FindMinGrid.MAZE[x][y] == 1:
            return False

        # 是否已经在 open_list 中
        if any(grid.x == x and grid.y == y for grid in open_list):
            return False

        # 是否已经在 close_list 中
        if any(grid.x == x and grid.y == y for grid in close_list):
            return False

        return True

class Grid:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y
        self.parent = None
        self.g = 0
        self.h = 0
        self.f = 0

    def init_grid(self, parent: "Grid", end: "Grid"):
        self.parent = parent
        self.g = parent.g + 1 if parent else 1
        self.h = abs(self.x - end.x) + abs(self.y - end.y)
        self.f = self.g + self.h

if __name__ == "__main__":
    # 设置起点和终点
    start = Grid(2, 1)
    end = Grid(2, 5)

    # 搜索迷宫终点
    result = FindMinGrid.a_star_search(start, end)

    # 回溯迷宫路径
    path = []
    while result:
        path.append(Grid(result.x, result.y))
        result = result.parent

    # 输出迷宫和路径，路径用*表示
    for i in range(len(FindMinGrid.MAZE)):
        for j in range(len(FindMinGrid.MAZE[0])):
            if any(grid.x == i and grid.y == j for grid in path):
                print("*", end=", ")
            else:
                print(FindMinGrid.MAZE[i][j], end=", ")
        print()
