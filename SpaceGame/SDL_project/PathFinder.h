#pragma once
#include "Map.h"
#include "Cell.h"
#include "Level.h"

enum class NodeStatus { None, Closed, Open };

class Node
{
public:
	Cell cell;
	NodeStatus status = NodeStatus::None;
	double g = 0, h = 0;
	std::shared_ptr<Node> cameFrom;

	Node(Cell& point)
		: cell(point)
	{
	}

	Node(int x, int y)
		: cell(x, y)
	{
	}
};

struct CompareNodeByGPlusH
{
	bool operator()(const std::shared_ptr<Node>& left, const std::shared_ptr<Node>& right)
	{
		return left->g + left->h > right->g + right->h;
	}
};

class Pathfinder
{
public:
	std::vector<Cell> findPath(const Level& map, const Cell& start, const Cell& goal);
	std::vector<Cell> reconstructPath(std::shared_ptr<Node> goalNode);

private:
	std::vector<std::vector<std::shared_ptr<Node>>> nodes;
	/*std::priority_queue<std::shared_ptr<Node>,
	std::vector<std::shared_ptr<Node>>,
	CompareNodeByGPlusH> openSet;*/

	void addToClosedSet(std::shared_ptr<Node> node);
	void addToOpenSet(std::shared_ptr<Node> node);

	std::shared_ptr<Node> getOpenSetElementWithLowestScore();

	std::vector<std::shared_ptr<Node>> getNeighbours(std::shared_ptr<Node> node);
	std::shared_ptr<Node> getOrCreateNode(int x, int y);
	std::shared_ptr<Node> getOrCreateNode(const Cell& point);
	bool isInClosedSet(Cell& point);
};

class PathfinderError : public std::exception
{
};
